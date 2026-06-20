__int64 __fastcall extract_mac_phy_cap_service_ready_ext2_tlv(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned int v14; // w8
  _DWORD *v15; // x19
  __int64 (*v17)(void); // x8
  unsigned int v18; // w19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  if ( !a2 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: null evt_buf",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "extract_mac_phy_cap_service_ready_ext2_tlv");
    return 4;
  }
  v14 = *(_DWORD *)(a2 + 56);
  if ( !v14 )
    return 0;
  if ( v14 <= a5 )
    return 4;
  v15 = (_DWORD *)(*(_QWORD *)(a2 + 48) + 192LL * a5);
  if ( v15[1] != a3 || v15[3] != a4 )
    return 4;
  *(_DWORD *)a6 = a3;
  *(_DWORD *)(a6 + 8) = v15[3];
  v17 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3672LL);
  if ( *((_DWORD *)v17 - 1) != -2112860426 )
    __break(0x8228u);
  *(_DWORD *)(a6 + 4) = v17();
  v18 = v15[4];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Target wireless mode: 0x%x",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "convert_wireless_modes_ext_tlv",
    v18);
  *(_QWORD *)(a6 + 16) = v18 << 23;
  return 0;
}
