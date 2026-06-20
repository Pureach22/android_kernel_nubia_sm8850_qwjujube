__int64 __fastcall dot11f_unpack_ie_ht_info(__int64 a1, _BYTE *a2, char a3, __int64 a4)
{
  __int64 result; // x0
  size_t v8; // x2
  _WORD v9[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    *(_BYTE *)a4 = 1;
    if ( !a3 )
      goto LABEL_12;
    *(_BYTE *)(a4 + 1) = *a2;
    if ( a3 == 1
      || (*(_DWORD *)(a4 + 2) = *(_DWORD *)(a4 + 2) & 0xFFFFFF00 | a2[1] & 3 | a2[1] & 0xC | a2[1] & 0x10 | a2[1] & 0xE0,
          (a3 & 0xFE) == 2)
      || (v10 = 0,
          v9[0] = 0,
          qdf_mem_copy(&v10, a2 + 2, 2u),
          *(_DWORD *)(a4 + 2) = *(_DWORD *)(a4 + 2) & 0xF800E0FF
                              | ((v10 & 3) << 8) & 0xE3FF
                              | (((v10 >> 2) & 1) << 10) & 0xF800E7FF
                              | (((v10 >> 3) & 1) << 11) & 0xF800EFFF
                              | (((v10 >> 4) & 1) << 12) & 0xF800FFFF
                              | ((unsigned __int8)(v10 >> 5) << 16) & 0xF8FFFFFF
                              | (v10 >> 13 << 24),
          (a3 & 0xFE) == 4)
      || (qdf_mem_copy(v9, a2 + 4, 2u), *(_WORD *)(a4 + 6) = v9[0], (unsigned __int8)(a3 - 6) <= 0xFu) )
    {
LABEL_12:
      *(_BYTE *)a4 = 0;
      result = 4;
    }
    else
    {
      qdf_mem_copy((void *)(a4 + 8), a2 + 6, 0x10u);
      v8 = (unsigned __int8)(a3 - 22);
      *(_BYTE *)(a4 + 24) = a3 - 22;
      if ( (unsigned int)v8 < 0x21 )
      {
        qdf_mem_copy((void *)(a4 + 25), a2 + 22, v8);
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
