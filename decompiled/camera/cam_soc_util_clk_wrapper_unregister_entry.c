__int64 __fastcall cam_soc_util_clk_wrapper_unregister_entry(int a1, const char **a2)
{
  _UNKNOWN **v4; // x19
  _QWORD *v5; // x0
  _QWORD *v6; // x27
  void *v7; // x22
  _QWORD *v8; // x26
  int v9; // w0
  _QWORD *v10; // x8
  _QWORD *v11; // x9
  int v12; // w8
  _QWORD *v13; // x8
  _QWORD *v14; // x9
  _QWORD *v16; // x9

  mutex_lock(&wrapper_lock);
  v4 = &wrapper_clk_list;
  do
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &wrapper_clk_list )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_clk_wrapper_unregister_entry",
        1336,
        "Shared clk id %d entry not found",
        a1);
      return mutex_unlock(&wrapper_lock);
    }
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_wrapper_unregister_entry",
        1317,
        "Clk list id %d num clients %d",
        *((_DWORD *)v4 + 4),
        *((_DWORD *)v4 + 12));
  }
  while ( *((_DWORD *)v4 + 4) != a1 );
  v5 = v4 + 4;
  do
  {
    v5 = (_QWORD *)*v5;
    if ( v5 == v4 + 4 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_clk_wrapper_unregister_entry",
        1344,
        "Client %pK for Shared clk id %d entry not found",
        a2,
        a1);
      return mutex_unlock(&wrapper_lock);
    }
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      v6 = v5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_wrapper_unregister_entry",
        1325,
        "Clk id %d entry client %s",
        *((_DWORD *)v4 + 4),
        *(const char **)(v5[2] + 24LL));
      v5 = v6;
    }
  }
  while ( (const char **)v5[2] != a2 );
  v7 = v4[7];
  --*((_DWORD *)v4 + 12);
  if ( v7 && v4[8] == (_UNKNOWN *)a2 )
  {
    v8 = v5;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_unregister_mmrm_client",
        965,
        "MMRM UnRegister handle=%pK",
        v7);
    v9 = mmrm_client_deregister(v7);
    if ( v9 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_unregister_mmrm_client",
        972,
        "Failed in deregister handle=%pK, rc %d",
        v7,
        v9);
    v5 = v8;
    v4[7] = nullptr;
    v4[8] = nullptr;
  }
  v10 = (_QWORD *)v5[1];
  if ( (_QWORD *)*v10 == v5 && (v11 = (_QWORD *)*v5, *(_QWORD **)(*v5 + 8LL) == v5) )
  {
    v11[1] = v10;
    *v10 = v11;
  }
  else
  {
    _list_del_entry_valid_or_report(v5);
    v5 = v16;
  }
  *v5 = v5;
  v5[1] = v5;
  if ( mem_trace_en == 1 )
  {
    cam_mem_trace_free(v5, 0);
    v12 = debug_mdl;
    if ( (debug_mdl & 0x20000) == 0 )
    {
LABEL_31:
      if ( *((_DWORD *)v4 + 12) )
        return mutex_unlock(&wrapper_lock);
      goto LABEL_32;
    }
  }
  else
  {
    kvfree(v5);
    v12 = debug_mdl;
    if ( (debug_mdl & 0x20000) == 0 )
      goto LABEL_31;
  }
  if ( debug_priority )
    goto LABEL_31;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    *(_QWORD *)&v12 & 0x20000LL,
    4,
    "cam_soc_util_clk_wrapper_unregister_entry",
    1360,
    "Unregister client %s for clk id %d, num clients %d",
    a2[3],
    a1,
    *((_DWORD *)v4 + 12));
  if ( *((_DWORD *)v4 + 12) )
    return mutex_unlock(&wrapper_lock);
LABEL_32:
  v13 = v4[1];
  if ( (_UNKNOWN **)*v13 == v4 && (v14 = *v4, *((_UNKNOWN ***)*v4 + 1) == v4) )
  {
    v14[1] = v13;
    *v13 = v14;
  }
  else
  {
    _list_del_entry_valid_or_report(v4);
  }
  *v4 = v4;
  v4[1] = v4;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v4, 0);
  else
    kvfree(v4);
  return mutex_unlock(&wrapper_lock);
}
