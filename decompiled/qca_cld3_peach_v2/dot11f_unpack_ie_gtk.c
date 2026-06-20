__int64 __fastcall dot11f_unpack_ie_gtk(__int64 a1, _BYTE *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  int v5; // w22
  int v9; // w8
  size_t v10; // x2
  unsigned __int16 v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    v5 = a3;
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u
      || (v11 = 0,
          qdf_mem_copy(&v11, a2, 2u),
          v9 = *(_WORD *)(a4 + 2) & 0xC000 | (v11 >> 2) & 0x3FEB,
          *(_BYTE *)(a4 + 1) = *(_BYTE *)(a4 + 1) & 0xFC | v11 & 3,
          *(_WORD *)(a4 + 2) = v9,
          v5 == 2)
      || (*(_BYTE *)(a4 + 4) = a2[2], (unsigned __int8)(a3 - 3) <= 7u) )
    {
      *(_BYTE *)a4 = 0;
      result = 4;
    }
    else
    {
      qdf_mem_copy((void *)(a4 + 5), a2 + 3, 8u);
      v10 = (unsigned __int8)(a3 - 11);
      *(_BYTE *)(a4 + 13) = a3 - 11;
      if ( (unsigned int)v10 < 0x21 )
      {
        qdf_mem_copy((void *)(a4 + 14), a2 + 11, v10);
        result = 0;
      }
      else
      {
        *(_BYTE *)a4 = 0;
        result = 8;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
