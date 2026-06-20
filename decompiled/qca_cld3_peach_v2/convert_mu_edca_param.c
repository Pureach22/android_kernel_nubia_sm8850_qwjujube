void *__fastcall convert_mu_edca_param(__int64 a1, __int64 a2, _BYTE *a3)
{
  void *result; // x0
  char v6; // w9
  char v7; // w9
  char v8; // w8
  char v9; // w9
  char v10; // w8
  char v11; // w9
  char v12; // w9
  char v13; // w9
  char v14; // w8
  char v15; // w9
  char v16; // w8
  char v17; // w9
  char v18; // w9
  char v19; // w9
  char v20; // w8
  char v21; // w9
  char v22; // w8
  char v23; // w9
  char v24; // w9
  char v25; // w9
  char v26; // w8
  char v27; // w9
  char v28; // w8

  result = qdf_mem_copy((void *)(a2 + 2), a3 + 1, 1u);
  v6 = *(_BYTE *)(a2 + 4) & 0xF0 | a3[2] & 0xF;
  *(_BYTE *)(a2 + 4) = v6;
  v7 = v6 & 0xEF | (16 * ((a3[2] & 0x10) != 0));
  *(_BYTE *)(a2 + 4) = v7;
  v8 = v7 & 0x9F | a3[2] & 0x60;
  v9 = *(_BYTE *)(a2 + 5);
  *(_BYTE *)(a2 + 4) = v8;
  v10 = a3[3];
  *(_BYTE *)(a2 + 5) = v9 & 0xF0 | v10 & 0xF;
  *(_BYTE *)(a2 + 5) = a3[3] & 0xF0 | v10 & 0xF;
  v11 = *(_BYTE *)(a2 + 9);
  *(_WORD *)(a2 + 6) = (unsigned __int8)a3[4];
  v12 = v11 & 0xF0 | a3[5] & 0xF;
  *(_BYTE *)(a2 + 9) = v12;
  v13 = v12 & 0xEF | (16 * ((a3[5] & 0x10) != 0));
  *(_BYTE *)(a2 + 9) = v13;
  v14 = v13 & 0x9F | a3[5] & 0x60;
  v15 = *(_BYTE *)(a2 + 10);
  *(_BYTE *)(a2 + 9) = v14;
  v16 = a3[6];
  *(_BYTE *)(a2 + 10) = v15 & 0xF0 | v16 & 0xF;
  *(_BYTE *)(a2 + 10) = a3[6] & 0xF0 | v16 & 0xF;
  v17 = *(_BYTE *)(a2 + 14);
  *(_WORD *)(a2 + 11) = (unsigned __int8)a3[7];
  v18 = v17 & 0xF0 | a3[8] & 0xF;
  *(_BYTE *)(a2 + 14) = v18;
  v19 = v18 & 0xEF | (16 * ((a3[8] & 0x10) != 0));
  *(_BYTE *)(a2 + 14) = v19;
  v20 = v19 & 0x9F | a3[8] & 0x60;
  v21 = *(_BYTE *)(a2 + 15);
  *(_BYTE *)(a2 + 14) = v20;
  v22 = a3[9];
  *(_BYTE *)(a2 + 15) = v21 & 0xF0 | v22 & 0xF;
  *(_BYTE *)(a2 + 15) = a3[9] & 0xF0 | v22 & 0xF;
  v23 = *(_BYTE *)(a2 + 19);
  *(_WORD *)(a2 + 16) = (unsigned __int8)a3[10];
  v24 = v23 & 0xF0 | a3[11] & 0xF;
  *(_BYTE *)(a2 + 19) = v24;
  v25 = v24 & 0xEF | (16 * ((a3[11] & 0x10) != 0));
  *(_BYTE *)(a2 + 19) = v25;
  v26 = v25 & 0x9F | a3[11] & 0x60;
  v27 = *(_BYTE *)(a2 + 20);
  *(_BYTE *)(a2 + 19) = v26;
  v28 = a3[12];
  *(_BYTE *)(a2 + 20) = v27 & 0xF0 | v28 & 0xF;
  *(_BYTE *)(a2 + 20) = a3[12] & 0xF0 | v28 & 0xF;
  *(_WORD *)(a2 + 21) = (unsigned __int8)a3[13];
  return result;
}
