__int64 __fastcall hal_rx_flow_setup_fse_peach(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x3
  int v12; // w8
  int v13; // w10
  int v14; // w11
  int v15; // w9
  int v16; // w8
  int v17; // w8
  int v18; // w9

  if ( *(unsigned __int16 *)(a1 + 24) <= a2 )
  {
    qdf_trace_msg(0x3Fu, 2u, "HAL FSE table offset %u exceeds max entries %u", a4, a5, a6, a7, a8, a9, a10, a11, a2);
    return 0;
  }
  v11 = *(_QWORD *)a1 + (a2 << 6);
  v12 = *(_DWORD *)(v11 + 36);
  if ( (v12 & 0x100) != 0 )
  {
    qdf_trace_msg(0x3Fu, 8u, "HAL FSE %pK already valid", a4, a5, a6, a7, a8, a9, a10, a11);
    return 0;
  }
  v13 = *(unsigned __int16 *)(v11 + 32);
  v14 = *(unsigned __int8 *)(v11 + 44);
  *(_DWORD *)v11 = *(_DWORD *)(a3 + 16);
  *(_DWORD *)(v11 + 4) = *(_DWORD *)(a3 + 20);
  *(_DWORD *)(v11 + 8) = *(_DWORD *)(a3 + 24);
  *(_DWORD *)(v11 + 12) = *(_DWORD *)(a3 + 28);
  *(_DWORD *)(v11 + 16) = *(_DWORD *)a3;
  *(_DWORD *)(v11 + 20) = *(_DWORD *)(a3 + 4);
  *(_DWORD *)(v11 + 24) = *(_DWORD *)(a3 + 8);
  *(_DWORD *)(v11 + 28) = *(_DWORD *)(a3 + 12);
  *(_DWORD *)(v11 + 32) = v13;
  v15 = *(unsigned __int16 *)(a3 + 32);
  *(_DWORD *)(v11 + 32) = v15 << 16;
  *(_DWORD *)(v11 + 32) = *(unsigned __int16 *)(a3 + 34) | ((unsigned __int16)v15 << 16);
  *(_DWORD *)(v11 + 36) = v12 & 0xFFFFFE00;
  v16 = v12 & 0x3FFFFE00 | *(unsigned __int8 *)(a3 + 36);
  *(_DWORD *)(v11 + 36) = v16;
  v17 = v16 | (*(unsigned __int8 *)(a3 + 40) << 30) | 0x100;
  *(_DWORD *)(v11 + 36) = v17;
  *(_DWORD *)(v11 + 40) = 0;
  v18 = *(_DWORD *)(a3 + 44);
  *(_DWORD *)(v11 + 36) = v17 & 0xE0FFFFFF;
  *(_DWORD *)(v11 + 40) = v18;
  LOBYTE(v13) = *(_BYTE *)(a3 + 41);
  *(_DWORD *)(v11 + 44) = v14;
  *(_QWORD *)(v11 + 48) = 0;
  *(_DWORD *)(v11 + 36) = v17 & 0xC0FFE1FF | ((v13 & 0x1F) << 24);
  return v11;
}
