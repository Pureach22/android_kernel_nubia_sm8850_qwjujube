__int64 __fastcall cam_icp_allocate_hfi_mem(__int64 a1)
{
  unsigned int region_info; // w0
  unsigned int v3; // w20
  const char *v4; // x5
  __int64 v5; // x6
  __int64 v6; // x4
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x7
  __int64 v11; // x8
  __int64 v12; // x11
  __int64 v13; // x7
  __int64 v14; // x9
  __int16 v15; // w10
  int v16; // w0
  unsigned int v17; // w0
  __int64 v18; // x0
  int v19; // w7
  __int64 v20; // x8
  __int16 v21; // w9
  unsigned int device_mem; // w0
  int v23; // w0
  unsigned int shared_mem; // w0
  __int64 v25; // x7
  __int64 v26; // x9
  __int64 v27; // x8
  int v28; // w11
  __int16 v29; // w10
  int v30; // w8
  __int64 v31; // x1
  int v32; // [xsp+8h] [xbp-A8h]
  __int64 v33; // [xsp+10h] [xbp-A0h]
  __int64 v34; // [xsp+88h] [xbp-28h] BYREF
  __int64 v35; // [xsp+90h] [xbp-20h] BYREF
  __int64 v36; // [xsp+98h] [xbp-18h] BYREF
  _QWORD v37[2]; // [xsp+A0h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  region_info = cam_smmu_get_region_info(*(_DWORD *)(a1 + 148), 1, (_QWORD *)(a1 + 728));
  if ( region_info )
  {
    v3 = region_info;
    v4 = "[%s] Unable to get shared memory info, rc: %d";
    v5 = a1 + 112;
    v6 = 4263;
LABEL_5:
    v9 = v3;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_allocate_hfi_mem",
      v6,
      v4,
      v5,
      v9);
    goto LABEL_7;
  }
  v7 = *(unsigned int *)(a1 + 148);
  v36 = 0;
  v37[0] = 0;
  v34 = 0;
  v35 = 0;
  v8 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD *, __int64 *, __int64 *))cam_smmu_get_io_region_info)(
         v7,
         &v35,
         v37,
         &v34,
         &v36);
  if ( (_DWORD)v8 )
  {
    v3 = v8;
    v4 = "[%s] Unable to get I/O region info, rc: %d";
    v5 = a1 + 112;
    v6 = 4270;
    goto LABEL_5;
  }
  v12 = v36;
  v11 = v37[0];
  v14 = v34;
  v13 = v35;
  v15 = debug_mdl;
  *(_QWORD *)(a1 + 800) = v37[0];
  *(_QWORD *)(a1 + 792) = v13;
  *(_QWORD *)(a1 + 808) = v14;
  *(_QWORD *)(a1 + 816) = v12;
  if ( (v15 & 0x100) != 0 && !debug_priority )
    v8 = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           v15 & 0x100,
           4,
           "cam_icp_get_io_mem_info",
           4030,
           "[%s] iova: %llx, len: %zu discard iova %llx len %llx",
           (const char *)(a1 + 112),
           v13,
           v11,
           v14,
           v12);
  if ( (*(_BYTE *)(a1 + 44232) & 1) == 0 )
  {
    v36 = 0;
    v37[0] = 0;
    v35 = 0;
    if ( (cam_presil_mode_enabled(v8) & 1) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        3,
        "cam_icp_allocate_fw_mem",
        3806,
        "PRESIL-ICP-B2B-HFI-INIT No Shutdown No Deinit No HFIfreeMem");
    }
    else
    {
      v23 = cam_smmu_alloc_firmware(*(_DWORD *)(a1 + 148), &v35, v37, &v36);
      if ( v23 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_allocate_fw_mem",
          3814,
          "[%s] Failed in alloc firmware rc %d",
          (const char *)(a1 + 112),
          v23);
        v4 = "[%s] Unable to allocate FW memory, rc: %d";
        v5 = a1 + 112;
        v6 = 4277;
        v9 = 4294967284LL;
        v3 = -12;
        goto LABEL_6;
      }
      v26 = v36;
      v25 = v37[0];
      v27 = v35;
      v28 = *(_DWORD *)(a1 + 148);
      v29 = debug_mdl;
      *(_DWORD *)(a1 + 376) = v35;
      *(_QWORD *)(a1 + 392) = v26;
      *(_QWORD *)(a1 + 368) = v25;
      *(_DWORD *)(a1 + 380) = v28;
      if ( (v29 & 0x100) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v29 & 0x100,
          4,
          "cam_icp_allocate_fw_mem",
          3825,
          "[%s], kva: %zX, iova: %llx, len: %zu",
          (const char *)(a1 + 112),
          v25,
          v27,
          v26);
    }
  }
  v16 = *(_DWORD *)(a1 + 148);
  v36 = 0;
  v37[0] = 0;
  v17 = cam_smmu_map_phy_mem_region(v16, 5u, 0, &v36, v37);
  if ( v17 )
  {
    v3 = v17;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_allocate_qdss_mem",
      3840,
      "[%s] Failed in alloc qdss mem rc %d",
      (const char *)(a1 + 112),
      v17);
    v18 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_allocate_hfi_mem",
            4284,
            "[%s] Unable to allocate qdss memory, rc: %d",
            (const char *)(a1 + 112),
            v3);
    if ( (*(_BYTE *)(a1 + 44232) & 1) != 0 )
      goto LABEL_7;
    goto LABEL_27;
  }
  v19 = v36;
  v20 = v37[0];
  v21 = debug_mdl;
  *(_DWORD *)(a1 + 420) = *(_DWORD *)(a1 + 148);
  *(_QWORD *)(a1 + 432) = v20;
  *(_DWORD *)(a1 + 416) = v19;
  if ( (v21 & 0x100) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v21 & 0x100,
      4,
      "cam_icp_allocate_qdss_mem",
      3849,
      "[%s] iova: %llx, len: %zu",
      a1 + 112);
  device_mem = cam_icp_allocate_device_mem(a1);
  if ( device_mem )
  {
    v3 = device_mem;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_allocate_hfi_mem",
      4291,
      "[%s] Unable to allocate device memory, rc: %d",
      (const char *)(a1 + 112),
      device_mem);
    goto LABEL_26;
  }
  shared_mem = cam_icp_allocate_shared_mem(a1);
  if ( shared_mem )
  {
    v3 = shared_mem;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_allocate_hfi_mem",
      4298,
      "[%s] Unable to allocate shared/fwuncached memory, rc: %d",
      (const char *)(a1 + 112),
      shared_mem);
    cam_icp_free_device_mem(a1);
