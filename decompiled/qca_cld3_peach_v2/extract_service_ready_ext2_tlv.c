__int64 __fastcall extract_service_ready_ext2_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x21
  __int64 v14; // x8
  unsigned int v16; // w8
  char v17; // w10
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w4
  const char *v27; // x2
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7

  if ( !a10 )
    return 4;
  v11 = *a10;
  if ( !*a10 )
    return 4;
  *(_WORD *)a11 = *(_DWORD *)(v11 + 4);
  *(_BYTE *)(a11 + 2) = *(_WORD *)(v11 + 6);
  *(_BYTE *)(a11 + 3) = *(_BYTE *)(v11 + 7);
  *(_DWORD *)(a11 + 8) = *(_DWORD *)(v11 + 16);
  *(_DWORD *)(a11 + 4) = *((_DWORD *)a10 + 6);
  *(_DWORD *)(a11 + 44) = *((_DWORD *)a10 + 34);
  v14 = a10[10];
  if ( v14 )
  {
    *(_DWORD *)(a11 + 12) = *(_DWORD *)(v14 + 4);
    LODWORD(v14) = *(_DWORD *)(a10[10] + 8);
  }
  else
  {
    *(_DWORD *)(a11 + 12) = 0;
  }
  *(_DWORD *)(a11 + 16) = v14;
  *(_DWORD *)(a11 + 20) = *(_DWORD *)(v11 + 20);
  *(_BYTE *)(a11 + 24) = *((_DWORD *)a10 + 26);
  *(_WORD *)(a11 + 26) = *(_WORD *)(v11 + 26);
  *(_WORD *)(a11 + 28) = *(_DWORD *)(v11 + 24);
  *(_WORD *)(a11 + 30) = *(_WORD *)(v11 + 30);
  *(_WORD *)(a11 + 32) = *(_DWORD *)(v11 + 28);
  v16 = *(_DWORD *)(v11 + 32);
  *(_BYTE *)(a11 + 40) = v16 & 3;
  *(_DWORD *)(a11 + 36) = v16;
  v17 = *(_BYTE *)(a11 + 41) & 0xC0;
  *(_BYTE *)(a11 + 48) = (*(_DWORD *)(v11 + 32) & 0x2000) != 0;
  *(_BYTE *)(a11 + 41) = v16 & 0x10
                       | (8 * ((v16 & 4) != 0))
                       | (v16 >> 1) & 0x20
                       | ((v16 & 8) != 0)
                       | (v16 >> 4) & 2
                       | (v16 >> 5) & 4
                       | v17;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: htt peer data :%d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "extract_service_ready_ext2_tlv",
    *(unsigned int *)(v11 + 32));
  *(_BYTE *)(a11 + 88) = (*(_DWORD *)(v11 + 32) & 0x4000) != 0;
  *(_BYTE *)(a11 + 96) = (*(_DWORD *)(v11 + 32) & 0x8000) != 0;
  *(_BYTE *)(a11 + 97) = *(_BYTE *)(v11 + 34) & 1;
  v26 = *(unsigned __int8 *)(v11 + 60);
  if ( v26 > 2 )
  {
    switch ( v26 )
    {
      case 3u:
        v27 = "%s: BDF VER is %d, BDF ver is newer than the newest version supported by FW";
        goto LABEL_22;
      case 4u:
        v27 = "%s: BDF VER is %d, FW ver is older than the major version supported by BDF";
        goto LABEL_22;
      case 5u:
        v27 = "%s: BDF VER is %d, FW ver is newer than the minor version supported by BDF";
        goto LABEL_22;
    }
LABEL_19:
    v27 = "%s: unknown BDF VER %d";
    goto LABEL_22;
  }
  if ( *(_BYTE *)(v11 + 60) )
  {
    if ( v26 == 1 )
    {
      v27 = "%s: BDF VER is %d, FW and BDF ver check good";
      goto LABEL_22;
    }
    if ( v26 == 2 )
    {
      v27 = "%s: BDF VER is %d, BDF ver is older than the oldest version supported by FW";
LABEL_22:
      qdf_trace_msg(0x31u, 4u, v27, v18, v19, v20, v21, v22, v23, v24, v25, "extract_hw_bdf_status");
      goto LABEL_23;
    }
    goto LABEL_19;
  }
  qdf_trace_msg(
    0x31u,
    4u,
    "%s: FW and BDF ver check skipped",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "extract_hw_bdf_status");
LABEL_23:
  *(_DWORD *)(a11 + 52) = *(_DWORD *)(v11 + 72);
  *(_DWORD *)(a11 + 56) = *(_DWORD *)(v11 + 76);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Firmware Max MLO link support: %d(mlo sta) %d(mlo sap)",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "extract_num_max_mlo_link");
  v36 = *(_DWORD *)(v11 + 32);
  *(_BYTE *)(a11 + 108) = (v36 >> 20) & 7;
  *(_BYTE *)(a11 + 109) = (v36 >> 17) & 7;
  *(_BYTE *)(a11 + 110) = BYTE1(v36) & 7;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Firmware num bss: %d (sap) %d (sta) %d (max)",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "extract_num_max_bss");
  *(_DWORD *)(a11 + 60) = *((_DWORD *)a10 + 58);
  v45 = *(_DWORD *)(v11 + 80);
  *(_BYTE *)(a11 + 98) = v45 & 0x1F;
  *(_BYTE *)(a11 + 99) = v45 & 0x1F;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Supported_wifi: 0x%x Certified_wifi: 0x%x",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "extract_wifi_generations_info");
  return 0;
}
