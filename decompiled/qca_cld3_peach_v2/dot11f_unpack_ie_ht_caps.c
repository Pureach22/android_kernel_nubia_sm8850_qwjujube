__int64 __fastcall dot11f_unpack_ie_ht_caps(__int64 a1, _BYTE *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  int v5; // w22
  unsigned int v9; // w9
  char v10; // w8
  size_t v11; // x2
  unsigned int v12; // [xsp+Ch] [xbp-14h] BYREF
  _WORD v13[2]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v14; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    v5 = a3;
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u )
      goto LABEL_13;
    v14 = 0;
    v13[0] = 0;
    v12 = 0;
    qdf_mem_copy(&v14, a2, 2u);
    *(_WORD *)(a4 + 1) = v14;
    if ( v5 == 2 )
      goto LABEL_13;
    *(_BYTE *)(a4 + 3) = a2[2];
    if ( (unsigned __int8)(a3 - 3) <= 0xFu
      || (qdf_mem_copy((void *)(a4 + 4), a2 + 3, 0x10u), (unsigned __int8)(a3 - 19) <= 1u)
      || (qdf_mem_copy(v13, a2 + 19, 2u),
          *(_DWORD *)(a4 + 20) = v13[0] & 1
                               | (*(unsigned __int16 *)(a4 + 22) << 16)
                               | v13[0] & 0xFE
                               | v13[0] & 0x300
                               | v13[0] & 0xFC00,
          (unsigned __int8)(a3 - 21) <= 3u)
      || (qdf_mem_copy(&v12, a2 + 21, 4u),
          v9 = HIWORD(v12),
          *(_WORD *)(a4 + 22) = v12,
          *(_WORD *)(a4 + 24) = v9,
          a3 == 25) )
    {
LABEL_13:
      *(_BYTE *)a4 = 0;
      result = 4;
    }
    else
    {
      v10 = a2[25];
      v11 = (unsigned __int8)(a3 - 26);
      *(_BYTE *)(a4 + 27) = a3 - 26;
      *(_BYTE *)(a4 + 26) = v10;
      if ( (unsigned int)v11 < 0x21 )
      {
        qdf_mem_copy((void *)(a4 + 28), a2 + 26, v11);
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
