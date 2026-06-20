__int64 __fastcall sch_qos_update_local(
        _BYTE *a1,
        __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  _BYTE s[272]; // [xsp+8h] [xbp-118h] BYREF
  __int64 v32; // [xsp+118h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: user_edca_set : %u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sch_qos_update_local",
    *(unsigned __int8 *)(a2 + 10071));
  if ( *(_BYTE *)(a2 + 10071) )
  {
    if ( !a3 )
      goto LABEL_7;
    goto LABEL_6;
  }
  a3 = s;
  memset(s, 0, sizeof(s));
  if ( !(unsigned int)sch_get_params((__int64)a1, (__int64)s, 1u, v14, v15, v16, v17, v18, v19, v20, v21) )
  {
LABEL_6:
    set_sch_edca_params(a1, a3, a2);
LABEL_7:
    lim_set_active_edca_params(a1, (int *)(a2 + 7096), a2);
    result = lim_send_edca_params((__int64)a1, (int *)(a2 + 7136), *(unsigned __int8 *)(a2 + 10), 0);
    goto LABEL_8;
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: sch_get_params(local) failed",
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             "sch_qos_update_local");
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
