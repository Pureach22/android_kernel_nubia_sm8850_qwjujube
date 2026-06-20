__int64 __fastcall populate_dot11f_ext_supp_rates(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10,
        _BYTE *a11,
        __int64 a12)
{
  _BYTE *v12; // x20
  __int64 ext_opr_rate; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  size_t v22; // x19
  __int64 result; // x0
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  int v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v24 = 0;
  if ( a10 == 0xFF )
  {
    if ( !a12 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: no session context exists while populating Operational Rate Set",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "populate_dot11f_ext_supp_rates");
      result = 0;
      goto LABEL_11;
    }
    v22 = *(unsigned __int8 *)(a12 + 265);
    v12 = a11;
    qdf_mem_copy(&v24, (const void *)(a12 + 266), v22);
    if ( !v22 )
      goto LABEL_5;
LABEL_8:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: ext supp rates present, num %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "populate_dot11f_ext_supp_rates",
      (unsigned __int8)v22);
    v12[1] = v22;
    qdf_mem_copy(v12 + 2, &v24, (unsigned int)v22);
    result = 0;
    *v12 = 1;
    goto LABEL_11;
  }
  if ( a10 <= 0xEu )
  {
    if ( !a12 )
    {
      qdf_trace_msg(0x35u, 2u, "%s: null pe_session", a1, a2, a3, a4, a5, a6, a7, a8, "populate_dot11f_ext_supp_rates");
      result = 4;
      goto LABEL_11;
    }
    v12 = a11;
    ext_opr_rate = mlme_get_ext_opr_rate(*(_QWORD *)(a12 + 16), &v24, 0xCu, a1, a2, a3, a4, a5, a6, a7, a8);
    LODWORD(v22) = ext_opr_rate;
    if ( ext_opr_rate )
      goto LABEL_8;
  }
LABEL_5:
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
