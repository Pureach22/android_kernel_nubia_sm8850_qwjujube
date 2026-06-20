__int64 __fastcall hdd_add_uplink_delay(
        __int64 a1,
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
  _QWORD *v22; // x20
  int v23; // w22
  __int64 v24; // x8
  _DWORD *v25; // x8
  __int64 v26; // x1
  int v27; // w8
  const char *v28; // x2
  const char *v29; // x3
  unsigned int v30; // w0
  unsigned int v31; // w1
  int v32; // w8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  __int64 v42; // [xsp+0h] [xbp-10h] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"hdd_add_uplink_delay", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = *(_QWORD *)(a1 + 24);
  v22 = context;
  LODWORD(v42) = 0;
  v23 = *(unsigned __int8 *)(*(_QWORD *)(v21 + 104) + 18LL);
  if ( v23 == 1 )
    qdf_trace_msg(0x33u, 4u, "%s: Received", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_add_uplink_delay");
  if ( (*(_DWORD *)(a1 + 40) | 2) != 2 )
    goto LABEL_21;
  if ( !*(_QWORD *)(a1 + 39392) )
  {
    if ( !v23 )
    {
LABEL_17:
      v27 = 0;
      LODWORD(v42) = 0;
      goto LABEL_18;
    }
    v28 = "%s: tsf report not enabled for delay";
    v29 = "hdd_add_uplink_delay";
    v30 = 51;
    v31 = 4;
LABEL_16:
    qdf_trace_msg(v30, v31, v28, v13, v14, v15, v16, v17, v18, v19, v20, v29, v42, v43);
    goto LABEL_17;
  }
  if ( !v22 || !*v22 )
  {
    v28 = "%s: Invalid SOC instance";
    v29 = "cdp_get_uplink_delay";
    v30 = 137;
    v31 = 2;
    goto LABEL_16;
  }
  v24 = *(_QWORD *)(*v22 + 8LL);
  if ( !v24 )
    goto LABEL_17;
  v25 = *(_DWORD **)(v24 + 216);
  if ( !v25 )
    goto LABEL_17;
  v26 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL);
  if ( *(v25 - 1) != -337757947 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(_QWORD *, __int64, __int64 *))v25)(v22, v26, &v42) )
    goto LABEL_17;
  v27 = v42;
LABEL_18:
  HIDWORD(v42) = v27;
  v32 = nla_put(a2, 50, 4, (char *)&v42 + 4);
  result = 16 * (unsigned int)(v32 != 0);
  if ( !v32 && v23 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: uplink_delay %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "hdd_add_uplink_delay",
      (unsigned int)v42);
LABEL_21:
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
