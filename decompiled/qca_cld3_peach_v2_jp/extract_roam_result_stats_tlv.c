__int64 __fastcall extract_roam_result_stats_tlv(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  __int64 v4; // x8
  __int64 v5; // x8
  int v6; // w9
  unsigned __int16 v7; // w9
  int v8; // w9

  if ( !a2 )
    return 16;
  v4 = *(_QWORD *)(a2 + 80);
  if ( !v4 || *(_DWORD *)(a2 + 88) <= (unsigned int)a4 )
    return 16;
  v5 = v4 + 28LL * a4;
  *(_BYTE *)a3 = 1;
  *(_DWORD *)(a3 + 8) = *(_DWORD *)(v5 + 8);
  *(_DWORD *)(a3 + 4) = *(_DWORD *)(v5 + 4);
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(v5 + 24);
  v6 = *(_DWORD *)(v5 + 12);
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 > 0x26u )
      v8 = 255;
    else
      v8 = dword_9E7024[v7];
    *(_DWORD *)(a3 + 12) = v8;
  }
  *(_WORD *)(a3 + 20) = *(_DWORD *)(v5 + 16);
  *(_BYTE *)(a3 + 22) = *(_WORD *)(v5 + 18);
  *(_BYTE *)(a3 + 23) = *(_BYTE *)(v5 + 19);
  *(_WORD *)(a3 + 24) = *(_DWORD *)(v5 + 20);
  return 0;
}
