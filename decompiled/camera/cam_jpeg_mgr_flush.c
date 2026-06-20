__int64 __fastcall cam_jpeg_mgr_flush(__int64 *a1, __int64 a2)
{
  __int64 *v2; // x20
  __int64 *v3; // x21
  __int64 v5; // x1
  __int64 **v6; // x8
  __int64 v7; // x9
  __int64 **v8; // x1
  _QWORD *v9; // x27
  _QWORD *v10; // x26
  __int64 v11; // x8
  __int64 v12; // x23
  _QWORD *v13; // x8
  __int64 *v14; // x1
  __int64 result; // x0

  if ( (debug_mdl & 0x200) == 0 || debug_priority )
  {
    if ( a2 )
      goto LABEL_4;
LABEL_36:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_flush",
      1184,
      "Invalid args");
    return 4294967274LL;
  }
  v2 = a1;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    debug_mdl & 0x200,
    4,
    "cam_jpeg_mgr_flush",
    1181,
    "E: JPEG flush ctx");
  a1 = v2;
  if ( !a2 )
    goto LABEL_36;
LABEL_4:
  v5 = *(unsigned int *)(a2 + 56);
  if ( (unsigned int)v5 >= 2 )
  {
    __break(0x5512u);
LABEL_39:
    _list_add_valid_or_report(v2);
    goto LABEL_15;
  }
  if ( *((_DWORD *)a1 + v5 + 1314) != 1 )
    goto LABEL_16;
  v2 = (__int64 *)a1[v5 + 658];
  if ( !v2 || v2[2] != a2 )
    goto LABEL_16;
  v3 = a1;
  cam_jpeg_mgr_stop_deinit_dev();
  v6 = (__int64 **)v2[1];
  if ( *v6 == v2 && (v7 = *v2, *(__int64 **)(*v2 + 8) == v2) )
  {
    *(_QWORD *)(v7 + 8) = v6;
    *v6 = (__int64 *)v7;
  }
  else
  {
    _list_del_entry_valid_or_report(v2);
  }
  *v2 = (__int64)v2;
  v2[1] = (__int64)v2;
  cam_mem_put_cpu_buf(*(_DWORD *)v2[4]);
  v8 = (__int64 **)qword_3AA150;
  if ( v2 == &qword_3AA148 || (__int64 *)qword_3AA150 == v2 || *(__int64 **)qword_3AA150 != &qword_3AA148 )
    goto LABEL_39;
  qword_3AA150 = (__int64)v2;
  *v2 = (__int64)&qword_3AA148;
  v2[1] = (__int64)v8;
  *v8 = v2;
LABEL_15:
  a1 = v3;
LABEL_16:
  v9 = (_QWORD *)a1[660];
  v10 = a1 + 660;
  while ( v9 != v10 )
  {
    v11 = v9[2];
    v12 = (__int64)v9;
    v9 = (_QWORD *)*v9;
    if ( v11 == a2 )
    {
      v13 = *(_QWORD **)(v12 + 8);
      if ( *v13 == v12 && v9[1] == v12 )
      {
        v9[1] = v13;
        *v13 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(v12);
      }
      *(_QWORD *)v12 = v12;
      *(_QWORD *)(v12 + 8) = v12;
      if ( v12 )
      {
        cam_mem_put_cpu_buf(**(_DWORD **)(v12 + 32));
        v14 = (__int64 *)qword_3AA150;
        if ( (__int64 *)v12 == &qword_3AA148 || qword_3AA150 == v12 || *(__int64 **)qword_3AA150 != &qword_3AA148 )
        {
          _list_add_valid_or_report(v12);
        }
        else
        {
          qword_3AA150 = v12;
          *(_QWORD *)v12 = &qword_3AA148;
          *(_QWORD *)(v12 + 8) = v14;
          *v14 = v12;
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_mgr_move_req_to_free_list",
          61,
          "Invalid args");
      }
    }
  }
  result = 0;
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_mgr_flush",
      1213,
      "X: JPEG flush ctx");
    return 0;
  }
  return result;
}
