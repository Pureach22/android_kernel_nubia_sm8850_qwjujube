__int64 __fastcall cm_roam_scan_offload_rssi_thresh(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  int v18; // w8
  int v19; // w8
  int v20; // w8
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int16 *v30; // x24
  unsigned __int8 roam_scan_high_rssi_offset; // w0
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int operation_chan_freq; // w0
  int v42; // w8
  int v43; // w8
  int v44; // w8

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( !result )
    return result;
  v17 = result;
  if ( *(_BYTE *)(a4 + 1383) == 1 && (*(_BYTE *)(a4 + 92) & 1) == 0 )
  {
    v19 = *(unsigned __int8 *)(result + 2772);
    goto LABEL_7;
  }
  v18 = *(_DWORD *)(result + 2688);
  if ( !v18 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: lookup_threshold:%d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "cm_roam_scan_offload_rssi_thresh",
      *(unsigned __int8 *)(a4 + 128));
    v19 = *(unsigned __int8 *)(a4 + 128);
LABEL_7:
    v18 = -v19;
  }
  *(_BYTE *)a3 = v18;
  *(_BYTE *)(a3 + 24) = a2;
  *(_BYTE *)(a3 + 1) = *(_BYTE *)(a4 + 148);
  *(_DWORD *)(a3 + 4) = *(_DWORD *)(a4 + 152);
  if ( (*(_BYTE *)(a4 + 91) & 1) != 0 )
    v20 = 0;
  else
    v20 = *(_DWORD *)(a4 + 156);
  *(_DWORD *)(a3 + 8) = v20;
  v21 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v21 )
  {
    v30 = (unsigned __int16 *)v21;
    roam_scan_high_rssi_offset = wlan_cm_get_roam_scan_high_rssi_offset(a1);
    if ( roam_scan_high_rssi_offset )
    {
      *(_DWORD *)(a3 + 8) = roam_scan_high_rssi_offset;
      operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq(v30);
      if ( wlan_reg_is_5ghz_ch_freq(operation_chan_freq) )
      {
        v32 = (unsigned int *)(*(_DWORD *)(a3 + 104) | 1u);
        *(_DWORD *)(a3 + 104) = (_DWORD)v32;
      }
    }
    result = wlan_objmgr_vdev_release_ref((__int64)v30, 0x4Du, v32, v33, v34, v35, v36, v37, v38, v39, v40);
  }
  else
  {
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: Cannot set high RSSI offset as vdev object is NULL for vdev %d",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "cm_roam_scan_offload_rssi_thresh",
               (unsigned __int8)a2);
  }
  *(_DWORD *)(a3 + 12) = *(_DWORD *)(a4 + 164);
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(v17 + 1872);
  *(_DWORD *)(a3 + 64) = *(_DWORD *)(v17 + 1796);
  v42 = *(_DWORD *)(v17 + 1800);
  *(_DWORD *)(a3 + 68) = v42;
  *(_DWORD *)(a3 + 76) = *(_DWORD *)(v17 + 1792);
  if ( v42 < *(char *)(a4 + 676) )
    *(_DWORD *)(a3 + 72) = 1;
  *(_BYTE *)(a3 + 84) = *(_DWORD *)(v17 + 1804);
  *(_DWORD *)(a3 + 88) = *(_DWORD *)(v17 + 1808);
  *(_BYTE *)(a3 + 85) = *(_DWORD *)(v17 + 1812);
  *(_DWORD *)(a3 + 92) = *(_DWORD *)(v17 + 1816);
  *(_DWORD *)(a3 + 96) = *(_DWORD *)(v17 + 1820);
  *(_DWORD *)(a3 + 100) = *(_DWORD *)(v17 + 1824);
  *(_DWORD *)(a3 + 20) = *(_DWORD *)(v17 + 1884);
  *(_BYTE *)(a3 + 36) = *(_DWORD *)(v17 + 1876);
  *(_BYTE *)(a3 + 37) = *(_DWORD *)(v17 + 1888);
  *(_DWORD *)(a3 + 40) = *(_DWORD *)(v17 + 1880);
  *(_DWORD *)(a3 + 44) = *(_DWORD *)(v17 + 1892);
  if ( *(_DWORD *)(v17 + 2684) )
    v43 = -96;
  else
    v43 = 0;
  *(_DWORD *)(a3 + 48) = v43;
  v44 = *(unsigned __int8 *)(v17 + 1764);
  *(_BYTE *)(a3 + 52) = v44;
  if ( v44 == 1 )
  {
    *(_DWORD *)(a3 + 56) = *(char *)(v17 + 1789);
    *(_DWORD *)(a3 + 60) = *(char *)(v17 + 1790);
  }
  *(_DWORD *)(a3 + 80) = *(char *)(a4 + 130);
  return result;
}
