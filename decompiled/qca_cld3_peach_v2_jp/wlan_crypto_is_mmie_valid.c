_BYTE *__fastcall wlan_crypto_is_mmie_valid(
        __int64 a1,
        _BYTE *a2,
        unsigned __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v11; // x22
  const char *v12; // x2
  _BYTE *result; // x0
  __int64 wlan_crypto_keys; // x0
  __int64 v18; // x8
  size_t v19; // x20
  unsigned __int64 v20; // x24
  int v21; // w8
  unsigned __int8 *v22; // x25
  __int64 v23; // x27
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w23
  __int64 v33; // x21
  _QWORD *v34; // x0
  int v35; // w8
  const void *v36; // x22
  __int64 v37; // x20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  char v86; // w9
  char v87; // w10
  char v88; // w8
  char v89; // w9
  char v90; // w8
  int v91; // w0
  int v92; // w23
  int v93; // w20
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // [xsp+8h] [xbp-18h] BYREF
  int v103; // [xsp+10h] [xbp-10h]
  __int64 v104; // [xsp+18h] [xbp-8h]

  v11 = a3 - (_QWORD)a2;
  v104 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v103 = 0;
  v102 = 0;
  if ( a3 >= (unsigned __int64)a2 && a2 && a3 && v11 > 0x17 )
  {
    wlan_crypto_keys = wlan_crypto_get_wlan_crypto_keys(a1);
    if ( !wlan_crypto_keys )
    {
      v12 = "%s: crypto_keys NULL";
      goto LABEL_6;
    }
    v18 = -26;
    if ( *(_DWORD *)(wlan_crypto_keys + 128) == 6 )
    {
      v18 = -18;
      v19 = 8;
    }
    else
    {
      v19 = 16;
    }
    v20 = a3 + v18;
    if ( !(a3 + v18) || *(_BYTE *)v20 != 76 )
    {
      v12 = "%s: IE is not MMIE";
      goto LABEL_6;
    }
    v21 = *(unsigned __int16 *)(v20 + 2);
    if ( (unsigned int)(v21 - 6) <= 0xFFFFFFFD )
    {
      v12 = "%s: keyid not valid";
      goto LABEL_6;
    }
    v22 = *(unsigned __int8 **)(wlan_crypto_keys + 8LL * (v21 & 1) + 32);
    if ( !v22 )
    {
      v12 = "%s: No igtk key present";
      goto LABEL_6;
    }
    v23 = wlan_crypto_keys;
    if ( (int)qdf_mem_cmp((const void *)(v20 + 4), v22 + 104, 6u) <= 0 )
    {
      v37 = *(_QWORD *)(a1 + 112);
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: replay error :",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wlan_crypto_is_mmie_valid");
      if ( v20 + 4 < v20 + 10 )
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: expected pn = %x received pn = %x",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wlan_crypto_is_mmie_valid",
          *(unsigned __int8 *)(v20 + 4),
          v22[104]);
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: expected pn = %x received pn = %x",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "wlan_crypto_is_mmie_valid",
          *(unsigned __int8 *)(v20 + 5),
          v22[105]);
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: expected pn = %x received pn = %x",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "wlan_crypto_is_mmie_valid",
          *(unsigned __int8 *)(v20 + 6),
          v22[106]);
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: expected pn = %x received pn = %x",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "wlan_crypto_is_mmie_valid",
          *(unsigned __int8 *)(v20 + 7),
          v22[107]);
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: expected pn = %x received pn = %x",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "wlan_crypto_is_mmie_valid",
          *(unsigned __int8 *)(v20 + 8),
          v22[108]);
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: expected pn = %x received pn = %x",
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          "wlan_crypto_is_mmie_valid",
          *(unsigned __int8 *)(v20 + 9),
          v22[109]);
      }
      wlan_cp_stats_vdev_mcast_rx_pnerr(a1);
      wlan_cp_stats_peer_rx_pnerr(v37);
      goto LABEL_7;
    }
    v32 = (unsigned __int16)v11 - 4;
    result = (_BYTE *)_qdf_mem_malloc(v32, "wlan_crypto_is_mmie_valid", 2337);
    if ( !result )
      goto LABEL_8;
    v33 = (__int64)result;
    *result = *a2;
    result[1] = a2[1] & 0xC7;
    qdf_mem_copy(result + 2, a2 + 4, 0x12u);
    qdf_mem_copy((void *)(v33 + 20), a2 + 24, (unsigned int)(unsigned __int16)v11 - 24);
    qdf_mem_set((void *)(v33 + v32 - (int)v19), (unsigned int)v19, 0);
    v34 = (_QWORD *)_qdf_mem_malloc(0x10u, "wlan_crypto_is_mmie_valid", 2360);
    if ( !v34 )
    {
      _qdf_mem_free(v33);
      goto LABEL_7;
    }
    v35 = *(_DWORD *)(v23 + 128);
    v36 = v34;
    if ( (unsigned int)(v35 - 11) < 2 )
    {
      qdf_mem_copy(&v102, a2 + 10, 6u);
      v86 = *(_BYTE *)(v20 + 8);
      v87 = *(_BYTE *)(v20 + 7);
      BYTE6(v102) = *(_BYTE *)(v20 + 9);
      v88 = *(_BYTE *)(v20 + 6);
      HIBYTE(v102) = v86;
      v89 = *(_BYTE *)(v20 + 5);
      BYTE1(v103) = v88;
      v90 = *(_BYTE *)(v20 + 4);
      LOBYTE(v103) = v87;
      BYTE2(v103) = v89;
      HIBYTE(v103) = v90;
      v91 = qdf_crypto_aes_gmac(
              (__int64)(v22 + 384),
              *v22,
              (__int64)&v102,
              v33,
              v33 + 20,
              (unsigned __int16)v32 - 36,
              (__int64)v36);
    }
    else
    {
      if ( v35 != 6 )
      {
        if ( v35 == 8 )
        {
          _qdf_mem_free(v33);
LABEL_35:
          v93 = qdf_mem_cmp(v36, (const void *)(v20 + 10), v19);
          _qdf_mem_free((__int64)v36);
          if ( !v93 )
          {
            qdf_mem_copy(v22 + 104, (const void *)(v20 + 4), 6u);
            qdf_trace_msg(
              0x1Cu,
              8u,
              "%s: mmie matched",
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              "wlan_crypto_is_mmie_valid");
            result = (_BYTE *)(&off_0 + 1);
            goto LABEL_8;
          }
          v12 = "%s: mmie mismatch";
          goto LABEL_6;
        }
        _qdf_mem_free(v33);
LABEL_39:
        _qdf_mem_free((__int64)v36);
        v12 = "%s: generate mmie failed";
        goto LABEL_6;
      }
      v91 = qdf_crypto_aes_128_cmac((__int64)(v22 + 384), v33, v32, v34);
    }
    v92 = v91;
    _qdf_mem_free(v33);
    if ( (v92 & 0x80000000) == 0 )
      goto LABEL_35;
    goto LABEL_39;
  }
  v12 = "%s: Invalid params";
LABEL_6:
  qdf_trace_msg(0x1Cu, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_crypto_is_mmie_valid");
LABEL_7:
  result = nullptr;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
