__int64 __fastcall dsi_display_drm_bridge_init(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x1
  __int64 v7; // x22
  unsigned int v8; // w20
  unsigned __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned int v12; // w9
  __int64 v13; // x10
  __int64 v14; // x9

  if ( !a1 || !a2 || !*(_QWORD *)(a1 + 8) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid param(s)\n");
    return (unsigned int)-22;
  }
  mutex_lock(a1 + 72);
  v6 = *(_QWORD *)(a1 + 8);
  v7 = *(_QWORD *)(v6 + 56);
  if ( !v7 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Private data is not present\n");
    v8 = -22;
    goto LABEL_24;
  }
  if ( *(_QWORD *)(a1 + 1296) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: display is already initialize\n");
    v8 = 0;
LABEL_24:
    mutex_unlock(a1 + 72);
    return v8;
  }
  v9 = dsi_drm_bridge_init(a1, v6, a2);
  v8 = v9;
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] brige init failed, %d\n",
      *(const char **)(a1 + 32),
      v9);
    goto LABEL_24;
  }
  *(_QWORD *)(a1 + 1296) = v9;
  v10 = *(unsigned int *)(v7 + 3928);
  *(_DWORD *)(v7 + 3928) = v10 + 1;
  if ( (unsigned int)v10 < 0x10 )
  {
    *(_QWORD *)(v7 + 8 * v10 + 3936) = v9;
    if ( *(_QWORD *)(a1 + 1224) )
    {
      v11 = a3;
      v8 = 0;
    }
    else
    {
      v8 = dsi_host_alloc_cmd_tx_buffer(a1);
      if ( v8 )
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to allocate cmd tx buffer memory\n");
      v11 = a3;
    }
    v12 = *(_DWORD *)(a1 + 160);
    if ( v12 )
    {
      v13 = *(_QWORD *)(a1 + 168);
      if ( v13 )
      {
        *(_QWORD *)(v13 + 2432) = v11;
        v12 = *(_DWORD *)(a1 + 160);
      }
      if ( v12 >= 2 )
      {
        v14 = *(_QWORD *)(a1 + 216);
        if ( v14 )
          *(_QWORD *)(v14 + 2432) = v11;
      }
    }
    goto LABEL_24;
  }
  __break(0x5512u);
  return dsi_display_drm_bridge_deinit(v9);
}
