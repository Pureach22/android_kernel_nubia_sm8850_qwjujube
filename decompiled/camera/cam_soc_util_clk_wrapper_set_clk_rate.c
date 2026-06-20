__int64 __fastcall cam_soc_util_clk_wrapper_set_clk_rate(unsigned int a1, __int64 a2, const void *a3, __int64 a4)
{
  int v4; // w22
  _UNKNOWN **v7; // x28
  void *v9; // x7
  const char *v10; // x5
  __int64 v11; // x4
  __int64 v12; // x11
  _QWORD *v13; // x19
  char v14; // w22
  void *v15; // x21
  unsigned int v16; // w23
  const char *v17; // x12
  __int64 v18; // x8
  __int64 v19; // x9
  const char *v20; // x22
  void *v21; // x8
  __int64 v22; // x6
  void *v23; // x0
  int v24; // [xsp+20h] [xbp-10h]

  v4 = (int)a3;
  if ( !a2 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x20000,
             1,
             "cam_soc_util_clk_wrapper_set_clk_rate",
             1523,
             "Invalid param soc_info %pK clk %pK",
             nullptr,
             a3);
  mutex_lock(&wrapper_lock);
  v7 = &wrapper_clk_list;
  do
  {
    v7 = (_UNKNOWN **)*v7;
    if ( v7 == &wrapper_clk_list )
    {
      v9 = *(void **)(a2 + 24);
      v10 = "Clk entry not found id %d client %s";
      v11 = 1540;
LABEL_38:
      v22 = a1;
LABEL_39:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, void *))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_clk_wrapper_set_clk_rate",
        v11,
        v10,
        v22,
        v9);
      return mutex_unlock(&wrapper_lock);
    }
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_wrapper_set_clk_rate",
        1531,
        "Clk list id %d num clients %d",
        *((_DWORD *)v7 + 4),
        *((_DWORD *)v7 + 12));
  }
  while ( *((_DWORD *)v7 + 4) != a1 );
  v12 = a4;
  v24 = v4;
  v13 = v7[4];
  if ( v13 == v7 + 4 )
    goto LABEL_37;
  v14 = 0;
  v15 = nullptr;
  v16 = 0;
  v17 = "Clk enable clk id %d, client %s curr %ld new %ld";
  do
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_wrapper_set_clk_rate",
        1548,
        "Clk id %d client %s, clk rate %lld",
        *((_DWORD *)v7 + 4),
        *(const char **)(v13[2] + 24LL),
        v13[4]);
      v12 = a4;
      v17 = "Clk enable clk id %d, client %s curr %ld new %ld";
    }
    v19 = v13[2];
    if ( v19 == a2 )
    {
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      {
        v20 = v17;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, __int64))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_clk_wrapper_set_clk_rate",
          1554,
          v17,
          a1,
          *(_QWORD *)(v19 + 24),
          v13[4],
          v12);
        v12 = a4;
        v17 = v20;
      }
      v14 = 1;
      v18 = v12;
      v13[4] = v12;
    }
    else
    {
      v18 = v13[4];
    }
    v13 = (_QWORD *)*v13;
    if ( v18 > 0 )
      ++v16;
    if ( (__int64)v15 <= v18 )
      v15 = (void *)v18;
  }
  while ( v13 != v7 + 4 );
  if ( (v14 & 1) == 0 )
  {
LABEL_37:
    v9 = *(void **)(a2 + 24);
    v10 = "Wrapper clk enable without client entry clk id %d client %s";
    v11 = 1569;
    goto LABEL_38;
  }
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_clk_wrapper_set_clk_rate",
      1577,
      "Clk id %d, client %s, clients rate %ld, curr %ld final %ld",
      *((_DWORD *)v7 + 4),
      *(const char **)(a2 + 24),
      v12,
      v7[3],
      v15);
  v21 = v7[3];
  if ( v15 != v21 || v16 != *((_DWORD *)v7 + 13) )
  {
    if ( skip_mmrm_set_rate || (v23 = v7[7]) == nullptr )
    {
      if ( v15 && v15 != v21 && (unsigned int)cam_wrapper_clk_set_rate(v24, (int)v15, (char *)v7 + 88) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_clk_wrapper_set_clk_rate",
          1605,
          "set_rate failed on clk %d",
          *((_DWORD *)v7 + 4));
        return mutex_unlock(&wrapper_lock);
      }
    }
    else if ( (unsigned int)cam_soc_util_set_sw_client_rate_through_mmrm(
                              v23,
                              *((unsigned __int8 *)v7 + 72),
                              v7[10],
                              v15,
                              v16) )
    {
      v22 = *((unsigned int *)v7 + 4);
      v10 = "set_sw_client_rate through mmrm failed clk_id %d, rate=%ld";
      v11 = 1592;
      v9 = v15;
      goto LABEL_39;
    }
    v7[3] = v15;
    *((_DWORD *)v7 + 13) = v16;
  }
  return mutex_unlock(&wrapper_lock);
}
