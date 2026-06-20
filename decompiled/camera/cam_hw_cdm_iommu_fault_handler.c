__int64 __fastcall cam_hw_cdm_iommu_fault_handler(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x22
  __int64 v4; // x23
  __int64 v5; // x0
  __int64 result; // x0
  const char *v7; // x5
  __int64 v8; // x4
  int v9; // w0
  unsigned __int64 v16; // x9

  if ( !a1 )
  {
    v7 = "pf_info is null";
    v8 = 1488;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             1,
             1,
             "cam_hw_cdm_iommu_fault_handler",
             v8,
             v7);
  }
  v1 = *(_QWORD *)(a1 + 32);
  if ( !v1 )
  {
    v7 = "Invalid token";
    v8 = 1543;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             1,
             1,
             "cam_hw_cdm_iommu_fault_handler",
             v8,
             v7);
  }
  v3 = *(_QWORD *)(v1 + 3680);
  v4 = *(_QWORD *)(v1 + 3392);
  if ( (unsigned int)__ratelimit(&cam_hw_cdm_iommu_fault_handler__rs, "cam_hw_cdm_iommu_fault_handler") )
    v5 = 3;
  else
    v5 = 2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    v5,
    1,
    1,
    "cam_hw_cdm_iommu_fault_handler",
    1497,
    "Page fault iova addr %pK\n",
    *(const void **)(a1 + 16));
  result = (__int64)cam_smmu_is_fault_ids_valid((_DWORD *)a1);
  if ( (result & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 48) != *(_DWORD *)(v4 + 24) || *(_DWORD *)(a1 + 52) != *(_DWORD *)(v4 + 28) )
      return result;
  }
  else if ( *(_BYTE *)(a1 + 58) != 1 )
  {
    return result;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    1,
    "cam_hw_cdm_iommu_fault_handler",
    1515,
    "Page Fault on %s%u, flags: %u, status: %llu",
    (const char *)(v3 + 4),
    *(_DWORD *)(v3 + 132),
    *(_DWORD *)(v3 + 136),
    *(_QWORD *)(v3 + 4856));
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(v3 + 4856);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 | 0x100, _X8) );
    mutex_lock(v1);
    cam_hw_cdm_pause_core(v1, 1u);
    if ( !**(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL)
      || (mutex_lock(v3 + 2352), **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) <= 1u)
      || (mutex_lock(v3 + 2992), **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) < 3u)
      || (mutex_lock(v3 + 3632), **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) < 4u)
      || (mutex_lock(v3 + 4272), **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) <= 4u) )
    {
      if ( *(_DWORD *)(v1 + 92) == 1 )
        cam_hw_cdm_dump_core_debug_registers(v1, 1);
      else
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          3,
          "cam_hw_cdm_iommu_fault_handler",
          1529,
          "%s%u hw is power in off state",
          *(const char **)(v1 + 152),
          *(_DWORD *)(v1 + 116));
      if ( !**(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) )
        break;
      mutex_unlock(v3 + 2352);
      if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) < 2u )
        break;
      mutex_unlock(v3 + 2992);
      if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) < 3u )
        break;
      mutex_unlock(v3 + 3632);
      if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) < 4u )
        break;
      mutex_unlock(v3 + 4272);
      if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) <= 4u )
        break;
    }
    __break(0x5512u);
  }
  cam_cdm_notify_clients(v1, 2, a1);
  v9 = cam_cdm_pf_stream_off_all_clients(v1);
  if ( v9 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_iommu_fault_handler",
      1540,
      "Stream off failed for %s%u rc: %d",
      (const char *)(v3 + 4),
      *(_DWORD *)(v3 + 132),
      v9);
  return mutex_unlock(v1);
}
