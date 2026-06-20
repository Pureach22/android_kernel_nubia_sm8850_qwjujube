__int64 __fastcall cam_icp_mgr_process_io_cfg(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  int v4; // w8
  unsigned int *v5; // x21
  unsigned int *v6; // x24
  int v7; // w9
  int v8; // w26
  unsigned __int64 v9; // x28
  unsigned int v10; // w27
  __int64 v11; // x19
  _DWORD *v12; // x9
  int v13; // w6
  __int64 v14; // x10
  unsigned int *v15; // x10
  __int64 v16; // x8
  unsigned int v17; // w8
  __int64 v18; // x20
  __int64 v19; // x26
  __int64 v20; // x19
  unsigned int v21; // w27
  unsigned int v22; // w0
  unsigned int v23; // w8
  int v25; // w9
  int v26; // w12
  __int64 v27; // x19
  unsigned int v28; // w20
  unsigned int v29; // [xsp+34h] [xbp-6Ch]
  __int64 v30; // [xsp+38h] [xbp-68h]
  __int64 v31; // [xsp+40h] [xbp-60h]
  __int64 v32; // [xsp+48h] [xbp-58h]
  int v33; // [xsp+54h] [xbp-4Ch] BYREF
  _QWORD v34[9]; // [xsp+58h] [xbp-48h] BYREF

  v34[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(a3 + 72) = 0;
  v5 = (unsigned int *)(a3 + 72);
  v34[6] = 0;
  v34[7] = 0;
  *(_DWORD *)(a3 + 56) = 0;
  v6 = (unsigned int *)(a3 + 56);
  v7 = *(_DWORD *)(a2 + 36);
  memset(v34, 0, 48);
  v33 = 0;
  if ( !v7 )
    goto LABEL_21;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = a2 + (v4 & 0xFFFFFFFC) + 56;
  do
  {
    v12 = (_DWORD *)(v11 + ((__int64)(int)v10 << 8));
    v13 = v12[56];
    if ( (unsigned int)(v13 - 2) >= 2 )
    {
      if ( v13 != 1 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_process_io_cfg",
          6556,
          "dir: %d, max_out:%u, out %u",
          v13,
          *(_DWORD *)(a3 + 44),
          *(_DWORD *)(a3 + 56));
        v23 = -22;
        goto LABEL_26;
      }
      if ( v9 >= 0x10 )
        goto LABEL_31;
      v15 = v5;
      *((_DWORD *)v34 + v9++) = v12[48];
    }
    else
    {
      v14 = (__int64)v8++ << 6;
      *(_DWORD *)(*(_QWORD *)(a3 + 48) + v14 + 16) = v12[48];
      *(_DWORD *)(*(_QWORD *)(a3 + 48) + v14) = v12[47];
      v15 = v6;
    }
    v16 = debug_mdl & 0x1000100;
    ++*v15;
    if ( v16 && !debug_priority )
    {
      v31 = a2;
      v32 = a1;
      v30 = a3;
      v29 = a4;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v16,
        4,
        "cam_icp_mgr_process_io_cfg",
        6565,
        "%s: req_id: %llu dir[%d]: %u, fence: %u resource_type = %u memh %x",
        (const char *)(a1 + 29824),
        *(_QWORD *)(a2 + 8),
        v10,
        v12[56],
        v12[48],
        v12[47],
        *v12);
      a3 = v30;
      a2 = v31;
      a4 = v29;
      a1 = v32;
    }
    ++v10;
  }
  while ( v10 < *(_DWORD *)(a2 + 36) );
  v17 = *v5;
  if ( *v5 < 2 )
  {
LABEL_18:
    if ( v17 )
    {
      *(_DWORD *)(*(_QWORD *)(a3 + 64) + 16LL) = v34[0];
      *(_DWORD *)(a3 + 72) = 1;
      if ( a4 > 0x27 )
        goto LABEL_31;
      goto LABEL_25;
    }
LABEL_21:
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      v27 = a1;
      v28 = a4;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_process_io_cfg",
        6595,
        "%s: No input fences for req id: %llu",
        (const char *)(a1 + 29824),
        *(_QWORD *)(a2 + 8));
      a4 = v28;
      a1 = v27;
    }
    *v5 = 0;
    if ( a4 > 0x27 )
      goto LABEL_31;
LABEL_25:
    v23 = 0;
    *(_DWORD *)(a1 + 4LL * a4 + 4504) = 0;
    goto LABEL_26;
  }
  v18 = a2;
  v19 = a1;
  v20 = a3;
  v21 = a4;
  v17 = cam_common_util_remove_duplicate_arr((__int64)v34, v17);
  *v5 = v17;
  if ( v17 < 2 )
  {
    a1 = v19;
    a4 = v21;
    a2 = v18;
    a3 = v20;
    goto LABEL_18;
  }
  v22 = cam_sync_merge((__int64)v34, v17, &v33);
  if ( v22 )
  {
    v23 = v22;
    *v6 = 0;
    *v5 = 0;
    goto LABEL_26;
  }
  if ( v21 > 0x27 )
LABEL_31:
    __break(0x5512u);
  v25 = v33;
  v23 = 0;
  *(_DWORD *)(v19 + 4LL * v21 + 4504) = v33;
  v26 = debug_mdl;
  *(_DWORD *)(*(_QWORD *)(v20 + 64) + 16LL) = v25;
  *(_DWORD *)(v20 + 72) = 1;
  if ( (v26 & 0x1000100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v26 & 0x1000100,
      4,
      "cam_icp_mgr_process_io_cfg",
      6588,
      "%s: req_id: %llu Merged Sync obj: %d",
      (const char *)(v19 + 29824),
      *(_QWORD *)(v18 + 8),
      v25);
    v23 = 0;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v23;
}
