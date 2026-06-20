__int64 __fastcall cam_smmu_get_handle(char *s2, int *a2)
{
  int v3; // w20
  __int64 v4; // x21
  int v5; // w28
  int v6; // w8
  __int64 v7; // x23
  int v8; // w26
  int v9; // w27
  const char *v10; // x5
  __int64 v11; // x4
  int v12; // w9
  int v13; // w23
  __int64 v14; // x8
  unsigned int v15; // w20
  int v17; // w20
  __int64 v18; // x9
  int v19; // w27
  unsigned int v20; // w6
  int v21; // w11
  int v22; // w13
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x9
  int v27; // w20
  __int64 v28; // x21
  int v29; // w22
  int v30; // w23
  int v31; // w7
  unsigned int v32; // [xsp+14h] [xbp-1Ch]
  int v34; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !s2 )
  {
    v10 = "Error: iommu hardware name is NULL";
    v11 = 3214;
LABEL_35:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_handle",
      v11,
      v10);
    v15 = -22;
    goto LABEL_36;
  }
  if ( !a2 )
  {
    v10 = "Error: handle pointer is NULL";
    v11 = 3219;
    goto LABEL_35;
  }
  v3 = dword_394060;
  if ( !dword_394060 )
  {
LABEL_21:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_create_add_handle_in_table",
      1307,
      "Error: Cannot find name %s or all handle exist",
      s2);
    if ( dword_394060 )
    {
      v12 = 0;
      do
      {
        v13 = v12;
        v14 = iommu_cb_set + 14280LL * v12;
        if ( *(int *)(v14 + 8624) >= 1 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_print_table",
            831,
            "i= %d, handle= %d, name_addr=%pK name %s",
            v12,
            *(_DWORD *)(v14 + 8480),
            *(const void **)(v14 + 32),
            *(const char **)(v14 + 32));
          v14 = iommu_cb_set + 14280LL * v13;
          if ( *(int *)(v14 + 8624) >= 2 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              64,
              1,
              "cam_smmu_print_table",
              831,
              "i= %d, handle= %d, name_addr=%pK name %s",
              v13,
              *(_DWORD *)(v14 + 8480),
              *(const void **)(v14 + 40),
              *(const char **)(v14 + 40));
            v14 = iommu_cb_set + 14280LL * v13;
            if ( *(int *)(v14 + 8624) > 2 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                64,
                1,
                "cam_smmu_print_table",
                831,
                "i= %d, handle= %d, name_addr=%pK name %s",
                v13,
                *(_DWORD *)(v14 + 8480),
                *(const void **)(v14 + 48),
                *(const char **)(v14 + 48));
              v14 = iommu_cb_set + 14280LL * v13;
              if ( *(int *)(v14 + 8624) >= 4 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  64,
                  1,
                  "cam_smmu_print_table",
                  831,
                  "i= %d, handle= %d, name_addr=%pK name %s",
                  v13,
                  *(_DWORD *)(v14 + 8480),
                  *(const void **)(v14 + 56),
                  *(const char **)(v14 + 56));
                v14 = iommu_cb_set + 14280LL * v13;
                if ( *(int *)(v14 + 8624) >= 5 )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    64,
                    1,
                    "cam_smmu_print_table",
                    831,
                    "i= %d, handle= %d, name_addr=%pK name %s",
                    v13,
                    *(_DWORD *)(v14 + 8480),
                    *(const void **)(v14 + 64),
                    *(const char **)(v14 + 64));
                  v14 = iommu_cb_set + 14280LL * v13;
                  if ( *(int *)(v14 + 8624) >= 6 )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      64,
                      1,
                      "cam_smmu_print_table",
                      831,
                      "i= %d, handle= %d, name_addr=%pK name %s",
                      v13,
                      *(_DWORD *)(v14 + 8480),
                      *(const void **)(v14 + 72),
                      *(const char **)(v14 + 72));
                    v14 = iommu_cb_set + 14280LL * v13;
                    if ( *(int *)(v14 + 8624) > 6 )
                      goto LABEL_31;
                  }
                }
              }
            }
          }
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_print_table",
          833,
          "dev = %pK",
          *(const void **)v14);
        v12 = v13 + 1;
      }
      while ( v13 + 1 < (unsigned int)dword_394060 );
    }
LABEL_32:
    v15 = -22;
    goto LABEL_33;
  }
  v4 = iommu_cb_set;
  v5 = 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = v4 + 14280LL * v6;
    v8 = v6;
    v9 = *(_DWORD *)(v7 + 8624);
    if ( v9 >= 1 )
    {
      if ( !strcmp(*(const char **)(v7 + 32), s2) )
        goto LABEL_37;
      if ( v9 != 1 )
      {
        if ( !strcmp(*(const char **)(v7 + 40), s2) )
          goto LABEL_37;
        if ( v9 != 2 )
        {
          if ( !strcmp(*(const char **)(v7 + 48), s2) )
            goto LABEL_37;
          if ( v9 != 3 )
          {
            if ( !strcmp(*(const char **)(v7 + 56), s2) )
              goto LABEL_37;
            if ( v9 != 4 )
            {
              if ( !strcmp(*(const char **)(v7 + 64), s2) )
                goto LABEL_37;
              if ( v9 != 5 )
                break;
            }
          }
        }
      }
    }
