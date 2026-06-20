__int64 __fastcall dot11f_unpack_ie_he_6ghz_band_cap(__int64 a1, const void *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  int v6; // w8
  unsigned __int16 v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u )
    {
      *(_BYTE *)a4 = 0;
      result = 4;
    }
    else
    {
      v7 = 0;
      qdf_mem_copy(&v7, a2, 2u);
      result = 0;
      v6 = *(_BYTE *)(a4 + 3) & 0xFC | (v7 >> 14);
      *(_WORD *)(a4 + 1) = *(_WORD *)(a4 + 1) & 0xC0 | v7 & 0x3F | ((unsigned __int8)(v7 >> 6) << 8);
      *(_BYTE *)(a4 + 3) = v6;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
