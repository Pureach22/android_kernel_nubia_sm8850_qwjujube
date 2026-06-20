__int64 __fastcall hif_pci_addr_in_boundary(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  bool v13; // cc
  __int64 v14; // x8
  unsigned int v17; // w8

  v4 = *(_DWORD *)(hif_get_target_info_handle(a1) + 4);
  v13 = v4 > 0x2B;
  v14 = (1LL << v4) & 0xC2488F00100LL;
  if ( !v13 && v14 != 0 )
    return 0;
  v17 = *(_DWORD *)(*(_QWORD *)(a1 + 616) + 268LL);
  if ( v17 <= a2 && v17 + 688128 >= a2 )
    return 0;
  if ( (unsigned __int64)a2 + 4 <= *(_QWORD *)(a1 + 30752) )
    return 0;
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: Refusing to read memory at 0x%x - 0x%x (max 0x%zx)",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "hif_pci_addr_in_boundary",
    a2);
  return 4294967274LL;
}
