__int64 __fastcall cm_send_rso_stop(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v11; // x0
  __int64 result; // x0
  char v13[4]; // [xsp+0h] [xbp-10h] BYREF
  char v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 1;
  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 216);
    if ( v9 )
      v11 = *(_QWORD *)(v9 + 80);
    else
      v11 = 0;
    v14[0] = 0;
    wlan_mlme_get_roaming_offload(v11, v14);
    cm_roam_state_change(*(_QWORD *)(a1 + 216), *(unsigned __int8 *)(a1 + 168), 3u, 4u, (__int64)v13, v14[0]);
    if ( v13[0] )
      result = 11;
    else
      result = 0;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "cm_send_rso_stop");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
