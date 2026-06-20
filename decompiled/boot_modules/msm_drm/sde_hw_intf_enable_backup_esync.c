__int64 __fastcall sde_hw_intf_enable_backup_esync(__int64 a1, char a2)
{
  __int64 result; // x0

  result = sde_reg_write(a1, 1136, a2 & 1, "INTF_BKUP_ESYNC_EN");
  if ( (a2 & 1) == 0 )
  {
    sde_reg_write(a1, 1160, 1, "INTF_BKUP_ESYNC_SW_RESET");
    sde_hw_intf_wait_for_esync_disable(a1, 1);
    return sde_reg_write(a1, 1160, 0, "INTF_BKUP_ESYNC_SW_RESET");
  }
  return result;
}
