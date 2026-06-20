__int64 __fastcall dsi_drm_bridge_init(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v5; // x19
  int v6; // w0
  int v7; // w20

  v5 = (_QWORD *)_kmalloc_cache_noprof(msleep, 3520, 504);
  if ( !v5 )
    return -12;
  v5[38] = a1;
  v5[21] = &dsi_bridge_ops;
  v5[14] = a3;
  v6 = drm_bridge_attach(a3, v5, 0, 1);
  if ( v6 )
  {
    v7 = v6;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to attach bridge, rc=%d\n", v6);
    kfree(v5);
    return v7;
  }
  return (__int64)v5;
}
