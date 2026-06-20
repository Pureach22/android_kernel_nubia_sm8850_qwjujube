__int64 __fastcall _qdf_cpuhp_os_init(void *a1, void *a2)
{
  __int64 result; // x0

  _qdf_cpuhp_on_up = a1;
  _qdf_cpuhp_on_down = a2;
  result = _cpuhp_setup_state(193, "wlan/qca-qdf:online", 1, qdf_cpuhp_up_handler, qdf_cpuhp_down_handler, 0);
  registered_hotplug_state = result;
  return result;
}
