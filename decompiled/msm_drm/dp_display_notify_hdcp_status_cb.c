__int64 __fastcall dp_display_notify_hdcp_status_cb(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v10; // w7
  __int64 v12; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_notify_hdcp_status_cb",
      681,
      8,
      4369,
      *(_DWORD *)(*(_QWORD *)(a1 + 168) + 136LL),
      -1059143953,
      a8,
      vars0);
    *(_DWORD *)(*(_QWORD *)(a1 + 168) + 136LL) = a2;
    queue_delayed_work_on(32, *(_QWORD *)(a1 + 1520), a1 + 1528, 62);
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "dp_display_notify_hdcp_status_cb",
             687,
             8,
             8738,
             *(_DWORD *)(*(_QWORD *)(a1 + 168) + 136LL),
             -1059143953,
             v10,
             vars0a);
  }
  else
  {
    if ( !g_dp_display || (v12 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v12 = 0;
    ipc_log_string(v12, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_display_notify_hdcp_status_cb");
  }
}
