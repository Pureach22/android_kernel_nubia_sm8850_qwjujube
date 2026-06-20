__int64 __fastcall cam_cdm_get_iommu_handle(const char *a1, __int64 a2)
{
  unsigned int v2; // w21
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  char *v8; // x25
  __int64 v9; // x27
  __int64 v10; // x26
  char v11; // w24
  int v12; // w28
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x9
  __int64 (__fastcall *v16)(__int64, __int64, __int64); // x8
  __int64 v17; // x0

  v2 = -22;
  if ( !a1 || !a2 )
    return v2;
  if ( (unsigned int)((__int64 (*)(void))get_cdm_mgr_refcount)() )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_get_iommu_handle",
      131,
      "CDM intf mgr get refcount failed");
    return (unsigned int)-1;
  }
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_get_iommu_handle",
      134,
      "Looking for Iommu handle of %s",
      a1);
  v5 = mutex_lock(&cam_cdm_mgr_lock);
  if ( !dword_394234 )
  {
    v2 = -1;
LABEL_37:
    v17 = mutex_unlock(&cam_cdm_mgr_lock);
    put_cdm_mgr_refcount(v17);
    return v2;
  }
  v6 = 0;
  v2 = -1;
  while ( v6 != 16 )
  {
    v8 = &cdm_mgr[72 * v6];
    v5 = mutex_lock(v8 + 16);
    if ( (unsigned __int64)(72 * v6 - 1096) < 0xFFFFFFFFFFFFFB68LL )
      goto LABEL_40;
    v9 = *((_QWORD *)v8 + 10);
    if ( v9 )
    {
      if ( (debug_mdl & 1) != 0 && !debug_priority )
      {
        v5 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               1,
               4,
               "cam_cdm_get_iommu_handle",
               144,
               "dt_num_supported_clients=%d",
               *(_DWORD *)(v9 + 20));
        v9 = *((_QWORD *)v8 + 10);
        if ( !*(_DWORD *)(v9 + 20) )
          goto LABEL_13;
      }
      else if ( !*(_DWORD *)(v9 + 20) )
      {
        goto LABEL_13;
      }
      v10 = 4;
      v11 = debug_mdl;
      v12 = debug_priority;
      while ( 1 )
      {
        v13 = v10 - 4;
        if ( (v11 & 1) != 0 && !v12 )
        {
          if ( v13 > 0xFF )
            goto LABEL_39;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            4,
            "cam_cdm_get_iommu_handle",
            150,
            "client name:%s dev Index: %d",
            *(const char **)(v9 + 8 * v10),
            v6);
          v9 = *((_QWORD *)v8 + 10);
          v12 = debug_priority;
          v11 = debug_mdl;
        }
        else if ( v13 > 0xFF )
        {
          goto LABEL_39;
        }
        v5 = strcmp(*(const char **)(v9 + 8 * v10), a1);
        if ( !(_DWORD)v5 )
          break;
        v14 = v10 - 3;
        ++v10;
        if ( v14 >= *(unsigned int *)(v9 + 20) )
          goto LABEL_13;
      }
      if ( (unsigned __int64)(72 * v6 - 1104) < 0xFFFFFFFFFFFFFB68LL )
        goto LABEL_40;
      v15 = *(_QWORD *)&cdm_mgr[72 * v6 + 72];
      v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v15 + 8);
      if ( v16 )
      {
        v7 = *(_QWORD *)(v15 + 112);
        if ( *((_DWORD *)v16 - 1) != 1989616049 )
          __break(0x8228u);
        v2 = v16(v7, a2, 8);
LABEL_13:
        v5 = mutex_unlock(v8 + 16);
        if ( !v2 )
          goto LABEL_37;
        goto LABEL_14;
      }
      v2 = -1;
    }
    v5 = mutex_unlock(v8 + 16);
LABEL_14:
    if ( ++v6 >= (unsigned __int64)(unsigned int)dword_394234 )
      goto LABEL_37;
  }
LABEL_39:
  __break(0x5512u);
LABEL_40:
  __break(1u);
  return get_cdm_mgr_refcount(v5);
}
