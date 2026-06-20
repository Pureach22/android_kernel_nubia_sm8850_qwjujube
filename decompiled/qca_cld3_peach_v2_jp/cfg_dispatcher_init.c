__int64 cfg_dispatcher_init()
{
  __int64 result; // x0
  unsigned int v1; // w19

  qdf_trace_msg(80, 8, "%s: enter", "cfg_dispatcher_init");
  if ( (_cfg_is_init & 1) != 0 )
    return 4;
  _cfg_stores_list = (__int64)&_cfg_stores_list;
  qword_6A40A8 = (__int64)&_cfg_stores_list;
  qword_6A40B0 = 0;
  _cfg_stores_lock = 0;
  qword_6A40C0 = 0;
  result = wlan_objmgr_register_psoc_create_handler(7, cfg_on_psoc_create, 0);
  if ( !(_DWORD)result )
  {
    result = wlan_objmgr_register_psoc_destroy_handler(7, cfg_on_psoc_destroy, 0);
    if ( (_DWORD)result )
    {
      v1 = result;
      wlan_objmgr_unregister_psoc_create_handler(7, cfg_on_psoc_create, 0);
      return v1;
    }
    else
    {
      _cfg_is_init = 1;
    }
  }
  return result;
}
