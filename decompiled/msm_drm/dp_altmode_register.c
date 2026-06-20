__int64 __fastcall dp_altmode_register(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  int v6; // w2
  __int64 result; // x0
  _QWORD v8[5]; // [xsp+8h] [xbp-28h] BYREF

  v8[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v8[0] = 65281;
  v8[1] = "displayport";
  v8[2] = a1;
  v8[3] = dp_altmode_notify;
  v3 = altmode_register_client(v2, v8);
  *(_QWORD *)(a1 + 96) = v3;
  ipc_log_context = get_ipc_log_context(v3);
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = *(_DWORD *)(StatusReg + 1800);
  if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL )
  {
    result = ipc_log_string(ipc_log_context, "[d][%-4d]success\n", v6);
    if ( (_drm_debug & 4) != 0 )
      result = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]success\n", *(_DWORD *)(StatusReg + 1800));
  }
  else
  {
    ipc_log_string(ipc_log_context, "[e][%-4d]failed to register as client: %ld\n", v6, *(_QWORD *)(a1 + 96));
    result = printk(&unk_2593CA, "dp_altmode_register");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
