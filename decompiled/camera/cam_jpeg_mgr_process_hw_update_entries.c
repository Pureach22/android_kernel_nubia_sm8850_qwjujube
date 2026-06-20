__int64 __fastcall cam_jpeg_mgr_process_hw_update_entries(_QWORD *a1, _QWORD *a2)
{
  __int64 v4; // x0
  __int64 *v5; // x20
  __int64 v6; // x8
  _QWORD *v7; // x25
  unsigned int v8; // w22
  __int64 v9; // x8
  __int64 **v10; // x8
  __int64 *v11; // x9
  __int64 v12; // x27
  __int64 v13; // x24
  __int64 *v14; // x23
  __int64 v15; // x21
  _QWORD *v16; // x28
  __int64 v17; // x9
  __int64 (__fastcall *v18)(__int64, __int64 *, __int64); // x8
  __int64 v19; // x0
  const char *v20; // x5
  __int64 v21; // x4
  const char *v22; // x5
  __int64 v23; // x4
  int v24; // w8
  __int64 *v25; // x9
  __int64 v26; // x9
  __int64 (__fastcall *v27)(__int64, __int64, __int64 (__fastcall **)(), __int64); // x8
  __int64 v28; // x0
  unsigned int v29; // w0
  __int64 v30; // x10
  __int64 v31; // x10
  __int64 v32; // x9
  _DWORD *v33; // x11
  int v34; // w12
  _DWORD *v35; // x8
  __int64 v36; // x0
  int v37; // w8
  _DWORD *v38; // x8
  __int64 v39; // x0
  __int64 v40; // x9
  _DWORD *v41; // x8
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x8
  _QWORD *v46; // [xsp+8h] [xbp-108h] BYREF
  __int64 v47; // [xsp+10h] [xbp-100h]
  __int64 (__fastcall *v48)(); // [xsp+18h] [xbp-F8h] BYREF
  __int64 *v49; // [xsp+20h] [xbp-F0h]
  __int64 v50; // [xsp+28h] [xbp-E8h]
  __int64 v51; // [xsp+30h] [xbp-E0h]
  _QWORD v52[2]; // [xsp+38h] [xbp-D8h] BYREF
  _QWORD v53[21]; // [xsp+48h] [xbp-C8h] BYREF
  __int64 v54; // [xsp+F0h] [xbp-20h]
  __int64 v55; // [xsp+F8h] [xbp-18h]
  __int64 v56; // [xsp+100h] [xbp-10h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  v51 = 0;
  v48 = nullptr;
  v49 = nullptr;
  v54 = 0;
  v55 = 0;
  memset(v53, 0, sizeof(v53));
  v46 = nullptr;
  v47 = 0;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_process_hw_update_entries",
      764,
      "Invalid arguments %pK %pK",
      a1,
      a2);
    v8 = -22;
LABEL_76:
    _ReadStatusReg(SP_EL0);
    return v8;
  }
  v4 = mutex_lock(a1);
  v5 = (__int64 *)a1[660];
  if ( v5 == a1 + 660 )
  {
    v8 = -14;
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_mgr_process_hw_update_entries",
        771,
        "no available request");
    goto LABEL_75;
  }
  if ( !v5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_process_hw_update_entries",
      779,
      "no request");
    v8 = -14;
    goto LABEL_75;
  }
  v6 = *((unsigned int *)v5 + 20);
  if ( (unsigned int)v6 >= 2 )
    goto LABEL_77;
  v7 = a1 + 657;
  if ( *((_DWORD *)a1 + v6 + 1314) )
  {
    v8 = -14;
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_mgr_process_hw_update_entries",
        789,
        "Not dequeing, just return");
    goto LABEL_75;
  }
  *((_DWORD *)v7 + v6) = 1;
  v9 = *((unsigned int *)v5 + 20);
  if ( (unsigned int)v9 > 1 )
    goto LABEL_77;
  a1[v9 + 658] = v5;
  v10 = (__int64 **)v5[1];
  if ( *v10 == v5 && (v11 = (__int64 *)*v5, *(__int64 **)(*v5 + 8) == v5) )
  {
    v11[1] = (__int64)v10;
    *v10 = v11;
  }
  else
  {
    v4 = _list_del_entry_valid_or_report(v5);
  }
  *v5 = (__int64)v5;
  v5[1] = (__int64)v5;
  v12 = v5[7];
  v13 = a2[2];
  if ( v13 == *(_QWORD *)(v12 + 8) || (debug_mdl & 0x200) == 0 || debug_priority )
  {
    if ( *((_DWORD *)v5 + 6) )
      goto LABEL_23;
LABEL_70:
    v22 = "No hw update enteries are available";
    v23 = 803;
    goto LABEL_71;
  }
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
         3,
         debug_mdl & 0x200,
         4,
         "cam_jpeg_mgr_process_hw_update_entries",
         799,
         "Probably received req from Bottom half. req %zd %zd",
         v13);
  if ( !*((_DWORD *)v5 + 6) )
    goto LABEL_70;
