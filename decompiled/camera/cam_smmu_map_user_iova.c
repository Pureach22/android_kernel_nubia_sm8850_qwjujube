__int64 __fastcall cam_smmu_map_user_iova(
        __int64 a1,
        int a2,
        _QWORD *a3,
        char a4,
        unsigned int a5,
        _QWORD *a6,
        _QWORD *a7,
        unsigned int a8,
        char a9,
        _QWORD *a10)
{
  int v17; // w23
  unsigned int v18; // w0
  unsigned int v19; // w25
  unsigned int v20; // w19
  __int64 v21; // x9
  __int64 v23; // x9
  __int64 *v24; // x8
  __int64 v25; // x9
  unsigned __int64 v26; // x9
  __int64 v27; // x13
  unsigned __int64 v28; // x10
  unsigned __int64 v29; // x12
  unsigned __int64 v30; // x11
  __int64 v31; // x14
  unsigned __int64 v32; // x9
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x7
  __int64 v35; // x10
  unsigned int v36; // w0
  __int64 v37; // x8
  __int64 v38; // x9
  char *v39; // x8
  __int64 v40; // x9
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x2
  __int64 *v44; // x1
  __int64 v45; // x21
  __int64 v46; // x8
  unsigned __int64 v47; // x22
  unsigned __int64 v54; // x9
  unsigned __int64 v55; // x9
  _QWORD v56[2]; // [xsp+50h] [xbp-10h] BYREF

  v17 = a1;
  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = cam_smmu_map_iova_validate_params(a1, a5, a6, a7, a8);
  if ( !v18 )
  {
    v20 = HIWORD(v17) & 0xFFF;
    mutex_lock(iommu_cb_set + 14280LL * v20 + 8432);
    v21 = iommu_cb_set + 14280LL * v20;
    if ( *(_BYTE *)(v21 + 80) == 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_map_user_iova",
        3973,
        "Error: can't map non-secure mem to secure cb idx=%d",
        v20);
    }
    else if ( *(_DWORD *)(v21 + 8480) == (v17 & 0xFFFFFFF) )
    {
      if ( !*(_DWORD *)(v21 + 8484) )
      {
        v23 = iommu_cb_set + 14280LL * v20;
        v24 = *(__int64 **)(v23 + 8400);
        v25 = v23 + 8400;
        if ( v24 == (__int64 *)v25 )
        {
LABEL_19:
          v56[0] = 0;
          v36 = cam_smmu_map_buffer_validate(a3, v20, (unsigned int)(v17 >> 28), a5, a6, a7, a8, a4 & 1, v56);
          if ( v36 )
          {
            v19 = v36;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              64,
              1,
              "cam_smmu_map_buffer_and_add_to_list",
              2900,
              "buffer validation failure");
            if ( (v19 & 0x80000000) != 0 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                64,
                1,
                "cam_smmu_map_user_iova",
                4017,
                "mapping or add list fail cb:%s idx=%d, fd=%d, region=%d, rc=%d",
                *(const char **)(iommu_cb_set + 14280LL * v20 + 32),
                v20,
                a2,
                a8,
                v19);
              ((void (__fastcall *)(_QWORD))cam_smmu_dump_cb_info)(v20);
            }
          }
          else
          {
            v37 = v56[0];
            *(int *)((char *)&_ksymtab_cam_cdm_publish_ops + v56[0]) = a2;
            v38 = *(_QWORD *)(*(_QWORD *)(a3[1] + 40LL) + 64LL);
            *(_DWORD *)((char *)&qword_28 + v37) = 1;
            v39 = (char *)&qword_28 + v37;
            *((_BYTE *)&qword_40 + (_QWORD)v39) = a9 & 1;
            *(__int64 *)((char *)&qword_28 + (_QWORD)v39) = v38;
            *a10 = v39;
            ktime_get_real_ts64(v39 + 72);
            v40 = iommu_cb_set + 14280LL * v20;
            v41 = v56[0];
            v42 = v56[0] + 56LL;
            v43 = *(_QWORD *)(v40 + 8400);
            v44 = (__int64 *)(v40 + 8400);
            if ( *(_QWORD *)(v43 + 8) != v40 + 8400 || (__int64 *)v42 == v44 || v43 == v42 )
            {
              _list_add_valid_or_report(v42);
            }
            else
            {
              *(_QWORD *)(v43 + 8) = v42;
              *(_QWORD *)((char *)&dword_38 + v41) = v43;
              *(_QWORD *)((char *)&dword_38 + v41 + 8) = v44;
              *v44 = v42;
            }
            if ( (debug_mdl & 0x40) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x40,
                4,
                "cam_smmu_map_buffer_and_add_to_list",
                2914,
                "fd %d i_ino %lu dmabuf %pK",
                a2,
                *(_QWORD *)((char *)&unk_50 + v56[0]),
                a3);
            v45 = v56[0];
            v46 = iommu_cb_set + 14280LL * v20;
            _X10 = (unsigned __int64 *)(v46 + 8672);
            __asm { PRFM            #0x11, [X10] }
            do
            {
              v54 = __ldxr(_X10);
              v55 = v54 + 1;
            }
            while ( __stlxr(v55, _X10) );
            __dmb(0xBu);
            v47 = v46 + 56 * (v55 % 0x64);
            ktime_get_real_ts64(v47 + 8680);
            v19 = 0;
            *(_BYTE *)(v47 + 8696) = 1;
            *(_DWORD *)(v47 + 8700) = *(int *)((char *)&_ksymtab_cam_cdm_publish_ops + v45);
            *(_QWORD *)(v47 + 8704) = *(_QWORD *)((char *)&unk_50 + v45);
            *(_QWORD *)(v47 + 8712) = *(__int64 *)((char *)&_ksymtab_cam_cdm_get_iommu_handle + v45);
            *(_QWORD *)(v47 + 8720) = *(__int64 *)((char *)&qword_58 + v45);
            *(_DWORD *)(v47 + 8728) = *(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v45 + 4);
          }
        }
        else
        {
          while ( *((_DWORD *)v24 + 4) != a2 || v24[3] != *(_QWORD *)(*(_QWORD *)(a3[1] + 40LL) + 64LL) )
          {
            v24 = (__int64 *)*v24;
            if ( v24 == (__int64 *)v25 )
              goto LABEL_19;
          }
          *a6 = *(v24 - 1);
          *a7 = v24[4];
          ++*((_DWORD *)v24 - 5);
          *a10 = v24 - 2;
          if ( v24 == (__int64 *)-56LL )
          {
            v32 = 0;
            v33 = 0;
            v34 = 0;
            v35 = 0;
          }
          else
          {
            v26 = v24[7];
            v27 = (unsigned __int128)(v24[8] * (__int128)0x431BDE82D7B634DBLL) >> 64;
            v28 = v26 / 0x3C;
            v29 = (v26 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64;
            v30 = v26 / 0xE10;
            v31 = (v26 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64;
            v32 = v26 % 0x3C;
            v33 = v28 - 60 * (v29 >> 1);
            v34 = v30 - 24 * v31;
            v35 = (v27 >> 18) + ((unsigned __int64)v27 >> 63);
          }
          v19 = 0;
          if ( (debug_mdl & 0x40) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40,
              4,
              "cam_smmu_map_user_iova",
              4005,
              "fd=%d already in list [%llu:%llu:%lu:%llu] cb=%s idx=%d handle=%d len=%llu,give same addr back",
              a2,
              v34,
              v33,
              v32,
              v35,
              *(const char **)(iommu_cb_set + 14280LL * v20 + 32),
              v20,
              v17,
              *a7);
            v19 = 0;
          }
        }
        goto LABEL_10;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_map_user_iova",
        3989,
        "Err:Dev %s should call SMMU attach before map buffer",
        *(const char **)(v21 + 32));
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_map_user_iova",
        3981,
        "hdl is not valid, idx=%d, table_hdl = %x, hdl = %x",
        v20);
    }
    v19 = -22;
LABEL_10:
    mutex_unlock(iommu_cb_set + 14280LL * v20 + 8432);
    goto LABEL_11;
  }
  v19 = v18;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_map_user_iova",
    3963,
    "initial checks failed, unable to proceed");
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v19;
}
