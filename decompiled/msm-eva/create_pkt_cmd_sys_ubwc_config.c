__int64 __fastcall create_pkt_cmd_sys_ubwc_config(__int64 a1, _DWORD *a2)
{
  unsigned int v4; // w9
  unsigned int v5; // w9
  unsigned int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w9

  if ( !a1 )
    return 4294967274LL;
  *(_QWORD *)a1 = 0x110100600000038LL;
  *(_QWORD *)(a1 + 8) = 0x700000001LL;
  *(_DWORD *)(a1 + 28) = a2[1];
  v4 = *(_DWORD *)(a1 + 24) & 0xFFFFFFFE | *a2 & 1;
  *(_DWORD *)(a1 + 24) = v4;
  *(_DWORD *)(a1 + 32) = a2[2];
  v5 = v4 & 0xFFFFFFFD | (2 * ((*a2 >> 1) & 1));
  *(_DWORD *)(a1 + 24) = v5;
  *(_DWORD *)(a1 + 36) = a2[3];
  v6 = v5 & 0xFFFFFFFB | (4 * ((*a2 >> 2) & 1));
  *(_DWORD *)(a1 + 24) = v6;
  *(_DWORD *)(a1 + 40) = a2[4];
  v7 = v6 & 0xFFFFFFF7 | (8 * ((*a2 >> 3) & 1));
  *(_DWORD *)(a1 + 24) = v7;
  *(_DWORD *)(a1 + 44) = a2[5];
  v8 = v7 & 0xFFFFFFEF | (16 * ((*a2 >> 4) & 1));
  *(_DWORD *)(a1 + 16) = 40;
  *(_DWORD *)(a1 + 24) = v8;
  return 0;
}
