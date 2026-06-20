__int64 __fastcall cam_soc_bus_client_update_bw(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5)
{
  atomic_uchar *v5; // x18
  __int64 v6; // x20
  __int64 v7; // x19
  unsigned __int8 v8; // w8
  __int64 result; // x0
  const char **v11; // x8
  unsigned int v12; // w19
  unsigned int v13; // w21
  const char *v14; // x7
  unsigned __int64 v15; // x22
  unsigned __int64 v16; // x23

  v6 = *(_QWORD *)a1;
  v7 = a1;
  v8 = 0;
  if ( (debug_mdl & 0x2020000) != 0 && debug_priority == 0 )
  {
    v13 = a4;
    if ( (unsigned int)a4 > 2 )
      v14 = "BUS_PATH_INVALID";
    else
      v14 = off_44BA00[(unsigned int)a4];
    v15 = a3;
    v16 = a2;
    a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           debug_mdl & 0x2020000,
           4,
           "cam_soc_bus_client_update_bw",
           182,
           "Bus client=[%s] [%s] :ab[%llu] ib[%llu]",
           **(const char ***)(a1 + 8),
           v14,
           a2,
           a3);
    a2 = v16;
    a3 = v15;
    a4 = v13;
    if ( v13 < 3 )
      goto LABEL_6;
LABEL_13:
    __break(0x5512u);
    atomic_fetch_add_explicit(v5, v8, memory_order_release);
    return cam_soc_bus_client_register(a1, a2, a3, a4, a5);
  }
  if ( (unsigned int)a4 >= 3 )
    goto LABEL_13;
LABEL_6:
  result = cam_wrapper_icc_set_bw(*(_QWORD *)(v6 + 8LL * (unsigned int)a4), a2 / 0x3E8, a3 / 0x3E8);
  if ( (_DWORD)result )
  {
    v11 = *(const char ***)(v7 + 8);
    v12 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_bus_client_update_bw",
      199,
      "Update request failed, client[%s]",
      *v11);
    return v12;
  }
  return result;
}
