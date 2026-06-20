__int64 *__fastcall cam_smmu_find_mapping_by_ion_index(unsigned int a1, int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 *v4; // x9
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 *result; // x0
  __int64 *v8; // [xsp+8h] [xbp-8h]

  if ( a2 < 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_find_mapping_by_ion_index",
      1428,
      "Invalid fd %d",
      a2);
    return nullptr;
  }
  else
  {
    v3 = iommu_cb_set + 14280LL * a1;
    v4 = *(__int64 **)(v3 + 8400);
    v5 = v3 + 8400;
    v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 8) + 40LL) + 64LL);
    while ( 1 )
    {
      if ( v4 == (__int64 *)v5 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_find_mapping_by_ion_index",
          1444,
          "Error: Cannot find entry by index %d, fd %d i_ino %lu",
          a1,
          a2,
          v6);
        return nullptr;
      }
      if ( *((_DWORD *)v4 + 4) == a2 && v4[3] == v6 )
        break;
      v4 = (__int64 *)*v4;
    }
    result = v4 - 7;
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    {
      v8 = v4 - 7;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_find_mapping_by_ion_index",
        1438,
        "find ion_fd %d i_ino %lu",
        a2,
        v6);
      return v8;
    }
  }
  return result;
}
