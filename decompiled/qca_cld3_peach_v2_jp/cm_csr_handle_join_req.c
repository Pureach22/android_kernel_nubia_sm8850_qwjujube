__int64 __fastcall cm_csr_handle_join_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v16; // w19
  _QWORD *context; // x0
  __int64 v18; // x21
  __int64 v19; // x0
  __int64 v20; // x20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  _BYTE *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x25
  __int64 pmksa; // x24
  __int64 fils_pmksa; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x1
  char v51; // w8
  __int64 v52; // x0
  __int64 v53; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int8 v54[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+18h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(unsigned __int8 *)(a1 + 104);
  v53 = 0;
  context = _cds_get_context(52, (__int64)"cm_csr_handle_join_req", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
  {
    result = 4;
    goto LABEL_9;
  }
  v18 = (__int64)context;
  v19 = _qdf_mem_malloc(
          (unsigned __int16)(*(_DWORD *)(*(_QWORD *)(a3 + 48) + 1704LL) + 68) + 108LL,
          "cm_csr_handle_join_req",
          5379);
  if ( !v19 )
  {
    result = 2;
    goto LABEL_9;
  }
  v20 = v19;
  if ( (unsigned int)wlan_fill_bss_desc_from_scan_entry(v18, v19, *(_QWORD *)(a3 + 48)) )
    goto LABEL_6;
  if ( (unsigned int)wlan_get_parsed_bss_description_ies(v18, (unsigned __int16 *)v20, &v53) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: IE parsing failed vdev id %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "cm_csr_handle_join_req",
      v16);
LABEL_6:
    _qdf_mem_free(v20);
    result = 16;
    goto LABEL_9;
  }
  if ( (a4 & 1) == 0 )
  {
    v30 = *(_BYTE **)(a2 + 64);
    *(_WORD *)v54 = 0;
    if ( v30 && (*v30 & 1) != 0 )
    {
      if ( *(_BYTE *)(v20 + 85) == 1 )
      {
        qdf_mem_copy(v54, (const void *)(v20 + 86), 2u);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: FILS_PMKSA: cache_id[0]:%d, cache_id[1]:%d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "csr_cm_update_fils_info",
          v54[0],
          v54[1]);
      }
      v39 = *(_QWORD *)(*(_QWORD *)(a2 + 56) + 24LL);
      pmksa = wlan_crypto_get_pmksa(a1, v39 + 1, v21, v22, v23, v24, v25, v26, v27, v28);
      fils_pmksa = wlan_crypto_get_fils_pmksa(a1, v54, (const void *)(v39 + 14), *(_BYTE *)(v39 + 13));
      v50 = *(_QWORD *)(a2 + 64);
      if ( (!*(_DWORD *)(v50 + 528) || !*(_DWORD *)(v50 + 4))
        && (*(_BYTE *)(v20 + 85) & 1) == 0
        && !pmksa
        && !fils_pmksa
        || (unsigned int)wlan_cm_update_mlme_fils_info(a1, v50, v42, v43, v44, v45, v46, v47, v48, v49) )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: failed to update fils info vdev id %d",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "cm_csr_handle_join_req",
          v16);
        _qdf_mem_free(v53);
        goto LABEL_6;
      }
    }
    else
    {
      wlan_cm_update_mlme_fils_info(a1, 0, v21, v22, v23, v24, v25, v26, v27, v28);
    }
    sme_qos_csr_event_ind(v18, v16, 0, 0);
  }
  v51 = wlan_reg_11d_enabled_on_host(*(_QWORD *)(v18 + 21552));
  v52 = v53;
  if ( (v51 & 1) != 0 && !*(_BYTE *)(v53 + 322) )
  {
    csr_apply_channel_power_info_wrapper(v18);
    v52 = v53;
  }
  _qdf_mem_free(v52);
  _qdf_mem_free(v20);
  ((void (__fastcall *)(_QWORD))cm_csr_set_joining)(v16);
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
