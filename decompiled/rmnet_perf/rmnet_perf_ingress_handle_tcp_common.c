__int64 __fastcall rmnet_perf_ingress_handle_tcp_common(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  _WORD *v3; // x8
  unsigned int v4; // w9
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x9
  char v9; // w8

  v2 = *(unsigned __int16 *)(a1 + 182);
  if ( v2 == 0xFFFF )
    return 0;
  if ( (*(_BYTE *)(a1 + 128) & 0x60) == 0 )
    return 0;
  v3 = (_WORD *)(*(_QWORD *)(a1 + 216) + v2);
  v4 = (unsigned __int16)v3[6];
  if ( (v4 & 0x200) != 0
    || (v4 & 0x1000) != 0 && !(*(_DWORD *)(a1 + 112) - (_DWORD)v3 - ((v4 >> 2) & 0x3C) + *(_DWORD *)(a1 + 224)) )
  {
    return 0;
  }
  *(_WORD *)(a2 + 32) = *v3;
  *(_WORD *)(a2 + 34) = v3[1];
  v6 = *(_QWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 184);
  if ( *(_WORD *)(a1 + 180) == 8 )
  {
    *(_DWORD *)a2 = *(_DWORD *)(v6 + 12);
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(v6 + 16);
    v9 = 4;
  }
  else
  {
    v7 = *(_QWORD *)(v6 + 16);
    *(_QWORD *)a2 = *(_QWORD *)(v6 + 8);
    *(_QWORD *)(a2 + 8) = v7;
    v8 = *(_QWORD *)(v6 + 32);
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(v6 + 24);
    *(_QWORD *)(a2 + 24) = v8;
    v9 = 6;
  }
  *(_BYTE *)(a2 + 36) = v9;
  return 1;
}
