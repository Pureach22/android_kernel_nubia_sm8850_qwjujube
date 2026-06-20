__int64 __fastcall sde_cesta_hw_get_status(__int64 a1, unsigned int a2, int *a3)
{
  __int64 v3; // x21
  unsigned int v6; // w0

  if ( a2 >= 0xA )
  {
    __break(0x5512u);
    return sde_cesta_hw_get_pwr_event();
  }
  else
  {
    v3 = a1 + 16LL * a2;
    v6 = dss_reg_r(v3 + 544, 0x10u);
    *a3 = (v6 >> 8) & 3;
    a3[1] = (v6 >> 4) & 3;
    a3[2] = v6 & 3;
    a3[3] = dss_reg_r(v3 + 544, 0x20u);
    return dss_reg_w(v3 + 544, 0x24u, 1u, *(_DWORD *)(a1 + 1160));
  }
}
