__int64 __fastcall _clk_rcg_set_rate(unsigned int *a1, __int64 a2)
{
  int v4; // w8
  int v5; // w9
  bool v6; // zf
  __int64 v7; // x8
  unsigned int v8; // w20
  __int64 v9; // x22
  char v10; // w9
  int v11; // w8
  __int64 v12; // x2
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x1
  char v16; // w9
  int v17; // w8
  __int64 v18; // x10
  int v19; // w11
  int v20; // w9
  int v21; // w9
  int v22; // w9
  char v23; // w9
  __int64 v24; // x10
  __int64 v25; // x0
  int v26; // w11
  unsigned int v27; // w9
  __int64 v28; // x1
  int v29; // w8
  char v30; // w10
  int v31; // w11
  __int64 v32; // x0
  __int64 v33; // x1
  __int64 result; // x0
  int v35; // [xsp+Ch] [xbp-14h] BYREF
  int v36; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v37; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+18h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((unsigned __int8 *)a1 + 14);
  v5 = *((unsigned __int8 *)a1 + 13);
  v37 = 0;
  v35 = 0;
  v36 = 0;
  v6 = v4 == 0;
  v7 = 20;
  if ( v6 )
    v7 = 0;
  v8 = a1[v7];
  if ( v5 )
  {
    v9 = 1LL << *((_BYTE *)a1 + 9);
    regmap_update_bits_base(*((_QWORD *)a1 + 9), v8, (unsigned int)v9, (unsigned int)v9, 0, 0, 0);
    regmap_read(*((_QWORD *)a1 + 9), a1[1], &v36);
    v10 = *((_BYTE *)a1 + 12);
    v11 = ~(-1 << *((_BYTE *)a1 + 13));
    v12 = v36 & ~(v11 << v10) & (unsigned int)(-1LL << *((_BYTE *)a1 + 13));
    if ( *(_WORD *)(a2 + 12) )
      v12 = v11 & ~*(unsigned __int16 *)(a2 + 12) | (*(unsigned __int16 *)(a2 + 10) << v10) | (unsigned int)v12;
    v13 = *((_QWORD *)a1 + 9);
    v14 = a1[1];
    v36 = v12;
    regmap_write(v13, v14, v12);
    regmap_read(*((_QWORD *)a1 + 9), *a1, &v37);
    v15 = a1[20];
    if ( (_DWORD)v15 == *a1 )
    {
      v16 = *((_BYTE *)a1 + 10);
      v17 = *(unsigned __int16 *)(a2 + 12);
      v18 = 1LL << *((_BYTE *)a1 + 8);
      v19 = (3 << v16) | v18;
      v20 = (2 << v16) | v18;
      if ( !*(_WORD *)(a2 + 12) )
        v20 = 0;
      v21 = v37 & ~v19 | v20;
    }
    else
    {
      regmap_read(*((_QWORD *)a1 + 9), v15, &v35);
      v23 = *((_BYTE *)a1 + 10);
      v24 = 1LL << *((_BYTE *)a1 + 8);
      v25 = *((_QWORD *)a1 + 9);
      v26 = (3 << v23) | v24;
      v27 = (2 << v23) | v24;
      v28 = a1[20];
      v29 = v35 & ~v26;
      if ( !*(_WORD *)(a2 + 12) )
        v27 = 0;
      v35 = v29 | v27;
      regmap_write(v25, v28, v29 | v27);
      v17 = *(unsigned __int16 *)(a2 + 12);
      v21 = v37;
    }
    v30 = *((_BYTE *)a1 + 11);
    v31 = ~(-1 << *((_BYTE *)a1 + 13));
    v22 = v21 & ~(v31 << v30);
    if ( v17 )
      v22 |= ((*(unsigned __int16 *)(a2 + 10) + ~v17) & v31) << v30;
  }
  else
  {
    regmap_read(*((_QWORD *)a1 + 9), *a1, &v37);
    v22 = v37;
    LODWORD(v9) = 0;
  }
  v32 = *((_QWORD *)a1 + 9);
  v33 = *a1;
  v37 = v22 & ~(~(unsigned int)(-1LL << *((_BYTE *)a1 + 16)) << *((_BYTE *)a1 + 15))
      | ((unsigned __int8)(*(_BYTE *)(a2 + 9) - 1) << *((_BYTE *)a1 + 15));
  regmap_write(v32, v33, v37);
  result = regmap_update_bits_base(*((_QWORD *)a1 + 9), v8, (unsigned int)v9, 0, 0, 0, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
