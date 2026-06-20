__int64 __fastcall mlo_mgr_ser_link_switch_cb(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 result; // x0
  __int64 v12; // x20
  __int64 v13; // x22
  unsigned int v14; // w21

  if ( !a1 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: cmd is NULL, reason: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "mlo_mgr_ser_link_switch_cb",
      (unsigned int)a2);
    return 29;
  }
  v10 = *(_QWORD *)(a1 + 32);
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
      return 0;
    if ( a2 == 3 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Link switch active cmd timeout",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "mlo_mgr_ser_link_switch_cb");
      wlan_cm_trigger_panic_on_cmd_timeout(v10);
      return 0;
    }
    goto LABEL_10;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Link switch cmd cancelled",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "mlo_mgr_ser_link_switch_cb");
      return 0;
    }
LABEL_10:
    mlo_mgr_link_switch_complete(*(_QWORD *)(a1 + 32));
    return 0;
  }
  v12 = *(_QWORD *)(*(_QWORD *)(v10 + 1360) + 3880LL);
  result = mlo_mgr_start_link_switch(*(_QWORD *)(a1 + 32));
  if ( (_DWORD)result )
  {
    v13 = *(_QWORD *)(v10 + 1360);
    v14 = result;
    qdf_mutex_acquire(v13 + 1656);
    *(_DWORD *)(*(_QWORD *)(v13 + 3880) + 164LL) = 6;
    qdf_mutex_release(v13 + 1656);
    mlo_mgr_link_switch_notify(v10, v12 + 144);
    mlo_mgr_link_switch_complete(v10);
    return v14;
  }
  return result;
}
