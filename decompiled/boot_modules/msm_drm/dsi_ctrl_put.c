__int64 __fastcall dsi_ctrl_put(__int64 a1)
{
  int v2; // w8
  const char *v3; // x3

  mutex_lock(a1 + 32);
  v2 = *(_DWORD *)(a1 + 24);
  if ( v2 )
  {
    *(_DWORD *)(a1 + 24) = v2 - 1;
  }
  else
  {
    if ( a1 )
      v3 = *(const char **)(a1 + 16);
    else
      v3 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Unbalanced %s call\n", v3, "dsi_ctrl_put");
  }
  return mutex_unlock(a1 + 32);
}
