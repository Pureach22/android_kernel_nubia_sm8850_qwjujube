__int64 __fastcall msm_mmrm_remove(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x20

  if ( result )
  {
    v1 = *(_QWORD *)(result + 168);
    drv_data = v1;
    if ( v1 )
    {
      if ( *(_BYTE *)(v1 + 8) == 1 )
      {
        v2 = result;
        sysfs_remove_group(result + 16, &mmrm_fs_attrs_group);
        msm_mmrm_debugfs_deinit();
        mmrm_deinit(drv_data);
        mmrm_free_platform_resources(drv_data);
        v1 = drv_data;
        result = v2;
      }
      *(_QWORD *)(result + 168) = 0;
      result = kfree(v1);
      drv_data = -517;
    }
    else if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      return printk(&unk_CD2B, "err ", "__remove");
    }
  }
  else if ( (~msm_mmrm_debug & 0x10001) == 0 )
  {
    result = printk(&unk_C50C, "err ", "__remove");
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      return printk(&unk_DA62, "err ", "__remove");
  }
  return result;
}
