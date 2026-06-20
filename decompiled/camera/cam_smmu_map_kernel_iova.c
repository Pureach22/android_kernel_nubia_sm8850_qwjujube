__int64 __fastcall cam_smmu_map_kernel_iova(
        signed int a1,
        _QWORD *a2,
        unsigned int a3,
        _QWORD *a4,
        _QWORD *a5,
        __int64 a6,
        __int64 a7)
{
  unsigned int v11; // w22
  unsigned int v13; // w0
  unsigned int v14; // w24
  unsigned int v15; // w24
  unsigned int v16; // w19
  __int64 v17; // x9
  int v18; // w6
  _QWORD *v20; // x8
  unsigned int v21; // w0
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x2
  __int64 *v27; // x1
  __int64 v28; // x21
  __int64 v29; // x8
  unsigned __int64 v30; // x22
  unsigned __int64 v37; // x9
  unsigned __int64 v38; // x9
  _QWORD v39[2]; // [xsp+10h] [xbp-10h] BYREF

  v11 = a6;
  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = cam_smmu_map_iova_validate_params(a1, a3, a4, a5, a6, a6, a7);
  if ( !v13 )
  {
    if ( a3 >= 3 )
    {
      v15 = 3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_translate_dir",
        1131,
        "Error: Direction is invalid. dir = %d",
        a3);
    }
    else
    {
      v15 = 2 - a3;
    }
    v16 = HIWORD(a1) & 0xFFF;
    mutex_lock(iommu_cb_set + 14280LL * v16 + 8432);
    v17 = iommu_cb_set + 14280LL * v16;
    if ( *(_BYTE *)(v17 + 80) == 1 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_map_kernel_iova",
        4047,
        "Error: can't map non-secure mem to secure cb");
    }
    else
    {
      v18 = *(_DWORD *)(v17 + 8480);
      if ( v18 == a1 )
      {
        if ( !*(_DWORD *)(v17 + 8484) )
        {
          v20 = (_QWORD *)(iommu_cb_set + 14280LL * v16 + 8416);
          while ( 1 )
          {
            v20 = (_QWORD *)*v20;
            if ( v20 == (_QWORD *)(iommu_cb_set + 14280LL * v16 + 8416) )
              break;
            if ( (_QWORD *)*(v20 - 7) == a2 )
            {
              *a4 = *(v20 - 1);
              *a5 = v20[4];
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                64,
                1,
                "cam_smmu_map_kernel_iova",
                4071,
                "dma_buf :%pK already in the list",
                a2);
              v14 = -114;
              goto LABEL_13;
            }
          }
          v39[0] = 0;
          v21 = cam_smmu_map_buffer_validate(a2, v16, (unsigned int)(a1 >> 28), v15, a4, a5, v11, 0, v39);
          if ( v21 )
          {
            v14 = v21;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              64,
              1,
              "cam_smmu_map_kernel_buffer_and_add_to_list",
              2936,
              "buffer validation failure");
            if ( (v14 & 0x80000000) != 0 )
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                64,
                1,
                "cam_smmu_map_kernel_iova",
                4079,
                "mapping or add list fail");
          }
          else
          {
            v22 = v39[0];
            *(int *)((char *)&_ksymtab_cam_cdm_publish_ops + v39[0]) = -1;
            *(_QWORD *)((char *)&unk_50 + v22) = *(_QWORD *)(*(_QWORD *)(a2[1] + 40LL) + 64LL);
            ktime_get_real_ts64(v22 + 112);
            v23 = iommu_cb_set + 14280LL * v16;
            v24 = v39[0];
            v25 = v39[0] + 56LL;
            v26 = *(_QWORD *)(v23 + 8416);
            v27 = (__int64 *)(v23 + 8416);
            if ( *(_QWORD *)(v26 + 8) != v23 + 8416 || (__int64 *)v25 == v27 || v26 == v25 )
            {
              _list_add_valid_or_report(v25);
            }
            else
            {
              *(_QWORD *)(v26 + 8) = v25;
              *(_QWORD *)((char *)&dword_38 + v24) = v26;
              *(_QWORD *)((char *)&dword_38 + v24 + 8) = v27;
              *v27 = v25;
            }
            if ( (debug_mdl & 0x40) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x40,
                4,
                "cam_smmu_map_kernel_buffer_and_add_to_list",
                2949,
                "fd %d i_ino %lu dmabuf %pK",
                *(int *)((char *)&_ksymtab_cam_cdm_publish_ops + v39[0]),
                *(_QWORD *)((char *)&unk_50 + v39[0]),
                a2);
            v28 = v39[0];
            v29 = iommu_cb_set + 14280LL * v16;
            _X10 = (unsigned __int64 *)(v29 + 8672);
            __asm { PRFM            #0x11, [X10] }
            do
            {
              v37 = __ldxr(_X10);
              v38 = v37 + 1;
            }
            while ( __stlxr(v38, _X10) );
            __dmb(0xBu);
            v30 = v29 + 56 * (v38 % 0x64);
            ktime_get_real_ts64(v30 + 8680);
            v14 = 0;
            *(_BYTE *)(v30 + 8696) = 1;
            *(_DWORD *)(v30 + 8700) = *(int *)((char *)&_ksymtab_cam_cdm_publish_ops + v28);
            *(_QWORD *)(v30 + 8704) = *(_QWORD *)((char *)&unk_50 + v28);
            *(_QWORD *)(v30 + 8712) = *(__int64 *)((char *)&_ksymtab_cam_cdm_get_iommu_handle + v28);
            *(_QWORD *)(v30 + 8720) = *(__int64 *)((char *)&qword_58 + v28);
            *(_DWORD *)(v30 + 8728) = *(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v28 + 4);
          }
          goto LABEL_13;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_map_kernel_iova",
          4062,
          "Err:Dev %s should call SMMU attach before map buffer",
          *(const char **)(v17 + 32));
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_map_kernel_iova",
          4054,
          "hdl is not valid, table_hdl = %x, hdl = %x",
          v18,
          a1);
      }
    }
    v14 = -22;
LABEL_13:
    mutex_unlock(iommu_cb_set + 14280LL * v16 + 8432);
    goto LABEL_14;
  }
  v14 = v13;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_map_kernel_iova",
    4038,
    "initial checks failed, unable to proceed");
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v14;
}
