__int64 cfg_dispatcher_deinit()
{
  unsigned __int64 StatusReg; // x8

  qdf_trace_msg(80, 8, "%s: enter", "cfg_dispatcher_deinit");
  if ( _cfg_is_init != 1 )
    return 4;
  _cfg_is_init = 0;
  wlan_objmgr_unregister_psoc_create_handler(7, cfg_on_psoc_create, 0);
  wlan_objmgr_unregister_psoc_destroy_handler(7, cfg_on_psoc_destroy, 0);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_cfg_stores_lock);
  }
  else
  {
    raw_spin_lock_bh(&_cfg_stores_lock);
    qword_75CAF0 |= 1uLL;
  }
  qdf_list_empty(&_cfg_stores_list);
  if ( (qword_75CAF0 & 1) != 0 )
  {
    qword_75CAF0 &= ~1uLL;
    raw_spin_unlock_bh(&_cfg_stores_lock);
  }
  else
  {
    raw_spin_unlock(&_cfg_stores_lock);
  }
  if ( (_DWORD)qword_75CAE0 )
    qdf_trace_msg(51, 2, "%s: list length not equal to zero", "qdf_list_destroy");
  return 0;
}