LABEL_26:
    v18 = cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 5, 0);
    if ( (*(_BYTE *)(a1 + 44232) & 1) != 0 )
      goto LABEL_7;
LABEL_27:
    if ( (cam_presil_mode_enabled(v18) & 1) != 0 )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        3,
        "cam_icp_free_fw_mem",
        3687,
        "PRESIL-ICP-B2B-HFI-INIT No Shutdown No Deinit No HFIfreeMem");
    else
      ((void (__fastcall *)(_QWORD))cam_smmu_dealloc_firmware)(*(unsigned int *)(a1 + 148));
    goto LABEL_7;
  }
  v30 = debug_priority;
  v31 = debug_mdl & 0x100;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v31,
      4,
      "cam_icp_allocate_hfi_mem",
      4304,
      "[%s] Shared Region [0x%x %lld] FW Uncached nested Region [0x%x %lld]",
      (const char *)(a1 + 112),
      *(_QWORD *)(a1 + 856),
      *(_QWORD *)(a1 + 864),
      v32,
      v33);
    v30 = debug_priority;
    v31 = debug_mdl & 0x100;
    if ( (debug_mdl & 0x100) != 0 )
    {
LABEL_36:
      if ( !v30 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v31,
          4,
          "cam_icp_allocate_hfi_mem",
          4312,
          "[%s] Shared Region [0x%x %lld] FwUncached[0x%x %lld] FwUncached_Generic[0x%x %p %lld] ",
          (const char *)(a1 + 112),
          *(_QWORD *)(a1 + 728),
          *(_QWORD *)(a1 + 736),
          *(_QWORD *)(a1 + 856),
          *(_QWORD *)(a1 + 864),
          *(_DWORD *)(a1 + 496),
          *(const void **)(a1 + 488),
          *(_QWORD *)(a1 + 512));
        v30 = debug_priority;
        v31 = debug_mdl & 0x100;
      }
    }
  }
  else if ( (debug_mdl & 0x100) != 0 )
  {
    goto LABEL_36;
  }
  v3 = 0;
  if ( v31 && !v30 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v31,
      4,
      "cam_icp_allocate_hfi_mem",
      4322,
      "[%s] QTbl[0x%x %p %lld] CmdQ[0x%x %p %lld] MsgQ[0x%x %p %lld] DbgQ[0x%x %p %lld] SFR[0x%x %p %lld] SecHeap[0x%x %p %lld]",
      (const char *)(a1 + 112),
      *(_DWORD *)(a1 + 176),
      *(const void **)(a1 + 168),
      *(_QWORD *)(a1 + 192),
      *(_DWORD *)(a1 + 216),
      *(const void **)(a1 + 208),
      *(_QWORD *)(a1 + 232),
      *(_DWORD *)(a1 + 256),
      *(const void **)(a1 + 248),
      *(_QWORD *)(a1 + 272),
      *(_DWORD *)(a1 + 296),
      *(const void **)(a1 + 288),
      *(_QWORD *)(a1 + 312),
      *(_DWORD *)(a1 + 456),
      *(const void **)(a1 + 448),
      *(_QWORD *)(a1 + 472),
      *(_DWORD *)(a1 + 336),
      *(const void **)(a1 + 328),
      *(_QWORD *)(a1 + 352));
    v3 = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v3;
}
