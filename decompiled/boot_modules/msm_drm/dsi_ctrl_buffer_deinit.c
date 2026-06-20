__int64 __fastcall dsi_ctrl_buffer_deinit(_QWORD *a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x1
  const char *v4; // x3

  if ( !a1[346] )
    return 0;
  if ( a1 )
  {
    if ( a1[10] )
    {
      v1 = a1;
      v2 = msm_gem_smmu_address_space_get(a1[10], 0);
      a1 = v1;
      if ( v2 )
      {
        msm_gem_put_iova(v1[346], v2);
        mutex_lock(v1[10] + 128LL);
        msm_gem_free_object(v1[346]);
        mutex_unlock(v1[10] + 128LL);
        v1[346] = 0;
        return 0;
      }
    }
    v4 = (const char *)a1[2];
  }
  else
  {
    v4 = "inv";
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: failed to get address space\n", v4);
  return 4294967284LL;
}
