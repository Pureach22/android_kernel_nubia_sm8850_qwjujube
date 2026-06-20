__int64 __fastcall wma_set_txrx_fw_stats_level(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10,
        unsigned int a11)
{
  __int64 **context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 **v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  _DWORD *v32; // x8
  const char *v33; // x2
  const char *v34; // x3
  __int64 result; // x0
  __int64 v36; // [xsp+8h] [xbp-48h] BYREF
  __int64 v37; // [xsp+10h] [xbp-40h]
  __int64 v38; // [xsp+18h] [xbp-38h]
  __int64 v39; // [xsp+20h] [xbp-30h]
  __int64 v40; // [xsp+28h] [xbp-28h]
  __int64 v41; // [xsp+30h] [xbp-20h]
  __int64 v42; // [xsp+38h] [xbp-18h]
  __int64 v43; // [xsp+40h] [xbp-10h]
  __int64 v44; // [xsp+48h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_set_txrx_fw_stats_level", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
  {
    v33 = "%s: SOC context is NULL";
    v34 = "wma_set_txrx_fw_stats_level";
LABEL_12:
    qdf_trace_msg(0x36u, 2u, v33, v14, v15, v16, v17, v18, v19, v20, v21, v34);
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( a11 > 0x11 || a11 - 17 >= 0xFFFFFFFD )
  {
    v33 = "%s: Not supported";
    v34 = "wma_is_valid_fw_stats_cmd";
    goto LABEL_12;
  }
  v22 = context;
  qdf_mem_set(&v36, 0x40u, 0);
  LODWORD(v37) = 1;
  LODWORD(v36) = 1 << (a11 - 1);
  if ( *v22 )
  {
    v31 = **v22;
    if ( v31 )
    {
      v32 = *(_DWORD **)(v31 + 328);
      if ( v32 )
      {
        if ( *(v32 - 1) != 151513730 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64 **, _QWORD, __int64 *, _QWORD, __int64))v32)(v22, a10, &v36, 0, 1);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v23, v24, v25, v26, v27, v28, v29, v30, "cdp_fw_stats_get");
  }
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
