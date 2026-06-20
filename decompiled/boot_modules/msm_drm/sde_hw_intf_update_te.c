__int64 __fastcall sde_hw_intf_update_te(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  int v4; // w0

  if ( result )
  {
    if ( a2 )
    {
      v3 = result;
      v4 = sde_reg_read(result, 668);
      sde_reg_write(v3, 668, v4 & 0xFFFF0000 | *(_DWORD *)(a2 + 12), "INTF_TEAR_SYNC_THRESH");
      return sde_reg_write(v3, 672, *(unsigned int *)(a2 + 20), "INTF_TEAR_START_POS");
    }
  }
  return result;
}
