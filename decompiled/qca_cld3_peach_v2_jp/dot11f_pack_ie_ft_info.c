__int64 __fastcall dot11f_pack_ie_ft_info(__int64 a1, __int64 a2, char *a3, unsigned int a4, int *a5)
{
  int v7; // w24
  __int64 result; // x0
  unsigned int v12; // [xsp+0h] [xbp-10h] BYREF
  __int16 v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a2 )
    goto LABEL_6;
  v7 = *a5;
  v12 = 82;
  result = get_packed_size_core(a1, a2, (int *)&v12, IES_FTInfo);
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
    *a3 = 55;
    *a5 += 2;
    if ( (a4 & 0xFFFFFFFE) == 2 )
    {
      result = 4;
    }
    else
    {
      v13 = *(_WORD *)(a2 + 1);
      qdf_mem_copy(a3 + 2, &v13, 2u);
      *a5 += 2;
      qdf_mem_copy(a3 + 4, (const void *)(a2 + 3), 0x10u);
      *a5 += 16;
      qdf_mem_copy(a3 + 20, (const void *)(a2 + 19), 0x20u);
      *a5 += 32;
      qdf_mem_copy(a3 + 52, (const void *)(a2 + 51), 0x20u);
      *a5 += 32;
      result = pack_core(a1, a2, a3 + 84, a4 - 4, a5, (__int64)&FFS_FTInfo, IES_FTInfo);
      if ( a3 != (char *)-1LL )
        a3[1] = *(_BYTE *)a5 - v7 - 2;
    }
  }
  else
  {
    result = 268435461;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
