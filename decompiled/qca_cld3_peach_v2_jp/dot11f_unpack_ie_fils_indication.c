__int64 __fastcall dot11f_unpack_ie_fils_indication(__int64 a1, __int64 a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  __int16 v8; // w8
  __int16 v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
      v9 = 0;
      qdf_mem_copy(&v9, (const void *)a2, 2u);
      v8 = v9;
      *(_BYTE *)(a4 + 3) = a3 - 2;
      *(_WORD *)(a4 + 1) = v8;
      qdf_mem_copy((void *)(a4 + 4), (const void *)(a2 + 2), (unsigned __int8)(a3 - 2));
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
