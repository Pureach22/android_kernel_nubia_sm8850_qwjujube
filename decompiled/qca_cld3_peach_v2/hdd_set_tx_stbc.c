__int64 __fastcall hdd_set_tx_stbc(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  __int64 *v13; // x22
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  const char *v24; // x2
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int16 v41; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v41 = 0;
  v13 = *(__int64 **)(v12 + 24);
  v14 = v13[2];
  qdf_trace_msg(0x33u, 8u, "%s: %d", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_tx_stbc", a2);
  if ( !v14 )
  {
    v24 = "%s: NULL Mac handle";
LABEL_6:
    qdf_trace_msg(0x33u, 2u, v24, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_set_tx_stbc");
    result = 4294967274LL;
    goto LABEL_14;
  }
  if ( a2 )
  {
    if ( (unsigned int)wlan_mlme_get_ht_cap_info(*v13, &v41) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get HT capability info",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_set_tx_stbc");
      result = 4294967291LL;
      goto LABEL_14;
    }
    if ( (v41 & 0x80) == 0 )
    {
      v24 = "%s: TX STBC not supported";
      goto LABEL_6;
    }
  }
  if ( (unsigned int)sme_update_ht_config(v14, *((unsigned __int8 *)a1 + 8), 7) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set TX STBC value",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_set_tx_stbc");
  if ( (unsigned int)sme_update_he_tx_stbc_cap(v14, *((unsigned __int8 *)a1 + 8), a2) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set HE TX STBC value",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "hdd_set_tx_stbc");
  result = sme_set_auto_rate_stbc(v14, *((unsigned __int8 *)a1 + 8), a2 == 0);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
