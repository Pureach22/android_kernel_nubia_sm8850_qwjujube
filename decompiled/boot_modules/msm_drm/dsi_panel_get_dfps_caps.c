__int64 __fastcall dsi_panel_get_dfps_caps(_QWORD *a1, _QWORD *a2)
{
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x8

  if ( a1 && a2 )
  {
    v4 = a1[173];
    v5 = a1[172];
    v6 = a1[170];
    v7 = a1[171];
    a2[2] = v5;
    a2[3] = v4;
    *a2 = v6;
    a2[1] = v7;
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return 4294967274LL;
  }
}