LABEL_23:
  v14 = (__int64 *)v5[2];
  if ( (v14[13] & 1) == 0 )
  {
    v22 = "ctx is not in use";
    v23 = 810;
LABEL_71:
    v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           512,
           1,
           "cam_jpeg_mgr_process_hw_update_entries",
           v23,
           v22);
    v8 = -22;
    goto LABEL_72;
  }
  v15 = *((unsigned int *)v14 + 14);
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           debug_mdl & 0x200,
           4,
           "cam_jpeg_mgr_process_hw_update_entries",
           818,
           "req_id: %u, dev_type: %u",
           v13,
           v15);
  if ( (_DWORD)v15 != *((_DWORD *)v5 + 20) )
    v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           512,
           2,
           "cam_jpeg_mgr_process_hw_update_entries",
           821,
           "dev types not same something wrong");
  if ( (unsigned int)v15 > 1 )
    goto LABEL_77;
  v16 = a1 + 649;
  v17 = *(_QWORD *)a1[v15 + 649];
  v18 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v17 + 16);
  if ( !v18 )
  {
    v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           512,
           1,
           "cam_jpeg_mgr_process_hw_update_entries",
           824,
           "hw op init null ");
    v8 = -14;
    goto LABEL_72;
  }
  v19 = *(_QWORD *)(v17 + 112);
  if ( *((_DWORD *)v18 - 1) != 1989616049 )
    __break(0x8228u);
  v4 = v18(v19, v14, 208);
  if ( !(_DWORD)v4 )
  {
    if ( *((_BYTE *)v14 + 188) == 1 && v14[21] == v13 )
    {
      v8 = 0;
      v24 = 1;
LABEL_50:
      v30 = *((unsigned int *)v5 + 12);
      LODWORD(v53[0]) = v30;
      if ( (_DWORD)v30 )
      {
        v31 = v30 << 6;
        v32 = 0;
        v33 = (_DWORD *)v53 + 1;
        while ( v32 != 2304 )
        {
          v34 = *(_DWORD *)(v5[5] + v32);
          v32 += 64;
          *v33++ = v34;
          if ( v31 == v32 )
            goto LABEL_54;
        }
        goto LABEL_77;
      }
LABEL_54:
      v54 = *(_QWORD *)(v12 + 8);
      if ( !v24 )
        goto LABEL_60;
      v35 = (_DWORD *)v14[12];
      v52[0] = v53;
      v52[1] = v14 + 20;
      if ( v35 )
      {
        v36 = *v14;
        if ( *(v35 - 1) != 414296116 )
          __break(0x8228u);
        v4 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v35)(v36, 1, v52);
      }
      v37 = *((unsigned __int8 *)v14 + 160);
      *((_BYTE *)v14 + 188) = 0;
      if ( v37 )
      {
LABEL_60:
        LODWORD(v47) = 1;
        v38 = (_DWORD *)v14[12];
        v46 = v53;
        v39 = *v14;
        if ( *(v38 - 1) != 414296116 )
          __break(0x8228u);
        v4 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD **))v38)(v39, 0, &v46);
      }
      v40 = *(_QWORD *)v16[v15];
      v41 = *(_DWORD **)(v40 + 24);
      if ( !v41 )
        goto LABEL_72;
      v42 = *(_QWORD *)(v40 + 112);
      if ( *(v41 - 1) != 1989616049 )
        __break(0x8228u);
      v4 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v41)(v42, 0, 0);
      v8 = v4;
      if ( !(_DWORD)v4 )
        goto LABEL_72;
      v20 = "Failed to Deinit %lu HW";
      v21 = 900;
      goto LABEL_35;
    }
    v25 = (__int64 *)v16[v15];
    v48 = cam_jpeg_hw_mgr_sched_bottom_half;
    v49 = v14;
    v50 = v12;
    LODWORD(v51) = 1;
    v26 = *v25;
    v27 = *(__int64 (__fastcall **)(__int64, __int64, __int64 (__fastcall **)(), __int64))(v26 + 88);
    if ( !v27 )
    {
      v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             512,
             1,
             "cam_jpeg_mgr_process_hw_update_entries",
             848,
             "op process_cmd null ");
      v24 = 0;
      v8 = -14;
      LODWORD(v55) = 154;
      goto LABEL_50;
    }
    v28 = *(_QWORD *)(v26 + 112);
    if ( *((_DWORD *)v27 - 1) != -1055839300 )
      __break(0x8228u);
    v29 = v27(v28, 1, &v48, 32);
    if ( v29 )
    {
      v8 = v29;
      v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             512,
             1,
             "cam_jpeg_mgr_process_hw_update_entries",
             858,
             "SET_IRQ_CB failed %d",
             v29);
      v24 = 0;
      LODWORD(v55) = 155;
      goto LABEL_50;
    }
    v8 = ((__int64 (__fastcall *)(_QWORD *, __int64 *, _QWORD *))cam_jpeg_process_next_hw_update)(a1, v14, v53);
    if ( v8 )
    {
      v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             512,
             1,
             "cam_jpeg_mgr_process_hw_update_entries",
             866,
             "next hw update failed %d",
             v8);
      v24 = 0;
      goto LABEL_50;
    }
    v5[12] = ktime_get_with_offset(1);
LABEL_75:
    mutex_unlock(a1);
    goto LABEL_76;
  }
  v8 = v4;
  v20 = "Failed to Init %d HW";
  v21 = 833;
LABEL_35:
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
         3,
         512,
         1,
         "cam_jpeg_mgr_process_hw_update_entries",
         v21,
         v20,
         (unsigned int)v15);
LABEL_72:
  v43 = *((unsigned int *)v5 + 20);
  if ( (unsigned int)v43 <= 1 )
  {
    *((_DWORD *)v7 + v43) = 0;
    v44 = *((unsigned int *)v5 + 20);
    if ( (unsigned int)v44 <= 1 )
    {
      a1[v44 + 658] = 0;
      goto LABEL_75;
    }
  }
LABEL_77:
  __break(0x5512u);
  return cam_jpeg_mgr_move_req_to_free_list(v4);
}
