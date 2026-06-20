__int64 __fastcall extract_mac_phy_cap_service_ready_ext_tlv(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        char a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x8
  unsigned int v14; // w8
  __int64 v15; // x20
  __int64 result; // x0
  __int64 v17; // x10
  char v18; // w9
  int v19; // w13
  unsigned __int8 v20; // w12
  __int64 v21; // x14
  unsigned int v22; // w13
  bool v23; // cc
  char v24; // w8
  __int64 v25; // x20
  int v27; // w9
  int v28; // w19
  __int64 (*v29)(void); // x8
  int v30; // w0
  int v31; // w9
  unsigned int v32; // w9
  unsigned int v33; // w9
  unsigned int v34; // w9
  unsigned int v35; // w9
  unsigned int v36; // w9
  unsigned int v37; // w9
  unsigned int v38; // w8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w19
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w10

  if ( !a2 )
    return 4;
  v13 = *(_QWORD *)(a2 + 16);
  if ( !v13 )
    return 4;
  v14 = *(_DWORD *)(v13 + 4);
  if ( v14 > 4 || v14 > *(_DWORD *)(a2 + 40) )
  {
    v15 = jiffies;
    if ( extract_mac_phy_cap_service_ready_ext_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: invalid num_hw_modes %d, num_hw_mode_caps %d",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "extract_mac_phy_cap_service_ready_ext_tlv",
        v14,
        *(unsigned int *)(a2 + 40));
      extract_mac_phy_cap_service_ready_ext_tlv___last_ticks = v15;
    }
    return 4;
  }
  if ( !v14 )
    return 4;
  v17 = *(_QWORD *)(a2 + 32);
  if ( *(_DWORD *)(v17 + 4) == a3 )
  {
    v18 = 0;
    v19 = 0;
  }
  else
  {
    v20 = 0;
    v18 = 0;
    v21 = *(_QWORD *)(a2 + 32);
    do
    {
      v22 = *(_DWORD *)(v21 + 8);
      if ( v22 )
      {
        do
        {
          v23 = v22 > 1;
          ++v18;
          v22 >>= 1;
        }
        while ( v23 );
      }
      v19 = ++v20;
      if ( v20 >= (unsigned int)(unsigned __int8)v14 )
        break;
      v21 = v17 + 16LL * v20;
    }
    while ( *(_DWORD *)(v21 + 4) != a3 );
  }
  if ( v14 == v19 )
    return 4;
  v24 = v18 + a4;
  if ( *(_DWORD *)(a2 + 56) <= (unsigned int)(unsigned __int8)(v18 + a4) )
    return 4;
  v25 = *(_QWORD *)(a2 + 48) + 240LL * (unsigned __int8)(v18 + a4);
  v27 = *(_DWORD *)(v25 + 4);
  *(_BYTE *)(a5 + 12) = v24;
  *(_DWORD *)a5 = v27;
  v28 = *(unsigned __int8 *)(v25 + 8);
  v29 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3688LL);
  if ( *((_DWORD *)v29 - 1) != -2112860426 )
    __break(0x8228u);
  v30 = v29();
  *(_DWORD *)(a5 + 248) = v28;
  v31 = *(_DWORD *)(a5 + 20);
  *(_DWORD *)(a5 + 4) = v30;
  *(_DWORD *)(a5 + 8) = *(_DWORD *)(v25 + 12);
  v32 = v31 & 0xFFFFFFFE | *(_DWORD *)(v25 + 16) & 1;
  *(_DWORD *)(a5 + 20) = v32;
  v33 = v32 & 0xFFFFFFFD | (2 * ((*(_DWORD *)(v25 + 16) >> 1) & 1));
  *(_DWORD *)(a5 + 20) = v33;
  v34 = v33 & 0xFFFFFFFB | (4 * ((*(_DWORD *)(v25 + 16) >> 2) & 1));
  *(_DWORD *)(a5 + 20) = v34;
  v35 = v34 & 0xFFFFFFF7 | (8 * ((*(_DWORD *)(v25 + 16) >> 3) & 1));
  *(_DWORD *)(a5 + 20) = v35;
  v36 = v35 & 0xFFFFFFEF | (16 * ((*(_DWORD *)(v25 + 16) >> 4) & 1));
  *(_DWORD *)(a5 + 20) = v36;
  v37 = v36 & 0xFFFFFFDF | (32 * ((*(_DWORD *)(v25 + 16) >> 5) & 1));
  *(_DWORD *)(a5 + 20) = v37;
  v38 = *(_DWORD *)(v25 + 16);
  *(_DWORD *)(a5 + 20) = v37 & 0xFFFFFFBF | (((v38 >> 6) & 1) << 6);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: 11be support %d",
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "extract_service_ready_11be_support",
    (v38 >> 6) & 1);
  *(_DWORD *)(a5 + 24) = *(_DWORD *)(v25 + 20);
  *(_DWORD *)(a5 + 28) = *(_DWORD *)(v25 + 24);
  *(_DWORD *)(a5 + 32) = *(_DWORD *)(v25 + 28);
  *(_DWORD *)(a5 + 36) = *(_DWORD *)(v25 + 32);
  *(_DWORD *)(a5 + 40) = *(_DWORD *)(v25 + 36);
  *(_DWORD *)(a5 + 44) = *(_DWORD *)(v25 + 40);
  *(_DWORD *)(a5 + 48) = *(_DWORD *)(v25 + 44);
  *(_DWORD *)(a5 + 52) = *(_DWORD *)(v25 + 204);
  *(_DWORD *)(a5 + 56) = *(_DWORD *)(v25 + 48);
  *(_DWORD *)(a5 + 60) = *(_DWORD *)(v25 + 52);
  *(_DWORD *)(a5 + 64) = *(_DWORD *)(v25 + 56);
  *(_DWORD *)(a5 + 68) = *(_DWORD *)(v25 + 60);
  *(_DWORD *)(a5 + 72) = *(_DWORD *)(v25 + 64);
  *(_DWORD *)(a5 + 76) = *(_DWORD *)(v25 + 68);
  *(_DWORD *)(a5 + 80) = *(_DWORD *)(v25 + 72);
  *(_DWORD *)(a5 + 84) = *(_DWORD *)(v25 + 76);
  *(_DWORD *)(a5 + 88) = *(_DWORD *)(v25 + 208);
  *(_DWORD *)(a5 + 92) = *(_DWORD *)(v25 + 80);
  *(_DWORD *)(a5 + 128) = *(_DWORD *)(v25 + 212);
  *(_DWORD *)(a5 + 96) = *(_DWORD *)(v25 + 84);
  *(_DWORD *)(a5 + 100) = *(_DWORD *)(v25 + 88);
  qdf_mem_copy((void *)(a5 + 104), (const void *)(v25 + 92), 0xCu);
  qdf_mem_copy((void *)(a5 + 116), (const void *)(v25 + 104), 0xCu);
  qdf_mem_copy((void *)(a5 + 132), (const void *)(v25 + 116), 0x28u);
  qdf_mem_copy((void *)(a5 + 172), (const void *)(v25 + 156), 0x28u);
  *(_DWORD *)(a5 + 212) = *(_DWORD *)(v25 + 196);
  *(_DWORD *)(a5 + 216) = *(_DWORD *)(v25 + 200);
  v47 = *(_DWORD *)(v25 + 216);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Target wireless mode: 0x%x",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "convert_wireless_modes_tlv",
    v47);
  result = 0;
  v56 = v47 & 0xF;
  if ( (v47 & 8) != 0 )
    v56 = v47 & 7 | 8;
  *(_QWORD *)(a5 + 224) = (v47 >> 14) & 0x80 | v47 & 0x1FFF60 | (v47 >> 3) & 0x200000 | (v47 >> 5) & 0x400000 | v56;
  *(_DWORD *)(a5 + 232) = *(_DWORD *)(v25 + 220);
  *(_DWORD *)(a5 + 236) = *(_DWORD *)(v25 + 224);
  *(_DWORD *)(a5 + 240) = *(_DWORD *)(v25 + 228);
  *(_DWORD *)(a5 + 244) = *(_DWORD *)(v25 + 232);
  *(_BYTE *)(a5 + 252) = *(_BYTE *)(v25 + 236) & 1;
  *(_BYTE *)(a5 + 253) = (*(_BYTE *)(v25 + 236) >> 1) & 0xF;
  return result;
}
