__int64 __fastcall dsi_phy_put(__int64 a1)
{
  int v2; // w8
  int v3; // w3

  mutex_lock(a1 + 32);
  v2 = *(_DWORD *)(a1 + 24);
  if ( v2 )
  {
    *(_DWORD *)(a1 + 24) = v2 - 1;
  }
  else
  {
    if ( a1 )
      v3 = *(_DWORD *)(a1 + 8);
    else
      v3 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Unbalanced %s call\n", v3, "dsi_phy_put");
  }
  return mutex_unlock(a1 + 32);
}
