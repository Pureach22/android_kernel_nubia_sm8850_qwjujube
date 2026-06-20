__int64 __fastcall cam_context_prepare_dev_to_hw(__int64 a1, const void *a2)
{
  unsigned int v4; // w23
  __int64 *v5; // x20
  __int64 v6; // x21
  __int64 **v7; // x8
  __int64 *v8; // x9
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x24
  unsigned int *v11; // x8
  unsigned __int64 v12; // x6
  int v13; // w10
  __int64 v14; // x11
  unsigned int v15; // w9
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x9
  __int64 v19; // x8
  void *v20; // x0
  __int64 *v21; // x8
  _DWORD *v22; // x9
  __int64 v23; // x0
  __int64 *v24; // x1
  int v26; // w27
  int v27; // w8
  int v28; // w9
  unsigned int *v29; // x9
  __int64 v30; // x11
  __int64 v31; // x10
  unsigned int obj_ref; // w0
  int v33; // w8
  __int64 v34; // x24
  unsigned int v35; // w0
  unsigned int v36; // w9
  unsigned int v37; // w28
  unsigned int v38; // w0
  const char *v39; // x5
  __int64 v40; // x8
  __int64 v41; // x4
  __int64 v42; // x8
  __int64 v43; // x26
  __int64 v44; // x27
  bool v45; // cc
  unsigned int *v46; // [xsp+18h] [xbp-178h] BYREF
  _QWORD s[46]; // [xsp+20h] [xbp-170h] BYREF

  s[44] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x160u);
  v46 = nullptr;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_prepare_dev_to_hw",
      530,
      "Invalid input params %pK %pK",
      (const void *)a1,
      a2);
    v4 = -22;
    goto LABEL_33;
  }
  if ( !*(_QWORD *)(a1 + 208) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_prepare_dev_to_hw",
      536,
      "[%s][%d] HW interface is not ready",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    v4 = -14;
    goto LABEL_33;
  }
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 )
  {
    _warn_printk("Invalid execution context\n");
    __break(0x800u);
    v4 = -22;
    goto LABEL_33;
  }
  raw_spin_lock(a1 + 120);
  v6 = a1 + 176;
  v5 = *(__int64 **)(a1 + 176);
  if ( v5 == (__int64 *)(a1 + 176) )
  {
    raw_spin_unlock(a1 + 120);
LABEL_20:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_prepare_dev_to_hw",
      553,
      "[%s][%d] No more request obj free",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    v4 = -12;
    goto LABEL_33;
  }
  v7 = (__int64 **)v5[1];
  if ( *v7 == v5 && (v8 = (__int64 *)*v5, *(__int64 **)(*v5 + 8) == v5) )
  {
    v8[1] = (__int64)v7;
    *v7 = v8;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 176));
  }
  *v5 = (__int64)v5;
  v5[1] = (__int64)v5;
  raw_spin_unlock(a1 + 120);
  if ( !v5 )
    goto LABEL_20;
  if ( v5[17] )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      2,
      "cam_context_prepare_dev_to_hw",
      559,
      "[%s][%d] Missing free request local packet",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    cam_smmu_buffer_tracker_putref(v5 + 14);
    cam_common_mem_free(v5[17]);
    v5[17] = 0;
  }
  v5[14] = (__int64)(v5 + 14);
  v5[15] = (__int64)(v5 + 14);
  *v5 = (__int64)v5;
  v5[1] = (__int64)v5;
  v5[13] = a1;
  *((_DWORD *)v5 + 12) = 0;
  *((_DWORD *)v5 + 16) = 0;
  *((_DWORD *)v5 + 20) = 0;
  *((_DWORD *)v5 + 22) = 0;
  *((_DWORD *)v5 + 24) = 0;
  *((_DWORD *)v5 + 21) = 0;
  v9 = cam_context_parse_config_cmd(a1, a2, &v46);
  v4 = (unsigned int)v46;
  if ( !v46 || (unsigned __int64)v46 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_29;
  v10 = v9;
  if ( (unsigned int)cam_packet_util_validate_packet(v46, v9) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_prepare_dev_to_hw",
      583,
      "Invalid packet params");
    v4 = -22;
LABEL_28:
    cam_common_mem_free((__int64)v46);
LABEL_29:
    cam_smmu_buffer_tracker_putref(v5 + 14);
    v5[17] = 0;
    v5[13] = 0;
    raw_spin_lock(a1 + 120);
    v24 = *(__int64 **)(a1 + 184);
    if ( v24 == v5 || *v24 != v6 )
    {
      _list_add_valid_or_report(v5);
    }
    else
    {
      *(_QWORD *)(a1 + 184) = v5;
      *v5 = v6;
      v5[1] = (__int64)v24;
      *v24 = (__int64)v5;
    }
    raw_spin_unlock(a1 + 120);
    goto LABEL_33;
  }
  v11 = v46;
  v12 = *((_QWORD *)v46 + 1);
  if ( v12 <= *(unsigned int *)(a1 + 464) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      3,
      "cam_context_prepare_dev_to_hw",
      591,
      "request %lld has been flushed, reject packet",
      v12);
    v4 = -53;
    goto LABEL_28;
  }
  *(_DWORD *)(a1 + 464) = 0;
  v13 = *(_DWORD *)(a1 + 472);
  v14 = *(unsigned int *)(a1 + 476);
  v15 = *((_DWORD *)v5 + 12);
  s[0] = v11;
  s[1] = v10;
  s[5] = __PAIR64__(v14, v15);
  v16 = v5[5];
  HIDWORD(s[7]) = v13;
  s[6] = v5[9];
  v17 = v5[7];
  s[4] = v16;
  s[8] = v17;
  s[42] = v5 + 16;
  v18 = *(_QWORD *)(a1 + 264);
  v19 = v5[4];
  LODWORD(s[9]) = 0;
  s[2] = v18;
  s[40] = v19;
  s[41] = v5 + 14;
  LODWORD(v19) = *(_DWORD *)(a1 + 468);
  v20 = (void *)v5[9];
  LODWORD(s[7]) = 0;
  LODWORD(s[3]) = v19;
  memset(v20, 0, v14 << 6);
  v21 = *(__int64 **)(a1 + 208);
  v22 = (_DWORD *)v21[7];
  v23 = *v21;
  if ( *(v22 - 1) != 1863972096 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD *))v22)(v23, s) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_prepare_dev_to_hw",
      623,
      "[%s][%d] Prepare config packet failed in HW layer",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    v4 = -14;
    goto LABEL_28;
  }
  v26 = 0;
  *((_DWORD *)v5 + 12) = s[5];
  v27 = s[7];
  v28 = s[9];
  *((_DWORD *)v5 + 20) = s[7];
  *((_DWORD *)v5 + 16) = v28;
  *((_DWORD *)v5 + 21) = 0;
  v29 = v46;
  v30 = *((_QWORD *)v46 + 1);
  *((_DWORD *)v5 + 4) = 1;
  v5[3] = v30;
  v31 = s[40];
  v5[16] = (__int64)v5;
  v5[17] = (__int64)v29;
  v5[4] = v31;
  if ( v27 )
  {
    while ( 1 )
    {
      obj_ref = cam_sync_get_obj_ref(*(unsigned int *)(v5[9] + ((__int64)v26 << 6) + 16));
      if ( obj_ref )
        break;
      if ( (unsigned int)++v26 >= *((_DWORD *)v5 + 20) )
        goto LABEL_37;
    }
    v4 = obj_ref;
    v39 = "Can't get ref for sync %d";
    v40 = v5[9] + ((__int64)v26 << 6);
    v41 = 642;
LABEL_54:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_prepare_dev_to_hw",
      v41,
      v39,
      *(unsigned int *)(v40 + 16));
    v42 = (unsigned int)(v26 - 1);
    if ( v26 - 1 < 0 )
      goto LABEL_28;
    goto LABEL_55;
  }
