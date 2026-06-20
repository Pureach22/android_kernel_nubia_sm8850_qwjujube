__int64 __fastcall sde_hw_intf_setup_panic_wakeup(__int64 result, __int64 a2)
{
  __int64 v3; // x19
  unsigned int v4; // w9
  int v5; // w8

  if ( result && a2 )
  {
    v3 = result;
    sde_reg_write(result, 744, *(unsigned int *)(a2 + 4), "INTF_TEAR_PANIC_START");
    sde_reg_write(v3, 748, *(unsigned int *)(a2 + 8), "INTF_TEAR_PANIC_WINDOW");
    sde_reg_write(v3, 752, *(unsigned int *)(a2 + 12), "INTF_TEAR_WAKEUP_START");
    sde_reg_write(v3, 756, *(unsigned int *)(a2 + 16), "INTF_TEAR_WAKEUP_WINDOW");
    v4 = sde_reg_read(v3, 644) & 0xFFFFFFCF;
    if ( *(_BYTE *)a2 )
      v5 = 48;
    else
      v5 = 0;
    return sde_reg_write(v3, 644, v5 | v4, "INTF_TEAR_TEAR_CHECK_EN");
  }
  return result;
}
