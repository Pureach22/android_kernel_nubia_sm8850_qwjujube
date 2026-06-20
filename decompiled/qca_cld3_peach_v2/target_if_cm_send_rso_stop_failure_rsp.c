__int64 __fastcall target_if_cm_send_rso_stop_failure_rsp(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 roam_rx_ops; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  void (__fastcall *v19)(_QWORD); // x8
  __int64 result; // x0
  _QWORD v21[3]; // [xsp+8h] [xbp-48h] BYREF
  int v22; // [xsp+20h] [xbp-30h]
  int v23; // [xsp+24h] [xbp-2Ch]
  __int64 v24; // [xsp+28h] [xbp-28h]
  __int64 v25; // [xsp+30h] [xbp-20h]
  __int64 v26; // [xsp+38h] [xbp-18h]
  __int64 v27; // [xsp+40h] [xbp-10h]
  __int64 v28; // [xsp+48h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v21[2] = 7;
  v26 = 0;
  v24 = 0;
  v25 = 0;
  v21[1] = a1;
  v21[0] = a2;
  v22 = 5;
  v27 = 1;
  roam_rx_ops = target_if_cm_get_roam_rx_ops(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( roam_rx_ops && (v19 = *(void (__fastcall **)(_QWORD))(roam_rx_ops + 24)) != nullptr )
  {
    if ( *((_DWORD *)v19 - 1) != -1251064106 )
      __break(0x8228u);
    v19(v21);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: No valid roam rx ops",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "target_if_cm_send_rso_stop_failure_rsp");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
