__int64 __fastcall sde_get_rscc_pwr_ctrl_status(__int64 a1)
{
  return dss_reg_r(a1 + 736, 0x2D0u);
}
