__int64 __fastcall sde_hw_ctl_update_wb_cfg(__int64 result, __int64 a2, char a3)
{
  __int64 v5; // x21
  int v6; // w0
  int v7; // w8
  unsigned int v8; // w9
  unsigned int v9; // w8
  __int64 v10; // x2

  if ( *(_DWORD *)(a2 + 4) )
  {
    v5 = result;
    v6 = sde_reg_read(result, 20);
    v7 = *(_DWORD *)(a2 + 4) & 3;
    v8 = (v7 + 2) | v6;
    v9 = (-3 - v7) & v6;
    if ( (a3 & 1) != 0 )
      v10 = v8;
    else
      v10 = v9;
    return sde_reg_write(v5, 20, v10, "CTL_TOP");
  }
  return result;
}
