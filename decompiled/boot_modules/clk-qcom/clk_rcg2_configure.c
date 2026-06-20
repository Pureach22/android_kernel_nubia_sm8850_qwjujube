__int64 __fastcall clk_rcg2_configure(int *a1, _QWORD *a2)
{
  int v4; // w8
  int v5; // w9
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v5 = *((unsigned __int8 *)a1 + 192);
  v6 = *((_QWORD *)a1 + 9);
  v8 = 0;
  result = regmap_read(v6, (unsigned int)(v4 + v5 + 4), &v8);
  if ( !(_DWORD)result )
  {
    result = _clk_rcg2_configure(a1, a2, &v8);
    if ( !(_DWORD)result )
    {
      result = regmap_write(*((_QWORD *)a1 + 9), *a1 + (unsigned int)*((unsigned __int8 *)a1 + 192) + 4, v8);
      if ( !(_DWORD)result )
      {
        *((_QWORD *)a1 + 2) = *a2;
        result = update_config(a1);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
