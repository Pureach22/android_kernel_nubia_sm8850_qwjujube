__int64 __fastcall dsi_display_phy_configure(__int64 a1, char a2)
{
  unsigned int v3; // w8
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 v6; // x9
  __int64 v7; // x10

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 64) & 1) != 0 || (*(_BYTE *)(a1 + 1641) & 1) != 0 )
      return 0;
    v3 = *(_DWORD *)(a1 + 836);
    if ( v3 >= 3 )
    {
      __break(0x5512u);
      return dsi_display_phy_disable();
    }
    v4 = a1 + 48LL * v3;
    v5 = *(_QWORD *)(v4 + 192);
    if ( v5 && (v6 = *(_QWORD *)(v4 + 168)) != 0 )
    {
      v7 = *(_QWORD *)(v5 + 1344);
      if ( v7 )
      {
        *(_QWORD *)(v7 + 64) = *(unsigned int *)(v6 + 2376);
        *(_QWORD *)(v7 + 72) = *(unsigned int *)(v6 + 2384);
        return ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_phy_configure)(*(_QWORD *)(v4 + 192), a2 & 1);
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] PLL res not found\n", *(_QWORD *)(a1 + 32));
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] PHY not found\n", *(_QWORD *)(a1 + 32));
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid arguments\n");
  }
  return 4294967274LL;
}
