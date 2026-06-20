__int64 __fastcall dot11f_unpack_ie_schedule(__int64 a1, __int64 a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  int v5; // w21
  int v8; // w8
  int v9; // w21
  unsigned __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    v5 = a3;
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u )
      goto LABEL_10;
    v10 = 0;
    qdf_mem_copy(&v10, (const void *)a2, 2u);
    v8 = *(_WORD *)(a4 + 2) & 0xFE00 | (v10 >> 7);
    *(_BYTE *)(a4 + 1) = *(_BYTE *)(a4 + 1) & 0x80 | v10 & 0x7F;
    *(_WORD *)(a4 + 2) = v8;
    if ( (unsigned int)(v5 - 2) <= 3
      || (qdf_mem_copy((void *)(a4 + 4), (const void *)(a2 + 2), 4u), (unsigned int)(v5 - 6) <= 3)
      || (qdf_mem_copy((void *)(a4 + 8), (const void *)(a2 + 6), 4u), v9 = v5 & 0xFE, v9 == 10)
      || (qdf_mem_copy((void *)(a4 + 12), (const void *)(a2 + 10), 2u), v9 == 12) )
    {
LABEL_10:
      *(_BYTE *)a4 = 0;
      result = 4;
    }
    else
    {
      qdf_mem_copy((void *)(a4 + 14), (const void *)(a2 + 12), 2u);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
