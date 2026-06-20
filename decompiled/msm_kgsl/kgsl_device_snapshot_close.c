__int64 __fastcall kgsl_device_snapshot_close(__int64 result)
{
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 v3; // x19
  __int64 v4; // x8
  unsigned __int64 v5; // x12
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x3
  __int64 v9; // x3

  v1 = *(_QWORD *)(result + 11216);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 11224);
    v3 = result;
    if ( !v2 )
    {
      v4 = v1 << 8 >> 8;
      v5 = (unsigned __int64)(v4 + 0x8000000000LL) >> 38;
      v6 = memstart_addr + v4 + 0x8000000000LL;
      v7 = v4 - kimage_voffset;
      if ( v5 )
        v2 = v7;
      else
        v2 = v6;
    }
    kgsl_remove_from_minidump("GPU_SNAPSHOT", v1, v2, *(unsigned int *)(result + 11232));
    atomic_notifier_chain_unregister(&panic_notifier_list, v3 + 11248);
    sysfs_remove_bin_file(v3 + 11320, &snapshot_attr);
    sysfs_remove_files(v3 + 11320, snapshot_attrs);
    result = kobject_put(v3 + 11320);
    v8 = *(_QWORD *)(v3 + 11224);
    if ( v8 )
      result = dma_free_attrs(
                 *(_QWORD *)(v3 + 11168) + 16LL,
                 *(unsigned int *)(v3 + 11232),
                 *(_QWORD *)(v3 + 11216),
                 v8,
                 0);
    v9 = *(_QWORD *)(v3 + 11280);
    if ( v9 )
      return dma_free_attrs(
               *(_QWORD *)(v3 + 11168) + 16LL,
               *(unsigned int *)(v3 + 11288),
               *(_QWORD *)(v3 + 11272),
               v9,
               0);
  }
  return result;
}
