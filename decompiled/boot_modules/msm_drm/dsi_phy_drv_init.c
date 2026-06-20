__int64 __fastcall dsi_phy_drv_init(__int64 *a1)
{
  int v2; // w3
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 phys_addr; // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v10; // [xsp+10h] [xbp-20h]
  __int64 v11; // [xsp+18h] [xbp-18h]
  __int64 v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_DWORD *)a1 + 2);
  v11 = 0;
  v12 = 0;
  *(_QWORD *)s = 0;
  v10 = 0;
  snprintf(s, 0x20u, "dsi%d_phy", v2);
  v3 = a1[11];
  v4 = msm_iomap_size(*a1, "dsi_phy");
  v5 = *a1;
  v6 = v4;
  phys_addr = msm_get_phys_addr(v5, "dsi_phy");
  sde_dbg_reg_register_base(s, v3, v6, phys_addr, 32);
  _ReadStatusReg(SP_EL0);
  return 0;
}
