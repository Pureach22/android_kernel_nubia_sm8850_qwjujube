__int64 __fastcall dot11f_unpack_ie_ft_info(__int64 a1, __int64 a2, unsigned __int8 a3, __int64 a4, char a5)
{
  __int64 result; // x0
  __int64 v11; // x7
  __int64 v12; // [xsp+0h] [xbp-10h] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u
      || (WORD2(v12) = 0,
          qdf_mem_copy((char *)&v12 + 4, (const void *)a2, 2u),
          *(_WORD *)(a4 + 1) = WORD2(v12),
          (unsigned __int8)(a3 - 2) <= 0xFu)
      || (qdf_mem_copy((void *)(a4 + 3), (const void *)(a2 + 2), 0x10u), (unsigned __int8)(a3 - 18) <= 0x1Fu)
      || (qdf_mem_copy((void *)(a4 + 19), (const void *)(a2 + 18), 0x20u), (unsigned __int8)(a3 - 50) <= 0x1Fu) )
    {
      *(_BYTE *)a4 = 0;
      result = 4;
    }
    else
    {
      qdf_mem_copy((void *)(a4 + 51), (const void *)(a2 + 50), 0x20u);
      result = unpack_core(a1, a2 + 82, (unsigned __int8)(a3 - 82), &FFS_FTInfo, &IES_FTInfo, a4, a5 & 1, v11, v12, v13);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
