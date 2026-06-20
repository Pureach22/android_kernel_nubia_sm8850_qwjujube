__int64 __fastcall hdd_clear_sr_stats(
        __int64 a1,
        char a2,
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
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  _DWORD *v25; // x8
  __int64 v26; // x1
  unsigned int v27; // w19
  const char *v28; // x2
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
  context = _cds_get_context(71, (__int64)"hdd_clear_sr_stats", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v27 = -22;
    v28 = "%s: invalid soc";
LABEL_12:
    qdf_trace_msg(0x33u, 2u, v28, v16, v17, v18, v19, v20, v21, v22, v23, "hdd_clear_sr_stats", v30, v31, v32, v33);
    goto LABEL_13;
  }
  LOBYTE(v33) = a2;
  if ( !*context )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "cdp_clear_pdev_obss_pd_stats",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35);
LABEL_11:
    v27 = -11;
    v28 = "%s: Unable to clear stats";
    goto LABEL_12;
  }
  v24 = *(_QWORD *)(*context + 32LL);
  if ( !v24 )
    goto LABEL_11;
  v25 = *(_DWORD **)(v24 + 336);
  if ( !v25 )
    goto LABEL_11;
  v26 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 40LL);
  if ( *(v25 - 1) != -242941968 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(_QWORD *, __int64, __int64 *, __int64, __int64, __int64))v25)(
         context,
         v26,
         &v30,
         v13,
         v14,
         v15) )
  {
    goto LABEL_11;
  }
  v27 = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v27;
}
