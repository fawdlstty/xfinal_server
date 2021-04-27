#ifndef __HTTP_METHOD_HPP__
#define __HTTP_METHOD_HPP__



#include <cstdint>
#include <functional>
#include <memory>
#include <string>



namespace xs {
	template<typename T>
	struct HttpMethodObjectPool {
		T *malloc () {
			std::unique_lock<std::mutex> ul { m_mtx };
			if (m_caches.empty ()) {
				ul.unlock ();
				return new T {};
			} else {
				size_t _n = m_caches.size () - 1;
				T *_ret = m_caches [_n];
				m_caches.erase (m_caches.begin () + _n);
				return _ret;
			}
		}
		void free (T *t) {
			std::unique_lock<std::mutex> ul { m_mtx };
			m_caches.push_back (t);
		}
		~HttpMethodObjectPool () {
			std::unique_lock<std::mutex> ul { m_mtx };
			for (T *_p : m_caches)
				delete _p;
			m_caches.clear ();
		}

	private:
		std::vector<T *>	m_caches;
		std::mutex			m_mtx;
	};



	struct HttpMethodBase {
		virtual void set_int (int _idx, int _val) = 0;
		virtual void set_int64_t (int _idx, int64_t _val) = 0;
		virtual void set_std_string (int _idx, std::string _val) = 0;
		virtual std::string call () = 0;
	};

	struct HttpMethod_: public HttpMethodBase {
		HttpMethod_ (): HttpMethodBase () {}
		void set_func (std::function<std::string ()> _func) {
			m_func = _func;
		}
		void set_int (int _idx, int _val) override {}
		void set_int64_t (int _idx, int64_t _val) override {}
		void set_std_string (int _idx, std::string _val) override {}
		std::string call () override {
			return m_func ();
		}

	private:
		std::function<std::string ()> m_func;
	};

	template<typename T0>
	struct HttpMethod0: public HttpMethodBase {
		HttpMethod0 (): HttpMethodBase () {}
		void set_func (std::function<std::string (T0)> _func) {
			m_func = _func;
		}
		void set_int (int _idx, int _val) override {
			if (_idx == 0) {
				if constexpr (std::is_same<T0, int>::value) m_val0 = (T0) _val; return;
			}
		}
		void set_int64_t (int _idx, int64_t _val) override {
			if (_idx == 0) {
				if constexpr (std::is_same<T0, int64_t>::value) m_val0 = (T0) _val; return;
			}
		}
		void set_std_string (int _idx, std::string _val) override {
			if (_idx == 0) {
				if constexpr (std::is_same<T0, std::string>::value) m_val0 = std::move ((T0) _val); return;
			}
		}
		std::string call () override {
			return m_func (std::move (m_val0));
		}

	private:
		T0 m_val0;
		std::function<std::string (T0)> m_func;
	};



	struct HttpMethodBaseBuilder {
		virtual HttpMethodBase *malloc () = 0;
		virtual void free (HttpMethodBase *_p) = 0;
	};

	struct HttpMethod_Builder: public HttpMethodBaseBuilder {
		HttpMethod_Builder (std::function<std::string ()> _func): HttpMethodBaseBuilder (), m_func (_func) {}
		HttpMethodBase *malloc () override {
			auto _p = m_pool.malloc (); _p->set_func (m_func); return _p;
		}
		void free (HttpMethodBase *_p) override {
			m_pool.free ((HttpMethod_ *) _p);
		}
	private:
		std::function<std::string ()> m_func;
		HttpMethodObjectPool<HttpMethod_> m_pool;
	};

	template<typename T0>
	struct HttpMethod0Builder: public HttpMethodBaseBuilder {
		HttpMethod0Builder (std::function<std::string (T0)> _func): HttpMethodBaseBuilder (), m_func (_func) {}
		HttpMethodBase *malloc () override {
			auto _p = m_pool.malloc (); _p->set_func (m_func); return _p;
		}
		void free (HttpMethodBase *_p) override {
			m_pool.free ((HttpMethod0<T0> *) _p);
		}
	private:
		std::function<std::string (T0)> m_func;
		HttpMethodObjectPool<HttpMethod0<T0>> m_pool;
	};
}



#endif //__HTTP_METHOD_HPP__
