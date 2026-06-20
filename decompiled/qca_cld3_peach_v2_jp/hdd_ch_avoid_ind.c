__int64 __fastcall hdd_ch_avoid_ind(
        __int64 a1,
        _WORD *a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int restriction_mask; // w21
  const char *v15; // x2
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x9
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x4
  __int64 v53; // x5
  unsigned __int16 v54; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v55[2]; // [xsp+10h] [xbp-10h] BYREF

  v55[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55[0] = 0;
  v54 = 0;
  if ( !a1 )
  {
    v15 = "%s: Invalid arguments";
    goto LABEL_5;
  }
  mutex_lock(a1 + 3184);
  qdf_mem_copy((void *)(a1 + 1820), a3, 0x2A8u);
  mutex_unlock(a1 + 3184);
  restriction_mask = wlan_hdd_get_restriction_mask(a1);
  if ( !(unsigned int)hdd_clone_local_unsafe_chan(a1, v55, (__int16 *)&v54) )
  {
    *(_WORD *)(a1 + 640) = 0;
    qdf_mem_set((void *)(a1 + 642), 0xCCu, 0);
    *(_WORD *)(a1 + 640) = *a2;
    wlan_hdd_set_restriction_mask(a1);
    if ( *a2 )
    {
      v25 = 0;
      do
      {
        if ( v25 == 102 )
          __break(0x5512u);
        v26 = v25++;
        *(_WORD *)(a1 + 642 + v26 * 2) = a2[v26 + 1];
      }
      while ( (unsigned __int16)*a2 > (unsigned int)(unsigned __int16)v25 );
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: number of unsafe channels is %d ",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "hdd_ch_avoid_ind",
      *(unsigned __int16 *)(a1 + 640));
    if ( (unsigned int)cnss_utils_set_wlan_unsafe_channel(
                         *(_QWORD *)(a1 + 96),
                         a1 + 642,
                         *(unsigned __int16 *)(a1 + 640)) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set unsafe channel",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "hdd_ch_avoid_ind");
      *(_WORD *)(a1 + 640) = 0;
      qdf_mem_set((void *)(a1 + 642), 0xCCu, 0);
    }
    else
    {
      mutex_lock(a1 + 3184);
      if ( *(_DWORD *)(a1 + 2500)
        && (unsigned int)((__int64 (__fastcall *)(const void *, __int64))wlan_hdd_merge_avoid_freqs)(a3, a1 + 2500) )
      {
        mutex_unlock(a1 + 3184);
        v43 = "%s: unable to merge avoid freqs";
      }
      else
      {
        mutex_unlock(a1 + 3184);
        wlan_hdd_send_avoid_freq_event(a1, a3, v44, v45, v46, v47, v48, v49, v50, v51);
        if ( *(_WORD *)(a1 + 640) )
        {
          if ( (hdd_local_unsafe_channel_updated(a1, v55[0], v54, restriction_mask, v52, v53) & 1) != 0 )
            hdd_unsafe_channel_restart_sap(a1);
          goto LABEL_20;
        }
        v43 = "%s: no unsafe channels - not restarting SAP";
      }
      qdf_trace_msg(0x33u, 8u, v43, v35, v36, v37, v38, v39, v40, v41, v42, "hdd_ch_avoid_ind");
    }
LABEL_20:
    result = _qdf_mem_free(v55[0]);
    goto LABEL_21;
  }
  v15 = "%s: failed to clone cur unsafe chan list";
LABEL_5:
  result = qdf_trace_msg(0x33u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_ch_avoid_ind");
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
