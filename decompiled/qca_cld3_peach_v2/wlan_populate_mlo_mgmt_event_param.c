__int64 __fastcall wlan_populate_mlo_mgmt_event_param(__int64 a1, _BYTE *a2, int a3)
{
  char is_mld_sta; // w8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  unsigned int bss_peer_mac; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x4
  const char *v26; // x2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w19
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  char v44; // w8
  int v45; // [xsp+8h] [xbp-18h] BYREF
  __int16 v46; // [xsp+Ch] [xbp-14h]
  int v47; // [xsp+10h] [xbp-10h] BYREF
  __int16 v48; // [xsp+14h] [xbp-Ch]
  __int64 v49; // [xsp+18h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v47 = 0;
  v46 = 0;
  v45 = 0;
  is_mld_sta = mlo_is_mld_sta(a1);
  result = 0;
  if ( (is_mld_sta & 1) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 60) & 2) != 0 )
    {
      result = 4;
    }
    else
    {
      bss_peer_mac = wlan_vdev_get_bss_peer_mac(a1, &v47, v7, v8, v9, v10, v11, v12, v13, v14);
      if ( bss_peer_mac )
      {
        v25 = *(unsigned __int8 *)(a1 + 168);
        v26 = "%s: vdev: %d bss peer not found";
LABEL_8:
        v35 = bss_peer_mac;
        qdf_trace_msg(0x38u, 2u, v26, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_populate_mlo_mgmt_event_param", v25);
        result = v35;
        goto LABEL_9;
      }
      qdf_mem_copy(a2, &v47, 6u);
      bss_peer_mac = wlan_vdev_get_bss_peer_mld_mac(a1, &v45, v27, v28, v29, v30, v31, v32, v33, v34);
      if ( bss_peer_mac )
      {
        v25 = *(unsigned __int8 *)(a1 + 168);
        v26 = "%s: vdev: %d failed to get mld mac address of peer";
        goto LABEL_8;
      }
      qdf_mem_copy(a2 + 57, &v45, 6u);
      if ( (a3 & 0xFFFFFFFD) == 4 )
      {
        if ( *(_QWORD *)(*(_QWORD *)(a1 + 1360) + 3880LL) )
        {
          v44 = wlan_populate_band_bitmap();
          result = 0;
          a2[39] = a2[39] & 3 | (4 * v44);
        }
        else
        {
          qdf_trace_msg(
            0x38u,
            8u,
            "%s: vdev: %d link_ctx not found",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "wlan_populate_mlo_mgmt_event_param",
            *(unsigned __int8 *)(a1 + 168));
          result = 4;
        }
      }
      else
      {
        result = 0;
      }
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
