__int64 __fastcall hdd_get_interface_info(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x23
  unsigned int v13; // w8
  char v14; // w8
  __int64 *link_mac_addr; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int8 *v24; // x19
  int v25; // w9
  int v26; // w8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w9
  void *v36; // x0
  unsigned __int64 *v37; // x13
  unsigned __int64 v38; // x8
  int v39; // w9
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  v10 = *(_QWORD *)a1;
  v13 = *(_DWORD *)(*(_QWORD *)a1 + 40LL);
  if ( v13 >= 4 )
    v14 = 0;
  else
    v14 = 0x4030100u >> (8 * v13);
  *(_BYTE *)a2 = v14;
  link_mac_addr = hdd_adapter_get_link_mac_addr((__int64 *)a1, a3, a4, a5, a6, a7, a8, a9, a10);
  v24 = (unsigned __int8 *)link_mac_addr;
  if ( !link_mac_addr )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Invalid HDD link info",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_get_interface_info");
    return v24 != nullptr;
  }
  v25 = *(_DWORD *)link_mac_addr;
  *(_WORD *)(a2 + 5) = *((_WORD *)link_mac_addr + 2);
  *(_DWORD *)(a2 + 1) = v25;
  v26 = *(_DWORD *)(v10 + 40);
  if ( v26 != 7 && v26 != 2 )
  {
    if ( v26 )
    {
LABEL_21:
      if ( (v26 | 2) == 3 && (*(_QWORD *)(a1 + 5968) & 2) != 0 )
      {
        v39 = *(_DWORD *)(a1 + 712);
        *(_WORD *)(a2 + 53) = *(_WORD *)(a1 + 716);
        *(_DWORD *)(a2 + 49) = v39;
      }
      wlan_reg_get_cc_and_src(**(_QWORD **)(v10 + 24), (void *)(a2 + 58), v16, v17, v18, v19, v20, v21, v22, v23);
      wlan_reg_get_cc_and_src(**(_QWORD **)(v10 + 24), (void *)(a2 + 55), v40, v41, v42, v43, v44, v45, v46, v47);
      return v24 != nullptr;
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
    v26 = *(_DWORD *)(v10 + 40);
    goto LABEL_21;
  }
  if ( hdd_cm_is_connecting(a1) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Session ID %d, Connection is in progress",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "hdd_get_interface_info",
      *(unsigned __int8 *)(a1 + 8));
    *(_BYTE *)(a2 + 7) = 2;
    goto LABEL_20;
  }
  if ( hdd_cm_is_vdev_associated((_DWORD *)a1) )
  {
    if ( !*(_BYTE *)(a1 + 684) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: client %02x:%02x:%02x:**:**:%02x is in the middle of WPS/EAPOL exchange.",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_get_interface_info",
        *v24,
        v24[1],
        v24[2],
        v24[5]);
      *(_BYTE *)(a2 + 7) = 1;
      goto LABEL_20;
    }
    goto LABEL_16;
  }
  if ( *(_BYTE *)(a2 + 7) != 3 )
    goto LABEL_20;
LABEL_18:
  v35 = *(_DWORD *)(a1 + 308);
  *(_WORD *)(a2 + 53) = *(_WORD *)(a1 + 312);
  *(_DWORD *)(a2 + 49) = v35;
  v36 = qdf_mem_copy((void *)(a2 + 16), (const void *)(a1 + 317), *(unsigned __int8 *)(a1 + 316));
  v38 = *(unsigned __int8 *)(a1 + 316);
  if ( v38 <= 0x20 )
  {
    *(_BYTE *)(a2 + 16 + v38) = 0;
    goto LABEL_20;
  }
  __break(0x5512u);
  __ldaxp(v37);
  return wlan_hdd_cfg80211_link_layer_stats_callback(v36);
}
