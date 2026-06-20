__int64 __fastcall hdd_add_uplink_jitter(
        _QWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  _QWORD *v22; // x21
  int v23; // w22
  __int64 v24; // x8
  _DWORD *v25; // x8
  __int64 v26; // x1
  unsigned int v27; // w20
  __int64 v28; // x4
  __int64 result; // x0
  __int64 v30; // [xsp+0h] [xbp-10h] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"hdd_add_uplink_jitter", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = a1[3];
  v22 = context;
  LODWORD(v30) = 0;
  v23 = *(unsigned __int8 *)(*(_QWORD *)(v21 + 104) + 18LL);
  if ( v23 == 1 )
  {
    qdf_trace_msg(0x33u, 4u, "%s: Received", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_add_uplink_jitter");
    if ( !a1[4924] )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: jitter request with tsf_auto_report_disabled",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "hdd_add_uplink_jitter");
LABEL_21:
      result = 0;
      goto LABEL_22;
    }
  }
  else if ( !a1[4924] )
  {
    goto LABEL_21;
  }
  if ( !v22 || !*v22 )
  {
    qdf_trace_msg(
      0x89u,
      2u,
      "%s: Invalid SOC instance",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "cdp_get_uplink_jitter",
      v30,
      v31);
LABEL_14:
    v27 = 16;
LABEL_15:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Error getting jitter",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hdd_add_uplink_jitter",
      v30);
    v28 = 0;
    LODWORD(v30) = 0;
    goto LABEL_16;
  }
  v24 = *(_QWORD *)(*v22 + 8LL);
  if ( !v24 )
    goto LABEL_14;
  v25 = *(_DWORD **)(v24 + 232);
  if ( !v25 )
    goto LABEL_14;
  v26 = *(unsigned __int8 *)(a1[6604] + 8LL);
  if ( *(v25 - 1) != -337757947 )
    __break(0x8228u);
  v27 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64 *))v25)(v22, v26, &v30);
  if ( v27 )
    goto LABEL_15;
  v28 = (unsigned int)v30;
LABEL_16:
  if ( v23 )
  {
    qdf_trace_msg(0x33u, 4u, "%s: jitter %d", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_add_uplink_jitter", v28);
    LODWORD(v28) = v30;
  }
  HIDWORD(v30) = v28;
  if ( (unsigned int)nla_put(a2, 54, 4, (char *)&v30 + 4) )
    result = 16;
  else
    result = v27;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
