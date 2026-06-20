__int64 __fastcall wlansap_set_mac_acl(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int16 v29; // w1
  __int64 v30; // x0

  qdf_trace_msg(0x39u, 8u, "%s: wlansap_set_mac_acl", a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_set_mac_acl");
  if ( !a1 )
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid SAP pointer", v12, v13, v14, v15, v16, v17, v18, v19, "wlansap_set_mac_acl");
    return 5;
  }
  v20 = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(a1 + 824) = v20;
  if ( !v20 )
  {
    qdf_mem_copy((void *)(a1 + 1022), (const void *)(a2 + 240), 0xC0u);
    v29 = *(_WORD *)(a2 + 480);
    v30 = a1 + 1022;
    *(_WORD *)(a1 + 1214) = v29;
    goto LABEL_7;
  }
  if ( v20 == 1 )
  {
    qdf_mem_copy((void *)(a1 + 828), (const void *)(a2 + 48), 0xC0u);
    v29 = *(_WORD *)(a2 + 478);
    v30 = a1 + 828;
    *(_WORD *)(a1 + 1020) = v29;
LABEL_7:
    sap_sort_mac_list(v30, v29, v21, v22, v23, v24, v25, v26, v27, v28);
  }
  return 0;
}
