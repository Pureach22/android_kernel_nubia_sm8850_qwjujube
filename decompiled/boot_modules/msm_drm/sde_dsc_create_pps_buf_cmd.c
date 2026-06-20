__int64 __fastcall sde_dsc_create_pps_buf_cmd(__int64 a1, char *s, char a3, size_t n)
{
  char v8; // w8
  char v9; // w9
  __int16 v10; // w9
  __int64 v11; // x8
  char v12; // w10
  char v13; // w11
  char *v14; // x9
  _BYTE *v15; // x11
  char v16; // w11
  char v17; // w8

  if ( (unsigned int)n < 0x80 )
    return 4294967274LL;
  memset(s, 0, (unsigned int)n);
  v8 = *(_BYTE *)(a1 + 126);
  v9 = *(_BYTE *)(a1 + 127);
  s[1] = a3;
  *s = v8 | (16 * v9);
  s[3] = *(_BYTE *)a1 & 0xF | (16 * *(_BYTE *)(a1 + 1));
  v10 = *(_WORD *)(a1 + 16);
  if ( (*(_BYTE *)(a1 + 128) & 1) != 0 || *(_BYTE *)(a1 + 129) == 1 )
    v10 *= 2;
  v11 = 0;
  v12 = (32 * *(_BYTE *)(a1 + 26)) | HIBYTE(v10) & 3 | (16 * *(_BYTE *)(a1 + 2)) | (8 * *(_BYTE *)(a1 + 8));
  v13 = *(_BYTE *)(a1 + 120);
  s[5] = v10;
  s[4] = v12 | (4 * v13);
  s[6] = *(_BYTE *)(a1 + 13);
  s[7] = *(_BYTE *)(a1 + 12);
  s[8] = *(_BYTE *)(a1 + 11);
  s[9] = *(_BYTE *)(a1 + 10);
  s[10] = *(_BYTE *)(a1 + 7);
  s[11] = *(_BYTE *)(a1 + 6);
  s[12] = *(_BYTE *)(a1 + 5);
  s[13] = *(_BYTE *)(a1 + 4);
  s[14] = *(_BYTE *)(a1 + 123);
  s[15] = *(_BYTE *)(a1 + 122);
  s[16] = *(_BYTE *)(a1 + 23) & 3;
  s[17] = *(_BYTE *)(a1 + 22);
  s[18] = *(_BYTE *)(a1 + 25);
  s[19] = *(_BYTE *)(a1 + 24);
  s[21] = *(_BYTE *)(a1 + 108) & 0x3F;
  s[22] = *(_BYTE *)(a1 + 113);
  s[23] = *(_BYTE *)(a1 + 112);
  s[24] = *(_BYTE *)(a1 + 111) & 0xF;
  s[25] = *(_BYTE *)(a1 + 110);
  s[27] = *(_BYTE *)(a1 + 27) & 0x1F;
  s[28] = *(_BYTE *)(a1 + 115);
  s[29] = *(_BYTE *)(a1 + 114);
  s[30] = *(_BYTE *)(a1 + 117);
  s[31] = *(_BYTE *)(a1 + 116);
  s[32] = *(_BYTE *)(a1 + 29);
  s[33] = *(_BYTE *)(a1 + 28);
  s[34] = *(_BYTE *)(a1 + 119);
  s[35] = *(_BYTE *)(a1 + 118);
  s[36] = *(_BYTE *)(a1 + 106) & 0x1F;
  s[37] = *(_BYTE *)(a1 + 107) & 0x1F;
  s[38] = *(_BYTE *)(a1 + 105);
  s[39] = *(_BYTE *)(a1 + 104);
  s[40] = *(_BYTE *)(a1 + 18) & 0xF;
  s[41] = *(_BYTE *)(a1 + 20) & 0x1F;
  s[42] = *(_BYTE *)(a1 + 19) & 0x1F;
  s[43] = *(_BYTE *)(a1 + 15) & 0xF | (16 * *(_BYTE *)(a1 + 14));
  s[44] = *(_BYTE *)(a1 + 30);
  s[45] = *(_BYTE *)(a1 + 32);
  s[46] = *(_BYTE *)(a1 + 34);
  s[47] = *(_BYTE *)(a1 + 36);
  s[48] = *(_BYTE *)(a1 + 38);
  s[49] = *(_BYTE *)(a1 + 40);
  s[50] = *(_BYTE *)(a1 + 42);
  s[51] = *(_BYTE *)(a1 + 44);
  s[52] = *(_BYTE *)(a1 + 46);
  s[53] = *(_BYTE *)(a1 + 48);
  s[54] = *(_BYTE *)(a1 + 50);
  s[55] = *(_BYTE *)(a1 + 52);
  s[56] = *(_BYTE *)(a1 + 54);
  v14 = s + 58;
  s[57] = *(_BYTE *)(a1 + 56);
  do
  {
    v15 = (_BYTE *)(a1 + 58 + v11);
    v11 += 3;
    *v14 = (8 * *v15) | (v15[1] >> 2) & 7;
    v16 = v15[2] & 0x3F | (v15[1] << 6);
    v14[1] = v16;
    v14 += 2;
  }
  while ( v11 != 45 );
  if ( *(_BYTE *)(a1 + 126) != 2 )
    return 0;
  if ( (*(_BYTE *)(a1 + 128) & 1) != 0 )
  {
    v17 = 1;
  }
  else if ( *(_BYTE *)(a1 + 129) )
  {
    v17 = 2;
  }
  else
  {
    v17 = v16;
  }
  *v14 = v17;
  v14[1] = *(_BYTE *)(a1 + 130);
  v14[2] = *(_BYTE *)(a1 + 133);
  v14[3] = *(_BYTE *)(a1 + 132);
  v14[4] = *(_BYTE *)(a1 + 135);
  v14[5] = *(_BYTE *)(a1 + 134);
  return 0;
}
