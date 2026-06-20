__int64 __fastcall sde_cesta_hw_get_pwr_event(__int64 a1)
{
  return dss_reg_r(a1 + 752, 0x24u);
}
