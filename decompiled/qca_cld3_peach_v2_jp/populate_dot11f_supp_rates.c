__int64 __fastcall populate_dot11f_supp_rates(
        __int64 a1,
        unsigned __int8 a2,
        _BYTE *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x8
  __int64 v14; // x1
  size_t v15; // x2
  unsigned int cfg_str; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  size_t v26; // x2
  size_t n; // [xsp+0h] [xbp-20h] BYREF
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  int v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v29 = 0;
  if ( a2 == 0xFF )
  {
    if ( !a4 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: no session context exists while populating Operational Rate Set",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "populate_dot11f_supp_rates");
      goto LABEL_12;
    }
    v15 = *(unsigned __int8 *)(a4 + 252);
    n = v15;
    qdf_mem_copy(&v29, (const void *)(a4 + 253), v15);
LABEL_9:
    v26 = n;
    if ( n )
    {
      a3[1] = n;
      qdf_mem_copy(a3 + 2, &v29, v26);
      v25 = 0;
      *a3 = 1;
      goto LABEL_13;
    }
LABEL_12:
    v25 = 0;
    goto LABEL_13;
  }
  v13 = *(_QWORD *)(a1 + 8);
  n = 12;
  if ( a2 > 0xEu )
    v14 = v13 + 2816;
  else
    v14 = v13 + 2776;
  cfg_str = wlan_mlme_get_cfg_str(&v29, v14, &n, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !cfg_str )
    goto LABEL_9;
  v25 = cfg_str;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Failed to retrieve nItem from CFG status: %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "populate_dot11f_supp_rates",
    cfg_str);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v25;
}
