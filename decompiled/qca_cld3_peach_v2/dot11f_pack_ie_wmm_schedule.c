__int64 __fastcall dot11f_pack_ie_wmm_schedule(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
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
    if ( a4 >= 0xF )
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
      a3[6] = 9;
      ++*a5;
      a3[7] = *(_BYTE *)(a2 + 1);
      ++*a5;
      LOWORD(v12) = *(_WORD *)(a2 + 2);
      qdf_mem_copy(a3 + 8, &v12, 2u);
      *a5 += 2;
      v12 = *(_DWORD *)(a2 + 4);
      qdf_mem_copy(a3 + 10, &v12, 4u);
      *a5 += 4;
      v12 = *(_DWORD *)(a2 + 8);
      qdf_mem_copy(a3 + 14, &v12, 4u);
      *a5 += 4;
      LOWORD(v12) = *(_WORD *)(a2 + 12);
      qdf_mem_copy(a3 + 18, &v12, 2u);
      *a5 += 2;
      LOWORD(v12) = *(_WORD *)(a2 + 14);
      qdf_mem_copy(a3 + 20, &v12, 2u);
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
