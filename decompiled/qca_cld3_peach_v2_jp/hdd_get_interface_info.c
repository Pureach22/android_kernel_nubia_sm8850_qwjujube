__int64 __fastcall hdd_get_interface_info(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  unsigned int v5; // w8
  char v6; // w8
  unsigned __int8 *link_mac_addr; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int8 *v16; // x19
  int v17; // w9
  int v18; // w8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w9
  void *v28; // x0
  unsigned __int64 *v29; // x13
  unsigned __int64 v30; // x8
  int v31; // w9
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v2 = *(_QWORD *)a1;
  v5 = *(_DWORD *)(*(_QWORD *)a1 + 40LL);
  if ( v5 >= 4 )
    v6 = 0;
  else
    v6 = 0x4030100u >> (8 * v5);
  *(_BYTE *)a2 = v6;
  link_mac_addr = (unsigned __int8 *)hdd_adapter_get_link_mac_addr((_QWORD *)a1);
  v16 = link_mac_addr;
  if ( !link_mac_addr )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Invalid HDD link info",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_get_interface_info");
    return v16 != nullptr;
  }
  v17 = *(_DWORD *)link_mac_addr;
  *(_WORD *)(a2 + 5) = *((_WORD *)link_mac_addr + 2);
  *(_DWORD *)(a2 + 1) = v17;
  v18 = *(_DWORD *)(v2 + 40);
  if ( v18 != 7 && v18 != 2 )
  {
    if ( v18 )
    {
LABEL_21:
      if ( (v18 | 2) == 3 && (*(_QWORD *)(a1 + 4416) & 2) != 0 )
      {
        v31 = *(_DWORD *)(a1 + 712);
        *(_WORD *)(a2 + 53) = *(_WORD *)(a1 + 716);
        *(_DWORD *)(a2 + 49) = v31;
      }
      wlan_reg_get_cc_and_src(**(_QWORD **)(v2 + 24), (void *)(a2 + 58), v8, v9, v10, v11, v12, v13, v14, v15);
      wlan_reg_get_cc_and_src(**(_QWORD **)(v2 + 24), (void *)(a2 + 55), v32, v33, v34, v35, v36, v37, v38, v39);
      return v16 != nullptr;
    }
    if ( *(unsigned __int8 *)(a1 + 8) == 255 )
    {
LABEL_16:
      *(_BYTE *)(a2 + 7) = 3;
      goto LABEL_18;
    }
  }
  if ( hdd_cm_is_disconnected(a1) )
  {
    *(_BYTE *)(a2 + 7) = 0;
LABEL_20:
    v18 = *(_DWORD *)(v2 + 40);
    goto LABEL_21;
  }
  if ( hdd_cm_is_connecting(a1) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Session ID %d, Connection is in progress",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "hdd_get_interface_info",
      *(unsigned __int8 *)(a1 + 8));
    *(_BYTE *)(a2 + 7) = 2;
    goto LABEL_20;
  }
  if ( hdd_cm_is_vdev_associated((_DWORD *)a1) )
  {
    if ( !*(_BYTE *)(a1 + 676) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: client %02x:%02x:%02x:**:**:%02x is in the middle of WPS/EAPOL exchange.",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "hdd_get_interface_info",
        *v16,
        v16[1],
        v16[2],
        v16[5]);
      *(_BYTE *)(a2 + 7) = 1;
      goto LABEL_20;
    }
    goto LABEL_16;
  }
  if ( *(_BYTE *)(a2 + 7) != 3 )
    goto LABEL_20;
LABEL_18:
  v27 = *(_DWORD *)(a1 + 300);
  *(_WORD *)(a2 + 53) = *(_WORD *)(a1 + 304);
  *(_DWORD *)(a2 + 49) = v27;
  v28 = qdf_mem_copy((void *)(a2 + 16), (const void *)(a1 + 309), *(unsigned __int8 *)(a1 + 308));
  v30 = *(unsigned __int8 *)(a1 + 308);
  if ( v30 <= 0x20 )
  {
    *(_BYTE *)(a2 + 16 + v30) = 0;
    goto LABEL_20;
  }
  __break(0x5512u);
  __ldaxp(v29);
  return wlan_hdd_cfg80211_link_layer_stats_callback(v28);
}
