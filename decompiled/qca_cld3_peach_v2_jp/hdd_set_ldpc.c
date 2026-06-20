__int64 __fastcall hdd_set_ldpc(
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
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  __int64 result; // x0
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int16 v50; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v50 = 0;
  v13 = *(__int64 **)(v12 + 24);
  v14 = v13[2];
  qdf_trace_msg(0x33u, 8u, "%s: %d", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_ldpc", a2);
  if ( v14 )
  {
    if ( (unsigned int)wlan_mlme_get_ht_cap_info(*v13, &v50) )
    {
      v31 = "%s: Failed to get HT capability info";
LABEL_9:
      qdf_trace_msg(0x33u, 2u, v31, v23, v24, v25, v26, v27, v28, v29, v30, "hdd_set_ldpc");
      result = 4294967291LL;
      goto LABEL_10;
    }
    v33 = *v13;
    v50 = v50 & 0xFFFE | a2 & 1;
    if ( (unsigned int)wlan_mlme_set_ht_cap_info(v33, v50) )
    {
      v31 = "%s: Failed to set HT capability info";
      goto LABEL_9;
    }
    if ( (unsigned int)wlan_mlme_cfg_set_vht_ldpc_coding_cap(*v13, a2 != 0) )
    {
      v31 = "%s: Failed to set VHT LDPC capability info";
      goto LABEL_9;
    }
    if ( (unsigned int)sme_update_ht_config(v14, *((unsigned __int8 *)a1 + 8), 0) )
      qdf_trace_msg(0x33u, 2u, "%s: Failed to set LDPC value", v34, v35, v36, v37, v38, v39, v40, v41, "hdd_set_ldpc");
    if ( (unsigned int)sme_update_he_ldpc_supp(v14, *((unsigned __int8 *)a1 + 8), a2) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set HE LDPC value",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "hdd_set_ldpc");
    result = sme_set_auto_rate_ldpc(v14, *((unsigned __int8 *)a1 + 8), a2 == 0);
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: NULL Mac handle", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_set_ldpc");
    result = 4294967274LL;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
