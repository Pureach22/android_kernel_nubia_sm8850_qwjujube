__int64 __fastcall sub_1D1740(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x24

  return dsi_ctrl_phy_sw_reset(a1, a2, a3, a4, a5, v5 & 0x3E0000000000000LL);
}
