__int64 __fastcall dsi_panel_get_phy_props(__int64 a1, __int64 a2)
{
  __int64 v4; // x9

  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(a1 + 1404);
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 1412);
    *(_QWORD *)a2 = v4;
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return 4294967274LL;
  }
}
