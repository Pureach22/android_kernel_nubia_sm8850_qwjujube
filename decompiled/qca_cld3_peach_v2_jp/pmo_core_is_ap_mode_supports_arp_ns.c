__int64 __fastcall pmo_core_is_ap_mode_supports_arp_ns(__int64 a1, int a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( (a2 & 0xFFFFFFFD) != 1 || (*(_BYTE *)(comp_private_obj + 14) & 1) != 0 )
    return 1;
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: ARP/NS Offload is not supported in SAP/P2PGO mode",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "pmo_core_is_ap_mode_supports_arp_ns");
  return 0;
}
