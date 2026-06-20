__int64 __fastcall dsi_panel_post_vreg_get(__int64 a1)
{
  int v2; // w8
  int v3; // w25
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x23
  unsigned int v6; // w22

  if ( *(_DWORD *)(a1 + 1464) )
  {
    v2 = 0;
    do
    {
      v3 = v2;
      v4 = devm_regulator_get(*(_QWORD *)(a1 + 1216), *(_QWORD *)(a1 + 1456) + 80LL * v2 + 8);
      v5 = v4;
      if ( v4 <= 0xFFFFFFFFFFFFF000LL )
        v6 = 0;
      else
        v6 = v4;
      if ( v6 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: failed to get %s post regulator\n",
          (const char *)(*(_QWORD *)(a1 + 1456) + 80LL * v3 + 8));
      *(_QWORD *)(*(_QWORD *)(a1 + 1456) + 80LL * v3) = v5;
      v2 = v3 + 1;
    }
    while ( (unsigned int)(v3 + 1) < *(_DWORD *)(a1 + 1464) );
  }
  else
  {
    return 0;
  }
  return v6;
}