LABEL_37:
  raw_spin_lock(a1 + 120);
  list_add_tail(v5, (_QWORD *)(a1 + 144));
  raw_spin_unlock(a1 + 120);
  if ( (*(_QWORD *)(a1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      3,
      "cam_context_prepare_dev_to_hw",
      653,
      "[%s][%d] : Moving req[%llu] from free_list to pending_list",
      (const char *)a1,
      *(_DWORD *)(a1 + 32),
      v5[3]);
  if ( *((_DWORD *)v5 + 16) )
  {
    v33 = 0;
    do
    {
      v34 = v33;
      v35 = cam_sync_check_valid(*(unsigned int *)(v5[7] + ((__int64)v33 << 6) + 16));
      if ( v35 )
      {
        v4 = v35;
        raw_spin_lock(a1 + 120);
        list_del_init(v5);
        raw_spin_unlock(a1 + 120);
        v39 = "invalid in map sync object %d";
        v40 = v5[7] + (v34 << 6);
        v41 = 665;
        goto LABEL_54;
      }
      v36 = *((_DWORD *)v5 + 16);
      v33 = v34 + 1;
    }
    while ( (int)v34 + 1 < v36 );
    if ( !v36 )
    {
      v4 = 0;
      goto LABEL_33;
    }
    v37 = 0;
    while ( 1 )
    {
      cam_context_getref(a1);
      v38 = cam_sync_register_callback(
              cam_context_sync_callback,
              v5,
              *(unsigned int *)(v5[7] + ((__int64)(int)v37 << 6) + 16));
      if ( v38 )
        break;
      if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x80000,
          4,
          "cam_context_prepare_dev_to_hw",
          695,
          "register in fence cb: %d ret = %d",
          *(_DWORD *)(v5[7] + ((__int64)(int)v37 << 6) + 16),
          0);
      ++v37;
      v4 = 0;
      if ( v37 >= *((_DWORD *)v5 + 16) )
        goto LABEL_33;
    }
    v4 = v38;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_prepare_dev_to_hw",
      680,
      "[%s][%d] Failed register fence cb: %d ret = %d",
      (const char *)a1,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(v5[7] + ((__int64)(int)v37 << 6) + 16),
      v38);
    raw_spin_lock(a1 + 120);
    list_del_init(v5);
    raw_spin_unlock(a1 + 120);
    if ( (*(_QWORD *)(a1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        3,
        "cam_context_prepare_dev_to_hw",
        689,
        "[%s][%d] : Moving req[%llu] from pending_list to free_list",
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        v5[3]);
    cam_context_putref(a1);
    v42 = (unsigned int)(v26 - 1);
    if ( v26 - 1 < 0 )
      goto LABEL_28;
LABEL_55:
    v43 = (v42 << 6) | 0x10;
    v44 = v42 + 1;
    do
    {
      if ( (unsigned int)cam_sync_put_obj_ref(*(unsigned int *)(v5[9] + v43)) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x80000,
          1,
          "cam_context_prepare_dev_to_hw",
          716,
          "Failed to put ref of fence %d",
          *(_DWORD *)(v5[9] + v43));
      v45 = v44-- <= 1;
      v43 -= 64;
    }
    while ( !v45 );
    goto LABEL_28;
  }
  mutex_lock(a1 + 416);
  v4 = cam_context_apply_req_to_hw(v5);
  mutex_unlock(a1 + 416);
  if ( v4 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_prepare_dev_to_hw",
      708,
      "[%s][%d] : Failed to apply req: %llu with no input dependencies",
      (const char *)a1,
      *(_DWORD *)(a1 + 32),
      v5[3]);
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return v4;
}
