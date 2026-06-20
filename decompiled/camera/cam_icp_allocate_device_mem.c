__int64 __fastcall cam_icp_allocate_device_mem(__int64 a1)
{
  unsigned int region_info; // w0
  unsigned int v3; // w20
  const char *v4; // x5
  __int64 v5; // x6
  __int64 v6; // x4
  int v8; // w0
  int v9; // w0
  int v10; // w7
  __int16 v11; // w9
  int v12; // w0
  int v13; // w7
  int v14; // w0
  __int16 v15; // w9
  int v16; // w0
  int v17; // w7
  __int64 v18; // x8
  int v19; // w0
  __int16 v20; // w9
  int v21; // w0
  int v22; // w7
  __int64 v23; // x8
  __int16 v24; // w9
  int v25; // w0
  int v26; // w7
  int v27; // w10
  __int16 v28; // w9
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  region_info = cam_smmu_get_region_info(*(_DWORD *)(a1 + 148), 7, (_QWORD *)(a1 + 920));
  if ( region_info )
  {
    v3 = region_info;
    v4 = "[%s] Unable to get device memory info, rc: %d";
    v5 = a1 + 112;
    v6 = 4203;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_allocate_device_mem",
      v6,
      v4,
      v5,
      v3);
    goto LABEL_4;
  }
  v8 = *(_DWORD *)(a1 + 148);
  if ( *(_BYTE *)(a1 + 44236) == 1 )
  {
    v29 = 0;
    v30[0] = 0;
    v9 = cam_smmu_map_phy_mem_region(v8, 7u, 5u, &v29, v30);
    if ( v9 )
    {
      v3 = v9;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_allocate_llcc_register_mem",
        3865,
        "[%s] Failed in alloc llcc mem rc %d",
        (const char *)(a1 + 112),
        v9);
      v4 = "[%s] Unable to allocate llcc memory, rc: %d";
      v5 = a1 + 112;
      v6 = 4212;
      goto LABEL_3;
    }
    v10 = v29;
    v8 = *(_DWORD *)(a1 + 148);
    v11 = debug_mdl;
    *(_QWORD *)(a1 + 712) = v30[0];
    *(_DWORD *)(a1 + 696) = v10;
    *(_DWORD *)(a1 + 700) = v8;
    if ( (v11 & 0x100) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v11 & 0x100,
        4,
        "cam_icp_allocate_llcc_register_mem",
        3874,
        "[%s] iova: %llx, len: %zu",
        a1 + 112);
      v8 = *(_DWORD *)(a1 + 148);
    }
  }
  if ( *(_BYTE *)(a1 + 44235) == 1 )
  {
    v29 = 0;
    v30[0] = 0;
    v12 = cam_smmu_map_phy_mem_region(v8, 6u, 3u, &v29, v30);
    if ( v12 )
    {
      v3 = v12;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_allocate_global_sync_mem",
        3891,
        "[%s] Failed in allocating global sync ipc mem rc %d",
        (const char *)(a1 + 112),
        v12);
LABEL_25:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_allocate_device_mem",
        4222,
        "[%s] Unable to allocate IPC memory, rc: %d",
        (const char *)(a1 + 112),
        v3);
LABEL_32:
      if ( *(_BYTE *)(a1 + 44236) == 1 )
        cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 5);
      goto LABEL_4;
    }
    v13 = v29;
    v14 = *(_DWORD *)(a1 + 148);
    v15 = debug_mdl;
    *(_QWORD *)(a1 + 552) = v30[0];
    *(_DWORD *)(a1 + 536) = v13;
    *(_DWORD *)(a1 + 540) = v14;
    if ( (v15 & 0x100) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v15 & 0x100,
        4,
        "cam_icp_allocate_global_sync_mem",
        3900,
        "[%s] iova: %llx, len: %zu",
        a1 + 112);
      v14 = *(_DWORD *)(a1 + 148);
    }
    v29 = 0;
    v30[0] = 0;
    v16 = cam_smmu_map_phy_mem_region(v14, 7u, 1u, &v29, v30);
    if ( v16 )
    {
      v3 = v16;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_allocate_device_synx_hwmutex_mem",
        3916,
        "Failed in allocating hwmutex mem rc %d",
        v16);
LABEL_24:
      cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 6, 3);
      goto LABEL_25;
    }
    v17 = v29;
    v18 = v30[0];
    v19 = *(_DWORD *)(a1 + 148);
    v20 = debug_mdl;
    *(_DWORD *)(a1 + 580) = v19;
    *(_QWORD *)(a1 + 592) = v18;
    *(_DWORD *)(a1 + 576) = v17;
    if ( (v20 & 0x100) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v20 & 0x100,
        4,
        "cam_icp_allocate_device_synx_hwmutex_mem",
        3925,
        "[%s] iova: %llx, len: %zu",
        a1 + 112);
      v19 = *(_DWORD *)(a1 + 148);
    }
    v29 = 0;
    v30[0] = 0;
    v21 = cam_smmu_map_phy_mem_region(v19, 7u, 2u, &v29, v30);
    if ( v21 )
    {
      v3 = v21;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_allocate_device_ipc_hwmutex_mem",
        3968,
        "Failed in allocating hwmutex mem rc %d",
        v21);
      cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 1);
      goto LABEL_24;
    }
    v22 = v29;
    v23 = v30[0];
    v8 = *(_DWORD *)(a1 + 148);
    v24 = debug_mdl;
    *(_DWORD *)(a1 + 620) = v8;
    *(_QWORD *)(a1 + 632) = v23;
    *(_DWORD *)(a1 + 616) = v22;
    if ( (v24 & 0x100) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v24 & 0x100,
        4,
        "cam_icp_allocate_device_ipc_hwmutex_mem",
        3977,
        "[%s] iova: %llx, len: %zu",
        a1 + 112);
      v8 = *(_DWORD *)(a1 + 148);
    }
  }
  v29 = 0;
  v30[0] = 0;
  v25 = cam_smmu_map_phy_mem_region(v8, 7u, 4u, &v29, v30);
  if ( v25 )
  {
    v3 = v25;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_allocate_device_global_cnt_mem",
      3942,
      "Failed in allocating global cntr mem rc %d",
      v25);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_allocate_device_mem",
      4231,
      "[%s] Unable to allocate global cnt memory, rc: %d",
      (const char *)(a1 + 112),
      v3);
    if ( *(_BYTE *)(a1 + 44235) == 1 )
    {
      cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 2);
      cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 1);
      cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 3);
    }
    goto LABEL_32;
  }
  v26 = v29;
  v27 = *(_DWORD *)(a1 + 148);
  v28 = debug_mdl;
  *(_QWORD *)(a1 + 672) = v30[0];
  *(_DWORD *)(a1 + 656) = v26;
  *(_DWORD *)(a1 + 660) = v27;
  if ( (v28 & 0x100) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v28 & 0x100,
      4,
      "cam_icp_allocate_device_global_cnt_mem",
      3951,
      "[%s] iova: %llx, len: %zu",
      a1 + 112);
  v3 = 0;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return v3;
}
