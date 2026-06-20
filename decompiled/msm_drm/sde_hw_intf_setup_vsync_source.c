__int64 __fastcall sde_hw_intf_setup_vsync_source(__int64 result, int a2)
{
  __int64 v2; // x19

  if ( result )
  {
    v2 = result;
    sde_reg_write(result, 568, 0x124F800u / (16 * a2), "INTF_WD_TIMER_0_LOAD_VALUE");
    sde_reg_write(v2, 560, 1, "INTF_WD_TIMER_0_CTL");
    result = sde_reg_write(v2, 564, 259, "INTF_WD_TIMER_0_CTL2");
    __dsb(0xEu);
  }
  return result;
}
