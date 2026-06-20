__int64 __fastcall policy_mgr_roam_invoke_on_sta_for_mcc(_QWORD *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int roam_state; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // [xsp+0h] [xbp-10h] BYREF
  __int16 v28; // [xsp+4h] [xbp-Ch]
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  roam_state = mlme_get_roam_state(*a1);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: STA(%d) + SAP(%d) in MCC, try roam on sta vdev %d (RSO enabled %d)",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "policy_mgr_roam_invoke_on_sta_for_mcc",
    a3,
    a4,
    (unsigned __int8)a2,
    roam_state == 2);
  result = mlme_get_roam_state(*a1);
  if ( (_DWORD)result == 2 )
  {
    v18 = a1[1];
    v28 = -1;
    v27 = -1;
    result = wlan_cm_roam_invoke(v18, a2, &v27, 0, 20);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x4Fu,
                 2u,
                 "%s: Vdev %d roam invoke failed",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "policy_mgr_roam_invoke_on_sta_for_mcc",
                 (unsigned __int8)a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
