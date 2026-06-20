__int64 __fastcall dsi_display_set_lp2_load(__int64 a1, char a2)
{
  unsigned int v2; // w9
  char v3; // w19
  __int64 v4; // x20
  unsigned int v5; // w0
  unsigned int v6; // w19
  char v7; // w19
  __int64 v8; // x20
  unsigned int v9; // w0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return (unsigned int)-22;
  }
  v2 = *(_DWORD *)(a1 + 160);
  if ( v2 )
  {
    if ( *(_QWORD *)(a1 + 168) )
    {
      v3 = a2;
      v4 = a1;
      v5 = dsi_ctrl_set_lp2_load(*(_QWORD *)(a1 + 168), a2 & 1);
      a2 = v3;
      v6 = v5;
      if ( v5 )
      {
LABEL_9:
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set lp2 load for dsi ctrl, rc = %d\n", v6);
        return v6;
      }
      v2 = *(_DWORD *)(v4 + 160);
      a1 = v4;
    }
    if ( v2 >= 2 )
    {
      if ( *(_QWORD *)(a1 + 216) )
      {
        v7 = a2;
        v8 = a1;
        v9 = dsi_ctrl_set_lp2_load(*(_QWORD *)(a1 + 216), a2 & 1);
        a2 = v7;
        v6 = v9;
        a1 = v8;
        if ( v6 )
          goto LABEL_9;
      }
    }
  }
  v6 = dsi_panel_set_lp2_load(*(_QWORD *)(a1 + 264), a2 & 1);
  if ( v6 )
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set lp2 load for dsi panel, rc = %d\n", v6);
  return v6;
}
