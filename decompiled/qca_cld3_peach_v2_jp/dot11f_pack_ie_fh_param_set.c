__int64 __fastcall dot11f_pack_ie_fh_param_set(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v11; // w8
  __int16 v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    if ( a4 >= 5 )
    {
      v6 = *a5;
      v7 = a3 + 1;
      *a3 = 2;
      *a5 += 2;
      v12 = *(_WORD *)(a2 + 2);
      qdf_mem_copy(a3 + 2, &v12, 2u);
      result = 0;
      *a5 += 2;
      a3[4] = *(_BYTE *)(a2 + 4);
      ++*a5;
      a3[5] = *(_BYTE *)(a2 + 5);
      ++*a5;
      a3[6] = *(_BYTE *)(a2 + 6);
      v11 = *a5 + 1;
      *a5 = v11;
      if ( v7 )
        *v7 = v11 - v6 - 2;
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
