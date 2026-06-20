__int64 __fastcall dot11f_pack_ie_hs20vendor_ie(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  unsigned int v5; // w8
  __int64 result; // x0
  int v7; // w19
  _BYTE *v8; // x20
  int v9; // w8
  int v10; // w9
  __int16 v11; // w8
  int *v12; // x21
  void *v13; // x0
  __int16 *v14; // x1
  __int16 v15; // w8
  __int16 v16; // [xsp+0h] [xbp-10h] BYREF
  __int16 v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a2 )
  {
    result = 0;
    goto LABEL_15;
  }
  if ( ((*(unsigned __int8 *)(a2 + 1) >> 1) & 3u) - 1 >= 2 )
    v5 = 1;
  else
    v5 = 3;
  if ( v5 > a4 )
  {
    result = 268435461;
    goto LABEL_15;
  }
  v7 = *a5;
  *a3 = -35;
  v8 = a3 + 1;
  *a5 += 2;
  a3[2] = 80;
  ++*a5;
  a3[3] = 111;
  ++*a5;
  a3[4] = -102;
  ++*a5;
  a3[5] = 16;
  ++*a5;
  a3[6] = *(_BYTE *)(a2 + 1);
  v9 = *a5 + 1;
  *a5 = v9;
  v10 = (*(unsigned __int8 *)(a2 + 1) >> 1) & 3;
  if ( v10 == 2 )
  {
    v15 = *(_WORD *)(a2 + 2);
    v12 = a5;
    v13 = a3 + 7;
    v14 = &v17;
    v17 = v15;
  }
  else
  {
    if ( v10 != 1 )
      goto LABEL_13;
    v11 = *(_WORD *)(a2 + 2);
    v12 = a5;
    v13 = a3 + 7;
    v14 = &v16;
    v16 = v11;
  }
  qdf_mem_copy(v13, v14, 2u);
  v9 = *v12 + 2;
  *v12 = v9;
LABEL_13:
  result = 0;
  if ( v8 )
    *v8 = v9 - v7 - 2;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
