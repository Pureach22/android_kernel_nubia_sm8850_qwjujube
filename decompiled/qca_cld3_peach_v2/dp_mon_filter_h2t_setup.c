__int64 __fastcall dp_mon_filter_h2t_setup(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x14
  int v7; // w17
  unsigned __int16 v8; // w15
  int v9; // w0
  int v10; // w16
  unsigned __int16 v11; // w15
  unsigned __int16 v12; // w15
  int v13; // w0
  int v14; // w16
  unsigned __int16 v15; // w15
  int v16; // w16

  v4 = 0;
  v5 = *(_QWORD *)(a2 + 96456);
  do
  {
    v6 = *(_QWORD *)(*(_QWORD *)(v5 + 37064) + v4) + 92LL * a3;
    if ( *(_BYTE *)v6 == 1 )
    {
      *(_BYTE *)a4 = 1;
      v7 = *(_DWORD *)(a4 + 8);
      *(_DWORD *)(a4 + 4) |= *(_DWORD *)(v6 + 4);
      v8 = v7 | *(_DWORD *)(v6 + 8);
      *(_DWORD *)(a4 + 8) = (unsigned __int16)*(_DWORD *)(v6 + 8) | v7;
      *(_DWORD *)(a4 + 8) = (*(_DWORD *)(v6 + 8) | v7) & 0xFFFF0000 | v8;
      v10 = *(_DWORD *)(a4 + 12);
      v9 = *(_DWORD *)(a4 + 16);
      v11 = v10 | *(_DWORD *)(v6 + 12);
      *(_DWORD *)(a4 + 12) = (unsigned __int16)*(_DWORD *)(v6 + 12) | v10;
      *(_DWORD *)(a4 + 12) = (*(_DWORD *)(v6 + 12) | v10) & 0xFFFF0000 | v11;
      v12 = v9 | *(_DWORD *)(v6 + 16);
      *(_DWORD *)(a4 + 16) = (unsigned __int16)*(_DWORD *)(v6 + 16) | v9;
      *(_DWORD *)(a4 + 16) = (*(_DWORD *)(v6 + 16) | v9) & 0xFFFF0000 | v12;
      v14 = *(_DWORD *)(a4 + 20);
      v13 = *(_DWORD *)(a4 + 24);
      v15 = v14 | *(_DWORD *)(v6 + 20);
      *(_DWORD *)(a4 + 20) = (unsigned __int16)*(_DWORD *)(v6 + 20) | v14;
      *(_DWORD *)(a4 + 20) = (*(_DWORD *)(v6 + 20) | v14) & 0xFFFF0000 | v15;
      v16 = *(_DWORD *)(a4 + 78);
      *(_DWORD *)(a4 + 24) = *(unsigned __int16 *)(v6 + 24) | v13;
      *(_BYTE *)(a4 + 88) = *(_BYTE *)(v6 + 88);
      *(_DWORD *)(a4 + 78) = v16 & 0xFFFFF1FF | (((*(_DWORD *)(v6 + 78) >> 9) & 7) << 9);
      *(_DWORD *)(a4 + 64) = *(_DWORD *)(v6 + 64);
      *(_DWORD *)(a4 + 72) = *(_DWORD *)(v6 + 72);
    }
    v4 += 8;
  }
  while ( v4 != 32 );
  return ((__int64 (*)(void))dp_mon_filter_show_filter)();
}
