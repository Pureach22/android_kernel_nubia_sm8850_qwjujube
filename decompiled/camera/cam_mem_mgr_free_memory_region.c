__int64 __fastcall cam_mem_mgr_free_memory_region(unsigned int *a1)
{
  unsigned int v1; // w19
  const char *v2; // x5
  __int64 v3; // x4
  __int64 result; // x0
  char *v5; // x20
  __int64 v7; // x0
  const char *v8; // x5
  __int64 v9; // x4
  const char *v10; // x5
  __int64 v11; // x4
  unsigned int v12; // w22
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !cam_mem_mgr_state )
  {
    v2 = "failed. mem_mgr not initialized";
    v3 = 3522;
    goto LABEL_9;
  }
  if ( !a1 )
  {
    v2 = "Invalid argument";
    v3 = 3527;
    goto LABEL_9;
  }
  if ( (a1[8] | 2) != 6 )
  {
    v2 = "Only secondary heap supported";
    v3 = 3533;
    goto LABEL_9;
  }
  v1 = a1[4] & 0x7FFF;
  if ( v1 - 2048 > 0xFFFFF800 )
  {
    v5 = (char *)&tbl + 296 * v1;
    mutex_lock(v5 + 72);
    if ( (v5[184] & 1) != 0 )
    {
      if ( *((_DWORD *)v5 + 34) == a1[4] )
      {
        if ( *((_DWORD *)v5 + 42) != 1 )
        {
          v8 = "Sec heap region should have only one smmu hdl";
          v9 = 3559;
          goto LABEL_25;
        }
        v7 = a1[3];
        v13 = 0;
        if ( (cam_mem_mgr_get_hwva_entry_idx(v7, &v13) & 1) == 0 )
        {
          v8 = "Passed SMMU handle not a valid handle";
          v9 = 3566;
          goto LABEL_25;
        }
        if ( (a1[3] & 0xFFFFFFF) != *(_DWORD *)(*((_QWORD *)v5 + 22) + 40LL * v13) )
        {
          v8 = "Passed SMMU handle doesn't match with internal hdl";
          v9 = 3574;
          goto LABEL_25;
        }
        if ( (unsigned int)cam_smmu_release_buf_region(a1[8]) )
        {
          v8 = "Sec heap region release failed";
          v9 = 3582;
LABEL_25:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x400000,
            1,
            "cam_mem_mgr_free_memory_region",
            v9,
            v8);
          v12 = -19;
          goto LABEL_26;
        }
        if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x400000,
            4,
            "cam_mem_mgr_free_memory_region",
            3587,
            "Releasing hdl = %X",
            a1[4]);
        if ( (unsigned int)kref_put((unsigned int *)v5 + 52, (void (*)(void))cam_mem_util_unmap_wrapper) )
        {
          v12 = 0;
          if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x400000,
              4,
              "cam_mem_mgr_free_memory_region",
              3591,
              "Called unmap from here, buf_handle: %u, idx: %d",
              a1[4],
              v1);
            v12 = 0;
          }
          goto LABEL_26;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_mgr_free_memory_region",
          3595,
          "Unbalanced release Called buf_handle: %u, idx: %d",
          a1[4],
          v1);
LABEL_21:
        v12 = -22;
LABEL_26:
        mutex_unlock(v5 + 72);
        result = v12;
        goto LABEL_10;
      }
      v10 = "Released buf handle not matching within table";
      v11 = 3552;
    }
    else
    {
      v10 = "Released buffer state should be active";
      v11 = 3545;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_free_memory_region",
      v11,
      v10);
    goto LABEL_21;
  }
  v2 = "Incorrect index extracted from mem handle";
  v3 = 3539;
LABEL_9:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x400000,
    1,
    "cam_mem_mgr_free_memory_region",
    v3,
    v2);
  result = 4294967274LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
