__int64 __fastcall sde_hw_intf_enable_esync(__int64 a1, char a2)
{
  const char *v4; // x3
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2

  sde_reg_write(a1, 1024, a2 & 1, "INTF_ESYNC_EN");
  if ( (a2 & 1) != 0 )
  {
    v4 = "INTF_ESYNC_TIMESTAMP_CTRL";
    v5 = a1;
    v6 = 1184;
    v7 = 5;
  }
  else
  {
    sde_reg_write(a1, 1164, 1, "INTF_ESYNC_SW_RESET");
    sde_hw_intf_wait_for_esync_disable(a1, 0);
    v5 = a1;
    v6 = 1164;
    v7 = 0;
    v4 = "INTF_ESYNC_SW_RESET";
  }
  return sde_reg_write(v5, v6, v7, v4);
}
