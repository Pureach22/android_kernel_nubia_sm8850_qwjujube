__int64 __fastcall dsi_bridge_attach(__int64 a1)
{
  if ( a1 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%d] attached\n", *(_DWORD *)(a1 + 296));
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
}
