__int64 __fastcall dsi_ctrl_phy_reset_config(__int64 a1, char a2)
{
  __int64 v2; // x17
  __int64 v3; // x8
  void (__fastcall *v4)(__int64, __int64); // x8
  __int64 v5; // x0
  __int64 v6; // x1

  if ( a1 )
  {
    v3 = *(unsigned int *)(a1 + 1608);
    if ( (unsigned int)v3 >= 3 )
    {
      __break(0x5512u);
      if ( (v2 & 0x800000000000LL) == 0 )
        JUMPOUT(0x1D59E4);
      return dsi_ctrl_enable_status_interrupt(a1, a2);
    }
    else
    {
      v4 = *(void (__fastcall **)(__int64, __int64))(a1 + 8 * v3 + 768);
      if ( v4 )
      {
        v5 = a1 + 96;
        v6 = a2 & 1;
        if ( *((_DWORD *)v4 - 1) != 1642962683 )
          __break(0x8228u);
        v4(v5, v6);
      }
      return 0;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
    return 4294967274LL;
  }
}
