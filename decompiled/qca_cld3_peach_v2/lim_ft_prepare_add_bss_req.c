__int64 __fastcall lim_ft_prepare_add_bss_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  __int64 v15; // x20
  __int64 v16; // x0
  __int64 v17; // x21
  _BYTE *v18; // x25
  unsigned __int16 ielen_from_bss_description; // w0
  _BYTE *v20; // x26
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  char v29; // w8
  int v30; // w8
  char ht_capability; // w0
  int v32; // w9
  char v33; // w8
  __int64 v34; // x2
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int16 v43; // w8
  int v44; // w8
  __int16 v45; // w8
  bool v46; // w8
  char v47; // w8
  char v48; // w8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int16 v65; // w2

  if ( *(_DWORD *)(a2 + 88) != 2 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: pe_session is not in STA mode",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_ft_prepare_add_bss_req");
  result = _qdf_mem_malloc(0x1A08u, "lim_ft_prepare_add_bss_req", 133);
  if ( result )
  {
    v15 = result;
    v16 = _qdf_mem_malloc(0x368u, "lim_ft_prepare_add_bss_req", 138);
    if ( !v16 )
      return _qdf_mem_free(v15);
    v17 = v16;
    v18 = (_BYTE *)(a2 + 7024);
    ielen_from_bss_description = wlan_get_ielen_from_bss_description(a3);
    lim_extract_ap_capabilities(a1, a3 + 104, ielen_from_bss_description, (void *)v15);
    if ( *(_BYTE *)(a1 + 8884) )
      lim_decide_sta_protection_on_assoc(a1, v15, a2);
    v20 = (_BYTE *)(v15 + 1201);
    qdf_mem_copy((void *)v17, (const void *)(a3 + 2), 6u);
    *(_WORD *)(v17 + 14) = *(_WORD *)(a3 + 16);
    v29 = *(_BYTE *)(v15 + 83);
    *(_BYTE *)(v17 + 848) = 0;
    *(_BYTE *)(v17 + 16) = v29;
    *(_DWORD *)(v17 + 8) = *(_DWORD *)(a3 + 20);
    *(_BYTE *)(v17 + 12) = (*(_WORD *)(v15 + 10) & 0x400) != 0;
    *(_BYTE *)(v17 + 13) = *(_BYTE *)(a2 + 7162);
    *(_BYTE *)(v17 + 18) = (*v18 & 0x10) != 0;
    v30 = *(unsigned __int8 *)(a2 + 154);
    if ( ((unsigned int)(v30 - 7) < 7 || v30 == 5 || !*(_BYTE *)(a2 + 154)) && *(_BYTE *)(v15 + 1200) )
    {
      ht_capability = lim_get_ht_capability(a1, 12, a2);
      lim_sta_add_bss_update_ht_parameter(*(unsigned int *)(a3 + 28), v15 + 1200, v15 + 1260, ht_capability != 0, v17);
      qdf_mem_copy((void *)(v17 + 170), (const void *)(v15 + 10), 2u);
      qdf_mem_copy((void *)(v17 + 172), (const void *)(v15 + 1201), 2u);
    }
    v32 = *(_DWORD *)(a2 + 7176);
    *(_DWORD *)(a2 + 164) = *(_DWORD *)(v15 + 1262) & 3;
    *(_DWORD *)(v17 + 852) = v32;
    *(_DWORD *)(v17 + 48) = v32;
    if ( *(_BYTE *)(a2 + 7170) )
    {
      if ( *(_BYTE *)(a2 + 7173) )
      {
        v33 = *(_BYTE *)(v15 + 2484);
        v34 = v15 + 2484;
LABEL_18:
        *(_BYTE *)(v17 + 850) = v33;
        lim_update_vhtcaps_assoc_resp(a1, v17, v34);
        goto LABEL_20;
      }
      if ( *(_BYTE *)(v15 + 2544) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: VHT caps are present in vendor specific IE",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "lim_ft_prepare_add_bss_req");
        v33 = *(_BYTE *)(v15 + 2544);
        v34 = v15 + 2544;
        goto LABEL_18;
      }
    }
    *(_BYTE *)(v17 + 850) = 0;
LABEL_20:
    if ( *(_BYTE *)(a2 + 8676) == 1 && *(_BYTE *)(v15 + 2640) )
    {
      lim_update_bss_he_capable(a1, v17);
      lim_add_bss_he_cfg(v17, a2);
    }
    if ( a2 && *(_BYTE *)(a2 + 10071) == 1 && *(_BYTE *)(v15 + 2740) )
    {
      lim_update_bss_eht_capable(a1, v17);
      lim_add_bss_eht_cfg(v17, a2);
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: SIR_HAL_ADD_BSS_REQ with frequency: %d, width: %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_ft_prepare_add_bss_req",
      *(unsigned int *)(a3 + 28),
      *(unsigned int *)(v17 + 852));
    *(_BYTE *)(v17 + 32) = 1;
    qdf_mem_copy((void *)(v17 + 24), (const void *)(a3 + 2), 6u);
    v43 = *(_WORD *)(a3 + 16);
    *(_WORD *)(v17 + 30) = 0;
    *(_WORD *)(v17 + 43) = 0;
    *(_WORD *)(v17 + 40) = v43;
    *(_BYTE *)(v17 + 140) = 0;
    *(_DWORD *)(v17 + 144) = *(_DWORD *)(a2 + 424);
    *(_BYTE *)(v17 + 141) = (*v18 & 0x10) != 0;
    v44 = *(unsigned __int8 *)(a2 + 154);
    if ( ((unsigned int)(v44 - 7) < 7 || v44 == 5 || !*(_BYTE *)(a2 + 154)) && *(_BYTE *)(v15 + 1200) )
    {
      *(_BYTE *)(v17 + 45) = 1;
      if ( *(_BYTE *)(a2 + 7170)
        && *(_BYTE *)(v15 + 2484)
        && *(__int16 *)(v15 + 2490) != -1
        && *(__int16 *)(v15 + 2494) != -1 )
      {
        *(_BYTE *)(v17 + 151) = 1;
        v45 = *(_WORD *)(v15 + 2485);
        if ( ((v45 & 0x800) != 0 || (*(_BYTE *)(v15 + 2487) & 8) != 0) && (*(_BYTE *)(a2 + 7269) & 0x10) != 0 )
        {
          *(_BYTE *)(v17 + 156) = 1;
          v45 = *(_WORD *)(v15 + 2485);
        }
        if ( (v45 & 0x1000) != 0 && (*(_BYTE *)(a2 + 7269) & 8) != 0 )
          *(_BYTE *)(v17 + 157) = 1;
      }
      if ( *(_BYTE *)(a2 + 8676) == 1 && *(_BYTE *)(v15 + 2640) )
        lim_intersect_ap_he_caps(a2, v17, v15, 0, a3);
      if ( a2 && *(_BYTE *)(a2 + 10071) == 1 && *(_BYTE *)(v15 + 2740) )
        lim_intersect_ap_eht_caps(a2, v17, v15, 0);
      *(_DWORD *)(v17 + 52) = (*(unsigned __int16 *)v20 >> 2) & 3;
      *(_BYTE *)(v17 + 57) = (*(_BYTE *)(v15 + 1203) >> 2) & 7;
      *(_BYTE *)(v17 + 59) = (*v20 & 0x20) != 0;
      *(_BYTE *)(v17 + 58) = (*v20 & 0x40) != 0;
      *(_BYTE *)(v17 + 56) = *(_BYTE *)(v15 + 1203) & 3;
    }
    v46 = (*v18 & 2) != 0 && *(_BYTE *)(v15 + 2469) || (*v18 & 1) != 0 && *(_BYTE *)(v15 + 2467);
    *(_BYTE *)(v17 + 42) = v46;
    v47 = *(_BYTE *)(v15 + 2474);
    *(_BYTE *)(v17 + 168) = v47;
    v48 = v47 | (2 * *(_BYTE *)(v15 + 2473));
    *(_BYTE *)(v17 + 168) = v48;
    if ( !v48 && *(_BYTE *)(a2 + 7364) == 1 )
      *(_BYTE *)(v17 + 168) = 1;
    lim_populate_peer_rate_set(
      a1,
      (char *)(v17 + 60),
      (_BYTE *)(v15 + 1204),
      0,
      a2,
      v15 + 2484,
      (char *)(v15 + 2640),
      v15 + 2740,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      0,
      a3);
    *(_BYTE *)(v17 + 849) = *(_BYTE *)(a2 + 7032);
    if ( (*v18 & 0x10) != 0 )
    {
      *(_BYTE *)(v17 + 18) = 1;
      *(_BYTE *)(v17 + 141) = 1;
    }
    *(_BYTE *)(v17 + 148) = *(_BYTE *)(a2 + 8);
    *(_BYTE *)(v17 + 167) = *(_BYTE *)(a2 + 10);
    if ( !wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a2 + 16), v49, v50, v51, v52, v53, v54, v55, v56) )
    {
      v65 = *(_WORD *)(a2 + 8);
      *(_DWORD *)(a2 + 72) = 27;
      qdf_trace(53, 0, v65, 27);
    }
    *(_QWORD *)(a2 + 7832) = v17;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Saving SIR_HAL_ADD_BSS_REQ for pre-auth ap",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "lim_ft_prepare_add_bss_req");
    return _qdf_mem_free(v15);
  }
  return result;
}
