__int64 __fastcall dot11f_pack_ie_wmmtspec(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v11; // w8
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    if ( a4 >= 0x26 )
    {
      v6 = *a5;
      *a3 = -35;
      v7 = a3 + 1;
      *a5 += 2;
      a3[2] = 0;
      ++*a5;
      a3[3] = 80;
      ++*a5;
      a3[4] = -14;
      ++*a5;
      a3[5] = 2;
      ++*a5;
      a3[6] = 2;
      ++*a5;
      a3[7] = *(_BYTE *)(a2 + 1);
      ++*a5;
      LOWORD(v12) = *(_DWORD *)(a2 + 2);
      qdf_mem_copy(a3 + 8, &v12, 2u);
      *a5 += 2;
      a3[10] = *(_WORD *)(a2 + 4);
      ++*a5;
      LOWORD(v12) = *(_WORD *)(a2 + 6);
      qdf_mem_copy(a3 + 11, &v12, 2u);
      *a5 += 2;
      LOWORD(v12) = *(_WORD *)(a2 + 8);
      qdf_mem_copy(a3 + 13, &v12, 2u);
      *a5 += 2;
      v12 = *(_DWORD *)(a2 + 12);
      qdf_mem_copy(a3 + 15, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 16);
      qdf_mem_copy(a3 + 19, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 20);
      qdf_mem_copy(a3 + 23, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 24);
      qdf_mem_copy(a3 + 27, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 28);
      qdf_mem_copy(a3 + 31, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 32);
      qdf_mem_copy(a3 + 35, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 36);
      qdf_mem_copy(a3 + 39, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 40);
      qdf_mem_copy(a3 + 43, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 44);
      qdf_mem_copy(a3 + 47, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 48);
      qdf_mem_copy(a3 + 51, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 52);
      qdf_mem_copy(a3 + 55, &v12, 4u);
      *a5 += 4;
      LOWORD(v12) = *(_WORD *)(a2 + 56);
      qdf_mem_copy(a3 + 59, &v12, 2u);
      *a5 += 2;
      LOWORD(v12) = *(_WORD *)(a2 + 58);
      qdf_mem_copy(a3 + 61, &v12, 2u);
      result = 0;
      v11 = *a5 + 2;
      *a5 = v11;
      if ( v7 )
        *v7 = v11 - v6 - 2;
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
