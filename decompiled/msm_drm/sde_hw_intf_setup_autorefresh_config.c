__int64 __fastcall sde_hw_intf_setup_autorefresh_config(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  int v6; // w0
  __int64 v7; // x2

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = a1;
    v6 = sde_reg_read(a1, 692);
    if ( *(_BYTE *)a2 == 1 )
      v7 = *(_DWORD *)(a2 + 4) | 0x80000000;
    else
      v7 = v6 & 0x7FFFFFFF;
    sde_reg_write(v5, 692, v7, "INTF_TEAR_AUTOREFRESH_CONFIG");
    return 0;
  }
  return result;
}
