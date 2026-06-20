__int64 __fastcall mlo_mgr_if_freq_n_inactive_links_freq_same(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char is_mlo_vdev; // w8
  __int64 result; // x0
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int16 tids_mapped_link_id; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x21
  int v33; // w20
  _WORD v34[6]; // [xsp+Ch] [xbp-B4h] BYREF
  _QWORD v35[19]; // [xsp+18h] [xbp-A8h] BYREF
  int v36; // [xsp+B0h] [xbp-10h]
  __int64 v37; // [xsp+B8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  memset(v35, 0, sizeof(v35));
  v34[0] = 0;
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  result = 0;
  if ( (is_mlo_vdev & 1) != 0 )
  {
    v14 = *(_QWORD *)(a1 + 1360);
    if ( v14 )
    {
      if ( (unsigned int)wlan_get_t2lm_mapping_status(a1, (char *)v35) )
      {
        qdf_trace_msg(
          0x8Fu,
          4u,
          "%s: Unable to get t2lm_mapping",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "mlo_mgr_if_freq_n_inactive_links_freq_same");
        goto LABEL_6;
      }
      if ( (unsigned int)t2lm_find_tid_mapped_link_id(v35, v34) )
        goto LABEL_6;
      tids_mapped_link_id = t2lm_get_tids_mapped_link_id(v34[0]);
      v32 = *(_QWORD *)(v14 + 3880);
      v33 = tids_mapped_link_id;
      if ( (*(_BYTE *)(v32 + 40) & 1) == 0 && *(_DWORD *)(v32 + 24) | *(unsigned __int16 *)(v32 + 28) )
      {
        if ( (v35[0] & 0x100000000LL) != 0 || *(unsigned __int8 *)(v32 + 6) == tids_mapped_link_id )
        {
          if ( **(_WORD **)(v32 + 32) && **(unsigned __int16 **)(v32 + 32) == a2 )
            goto LABEL_32;
        }
        else if ( **(unsigned __int16 **)(v32 + 32) == a2 )
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Skip link_id %d chan_freq %d as tid is mapped to %d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "mlo_mgr_if_freq_n_inactive_links_freq_same");
        }
      }
      if ( (*(_BYTE *)(v32 + 88) & 1) == 0 && *(_DWORD *)(v32 + 72) | *(unsigned __int16 *)(v32 + 76) )
      {
        if ( (v35[0] & 0x100000000LL) != 0 || *(unsigned __int8 *)(v32 + 54) == v33 )
        {
          if ( **(_WORD **)(v32 + 80) && **(unsigned __int16 **)(v32 + 80) == a2 )
            goto LABEL_32;
        }
        else if ( **(unsigned __int16 **)(v32 + 80) == a2 )
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Skip link_id %d chan_freq %d as tid is mapped to %d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "mlo_mgr_if_freq_n_inactive_links_freq_same");
        }
      }
      if ( (*(_BYTE *)(v32 + 136) & 1) == 0 && *(_DWORD *)(v32 + 120) | *(unsigned __int16 *)(v32 + 124) )
      {
        if ( (v35[0] & 0x100000000LL) == 0 && *(unsigned __int8 *)(v32 + 102) != v33 )
        {
          if ( **(unsigned __int16 **)(v32 + 128) == a2 )
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: Skip link_id %d chan_freq %d as tid is mapped to %d",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              "mlo_mgr_if_freq_n_inactive_links_freq_same");
          goto LABEL_6;
        }
        if ( **(_WORD **)(v32 + 128) && **(unsigned __int16 **)(v32 + 128) == a2 )
        {
LABEL_32:
          result = 1;
          goto LABEL_7;
        }
      }
    }
LABEL_6:
    result = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
