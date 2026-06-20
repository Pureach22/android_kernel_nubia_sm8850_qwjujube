__int64 __fastcall dot11f_unpack_ie_vht_caps(__int64 a1, __int64 a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v8; // w8
  int v9; // w21
  __int16 v10; // w10
  int v11; // w9
  __int16 v12; // [xsp+Ch] [xbp-14h] BYREF
  _WORD v13[2]; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v14; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    *(_BYTE *)a4 = 1;
    if ( a3 <= 3u )
      goto LABEL_10;
    v14 = 0;
    v13[0] = 0;
    v12 = 0;
    qdf_mem_copy(&v14, (const void *)a2, 4u);
    v8 = v14;
    v9 = a3 & 0xFE;
    v10 = *(_WORD *)(a4 + 4);
    v11 = *(_BYTE *)(a4 + 3) & 0x80 | HIWORD(v14) & 0x7F;
    *(_WORD *)(a4 + 1) = v14;
    *(_BYTE *)(a4 + 3) = v11;
    *(_WORD *)(a4 + 4) = v10 & 0xFE00 | (v8 >> 23);
    if ( v9 == 4
      || (qdf_mem_copy((void *)(a4 + 6), (const void *)(a2 + 4), 2u), v9 == 6)
      || (qdf_mem_copy(v13, (const void *)(a2 + 6), 2u), *(_WORD *)(a4 + 8) = v13[0], v9 == 8)
      || (qdf_mem_copy((void *)(a4 + 10), (const void *)(a2 + 8), 2u), v9 == 10) )
    {
LABEL_10:
      *(_BYTE *)a4 = 0;
      result = 4;
    }
    else
    {
      qdf_mem_copy(&v12, (const void *)(a2 + 10), 2u);
      result = 0;
      *(_WORD *)(a4 + 12) = v12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
