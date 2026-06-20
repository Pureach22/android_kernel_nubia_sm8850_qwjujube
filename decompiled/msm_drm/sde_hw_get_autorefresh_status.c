__int64 __fastcall sde_hw_get_autorefresh_status(__int64 a1, int a2)
{
  unsigned int v2; // w2
  unsigned int v4; // w19

  if ( a1 )
  {
    if ( a2 == 3 )
      v2 = 1045;
    else
      v2 = 1029;
    sde_reg_write(a1, 0x418u, v2, "MDP_PERIPH_DBGBUS_CTRL");
    sde_reg_write(a1, 0x348u, 0x7001u, "MDP_DSPP_DBGBUS_CTRL");
    __dsb(0xEu);
    v4 = sde_reg_read(a1, 0x34Cu);
    sde_reg_write(a1, 0x418u, 0, "MDP_PERIPH_DBGBUS_CTRL");
  }
  else
  {
    return 0;
  }
  return v4;
}
