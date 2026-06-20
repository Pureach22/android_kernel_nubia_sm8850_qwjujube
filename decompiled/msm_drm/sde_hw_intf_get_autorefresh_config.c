__int64 __fastcall sde_hw_intf_get_autorefresh_config(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w8

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v5 = sde_reg_read(a1, 692);
      *(_DWORD *)(a2 + 4) = (unsigned __int16)v5;
      *(_BYTE *)a2 = v5 < 0;
      return 0;
    }
  }
  return result;
}
