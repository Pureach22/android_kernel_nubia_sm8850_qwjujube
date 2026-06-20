__int64 __fastcall populate_dot11f_wmm_params(__int64 result, __int64 a2, __int64 a3)
{
  _BYTE *v3; // x10
  char v4; // w9
  __int16 v5; // w10
  __int16 v6; // w10
  __int16 v7; // w11
  __int16 v8; // w10
  __int16 v9; // w10
  __int16 v10; // w10
  __int16 v11; // w11
  __int16 v12; // w11
  __int16 v13; // w10
  __int16 v14; // w10
  __int16 v15; // w10
  __int16 v16; // w10
  char v17; // w11
  __int16 v18; // w9
  __int16 v19; // w9
  __int16 v20; // w9
  __int16 v21; // w9
  __int16 v22; // w9
  __int16 v23; // w10
  __int16 v24; // w9
  __int16 v25; // w9
  __int16 v26; // w9
  __int16 v27; // w8

  *(_BYTE *)(a2 + 1) = 1;
  v3 = (_BYTE *)(result + 8896);
  if ( *(_DWORD *)(a3 + 88) == 1 )
    v3 = (_BYTE *)(a3 + 1936);
  v4 = *(_BYTE *)(a3 + 7156) & 0xF | (*v3 << 7);
  v5 = *(_WORD *)(a2 + 4);
  *(_BYTE *)(a2 + 2) = v4;
  v6 = v5 & 0xFFF0;
  v7 = *(_BYTE *)(a3 + 7116) & 0xF;
  if ( (*(_BYTE *)(a3 + 7116) & 0xE) == 0 )
    v7 = 2;
  v8 = v6 | v7;
  *(_WORD *)(a2 + 4) = v8;
  v9 = v8 & 0xFF8F | *(_BYTE *)(a3 + 7116) & 0x10;
  *(_WORD *)(a2 + 4) = v9;
  v10 = v9 & 0xF0FF | ((*(_BYTE *)(a3 + 7117) & 0xF) << 8);
  *(_WORD *)(a2 + 4) = v10;
  v11 = *(_WORD *)(a2 + 8);
  *(_WORD *)(a2 + 4) = v10 & 0xFFF | (*(unsigned __int8 *)(a3 + 7117) << 8) & 0xF000;
  v12 = v11 & 0xFFF0;
  *(_WORD *)(a2 + 6) = *(_WORD *)(a3 + 7118);
  if ( (*(_BYTE *)(a3 + 7121) & 0xE) != 0 )
    v13 = *(_BYTE *)(a3 + 7121) & 0xF;
  else
    v13 = 2;
  v14 = v12 | v13;
  *(_WORD *)(a2 + 8) = v14;
  v15 = *(_BYTE *)(a3 + 7121) & 0x10 | v14 & 0xFF8F | 0x20;
  *(_WORD *)(a2 + 8) = v15;
  v16 = v15 & 0xF0FF | ((*(_BYTE *)(a3 + 7122) & 0xF) << 8);
  *(_WORD *)(a2 + 8) = v16;
  *(_WORD *)(a2 + 8) = v16 & 0xFFF | (*(unsigned __int8 *)(a3 + 7122) << 8) & 0xF000;
  *(_WORD *)(a2 + 10) = *(_WORD *)(a3 + 7123);
  v17 = *(_BYTE *)(a3 + 7126);
  if ( *(_DWORD *)(a3 + 88) == 1 )
  {
    v18 = *(_WORD *)(a2 + 12) & 0xFFF0 | v17 & 0xF;
  }
  else
  {
    if ( (*(_BYTE *)(a3 + 7126) & 0xE) != 0 )
      v19 = v17 & 0xF;
    else
      v19 = 2;
    v18 = *(_WORD *)(a2 + 12) & 0xFFF0 | v19;
  }
  *(_WORD *)(a2 + 12) = v18;
  v20 = *(_BYTE *)(a3 + 7126) & 0x10 | v18 & 0xFF8F | 0x40;
  *(_WORD *)(a2 + 12) = v20;
  v21 = v20 & 0xF0FF | ((*(_BYTE *)(a3 + 7127) & 0xF) << 8);
  *(_WORD *)(a2 + 12) = v21;
  *(_WORD *)(a2 + 12) = v21 & 0xFFF | (*(unsigned __int8 *)(a3 + 7127) << 8) & 0xF000;
  *(_WORD *)(a2 + 14) = *(_WORD *)(a3 + 7128);
  v22 = *(_BYTE *)(a3 + 7131) & 0xF;
  if ( *(_DWORD *)(a3 + 88) == 1 )
  {
    v23 = *(_WORD *)(a2 + 16) & 0xFFF0;
  }
  else
  {
    if ( (*(_BYTE *)(a3 + 7131) & 0xE) == 0 )
      v22 = 2;
    v23 = *(_WORD *)(a2 + 16) & 0xFFF0;
  }
  v24 = v23 | v22;
  *(_WORD *)(a2 + 16) = v24;
  v25 = *(_BYTE *)(a3 + 7131) & 0x10 | v24 & 0xFF8F | 0x60;
  *(_WORD *)(a2 + 16) = v25;
  v26 = v25 & 0xF0FF | ((*(_BYTE *)(a3 + 7132) & 0xF) << 8);
  *(_WORD *)(a2 + 16) = v26;
  *(_WORD *)(a2 + 16) = (*(unsigned __int8 *)(a3 + 7132) << 8) & 0xF000 | v26 & 0xFFF;
  v27 = *(_WORD *)(a3 + 7133);
  *(_BYTE *)a2 = 1;
  *(_WORD *)(a2 + 18) = v27;
  return result;
}
