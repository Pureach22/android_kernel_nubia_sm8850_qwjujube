__int64 __fastcall wlan_cfg80211_tdls_mgmt(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 a3,
        char a4,
        char a5,
        int a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x27
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  __int64 result; // x0
  char v36; // w8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  const char *v63; // x5
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // [xsp+18h] [xbp-68h] BYREF
  __int64 v73; // [xsp+20h] [xbp-60h] BYREF
  __int64 v74; // [xsp+28h] [xbp-58h] BYREF
  __int64 v75; // [xsp+30h] [xbp-50h] BYREF
  __int64 v76; // [xsp+38h] [xbp-48h]
  __int64 v77; // [xsp+40h] [xbp-40h]
  __int64 v78; // [xsp+48h] [xbp-38h]
  __int64 v79; // [xsp+50h] [xbp-30h]
  __int64 v80; // [xsp+58h] [xbp-28h]
  __int64 v81; // [xsp+60h] [xbp-20h] BYREF
  __int64 v82; // [xsp+68h] [xbp-18h]
  __int64 v83; // [xsp+70h] [xbp-10h]
  __int64 v84; // [xsp+78h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v82 = 0;
  v83 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  if ( !(unsigned int)qdf_mem_cmp(a2, &wlan_cfg80211_tdls_validate_mac_addr_temp_mac, 6u) )
  {
    if ( a2 )
    {
      v31 = *a2;
      v32 = a2[1];
      v33 = a2[2];
      v34 = a2[5];
    }
    else
    {
      v33 = 0;
      v31 = 0;
      v32 = 0;
      v34 = 0;
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Invalid Mac address %02x:%02x:%02x:**:**:%02x cmd declined.",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_cfg80211_tdls_validate_mac_addr",
      v31,
      v32,
      v33,
      v34);
    goto LABEL_12;
  }
  v25 = *(_QWORD *)(a1 + 608);
  if ( !v25 || (v26 = *(_QWORD *)(v25 + 16)) == 0 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: osif priv or tdls priv is NULL",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_cfg80211_tdls_mgmt");
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
  if ( *(_DWORD *)(v26 + 228) == 1413762131 )
  {
    if ( a2 )
    {
      v27 = *a2;
      v28 = a2[1];
      v29 = a2[2];
      v30 = a2[5];
    }
    else
    {
      v29 = 0;
      v27 = 0;
      v28 = 0;
      v30 = 0;
    }
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: %02x:%02x:%02x:**:**:%02x action %d couldn't sent, as one is pending. return EBUSY",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_cfg80211_tdls_mgmt",
      v27,
      v28,
      v29,
      v30,
      a3);
    result = 4294967280LL;
    goto LABEL_13;
  }
  *(_DWORD *)(v26 + 228) = 1413762131;
  LOBYTE(v75) = a3;
  qdf_mem_copy((char *)&v75 + 1, a2, 6u);
  v36 = *(_BYTE *)(a1 + 104);
  HIBYTE(v75) = a4;
  LOBYTE(v75) = a3;
  LOBYTE(v76) = a5;
  v77 = a8;
  v74 = a1;
  BYTE2(v79) = v36;
  LOBYTE(v79) = v36;
  qdf_mem_copy((char *)&v81 + 4, a2, 6u);
  BYTE4(v83) = a8;
  LOBYTE(v81) = a8;
  WORD2(v82) = (unsigned __int8)v76;
  BYTE3(v82) = a4;
  BYTE2(v82) = a3;
  LODWORD(v83) = a6;
  BYTE2(v81) = 0;
  BYTE1(v79) = a9;
  v80 = a7;
  *(_DWORD *)(v26 + 64) = 0;
  v45 = ucfg_tdls_send_mgmt_frame((unsigned __int8 *)&v74, v37, v38, v39, v40, v41, v42, v43, v44);
  if ( v45 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: ucfg_tdls_send_mgmt failed err %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wlan_cfg80211_tdls_mgmt",
      v45);
    *(_DWORD *)(v26 + 228) = 0;
    result = 4294967291LL;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Wait for tdls_mgmt_comp. Timeout %u ms",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "wlan_cfg80211_tdls_mgmt",
    1000);
  v54 = wait_for_completion_timeout(v26 + 64, 250);
  if ( !v54 )
  {
    v63 = "TDLS Tx Completion timed out";
    goto LABEL_22;
  }
  if ( *(_DWORD *)(v26 + 228) )
  {
    v63 = "TDLS Tx Completion failed";
LABEL_22:
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: vdev:%d %s rc %ld Tx Completion Status %u",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "wlan_cfg80211_tdls_mgmt",
      BYTE2(v79),
      v63,
      v54);
    *(_DWORD *)(v26 + 228) = 0;
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: vdev:%d rc:%ld TDLS Tx Completion status:%u",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "wlan_cfg80211_tdls_mgmt",
    BYTE2(v79),
    v54,
    0);
  result = 0;
  if ( (unsigned int)a3 - 1 <= 1 )
  {
    qdf_mem_copy(&v73, a2, 6u);
    v72 = a1;
    BYTE6(v73) = a3 != 1;
    ucfg_tdls_responder((__int64)&v72, v64, v65, v66, v67, v68, v69, v70, v71);
    result = 0;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
