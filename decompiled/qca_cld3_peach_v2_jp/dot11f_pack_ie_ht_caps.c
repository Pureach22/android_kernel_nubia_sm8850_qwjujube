__int64 __fastcall dot11f_pack_ie_ht_caps(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  unsigned int v11; // w8
  unsigned __int64 v12; // t2
  int v13; // w8
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    if ( (unsigned int)*(unsigned __int8 *)(a2 + 27) + 26 <= a4 )
    {
      v6 = *a5;
      v7 = a3 + 1;
      *a3 = 45;
      *a5 += 2;
      LOWORD(v14) = *(_WORD *)(a2 + 1);
      qdf_mem_copy(a3 + 2, &v14, 2u);
      *a5 += 2;
      a3[4] = *(_BYTE *)(a2 + 3);
      ++*a5;
      qdf_mem_copy(a3 + 5, (const void *)(a2 + 4), 0x10u);
      *a5 += 16;
      LOWORD(v14) = *(_DWORD *)(a2 + 20);
      qdf_mem_copy(a3 + 21, &v14, 2u);
      *a5 += 2;
      v11 = *(unsigned __int16 *)(a2 + 24);
      HIDWORD(v12) = v11 & 7;
      LODWORD(v12) = *(_DWORD *)(a2 + 20);
      v14 = (v12 >> 16) & 0x7FFFF
          | (((v11 >> 3) & 3) << 19) & 0x1FFFFF
          | (((v11 >> 5) & 3) << 21) & 0x7FFFFF
          | (((v11 >> 7) & 3) << 23) & 0x1FFFFFF
          | ((unsigned __int8)(v11 >> 9) << 25);
      qdf_mem_copy(a3 + 23, &v14, 4u);
      *a5 += 4;
      a3[27] = *(_BYTE *)(a2 + 26);
      ++*a5;
      qdf_mem_copy(a3 + 28, (const void *)(a2 + 28), *(unsigned __int8 *)(a2 + 27));
      result = 0;
      v13 = *a5 + *(unsigned __int8 *)(a2 + 27);
      *a5 = v13;
      if ( v7 )
        *v7 = v13 - v6 - 2;
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
