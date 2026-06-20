__int64 __fastcall cam_soc_util_clk_aggregate_set_clk_rate(
        __int64 a1,
        __int64 a2,
        const void *a3,
        __int64 a4,
        __int64 a5)
{
  int v7; // w20
  _UNKNOWN **v8; // x24
  __int64 v10; // x9
  _QWORD *v11; // x21
  _QWORD *v12; // x26
  __int64 v13; // x8
  char v14; // w20
  void *v15; // x19
  int v16; // w28
  const char *v17; // x13
  __int64 v18; // x10
  __int64 v19; // x11
  const char *v20; // x20
  void *v21; // x8
  _QWORD *v22; // x22
  _QWORD *v23; // x20
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x10
  unsigned int v27; // [xsp+1Ch] [xbp-4h]

  if ( !a2 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x20000,
             1,
             "cam_soc_util_clk_aggregate_set_clk_rate",
             1386,
             "Invalid param soc_info %pK clk %pK",
             nullptr,
             a3);
  if ( *(_DWORD *)(a2 + 868) <= (unsigned int)a5 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x20000,
             1,
             "cam_soc_util_clk_aggregate_set_clk_rate",
             1391,
             "Invalid clk idx %d",
             a5);
  v27 = a1;
  if ( (unsigned int)a5 >= 0x20 )
  {
LABEL_55:
    __break(0x5512u);
    return cam_soc_util_set_sw_client_rate_through_mmrm(a1, a2, a3, a4, a5);
  }
  else
  {
    v7 = *(_DWORD *)(a2 + 8LL * (unsigned int)a5 + 3316);
    a1 = mutex_lock(&aggregate_lock);
    v8 = &aggregate_clk_list;
    do
    {
      v8 = (_UNKNOWN **)*v8;
      if ( v8 == &aggregate_clk_list )
      {
        __break(1u);
        goto LABEL_55;
      }
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 0x20000,
               4,
               "cam_soc_util_clk_aggregate_set_clk_rate",
               1401,
               "Aggregate clk cmn src id %d num clients %d",
               *((_DWORD *)v8 + 54),
               *((_DWORD *)v8 + 12));
    }
    while ( *((_DWORD *)v8 + 54) != v7 );
    v10 = a2;
    v12 = v8 + 4;
    v11 = v8[4];
    if ( v11 == v8 + 4 )
      goto LABEL_43;
    v13 = a4;
    v14 = 0;
    v15 = nullptr;
    v16 = 0;
    v17 = "Aggregate clk enable cmn src id %d, clk id %d, client %s, curr %ld, new %ld";
    do
    {
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      {
        a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 0x20000,
               4,
               "cam_soc_util_clk_aggregate_set_clk_rate",
               1419,
               "Aggregate clk with cmn src id %d, client %s, client clk rate %lld",
               *((_DWORD *)v8 + 54),
               *(const char **)(v11[2] + 24LL),
               v11[4]);
        v17 = "Aggregate clk enable cmn src id %d, clk id %d, client %s, curr %ld, new %ld";
        v13 = a4;
        v10 = a2;
      }
      v19 = v11[2];
      if ( v19 == v10 )
      {
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        {
          v20 = v17;
          a1 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, _QWORD, __int64))cam_print_log)(
                 3,
                 debug_mdl & 0x20000,
                 4,
                 "cam_soc_util_clk_aggregate_set_clk_rate",
                 1426,
                 v17,
                 *((unsigned int *)v8 + 54),
                 v27,
                 *(_QWORD *)(v19 + 24),
                 v11[4],
                 v13);
          v17 = v20;
          v13 = a4;
          v10 = a2;
        }
        v14 = 1;
        v18 = v13;
        v11[4] = v13;
      }
      else
      {
        v18 = v11[4];
      }
      v11 = (_QWORD *)*v11;
      if ( v18 > 0 )
        ++v16;
      if ( (__int64)v15 <= v18 )
        v15 = (void *)v18;
    }
    while ( v11 != v12 );
    if ( (v14 & 1) == 0 )
    {
LABEL_43:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_clk_aggregate_set_clk_rate",
        1441,
        "Aggregate clk enable without client entry, cmn src id %d, clk id %d client %s",
        *((_DWORD *)v8 + 54),
        v27,
        *(const char **)(v10 + 24));
    }
    else
    {
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      {
        a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 0x20000,
               4,
               "cam_soc_util_clk_aggregate_set_clk_rate",
               1449,
               "Aggregate cmn src id %d, client %s, clients rate %ld, curr %ld final %ld",
               *((_DWORD *)v8 + 54),
               *(const char **)(v10 + 24),
               v13,
               v8[3],
               v15);
        v10 = a2;
      }
      v21 = v8[3];
      if ( v15 != v21 || v16 != *((_DWORD *)v8 + 13) )
      {
        if ( skip_mmrm_set_rate || !*(_QWORD *)(v10 + 3192) )
        {
          if ( v15 && v15 != v21 )
          {
            v22 = v8 + 4;
            while ( 1 )
            {
              v22 = (_QWORD *)*v22;
              if ( v22 == v12 )
                break;
              if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x20000,
                  4,
                  "cam_soc_util_clk_aggregate_set_clk_rate",
                  1488,
                  "Set clk rate on aggregate clk, cmn src id: %d, clk rate: %d, client device name: %s",
                  *((_DWORD *)v8 + 54),
                  (_DWORD)v15,
                  *(const char **)(v22[2] + 24LL));
              if ( (unsigned int)cam_wrapper_clk_set_rate(v22[3], (int)v15, (char *)v8 + 88) )
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x20000,
                  1,
                  "cam_soc_util_clk_aggregate_set_clk_rate",
                  1494,
                  "set_rate failed on aggregate clk");
                return mutex_unlock(&aggregate_lock);
              }
            }
          }
        }
        else
        {
          v23 = v8 + 4;
          while ( 1 )
          {
            v23 = (_QWORD *)*v23;
            if ( v23 == v12 )
              break;
            v24 = v23[2];
            v25 = *(unsigned int *)(v24 + 2872);
            if ( (unsigned int)v25 > 9 )
              goto LABEL_55;
            v26 = *(unsigned int *)(v24 + 2796);
            if ( (unsigned int)v26 > 0x1F )
              goto LABEL_55;
            a1 = cam_soc_util_set_sw_client_rate_through_mmrm(
                   *(_QWORD *)(v24 + 3192),
                   *(unsigned __int8 *)(v24 + 32),
                   *(int *)(v24 + (v25 << 7) + 4 * v26 + 1384),
                   v15,
                   1);
            if ( (_DWORD)a1 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x20000,
                1,
                "cam_soc_util_clk_aggregate_set_clk_rate",
                1472,
                "set_rate through mmrm failed clk_id %d, rate=%ld",
                *((_DWORD *)v8 + 4),
                v15);
              return mutex_unlock(&aggregate_lock);
            }
          }
        }
        v8[3] = v15;
        *((_DWORD *)v8 + 13) = v16;
      }
    }
    return mutex_unlock(&aggregate_lock);
  }
}
