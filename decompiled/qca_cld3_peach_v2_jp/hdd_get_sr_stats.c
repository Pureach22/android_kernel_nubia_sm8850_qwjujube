__int64 __fastcall hdd_get_sr_stats(
        __int64 a1,
        char a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  __int64 v15; // x4
  __int64 v16; // x5
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  _DWORD *v26; // x8
  __int64 v27; // x1
  __int64 result; // x0
  const char *v29; // x2
  __int64 v30; // [xsp+0h] [xbp-30h] BYREF
  __int64 v31; // [xsp+8h] [xbp-28h]
  __int64 v32; // [xsp+10h] [xbp-20h]
  __int64 v33; // [xsp+18h] [xbp-18h]
  __int64 v34; // [xsp+20h] [xbp-10h]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v30 = 0;
  context = _cds_get_context(71, (__int64)"hdd_get_sr_stats", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
    v29 = "%s: invalid soc";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v29, v17, v18, v19, v20, v21, v22, v23, v24, "hdd_get_sr_stats", v30, v31, v32, v33);
    result = 4294967274LL;
    goto LABEL_14;
  }
  LOBYTE(v33) = a2;
  if ( *context )
  {
    v25 = *(_QWORD *)(*context + 32LL);
    if ( v25 )
    {
      v26 = *(_DWORD **)(v25 + 328);
      if ( v26 )
      {
        v27 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 40LL);
        if ( *(v26 - 1) != 790522120 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64 *, __int64, __int64))v26)(
          context,
          v27,
          a3,
          &v30,
          v15,
          v16);
      }
    }
    if ( a3 )
      goto LABEL_9;
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x89u,
    8u,
    "%s: Invalid Instance",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "cdp_get_pdev_obss_pd_stats",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35);
  if ( !a3 )
  {
LABEL_12:
    v29 = "%s: invalid stats";
    goto LABEL_13;
  }
LABEL_9:
  result = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
