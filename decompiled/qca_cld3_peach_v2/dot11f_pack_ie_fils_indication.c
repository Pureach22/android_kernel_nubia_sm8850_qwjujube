__int64 __fastcall dot11f_pack_ie_fils_indication(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w20
  void *v7; // x19
  _BYTE *v8; // x21
  int v11; // w8
  __int16 v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    if ( (unsigned int)*(unsigned __int8 *)(a2 + 3) + 2 <= a4 )
    {
      v6 = *a5;
      *a3 = -16;
      v7 = a3 + 4;
      v8 = a3 + 1;
      *a5 += 2;
      v12 = *(_WORD *)(a2 + 1);
      qdf_mem_copy(a3 + 2, &v12, 2u);
      *a5 += 2;
      qdf_mem_copy(v7, (const void *)(a2 + 4), *(unsigned __int8 *)(a2 + 3));
      result = 0;
      v11 = *a5 + *(unsigned __int8 *)(a2 + 3);
      *a5 = v11;
      if ( v8 )
        *v8 = v11 - v6 - 2;
    }
    else
    {
      result = 268435461;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
