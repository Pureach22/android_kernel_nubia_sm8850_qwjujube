__int64 __fastcall dot11f_pack_ie_vht_caps(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w20
  void *v7; // x19
  _BYTE *v8; // x21
  unsigned int v12; // w8
  unsigned int v13; // w12
  int v14; // w8
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    if ( a4 >= 0xC )
    {
      v6 = *a5;
      *a3 = -65;
      v7 = a3 + 12;
      v8 = a3 + 1;
      *a5 += 2;
      v12 = *(unsigned __int8 *)(a2 + 3);
      v13 = *(unsigned __int16 *)(a2 + 4);
      v15 = *(unsigned __int16 *)(a2 + 1)
          | ((v12 & 7) << 16) & 0x3FC7FFFF
          | (((v12 >> 3) & 1) << 19) & 0x3FCFFFFF
          | (((v12 >> 4) & 1) << 20) & 0x3FDFFFFF
          | (((v12 >> 5) & 1) << 21) & 0x3FFFFFFF
          | ((unsigned __int8)(v13 >> 7) << 30)
          | (((v12 >> 6) & 1) << 22) & 0xC07FFFFF
          | ((v13 & 7) << 23) & 0xC3FFFFFF
          | (((v13 >> 3) & 3) << 26) & 0xCFFFFFFF
          | (((v13 >> 5) & 1) << 28) & 0xDFFFFFFF
          | (((v13 >> 6) & 1) << 29);
      qdf_mem_copy(a3 + 2, &v15, 4u);
      *a5 += 4;
      LOWORD(v15) = *(_WORD *)(a2 + 6);
      qdf_mem_copy(a3 + 6, &v15, 2u);
      *a5 += 2;
      LOWORD(v15) = *(_WORD *)(a2 + 8);
      qdf_mem_copy(a3 + 8, &v15, 2u);
      *a5 += 2;
      LOWORD(v15) = *(_WORD *)(a2 + 10);
      qdf_mem_copy(a3 + 10, &v15, 2u);
      *a5 += 2;
      LOWORD(v15) = *(_WORD *)(a2 + 12);
      qdf_mem_copy(v7, &v15, 2u);
      result = 0;
      v14 = *a5 + 2;
      *a5 = v14;
      if ( v8 )
        *v8 = v14 - v6 - 2;
    }
    else
    {
      result = 268435461;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
