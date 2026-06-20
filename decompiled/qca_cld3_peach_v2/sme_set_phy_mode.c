__int64 __fastcall sme_set_phy_mode(__int64 a1, int a2)
{
  __int64 v2; // x19
  int cfg_dot11_mode_from_csr_phy_mode; // w8

  v2 = a1 + 0x4000;
  *(_DWORD *)(a1 + 17200) = a2;
  cfg_dot11_mode_from_csr_phy_mode = csr_get_cfg_dot11_mode_from_csr_phy_mode(0);
  *(_DWORD *)(v2 + 820) = cfg_dot11_mode_from_csr_phy_mode;
  return 0;
}
