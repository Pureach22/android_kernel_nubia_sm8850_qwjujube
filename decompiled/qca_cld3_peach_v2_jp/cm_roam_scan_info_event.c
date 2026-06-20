__int64 __fastcall cm_roam_scan_info_event(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 v16; // x0
  unsigned int v17; // w24
  __int64 v18; // x21
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  unsigned int v38; // w8
  unsigned __int64 v39; // x8
  __int64 result; // x0
  unsigned int connected_roaming_vdev_band_mask; // w22
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w8
  __int64 v51; // x25
  unsigned int v52; // w24
  unsigned int v53; // w23
  char v54; // w27
  __int64 v55; // [xsp+0h] [xbp-10h] BYREF
  __int64 v56; // [xsp+8h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v55) = 0;
  LODWORD(v55) = 0;
  v6 = _qdf_mem_malloc(0x206u, "cm_roam_scan_info_event", 6836);
  if ( !v6 )
  {
    v37 = "%s: Mem malloc failed for wlan_diag_event";
LABEL_21:
    result = qdf_trace_msg(0x68u, 2u, v37, v7, v8, v9, v10, v11, v12, v13, v14, "cm_roam_scan_info_event", v55, v56);
    goto LABEL_22;
  }
  v15 = v6;
  v16 = _qdf_mem_malloc(0x198u, "cm_roam_scan_info_event", 6842);
  if ( !v16 )
  {
    _qdf_mem_free(v15);
    v37 = "%s: Mem malloc failed for chan_freq";
    goto LABEL_21;
  }
  v17 = *(_DWORD *)(a2 + 672);
  v18 = v16;
  *(_WORD *)(v15 + 6) = (unsigned __int8)a3;
  *(_QWORD *)(v15 + 8) = qdf_get_time_of_the_day_us();
  v19 = ktime_get();
  *(_QWORD *)(v15 + 16) = 1000LL * v17;
  *(_QWORD *)(v15 + 24) = v19 / 1000;
  qdf_mem_copy((void *)v15, (const void *)(a2 + 97), 6u);
  *(_BYTE *)(v15 + 32) = 1;
  if ( *(_WORD *)(a2 + 4) )
    *(_WORD *)(v15 + 34) = *(_WORD *)(a2 + 4) - 1;
  if ( *(_BYTE *)a2 != 1 || (v28 = *(unsigned __int16 *)(a2 + 2), v28 > 4) || ((1 << v28) & 0x1A) == 0 )
  {
    v38 = *(unsigned __int16 *)(a2 + 6);
    if ( v38 >= 0x27 )
    {
      LOWORD(v38) = 38;
      *(_WORD *)(a2 + 6) = 38;
    }
    *(_WORD *)(v15 + 36) = v38;
    if ( *(_WORD *)(a2 + 6) )
    {
      v39 = 0;
      do
      {
        if ( v39 == 38 )
LABEL_43:
          __break(0x5512u);
        *(_DWORD *)(v15 + 38 + 4 * v39) = *(unsigned __int16 *)(a2 + 16 + 2 * v39);
        ++v39;
      }
      while ( v39 < *(unsigned __int16 *)(a2 + 6) );
    }
    goto LABEL_18;
  }
  if ( !(unsigned __int8)mlme_get_fw_scan_channels(a1, v18, (_BYTE *)&v55 + 4, v20, v21, v22, v23, v24, v25, v26, v27) )
  {
    if ( BYTE4(v55) >= 0x67u )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: unexpected num chan %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "cm_roam_scan_info_event");
      goto LABEL_19;
    }
    if ( (unsigned __int8)wlan_mlme_get_band_capability(a1, &v55) )
      goto LABEL_19;
    BYTE4(v55) = 102;
    connected_roaming_vdev_band_mask = policy_mgr_get_connected_roaming_vdev_band_mask(a1, a3);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: mask:%d, capability:%d, scan_type:%d, num_chan:%d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "cm_roam_scan_info_event",
      connected_roaming_vdev_band_mask,
      (unsigned int)v55,
      *(unsigned __int16 *)(a2 + 2),
      BYTE4(v55));
    v50 = *(unsigned __int16 *)(a2 + 2);
    if ( v50 != 4 )
    {
      if ( v50 != 3 )
      {
LABEL_28:
        if ( BYTE4(v55) )
        {
          v51 = 0;
          v52 = 0;
          while ( 1 )
          {
            v53 = *(_DWORD *)(v18 + 4 * v51);
            if ( connected_roaming_vdev_band_mask == 7 && (_DWORD)v55 == 7
              || ((v54 = v55 & connected_roaming_vdev_band_mask,
                   ((unsigned __int8)v55 & (unsigned __int8)connected_roaming_vdev_band_mask & 4) != 0)
               || !wlan_reg_is_6ghz_chan_freq(v53))
              && ((v54 & 2) != 0 || !wlan_reg_is_5ghz_ch_freq(v53))
              && ((v54 & 1) != 0 || !wlan_reg_is_24ghz_ch_freq(v53)) )
            {
              if ( v52 >= 0x78 )
                goto LABEL_43;
              *(_DWORD *)(v15 + 38 + 4LL * v52++) = *(_DWORD *)(v18 + 4 * v51);
            }
            if ( ++v51 >= (unsigned __int64)BYTE4(v55) )
              goto LABEL_42;
          }
        }
        LOBYTE(v52) = 0;
LABEL_42:
        *(_WORD *)(v15 + 36) = (unsigned __int8)v52;
LABEL_18:
        *(_BYTE *)(v15 + 33) = *(_BYTE *)(v15 + 33) & 0xFE | *(_BYTE *)(a2 + 1);
        goto LABEL_19;
      }
      v50 = 6;
    }
    connected_roaming_vdev_band_mask &= v50;
    goto LABEL_28;
  }
LABEL_19:
  host_diag_event_report_payload(3357, 518, v15);
  _qdf_mem_free(v18);
  result = _qdf_mem_free(v15);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
