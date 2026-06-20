__int64 __fastcall _sha256_import_common(__int64 result, _QWORD *a2, char a3)
{
  __int64 v3; // x8
  __int64 v4; // x10
  __int64 v5; // x12
  __int64 v6; // x13
  __int64 v7; // x9
  __int64 v8; // x14
  __int64 v9; // x15
  __int64 v10; // x16
  __int64 v11; // x10
  _BYTE *v12; // x12
  unsigned __int64 v13; // x9
  bool v14; // cf
  bool v15; // w9
  __int64 v16; // x10
  unsigned int v17; // w10
  _BYTE *v18; // x9
  _QWORD *v19; // x8
  unsigned int v20; // w11
  int v21; // t1
  int v22; // w11
  char v23; // w10
  char v24; // w11
  __int64 v25; // x13
  _BYTE *v26; // x12

  v3 = a2[4];
  *(_QWORD *)(result + 216) = v3;
  v4 = a2[6];
  v5 = a2[7];
  v6 = a2[8];
  *(_QWORD *)(result + 226) = a2[5];
  v8 = a2[11];
  v7 = a2[12];
  v9 = a2[9];
  v10 = a2[10];
  *(_QWORD *)(result + 242) = v5;
  *(_QWORD *)(result + 250) = v6;
  *(_QWORD *)(result + 234) = v4;
  v11 = v3 + 64;
  v12 = (_BYTE *)(result + 456);
  *(_QWORD *)(result + 274) = v8;
  *(_QWORD *)(result + 282) = v7;
  if ( (a3 & 1) == 0 )
    v11 = v3;
  *(_QWORD *)(result + 258) = v9;
  *(_QWORD *)(result + 266) = v10;
  v13 = a2[4];
  v14 = v13 >= 0x41;
  v15 = v13 < 0x41;
  if ( v14 )
    v3 = v11;
  v16 = *(_QWORD *)(result + 32);
  *(_BYTE *)(result + 224) = v15;
  *(_DWORD *)(result + 200) = v3 & 0xFFFFFFC0;
  *(_DWORD *)(result + 204) = HIDWORD(v3);
  v17 = *(_DWORD *)(v16 + 72);
  if ( v17 >= 4 )
  {
    v20 = v17 >> 2;
    v19 = a2;
    do
    {
      --v20;
      *v12 = *((_BYTE *)v19 + 3);
      v12[1] = *((_WORD *)v19 + 1);
      v12[2] = BYTE1(*(_DWORD *)v19);
      v18 = v12 + 4;
      v21 = *(_DWORD *)v19;
      v19 = (_QWORD *)((char *)v19 + 4);
      v12[3] = v21;
      v12 += 4;
    }
    while ( v20 );
  }
  else
  {
    v18 = (_BYTE *)(result + 456);
    v19 = a2;
  }
  v22 = v17 & 3;
  v23 = 24;
  switch ( v22 )
  {
    case 1:
      goto LABEL_16;
    case 2:
      v24 = 16;
      v25 = 1;
      v26 = v18;
      goto LABEL_15;
    case 3:
      v24 = 8;
      v25 = 2;
      *v18 = *((_BYTE *)v19 + 3);
      v26 = v18 + 1;
      v23 = 16;
LABEL_15:
      v18 += v25;
      *v26 = *(_DWORD *)v19 >> v23;
      v23 = v24;
LABEL_16:
      *v18 = *(_DWORD *)v19 >> v23;
      break;
  }
  *(_DWORD *)(result + 292) = a2[4] & 0x3F;
  return result;
}
