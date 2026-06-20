void __fastcall populate_dot11f_edca_param_set(__int64 a1, __int64 a2, __int64 a3)
{
  __int16 v3; // w11
  __int16 v4; // w10
  __int16 v5; // w10
  __int16 v6; // w10
  __int16 v7; // w10
  __int16 v8; // w11
  __int16 v9; // w11
  __int16 v10; // w10
  __int16 v11; // w10
  __int16 v12; // w10
  __int16 v13; // w10
  __int16 v14; // w11
  __int16 v15; // w11
  __int16 v16; // w10
  __int16 v17; // w10
  __int16 v18; // w10
  __int16 v19; // w10
  __int16 v20; // w11
  __int16 v21; // w9
  __int16 v22; // w9
  __int16 v23; // w9
  __int16 v24; // w9
  __int16 v25; // w8

  if ( (*(_BYTE *)(a3 + 7024) & 1) != 0 )
  {
    v3 = *(_WORD *)(a2 + 3) & 0xFFF0;
    *(_BYTE *)(a2 + 1) = 16 * *(_BYTE *)(a3 + 7156);
    v4 = *(_BYTE *)(a3 + 7116) & 0xF;
    if ( (*(_BYTE *)(a3 + 7116) & 0xE) == 0 )
      v4 = 2;
    v5 = v3 | v4;
    *(_WORD *)(a2 + 3) = v5;
    v6 = v5 & 0xFF8F | *(_BYTE *)(a3 + 7116) & 0x10;
    *(_WORD *)(a2 + 3) = v6;
    v7 = v6 & 0xF0FF | ((*(_BYTE *)(a3 + 7117) & 0xF) << 8);
    *(_WORD *)(a2 + 3) = v7;
    v8 = *(_WORD *)(a2 + 8);
    *(_WORD *)(a2 + 3) = v7 & 0xFFF | (*(unsigned __int8 *)(a3 + 7117) << 8) & 0xF000;
    v9 = v8 & 0xFFF0;
    *(_WORD *)(a2 + 6) = *(_WORD *)(a3 + 7118);
    v10 = *(_BYTE *)(a3 + 7121) & 0xF;
    if ( (*(_BYTE *)(a3 + 7121) & 0xE) == 0 )
      v10 = 2;
    v11 = v9 | v10;
    *(_WORD *)(a2 + 8) = v11;
    v12 = *(_BYTE *)(a3 + 7121) & 0x10 | v11 & 0xFF8F | 0x20;
    *(_WORD *)(a2 + 8) = v12;
    v13 = v12 & 0xF0FF | ((*(_BYTE *)(a3 + 7122) & 0xF) << 8);
    *(_WORD *)(a2 + 8) = v13;
    *(_WORD *)(a2 + 8) = v13 & 0xFFF | (*(unsigned __int8 *)(a3 + 7122) << 8) & 0xF000;
    v14 = *(_WORD *)(a2 + 12);
    *(_WORD *)(a2 + 10) = *(_WORD *)(a3 + 7123);
    v15 = v14 & 0xFFF0;
    v16 = *(_BYTE *)(a3 + 7126) & 0xF;
    if ( (*(_BYTE *)(a3 + 7126) & 0xE) == 0 )
      v16 = 2;
    v17 = v15 | v16;
    *(_WORD *)(a2 + 12) = v17;
    v18 = *(_BYTE *)(a3 + 7126) & 0x10 | v17 & 0xFF8F | 0x40;
    *(_WORD *)(a2 + 12) = v18;
    v19 = v18 & 0xF0FF | ((*(_BYTE *)(a3 + 7127) & 0xF) << 8);
    *(_WORD *)(a2 + 12) = v19;
    v20 = *(_WORD *)(a2 + 16);
    *(_WORD *)(a2 + 12) = v19 & 0xFFF | (*(unsigned __int8 *)(a3 + 7127) << 8) & 0xF000;
    *(_WORD *)(a2 + 14) = *(_WORD *)(a3 + 7128);
    if ( (*(_BYTE *)(a3 + 7131) & 0xE) != 0 )
      v21 = *(_BYTE *)(a3 + 7131) & 0xF;
    else
      v21 = 2;
    v22 = v20 & 0xFFF0 | v21;
    *(_WORD *)(a2 + 16) = v22;
    v23 = *(_BYTE *)(a3 + 7131) & 0x10 | v22 & 0xFF8F | 0x60;
    *(_WORD *)(a2 + 16) = v23;
    v24 = v23 & 0xF0FF | ((*(_BYTE *)(a3 + 7132) & 0xF) << 8);
    *(_WORD *)(a2 + 16) = v24;
    *(_WORD *)(a2 + 16) = (*(unsigned __int8 *)(a3 + 7132) << 8) & 0xF000 | v24 & 0xFFF;
    v25 = *(_WORD *)(a3 + 7133);
    *(_BYTE *)a2 = 1;
    *(_WORD *)(a2 + 18) = v25;
  }
}
