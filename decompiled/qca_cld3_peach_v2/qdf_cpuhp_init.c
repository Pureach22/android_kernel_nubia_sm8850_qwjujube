__int64 qdf_cpuhp_init()
{
  __int64 result; // x0

  result = qdf_mutex_create((__int64)&qdf_cpuhp_lock);
  if ( !(_DWORD)result )
  {
    qdf_cpuhp_handlers = (__int64)&qdf_cpuhp_handlers;
    qword_92E430 = (__int64)&qdf_cpuhp_handlers;
    qword_92E438 = 0;
    _qdf_cpuhp_os_init(qdf_cpuhp_on_up, qdf_cpuhp_on_down);
    return 0;
  }
  return result;
}
