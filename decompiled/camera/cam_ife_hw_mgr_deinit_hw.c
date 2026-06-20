__int64 __fastcall cam_ife_hw_mgr_deinit_hw(__int64 result)
{
  _BYTE *v1; // x22
  __int64 v2; // x19
  _BYTE *v3; // x23
  _QWORD *i; // x28
  __int64 v5; // x1
  __int64 v6; // x9
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x9
  __int64 (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x0
  __int64 *j; // x28
  __int64 v14; // x1
  __int64 v15; // x9
  __int64 (__fastcall *v16)(_QWORD); // x8
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x9
  __int64 (__fastcall *v20)(_QWORD); // x8
  __int64 v21; // x0
  unsigned int v22; // w20
  __int64 v23; // x21
  __int64 v24; // x1
  __int64 v25; // x9
  __int64 (__fastcall *v26)(_QWORD); // x8
  __int64 v27; // x0
  __int64 v28; // x1
  __int64 v29; // x9
  __int64 (__fastcall *v30)(_QWORD); // x8
  __int64 v31; // x0
  __int64 *k; // x27
  __int64 v33; // x1
  __int64 v34; // x9
  __int64 (__fastcall *v35)(_QWORD); // x8
  __int64 v36; // x0
  __int64 v37; // x1
  __int64 v38; // x9
  __int64 (__fastcall *v39)(_QWORD); // x8
  __int64 v40; // x0
  __int64 *m; // x28
  __int64 v42; // x1
  __int64 v43; // x9
  __int64 (__fastcall *v44)(_QWORD); // x8
  __int64 v45; // x0
  __int64 v46; // x1
  __int64 v47; // x9
  __int64 (__fastcall *v48)(_QWORD); // x8
  __int64 v49; // x0
  unsigned int v50; // w20
  __int64 v51; // x21
  __int64 v52; // x1
  __int64 v53; // x9
  __int64 (__fastcall *v54)(_QWORD); // x8
  __int64 v55; // x0
  __int64 v56; // x1
  __int64 v57; // x9
  __int64 (__fastcall *v58)(_QWORD); // x8
  __int64 v59; // x0
  int v60; // w8
  int v61; // w8
  int v62; // w8
  int v63; // w8
  int v64; // w8
  unsigned __int64 v65; // x12
  unsigned __int64 v66; // x8
  unsigned int *v67; // x9
  _BYTE *v68; // x10

  v1 = (_BYTE *)(result + 0x2000);
  v2 = result;
  if ( (*(_BYTE *)(result + 9377) & 1) == 0 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             2,
             "cam_ife_hw_mgr_deinit_hw",
             1876,
             "ctx is not in init state, ctx_idx: %u",
             *(_DWORD *)(result + 56));
  v3 = *(_BYTE **)(result + 72);
  if ( v3[81882] == 1 )
    result = cam_ife_hw_mgr_reset_csid(result, 0);
  for ( i = *(_QWORD **)(v2 + 208); i != (_QWORD *)(v2 + 208); i = (_QWORD *)*i )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 8,
                 4,
                 "cam_ife_hw_mgr_deinit_hw",
                 1888,
                 "%s: Going to DeInit IFE CSID\n ctx_idx: %u",
                 "cam_ife_hw_mgr_deinit_hw",
                 *(_DWORD *)(v2 + 56));
      v5 = i[4];
      if ( v5 )
      {
LABEL_10:
        v6 = *(_QWORD *)(v5 + 16);
        v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 24);
        if ( v7 )
        {
          v8 = *(_QWORD *)(v6 + 112);
          if ( *((_DWORD *)v7 - 1) != 1989616049 )
            __break(0x8228u);
          result = v7(v8);
        }
      }
    }
    else
    {
      v5 = i[4];
      if ( v5 )
        goto LABEL_10;
    }
    v9 = i[5];
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 16);
      v11 = *(__int64 (__fastcall **)(_QWORD))(v10 + 24);
      if ( v11 )
      {
        v12 = *(_QWORD *)(v10 + 112);
        if ( *((_DWORD *)v11 - 1) != 1989616049 )
          __break(0x8228u);
        result = v11(v12);
      }
    }
  }
  if ( *(_DWORD *)(v2 + 9312) == 2 )
  {
    for ( j = *(__int64 **)(v2 + 240); j != (__int64 *)(v2 + 240); j = (__int64 *)*j )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   debug_mdl & 8,
                   4,
                   "cam_ife_hw_mgr_deinit_hw",
                   1896,
                   "Going to DeInit SFE SRC %u, ctx_idx: %u",
                   *((_DWORD *)j + 5),
                   *(_DWORD *)(v2 + 56));
        v14 = j[4];
        if ( v14 )
        {
LABEL_29:
          v15 = *(_QWORD *)(v14 + 16);
          v16 = *(__int64 (__fastcall **)(_QWORD))(v15 + 24);
          if ( v16 )
          {
            v17 = *(_QWORD *)(v15 + 112);
            if ( *((_DWORD *)v16 - 1) != 1989616049 )
              __break(0x8228u);
            result = v16(v17);
          }
        }
      }
      else
      {
        v14 = j[4];
        if ( v14 )
          goto LABEL_29;
      }
      v18 = j[5];
      if ( v18 )
      {
        v19 = *(_QWORD *)(v18 + 16);
        v20 = *(__int64 (__fastcall **)(_QWORD))(v19 + 24);
        if ( v20 )
        {
          v21 = *(_QWORD *)(v19 + 112);
          if ( *((_DWORD *)v20 - 1) != 1989616049 )
            __break(0x8228u);
          result = v20(v21);
        }
      }
    }
    if ( *(_DWORD *)(v2 + 8516) )
    {
      v22 = 0;
      do
      {
        v23 = *(_QWORD *)(v2 + 280) + ((__int64)(int)v22 << 7);
        v24 = *(_QWORD *)(v23 + 32);
        if ( v24 )
        {
          v25 = *(_QWORD *)(v24 + 16);
          v26 = *(__int64 (__fastcall **)(_QWORD))(v25 + 24);
          if ( v26 )
          {
            v27 = *(_QWORD *)(v25 + 112);
            if ( *((_DWORD *)v26 - 1) != 1989616049 )
              __break(0x8228u);
            result = v26(v27);
          }
        }
        v28 = *(_QWORD *)(v23 + 40);
        if ( v28 )
        {
          v29 = *(_QWORD *)(v28 + 16);
          v30 = *(__int64 (__fastcall **)(_QWORD))(v29 + 24);
          if ( v30 )
          {
            v31 = *(_QWORD *)(v29 + 112);
            if ( *((_DWORD *)v30 - 1) != 1989616049 )
              __break(0x8228u);
            result = v30(v31);
          }
        }
        ++v22;
      }
      while ( v22 < *(_DWORD *)(v2 + 8516) );
    }
  }
  for ( k = *(__int64 **)(v2 + 256); k != (__int64 *)(v2 + 256); k = (__int64 *)*k )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 8,
                 4,
                 "cam_ife_hw_mgr_deinit_hw",
                 1908,
                 "Going to DeInit BUS RD %u, ctx_idx: %u",
                 *((_DWORD *)k + 5),
                 *(_DWORD *)(v2 + 56));
      v33 = k[4];
      if ( v33 )
      {
LABEL_59:
        v34 = *(_QWORD *)(v33 + 16);
        v35 = *(__int64 (__fastcall **)(_QWORD))(v34 + 24);
        if ( v35 )
        {
          v36 = *(_QWORD *)(v34 + 112);
          if ( *((_DWORD *)v35 - 1) != 1989616049 )
            __break(0x8228u);
          result = v35(v36);
        }
      }
    }
    else
    {
      v33 = k[4];
      if ( v33 )
        goto LABEL_59;
    }
    v37 = k[5];
    if ( v37 )
    {
      v38 = *(_QWORD *)(v37 + 16);
      v39 = *(__int64 (__fastcall **)(_QWORD))(v38 + 24);
      if ( v39 )
      {
        v40 = *(_QWORD *)(v38 + 112);
        if ( *((_DWORD *)v39 - 1) != 1989616049 )
          __break(0x8228u);
        result = v39(v40);
      }
    }
  }
  for ( m = *(__int64 **)(v2 + 224); m != (__int64 *)(v2 + 224); m = (__int64 *)*m )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 8,
                 4,
                 "cam_ife_hw_mgr_deinit_hw",
                 1915,
                 "Going to DeInit IFE SRC %u, ctx_idx: %u",
                 *((_DWORD *)m + 5),
                 *(_DWORD *)(v2 + 56));
      v42 = m[4];
      if ( v42 )
      {
LABEL_76:
        v43 = *(_QWORD *)(v42 + 16);
        v44 = *(__int64 (__fastcall **)(_QWORD))(v43 + 24);
        if ( v44 )
        {
          v45 = *(_QWORD *)(v43 + 112);
          if ( *((_DWORD *)v44 - 1) != 1989616049 )
            __break(0x8228u);
          result = v44(v45);
        }
      }
    }
    else
    {
      v42 = m[4];
      if ( v42 )
        goto LABEL_76;
    }
    v46 = m[5];
    if ( v46 )
    {
      v47 = *(_QWORD *)(v46 + 16);
      v48 = *(__int64 (__fastcall **)(_QWORD))(v47 + 24);
      if ( v48 )
      {
        v49 = *(_QWORD *)(v47 + 112);
        if ( *((_DWORD *)v48 - 1) != 1989616049 )
          __break(0x8228u);
        result = v48(v49);
      }
    }
  }
  if ( *(_DWORD *)(v2 + 8512) )
  {
    v50 = 0;
    do
    {
      v51 = *(_QWORD *)(v2 + 272) + ((__int64)(int)v50 << 7);
      v52 = *(_QWORD *)(v51 + 32);
      if ( v52 )
      {
        v53 = *(_QWORD *)(v52 + 16);
        v54 = *(__int64 (__fastcall **)(_QWORD))(v53 + 24);
        if ( v54 )
        {
          v55 = *(_QWORD *)(v53 + 112);
          if ( *((_DWORD *)v54 - 1) != 1989616049 )
            __break(0x8228u);
          result = v54(v55);
        }
      }
      v56 = *(_QWORD *)(v51 + 40);
      if ( v56 )
      {
        v57 = *(_QWORD *)(v56 + 16);
        v58 = *(__int64 (__fastcall **)(_QWORD))(v57 + 24);
        if ( v58 )
        {
          v59 = *(_QWORD *)(v57 + 112);
          if ( *((_DWORD *)v58 - 1) != 1989616049 )
            __break(0x8228u);
          result = v58(v59);
        }
      }
      ++v50;
    }
    while ( v50 < *(_DWORD *)(v2 + 8512) );
  }
  if ( (v1[1201] & 1) != 0 )
  {
    if ( (cam_cpas_is_notif_staling_supported() & 1) != 0
      && v3[81184] == 1
      && (unsigned int)cam_cpas_notif_increment_staling_counter(0) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_deinit_hw",
        1934,
        "llcc cache notif increment staling failed %d",
        0);
    }
    result = cam_cpas_deactivate_llcc(0);
  }
  v60 = (unsigned __int8)v1[1202];
  v1[1201] = 0;
  if ( v60 == 1 )
  {
    if ( (cam_cpas_is_notif_staling_supported() & 1) != 0
      && v3[81196] == 1
      && (unsigned int)cam_cpas_notif_increment_staling_counter(1) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_deinit_hw",
        1934,
        "llcc cache notif increment staling failed %d",
        1);
    }
    result = cam_cpas_deactivate_llcc(1);
  }
  v61 = (unsigned __int8)v1[1203];
  v1[1202] = 0;
  if ( v61 == 1 )
  {
    if ( (cam_cpas_is_notif_staling_supported() & 1) != 0
      && v3[81208] == 1
      && (unsigned int)cam_cpas_notif_increment_staling_counter(2) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_deinit_hw",
        1934,
        "llcc cache notif increment staling failed %d",
        2);
    }
    result = cam_cpas_deactivate_llcc(2);
  }
  v62 = (unsigned __int8)v1[1204];
  v1[1203] = 0;
  if ( v62 == 1 )
  {
    if ( (cam_cpas_is_notif_staling_supported() & 1) != 0
      && v3[81220] == 1
      && (unsigned int)cam_cpas_notif_increment_staling_counter(3) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_deinit_hw",
        1934,
        "llcc cache notif increment staling failed %d",
        3);
    }
    result = cam_cpas_deactivate_llcc(3);
  }
  v63 = (unsigned __int8)v1[1205];
  v1[1204] = 0;
  if ( v63 == 1 )
  {
    if ( (cam_cpas_is_notif_staling_supported() & 1) != 0
      && v3[81232] == 1
      && (unsigned int)cam_cpas_notif_increment_staling_counter(4) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_deinit_hw",
        1934,
        "llcc cache notif increment staling failed %d",
        4);
    }
    result = cam_cpas_deactivate_llcc(4);
  }
  v64 = (unsigned __int8)v1[1206];
  v1[1205] = 0;
  if ( v64 == 1 )
  {
    if ( (cam_cpas_is_notif_staling_supported() & 1) != 0
      && v3[81244] == 1
      && (unsigned int)cam_cpas_notif_increment_staling_counter(5) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_deinit_hw",
        1934,
        "llcc cache notif increment staling failed %d",
        5);
    }
    result = cam_cpas_deactivate_llcc(5);
  }
  v65 = *(unsigned int *)(v2 + 8716);
  v1[1206] = 0;
  if ( (_DWORD)v65 )
  {
    v66 = 0;
    v67 = (unsigned int *)(v2 + 8584);
    v68 = v3 + 81248;
    while ( v66 != 11 )
    {
      if ( v67[2] == 7 )
      {
        if ( *v67 > 2 )
          break;
        v68[20 * *v67 + 16] = 0;
        if ( *v67 > 2 )
          break;
        v68[20 * *v67 + 17] = 0;
        if ( *v67 > 2 )
          break;
        v68[20 * *v67 + 18] = 0;
        v65 = *(unsigned int *)(v2 + 8716);
      }
      ++v66;
      v67 += 3;
      if ( v66 >= v65 )
        goto LABEL_146;
    }
    __break(0x5512u);
  }
LABEL_146:
  v1[1185] = 0;
  return result;
}
