int *__fastcall dp_rx_mon_enable_fpmo(int *result, __int64 a2)
{
  int v2; // w8
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8
  int v9; // w8
  int v10; // w8
  int v11; // w8
  int v12; // w8
  int v13; // w8
  int v14; // w8
  int v15; // w8
  int v16; // w8
  int v17; // w8
  int v18; // w8
  int v19; // w8
  int v20; // w8
  int v21; // w8
  int v22; // w8
  int v23; // w8
  int v24; // w8
  int v25; // w8
  int v26; // w8
  int v27; // w8
  int v28; // w8
  int v29; // w8
  int v30; // w8
  int v31; // w8
  int v32; // w8
  unsigned int v33; // w8
  int v34; // w9

  if ( result && a2 )
  {
    if ( (*(_BYTE *)(a2 + 76) & 1) != 0 )
    {
      v2 = *result | *(_WORD *)(a2 + 80) & 1;
      *result = v2;
      v3 = v2 | *(_WORD *)(a2 + 80) & 2;
      *result = v3;
      v4 = v3 | *(_WORD *)(a2 + 80) & 4;
      *result = v4;
      v5 = v4 | *(_WORD *)(a2 + 80) & 8;
      *result = v5;
      v6 = v5 | *(_WORD *)(a2 + 80) & 0x10;
      *result = v6;
      v7 = v6 | *(_WORD *)(a2 + 80) & 0x20;
      *result = v7;
      v8 = v7 | *(_WORD *)(a2 + 80) & 0x40;
      *result = v8;
      v9 = v8 | *(_WORD *)(a2 + 80) & 0x80;
      *result = v9;
      v10 = v9 | *(_WORD *)(a2 + 80) & 0x100;
      *result = v10;
      v11 = v10 | *(_WORD *)(a2 + 80) & 0x200;
      *result = v11;
      v12 = v11 | *(_WORD *)(a2 + 80) & 0x400;
      *result = v12;
      v13 = v12 | *(_WORD *)(a2 + 80) & 0x800;
      *result = v13;
      v14 = v13 | *(_WORD *)(a2 + 80) & 0x1000;
      *result = v14;
      v15 = v14 | *(_WORD *)(a2 + 80) & 0x2000;
      *result = v15;
      v16 = v15 | *(_WORD *)(a2 + 80) & 0x4000;
      *result = v16;
      v17 = v16 | *(_WORD *)(a2 + 80) & 0x8000;
      *result = v17;
      v18 = v17 | ((*(_WORD *)(a2 + 82) & 1) << 16);
      *result = v18;
      v19 = v18 | (((*(unsigned __int16 *)(a2 + 82) >> 1) & 1) << 17);
      *result = v19;
      v20 = v19 | (((*(unsigned __int16 *)(a2 + 82) >> 2) & 1) << 18);
      *result = v20;
      v21 = v20 | (((*(unsigned __int16 *)(a2 + 82) >> 3) & 1) << 19);
      *result = v21;
      v22 = v21 | (((*(unsigned __int16 *)(a2 + 82) >> 4) & 1) << 20);
      *result = v22;
      v23 = v22 | (((*(unsigned __int16 *)(a2 + 82) >> 5) & 1) << 21);
      *result = v23;
      v24 = v23 | (((*(unsigned __int16 *)(a2 + 82) >> 6) & 1) << 22);
      *result = v24;
      v25 = v24 | (((*(unsigned __int16 *)(a2 + 82) >> 7) & 1) << 23);
      *result = v25;
      v26 = v25 | ((HIBYTE(*(unsigned __int16 *)(a2 + 82)) & 1) << 24);
      *result = v26;
      v27 = v26 | (((*(unsigned __int16 *)(a2 + 82) >> 9) & 1) << 25);
      *result = v27;
      v28 = v27 | (((*(unsigned __int16 *)(a2 + 82) >> 10) & 1) << 26);
      *result = v28;
      v29 = v28 | (((*(unsigned __int16 *)(a2 + 82) >> 11) & 1) << 27);
      *result = v29;
      v30 = v29 | (((*(unsigned __int16 *)(a2 + 82) >> 12) & 1) << 28);
      *result = v30;
      v31 = v30 | (((*(unsigned __int16 *)(a2 + 82) >> 13) & 1) << 29);
      *result = v31;
      v32 = v31 | (((*(unsigned __int16 *)(a2 + 82) >> 14) & 1) << 30);
      *result = v32;
      *result = v32 | (*(unsigned __int16 *)(a2 + 82) >> 15 << 31);
      result[1] = 0;
      v33 = *(unsigned __int16 *)(a2 + 78);
      result[1] = (v33 >> 14) & 1;
      v34 = (*(unsigned __int16 *)(a2 + 78) >> 14) & 2 | (v33 >> 14) & 1;
      result[1] = v34;
      result[1] = (*(unsigned __int16 *)(a2 + 78) >> 1) & 4 | v34;
    }
    else
    {
      result[1] = 0;
    }
  }
  return result;
}
