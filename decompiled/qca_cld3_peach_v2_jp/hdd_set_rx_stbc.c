__int64 __fastcall hdd_set_rx_stbc(
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
  unsigned int v25; // w1
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  __int16 v43; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v43 = 0;
  v13 = *(__int64 **)(v12 + 24);
  v14 = v13[2];
  qdf_trace_msg(0x33u, 8u, "%s: %d", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_rx_stbc", a2);
  if ( !v14 )
  {
    v24 = "%s: NULL Mac handle";
    v25 = 2;
LABEL_6:
    qdf_trace_msg(0x33u, v25, v24, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_set_rx_stbc");
    result = 4294967274LL;
    goto LABEL_12;
  }
  if ( a2 )
  {
    if ( (unsigned int)wlan_mlme_get_ht_cap_info(*v13, &v43) )
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
        "hdd_set_rx_stbc");
      result = 4294967291LL;
      goto LABEL_12;
    }
    if ( (v43 & 0x300) == 0 )
    {
      v24 = "%s: RX STBC not supported";
      v25 = 3;
      goto LABEL_6;
    }
  }
  if ( (unsigned int)sme_update_ht_config(v14, *((unsigned __int8 *)a1 + 8), 8) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set RX STBC value",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_set_rx_stbc");
  result = sme_update_he_rx_stbc_cap(v14, *((unsigned __int8 *)a1 + 8), a2);
  if ( (_DWORD)result )
  {
    v42 = result;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set HE RX STBC value",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "hdd_set_rx_stbc");
    result = v42;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
