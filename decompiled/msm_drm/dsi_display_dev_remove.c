__int64 __fastcall dsi_display_dev_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  unsigned int v4; // w8
  __int64 v5; // x9
  __int64 v6; // x8

  if ( !a1 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid device\n");
  v1 = *(_QWORD *)(a1 + 168);
  if ( !v1 || !*(_QWORD *)(v1 + 272) )
    return drm_dev_printk(
             0,
             &unk_248D72,
             "*ERROR* [msm-dsi-error]: invalid param, display %pK, display panel node %pK\n",
             (const void *)v1,
             nullptr);
  v3 = *(_QWORD *)(v1 + 1624);
  if ( v3 )
  {
    _flush_workqueue(v3);
    destroy_workqueue(*(_QWORD *)(v1 + 1624));
    v4 = *(_DWORD *)(v1 + 160);
    *(_QWORD *)(v1 + 1624) = 0;
    if ( v4 )
    {
      v5 = *(_QWORD *)(v1 + 168);
      if ( v5 )
      {
        *(_QWORD *)(v5 + 2840) = 0;
        v4 = *(_DWORD *)(v1 + 160);
      }
      if ( v4 >= 2 )
      {
        v6 = *(_QWORD *)(v1 + 216);
        if ( v6 )
          *(_QWORD *)(v6 + 2840) = 0;
      }
    }
  }
  mutex_lock(v1 + 72);
  if ( *(_DWORD *)(v1 + 160) )
  {
    dsi_phy_put(*(_QWORD *)(v1 + 192));
    dsi_ctrl_put(*(_QWORD *)(v1 + 168));
    if ( *(_DWORD *)(v1 + 160) >= 2u )
    {
      dsi_phy_put(*(_QWORD *)(v1 + 240));
      dsi_ctrl_put(*(_QWORD *)(v1 + 216));
    }
  }
  if ( *(_QWORD *)(v1 + 264) )
    dsi_panel_put();
  mutex_unlock(v1 + 72);
  qword_F120 = 0;
  qword_F110 = 0;
  qword_F348 = 0;
  qword_F338 = 0;
  *(_QWORD *)(a1 + 168) = 0;
  return devm_kfree(a1 + 16);
}