LABEL_5:
    v6 = v8 + 1;
    v5 += 0x10000;
    if ( v3 == v8 + 1 )
      goto LABEL_21;
  }
  if ( strcmp(*(const char **)(v7 + 72), s2) )
  {
    if ( v9 != 6 )
      goto LABEL_31;
    goto LABEL_5;
  }
LABEL_37:
  v17 = *(_DWORD *)(v7 + 8480);
  mutex_lock(v7 + 8432);
  if ( v17 == -1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v34 = 0;
        get_random_bytes(&v34, 2);
        v19 = (unsigned __int16)v34;
        v20 = v5 + (unsigned __int16)v34;
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        {
          v32 = v5 + (unsigned __int16)v34;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_smmu_create_iommu_handle",
            1198,
            "create handle value = %x",
            v20);
          v20 = v32;
        }
        if ( v20 - 1 <= 0xFFFFFFFD )
          break;
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_smmu_is_hdl_nonunique_or_null",
            1172,
            "iommu handle: %d is not valid",
            v20);
      }
      if ( !dword_394060 )
        break;
      v21 = 0;
      while ( 1 )
      {
        v22 = *(_DWORD *)(iommu_cb_set + 14280LL * v21 + 8480);
        if ( v22 != -1 && v5 + v19 == v22 )
          break;
        if ( dword_394060 == ++v21 )
          goto LABEL_58;
      }
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_is_hdl_nonunique_or_null",
          1182,
          "iommu handle %d conflicts",
          v20);
    }
LABEL_58:
    *(_DWORD *)(iommu_cb_set + 14280LL * v8 + 8480) = v19 + v5;
    *(_DWORD *)(iommu_cb_set + 14280LL * v8 + 8584) = 0;
    v24 = iommu_cb_set;
    v25 = iommu_cb_set + 14280LL * v8;
    if ( *(_BYTE *)(v25 + 80) == 1 )
    {
      ++*(_DWORD *)(v25 + 8588);
      v24 = iommu_cb_set;
    }
    v26 = v24 + 14280LL * v8;
    if ( *(_BYTE *)(v26 + 8616) == 1 )
      ++*(_DWORD *)(v26 + 8620);
    *a2 = v19 + v5;
    v15 = 0;
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_create_add_handle_in_table",
        1269,
        "%s creates handle 0x%x",
        s2);
      v15 = 0;
    }
  }
  else
  {
    v18 = iommu_cb_set + 14280LL * v8;
    if ( *(_BYTE *)(v18 + 80) == 1 )
    {
      v15 = 0;
      ++*(_DWORD *)(v18 + 8588);
      *a2 = *(_DWORD *)(iommu_cb_set + 14280LL * v8 + 8480);
      goto LABEL_79;
    }
    v27 = *(_DWORD *)(v18 + 8480);
    if ( *(_BYTE *)(v18 + 8616) == 1 )
    {
      *a2 = v27;
      v28 = iommu_cb_set + 14280LL * v8;
      v29 = *(_DWORD *)(v28 + 8628);
      if ( !v29 )
        goto LABEL_77;
      if ( v29 < 1 )
        goto LABEL_72;
      v30 = *(_DWORD *)(v28 + 8620);
      if ( strcmp(*(const char **)(v28 + 8632), s2) )
      {
        if ( v29 == 1 )
          goto LABEL_72;
        if ( strcmp(*(const char **)(v28 + 8640), s2) )
        {
          if ( v29 == 2 )
          {
LABEL_72:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              64,
              1,
              "cam_smmu_update_multiregion_dev_id",
              1234,
              "%s not found as client in bank: %s",
              s2,
              *(const char **)(v28 + 32));
            v15 = -22;
            goto LABEL_78;
          }
LABEL_31:
          __break(0x5512u);
          goto LABEL_32;
        }
      }
      v31 = v27 | (v30 << 28);
      v15 = 0;
      *a2 = v31;
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_update_multiregion_dev_id",
          1228,
          "%s got shared multi region handle 0x%x",
          s2);
LABEL_77:
        v15 = 0;
      }
LABEL_78:
      ++*(_DWORD *)(iommu_cb_set + 14280LL * v8 + 8620);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_create_add_handle_in_table",
        1298,
        "Error: %s already got handle 0x%x",
        s2,
        v27);
      v15 = -114;
    }
  }
LABEL_79:
  mutex_unlock(iommu_cb_set + 14280LL * v8 + 8432);
  if ( (v15 & 0x80000000) == 0 )
  {
    v15 = 0;
    goto LABEL_36;
  }
LABEL_33:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_get_handle",
    3227,
    "Error: %s get handle fail, rc %d",
    s2,
    v15);
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return v15;
}
