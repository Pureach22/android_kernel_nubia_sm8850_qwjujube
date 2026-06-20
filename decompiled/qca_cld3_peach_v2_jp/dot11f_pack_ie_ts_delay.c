__int64 __fastcall dot11f_pack_ie_ts_delay(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v9; // w8
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    if ( a4 >= 4 )
    {
      v6 = *a5;
      v7 = a3 + 1;
      *a3 = 43;
      *a5 += 2;
      v10 = *(_DWORD *)(a2 + 4);
      qdf_mem_copy(a3 + 2, &v10, 4u);
      result = 0;
      v9 = *a5 + 4;
      *a5 = v9;
      if ( v7 )
        *v7 = v9 - v6 - 2;
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
