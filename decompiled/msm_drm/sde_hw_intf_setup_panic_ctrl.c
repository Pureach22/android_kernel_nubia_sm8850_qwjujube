__int64 __fastcall sde_hw_intf_setup_panic_ctrl(__int64 result, unsigned __int8 *a2)
{
  __int64 v3; // x19
  __int64 v4; // x2

  if ( result && a2 )
  {
    v3 = result;
    sde_reg_write(result, 208, *a2, "INTF_RSCC_PANIC_CTRL");
    sde_reg_write(v3, 212, *((unsigned int *)a2 + 1), "INTF_RSCC_PANIC_LEVEL");
    if ( *a2 == 1 )
      v4 = *((unsigned int *)a2 + 2);
    else
      v4 = 0xFFFFFFFFLL;
    return sde_reg_write(v3, 216, v4, "INTF_RSCC_PANIC_EXT_VFP_START");
  }
  return result;
}
