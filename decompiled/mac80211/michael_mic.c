_DWORD *__fastcall michael_mic(_DWORD *result, _WORD *a2, int *a3, unsigned __int64 a4, _DWORD *a5)
{
  int v5; // w10
  __int64 v6; // x8
  int v7; // w8
  __int64 v8; // x12
  bool v9; // zf
  __int64 v10; // x10
  __int64 v11; // x9
  unsigned __int16 *v12; // x10
  _WORD *v13; // x9
  int v14; // w11
  int v15; // w12
  unsigned int v16; // w11
  int v17; // w12
  unsigned int v18; // w11
  int v19; // w12
  unsigned int v20; // w11
  int v21; // w12
  int v22; // w11
  int v23; // w11
  unsigned __int64 v24; // x12
  int v25; // w11
  int v26; // w11
  int v27; // w8
  unsigned int v28; // w8
  unsigned int v29; // w8
  int v30; // w10
  int v31; // w11
  unsigned __int64 v32; // x13
  int *v33; // x14
  int v34; // t1
  int v35; // w11
  int v36; // w10
  unsigned int v37; // w11
  unsigned int v38; // w10
  unsigned int v39; // w11
  int v40; // w10
  unsigned int v41; // w11
  char *v42; // x14
  int v43; // w13
  int v44; // w11
  int v45; // w10
  unsigned int v46; // w11
  unsigned int v47; // w10
  unsigned int v48; // w11
  int v49; // w10
  unsigned int v50; // w11
  int v51; // w10
  unsigned int v52; // w11
  int v53; // w10
  unsigned int v54; // w11
  unsigned int v55; // w8
  unsigned int v56; // w9
  int v57; // w8
  unsigned int v58; // w9
  int v59; // w8

  v5 = *a2 & 0x300;
  if ( (*a2 & 0x8C) == 0x88 )
  {
    v6 = 12;
    if ( v5 == 768 )
      v6 = 15;
    v7 = a2[v6] & 0xF;
  }
  else
  {
    v7 = 0;
  }
  v8 = 10;
  if ( (*a2 & 0x200) != 0 )
    v8 = 16;
  v9 = v5 == 768;
  v10 = 24;
  if ( !v9 )
    v10 = v8;
  v11 = 2;
  if ( (*a2 & 0x100) != 0 )
    v11 = 8;
  v12 = (_WORD *)((char *)a2 + v10);
  v13 = &a2[v11];
  v14 = *(_DWORD *)v13 ^ *result;
  v15 = result[1] ^ __ROR4__(v14, 15);
  v16 = v15 + v14;
  v17 = v15 ^ __ROR4__(bswap32(v16), 16);
  v18 = v17 + v16;
  v19 = v17 ^ __ROR4__(v18, 29);
  v20 = v19 + v18;
  v21 = v19 ^ __ROR4__(v20, 2);
  LODWORD(v13) = (v21 + v20) ^ ((unsigned __int16)v13[2] | (*v12 << 16));
  v22 = v21 ^ __ROR4__((_DWORD)v13, 15);
  LODWORD(v13) = v22 + (_DWORD)v13;
  v23 = v22 ^ __ROR4__(bswap32((unsigned int)v13), 16);
  v24 = a4 & 3;
  LODWORD(v13) = v23 + (_DWORD)v13;
  v25 = v23 ^ __ROR4__((_DWORD)v13, 29);
  LODWORD(v13) = v25 + (_DWORD)v13;
  v26 = v25 ^ __ROR4__((_DWORD)v13, 2);
  LODWORD(v13) = (v26 + (_DWORD)v13) ^ *(_DWORD *)(v12 + 1);
  LODWORD(v12) = v26 ^ __ROR4__((_DWORD)v13, 15);
  LODWORD(v13) = (_DWORD)v12 + (_DWORD)v13;
  LODWORD(v12) = (unsigned int)v12 ^ __ROR4__(bswap32((unsigned int)v13), 16);
  LODWORD(v13) = (_DWORD)v12 + (_DWORD)v13;
  LODWORD(v12) = (unsigned int)v12 ^ __ROR4__((_DWORD)v13, 29);
  LODWORD(v13) = (_DWORD)v12 + (_DWORD)v13;
  LODWORD(v12) = (unsigned int)v12 ^ __ROR4__((_DWORD)v13, 2);
  v27 = ((_DWORD)v12 + (_DWORD)v13) ^ v7;
  LODWORD(v13) = (unsigned int)v12 ^ __ROR4__(v27, 15);
  v28 = (_DWORD)v13 + v27;
  LODWORD(v13) = (unsigned int)v13 ^ __ROR4__(bswap32(v28), 16);
  v29 = (_DWORD)v13 + v28;
  LODWORD(v13) = (unsigned int)v13 ^ __ROR4__(v29, 29);
  v30 = (unsigned int)v13 ^ __ROR4__((_DWORD)v13 + v29, 2);
  v31 = v30 + (_DWORD)v13 + v29;
  if ( a4 >= 4 )
  {
    v32 = a4 >> 2;
    v33 = a3;
    do
    {
      v34 = *v33++;
      --v32;
      v35 = v34 ^ v31;
      v36 = v30 ^ __ROR4__(v35, 15);
      v37 = v36 + v35;
      v38 = ((v37 >> 8) & 0xFF00FF | (v37 << 8) & 0xFF00FF00) ^ v36;
      v39 = v38 + v37;
      v40 = v38 ^ __ROR4__(v39, 29);
      v41 = v40 + v39;
      v30 = v40 ^ __ROR4__(v41, 2);
      v31 = v30 + v41;
    }
    while ( v32 );
  }
  if ( (a4 & 3) != 0 )
  {
    v42 = (char *)a3 + (a4 & 0xFFFFFFFFFFFFFFFCLL);
    v43 = (unsigned __int8)v42[v24 - 1] | 0x5A00;
    if ( v24 != 1 )
    {
      v43 = (unsigned __int8)v42[v24 - 2] | (v43 << 8);
      if ( v24 != 2 )
        v43 = (unsigned __int8)v42[v24 - 3] | (v43 << 8);
    }
  }
  else
  {
    v43 = 90;
  }
  v44 = v43 ^ v31;
  v45 = v30 ^ __ROR4__(v44, 15);
  v46 = v45 + v44;
  v47 = ((v46 >> 8) & 0xFF00FF | (v46 << 8) & 0xFF00FF00) ^ v45;
  v48 = v47 + v46;
  v49 = v47 ^ __ROR4__(v48, 29);
  v50 = v49 + v48;
  v51 = v49 ^ __ROR4__(v50, 2);
  v52 = v51 + v50;
  v53 = v51 ^ __ROR4__(v52, 15);
  v54 = v53 + v52;
  v55 = ((v54 >> 8) & 0xFF00FF | (v54 << 8) & 0xFF00FF00) ^ v53;
  v56 = v55 + v54;
  v57 = v55 ^ __ROR4__(v55 + v54, 29);
  v58 = v57 + v56;
  v59 = v57 ^ __ROR4__(v58, 2);
  *a5 = v59 + v58;
  a5[1] = v59;
  return result;
}
