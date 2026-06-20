__int64 __fastcall dot11f_pack_ie_eht_op(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
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
    if ( (*(_DWORD *)(a2 + 1) & 2 | 8u) <= a4 )
    {
      v6 = *a5;
      *a3 = -1;
      v7 = a3 + 1;
      *a5 += 2;
      a3[2] = 106;
      ++*a5;
      a3[3] = *(_DWORD *)(a2 + 1);
      ++*a5;
      v12 = (__PAIR64__(*(_WORD *)(a2 + 5) & 0xF, *(_DWORD *)(a2 + 1)) >> 8) & 0xFFFFFFF
          | ((unsigned __int8)(*(unsigned __int16 *)(a2 + 5) >> 4) << 28);
      qdf_mem_copy(a3 + 4, &v12, 4u);
      *a5 += 4;
      a3[8] = *(_BYTE *)(a2 + 6);
      ++*a5;
      a3[9] = *(_BYTE *)(a2 + 7);
      ++*a5;
      a3[10] = *(_BYTE *)(a2 + 8);
      ++*a5;
      qdf_mem_copy(a3 + 11, (const void *)(a2 + 9), *(_DWORD *)(a2 + 1) & 2);
      result = 0;
      v11 = *a5 + (*(_DWORD *)(a2 + 1) & 2);
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
