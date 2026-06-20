__int64 __fastcall dot11f_pack_ie_descriptor_element(__int64 a1, __int64 a2, char *a3, unsigned int a4, int *a5)
{
  int v7; // w24
  __int64 result; // x0
  unsigned int v12; // [xsp+0h] [xbp-10h] BYREF
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a2 )
    goto LABEL_6;
  v7 = *a5;
  v12 = 7;
  result = get_packed_size_core(a1, a2, (int *)&v12, IES_descriptor_element);
  if ( (_DWORD)result )
    goto LABEL_7;
  if ( !*(_BYTE *)a2 )
  {
LABEL_6:
    result = 0;
    goto LABEL_7;
  }
  if ( v12 <= a4 )
  {
    *a3 = -1;
    *a5 += 2;
    a3[2] = 88;
    ++*a5;
    a3[3] = *(_BYTE *)(a2 + 1);
    ++*a5;
    LOWORD(v13) = *(_WORD *)(a2 + 2);
    qdf_mem_copy(a3 + 4, &v13, 2u);
    *a5 += 2;
    v13 = *(_DWORD *)(a2 + 4);
    qdf_mem_copy(a3 + 6, &v13, 4u);
    *a5 += 4;
    result = pack_core(a1, a2, a3 + 10, a4 - 3, a5, (__int64)&FFS_descriptor_element, IES_descriptor_element);
    if ( a3 != (char *)-1LL )
      a3[1] = *(_BYTE *)a5 - v7 - 2;
  }
  else
  {
    result = 268435461;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
