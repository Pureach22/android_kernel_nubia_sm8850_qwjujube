__int64 __fastcall convert_to_drm_mode(_DWORD *a1, __int64 a2)
{
  __int16 v2; // w9
  __int16 v3; // w9
  __int16 v4; // w9
  __int16 v5; // w9
  __int16 v6; // w9
  __int16 v7; // w9
  int v8; // w8
  int v9; // w9

  *(_QWORD *)(a2 + 104) = 0;
  *(_QWORD *)(a2 + 112) = 0;
  *(_QWORD *)(a2 + 88) = 0;
  *(_QWORD *)(a2 + 96) = 0;
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)a2 = 0;
  v2 = *a1;
  *(_WORD *)(a2 + 4) = v2;
  v3 = a1[3] + v2;
  *(_WORD *)(a2 + 6) = v3;
  v4 = a1[4] + v3;
  *(_WORD *)(a2 + 8) = v4;
  *(_WORD *)(a2 + 10) = a1[2] + v4;
  *(_WORD *)(a2 + 12) = a1[10];
  v5 = a1[1];
  *(_WORD *)(a2 + 14) = v5;
  v6 = a1[7] + v5;
  *(_WORD *)(a2 + 16) = v6;
  v7 = a1[8] + v6;
  *(_WORD *)(a2 + 18) = v7;
  *(_WORD *)(a2 + 20) = a1[6] + v7;
  *(_DWORD *)a2 = a1[12];
  if ( a1[5] )
    v8 = 2;
  else
    v8 = 1;
  if ( a1[9] )
    v9 = 8;
  else
    v9 = 4;
  *(_DWORD *)(a2 + 24) = v9 | v8;
  *(_BYTE *)(a2 + 62) = 72;
  return drm_mode_set_name(a2);
}
