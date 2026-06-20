__int64 __fastcall lim_send_ht40_obss_scanind(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int8 v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned __int64 v39; // x24
  unsigned __int64 v40; // x23
  __int64 v41; // x26
  unsigned int v42; // w22
  unsigned int v43; // w20
  __int64 v44; // x5
  char v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v55; // [xsp+10h] [xbp-40h] BYREF
  __int64 v56; // [xsp+18h] [xbp-38h]
  __int64 v57; // [xsp+20h] [xbp-30h]
  __int64 v58; // [xsp+28h] [xbp-28h]
  __int64 v59; // [xsp+30h] [xbp-20h]
  __int64 v60; // [xsp+38h] [xbp-18h]
  __int16 v61; // [xsp+44h] [xbp-Ch] BYREF
  char v62; // [xsp+46h] [xbp-Ah]
  __int64 v63; // [xsp+48h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v62 = 0;
  v61 = 0;
  v4 = _qdf_mem_malloc(0x374u, "lim_send_ht40_obss_scanind", 455);
  if ( v4 )
  {
    v13 = v4;
    wlan_reg_read_current_country(a1[2703], &v61, v5, v6, v7, v8, v9, v10, v11, v12);
    *(_QWORD *)v13 = 0x100000000LL;
    *(_WORD *)(v13 + 8) = *(_WORD *)(a2 + 8638);
    *(_WORD *)(v13 + 10) = *(_WORD *)(a2 + 8640);
    *(_WORD *)(v13 + 12) = *(_WORD *)(a2 + 8642);
    *(_WORD *)(v13 + 14) = *(_WORD *)(a2 + 8644);
    *(_WORD *)(v13 + 16) = *(_WORD *)(a2 + 8646);
    *(_WORD *)(v13 + 18) = *(_WORD *)(a2 + 8648);
    *(_WORD *)(v13 + 20) = *(_WORD *)(a2 + 8650);
    v22 = wlan_reg_freq_to_chan(a1[2704], *(_DWORD *)(a2 + 284), v14, v15, v16, v17, v18, v19, v20, v21);
    *(_BYTE *)(v13 + 428) = wlan_reg_dmn_get_opclass_from_channel(
                              (unsigned __int8 *)&v61,
                              v22,
                              *(_DWORD *)(a2 + 7176),
                              v23,
                              v24,
                              v25,
                              v26,
                              v27,
                              v28,
                              v29,
                              v30);
    v39 = *(unsigned int *)(a1[1] + 6392LL);
    if ( (_DWORD)v39 )
    {
      v40 = 0;
      v41 = 1498;
      do
      {
        if ( v41 == 1598 )
          __break(0x5512u);
        v42 = *(_DWORD *)(a1[1] + 4 * v41);
        if ( wlan_reg_is_24ghz_ch_freq(v42) )
          *(_DWORD *)(v13 + 28 + 4 * v40++) = v42;
        if ( v41 - 1497 >= v39 )
          break;
        ++v41;
      }
      while ( v40 < 0x64 );
    }
    else
    {
      LOBYTE(v40) = 0;
    }
    *(_BYTE *)(v13 + 25) = v40;
    v44 = *(unsigned __int16 *)(v13 + 18);
    v45 = *(_BYTE *)(a2 + 10);
    *(_BYTE *)(v13 + 24) = 0;
    *(_WORD *)(v13 + 430) = 0;
    *(_BYTE *)(v13 + 23) = v45;
    v56 = v13;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Obss Scan trigger width: %d, delay factor: %d bssid %02x:%02x:%02x:**:**:%02x",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_send_ht40_obss_scanind",
      *(unsigned __int16 *)(v13 + 12),
      v44,
      *(unsigned __int8 *)(a2 + 24),
      *(unsigned __int8 *)(a2 + 25),
      *(unsigned __int8 *)(a2 + 26),
      *(unsigned __int8 *)(a2 + 29),
      4465,
      v13,
      v57,
      v58,
      v59,
      v60);
    v43 = wma_post_ctrl_msg(a1, &v55);
    if ( v43 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: WDA_HT40_OBSS_SCAN_IND msg failed, reason=%X",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "lim_send_ht40_obss_scanind",
        v43);
      _qdf_mem_free(v13);
    }
    wlan_scan_set_obss_scan_enable(*(_QWORD *)(a2 + 16));
  }
  else
  {
    v43 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v43;
}
