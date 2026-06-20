__int64 _qdf_cpuhp_os_deinit()
{
  __int64 result; // x0

  result = (unsigned int)registered_hotplug_state;
  if ( registered_hotplug_state )
    return _cpuhp_remove_state();
  return result;
}
