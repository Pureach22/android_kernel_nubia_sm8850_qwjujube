__int64 __fastcall dot11f_pack_ie_neighbor_rpt(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
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
  v12 = 13;
  result = get_packed_size_core(a1, a2, (int *)&v12, IES_neighbor_rpt);
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
    *a3 = 52;
    *a5 += 2;
    qdf_mem_copy(a3 + 2, (const void *)(a2 + 1), 6u);
    *a5 += 6;
    if ( a4 == 2 || (a3[8] = *(_BYTE *)(a2 + 7), ++*a5, a4 == 3) )
    {
      result = 4;
    }
    else
    {
      a3[9] = *(_BYTE *)(a2 + 8);
      ++*a5;
      v13 = *(_WORD *)(a2 + 10);
      qdf_mem_copy(a3 + 10, &v13, 2u);
      *a5 += 2;
      a3[12] = *(_BYTE *)(a2 + 12);
      ++*a5;
      a3[13] = *(_BYTE *)(a2 + 13);
      ++*a5;
      a3[14] = *(_BYTE *)(a2 + 14);
      ++*a5;
      result = pack_core(a1, a2, a3 + 15, a4 - 4, a5, &FFS_neighbor_rpt, IES_neighbor_rpt);
      if ( a3 != (_BYTE *)-1LL )
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
