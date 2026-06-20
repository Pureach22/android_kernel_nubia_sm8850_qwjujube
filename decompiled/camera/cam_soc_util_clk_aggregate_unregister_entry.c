__int64 __fastcall cam_soc_util_clk_aggregate_unregister_entry(__int64 a1, __int64 a2, unsigned int a3)
{
  int v3; // w20
  int v5; // w24
  _UNKNOWN **v6; // x19
  _QWORD *v7; // x22
  const void *v8; // x23
  int v9; // w0
  _QWORD *v10; // x8
  _QWORD *v11; // x9
  int v12; // w8
  _QWORD *v13; // x8
  _QWORD *v14; // x9

  if ( a3 < 0x20 )
  {
    v3 = a1;
    v5 = *(_DWORD *)(a2 + 8LL * a3 + 3316);
    mutex_lock(&aggregate_lock);
    v6 = &aggregate_clk_list;
    do
    {
      v6 = (_UNKNOWN **)*v6;
      if ( v6 == &aggregate_clk_list )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_clk_aggregate_unregister_entry",
          1171,
          "Aggregate clk entry for clk id %d is not found",
          v3);
        return mutex_unlock(&aggregate_lock);
      }
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_clk_aggregate_unregister_entry",
          1152,
          "Aggregate clk cmn src id %d, num clients %d",
          *((_DWORD *)v6 + 54),
          *((_DWORD *)v6 + 12));
    }
    while ( *((_DWORD *)v6 + 54) != v5 );
    v7 = v6 + 4;
    do
    {
      v7 = (_QWORD *)*v7;
      if ( v7 == v6 + 4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_clk_aggregate_unregister_entry",
          1179,
          "Client %pK for aggregate clk with cmn src id %d entry not found",
          (const void *)a2,
          *((_DWORD *)v6 + 54));
        return mutex_unlock(&aggregate_lock);
      }
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_clk_aggregate_unregister_entry",
          1160,
          "Aggregate cmn src id %d, entry client %s",
          *((_DWORD *)v6 + 54),
          *(const char **)(v7[2] + 24LL));
    }
    while ( v7[2] != a2 );
    --*((_DWORD *)v6 + 12);
    v8 = *(const void **)(a2 + 3192);
    if ( v8 )
    {
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_unregister_mmrm_client",
          965,
          "MMRM UnRegister handle=%pK",
          *(const void **)(a2 + 3192));
      v9 = mmrm_client_deregister(v8);
      if ( v9 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_unregister_mmrm_client",
          972,
          "Failed in deregister handle=%pK, rc %d",
          v8,
          v9);
      *(_QWORD *)(a2 + 3192) = 0;
      v7[2] = 0;
    }
    v10 = (_QWORD *)v7[1];
    if ( (_QWORD *)*v10 == v7 && (v11 = (_QWORD *)*v7, *(_QWORD **)(*v7 + 8LL) == v7) )
    {
      v11[1] = v10;
      *v10 = v11;
    }
    else
    {
      _list_del_entry_valid_or_report(v7);
    }
    *v7 = v7;
    v7[1] = v7;
    if ( mem_trace_en == 1 )
    {
      cam_mem_trace_free(v7, 0);
      v12 = debug_mdl;
      if ( (debug_mdl & 0x20000) == 0 )
        goto LABEL_31;
    }
    else
    {
      kvfree(v7);
      v12 = debug_mdl;
      if ( (debug_mdl & 0x20000) == 0 )
        goto LABEL_31;
    }
    if ( !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v12 & 0x20000LL,
        4,
        "cam_soc_util_clk_aggregate_unregister_entry",
        1197,
        "Unregister client %s clk id %d from aggregate cmn src id %d, num clients %d",
        *(const char **)(a2 + 24),
        v3,
        *((_DWORD *)v6 + 54),
        *((_DWORD *)v6 + 12));
      if ( !*((_DWORD *)v6 + 12) )
      {
LABEL_32:
        v13 = v6[1];
        if ( (_UNKNOWN **)*v13 == v6 && (v14 = *v6, *((_UNKNOWN ***)*v6 + 1) == v6) )
        {
          v14[1] = v13;
          *v13 = v14;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
        }
        *v6 = v6;
        v6[1] = v6;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v6, 0);
        else
          kvfree(v6);
      }
      return mutex_unlock(&aggregate_lock);
    }
LABEL_31:
    if ( !*((_DWORD *)v6 + 12) )
      goto LABEL_32;
    return mutex_unlock(&aggregate_lock);
  }
  __break(0x5512u);
  return cam_wrapper_clk_put(a1, a2);
}
