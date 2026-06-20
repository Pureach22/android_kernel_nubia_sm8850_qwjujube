__int64 __fastcall cam_cpas_util_axi_setup(__int64 a1, _QWORD *a2)
{
  unsigned int v2; // w6
  __int64 v4; // x19
  __int64 v6; // x23
  unsigned __int64 v7; // x24
  __int64 v8; // x26
  int v9; // w0
  __int64 v10; // x23
  unsigned __int64 v11; // x24
  __int64 v12; // x21
  const char *v13; // x6
  unsigned int v14; // w19

  v2 = *(_DWORD *)(a1 + 2780);
  if ( v2 > 6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_axi_setup",
      536,
      "Invalid num_axi_ports: %d",
      v2);
    return 4294967274LL;
  }
  v4 = a1;
  if ( v2 )
  {
    v6 = 0;
    v7 = 0;
    while ( v6 != 2448 )
    {
      v8 = v4 + v6;
      v9 = cam_soc_bus_client_register(
             *a2,
             *(_QWORD *)(v4 + v6 + 3352),
             v4 + v6 + 3336,
             v4 + v6 + 3168,
             *(unsigned __int8 *)(a2[412] + 10LL));
      if ( v9 )
      {
        v13 = *(const char **)(v8 + 3168);
LABEL_16:
        v14 = v9;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_util_register_bus_client",
          466,
          "Bus client: %s registertion failed ,rc: %d",
          v13,
          v9);
        return v14;
      }
      *(_DWORD *)(v8 + 3160) = 0;
      *(_BYTE *)(v8 + 3104) = 1;
      a1 = _mutex_init(v8 + 3112, "&bus_client->lock", &cam_cpas_util_register_bus_client___key);
      ++v7;
      v6 += 408;
      if ( v7 >= *(unsigned int *)(v4 + 2780) )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    if ( !*(_DWORD *)(v4 + 2784) )
      return 0;
    v10 = 0;
    v11 = 0;
    while ( v10 != 2448 )
    {
      v12 = v4 + v10;
      v9 = cam_soc_bus_client_register(
             *a2,
             *(_QWORD *)(v4 + v10 + 5800),
             v4 + 5784 + v10,
             v4 + 5616 + v10,
             *(unsigned __int8 *)(a2[412] + 10LL));
      if ( v9 )
      {
        v13 = *(const char **)(v12 + 5616);
        goto LABEL_16;
      }
      *(_DWORD *)(v12 + 5608) = 0;
      *(_BYTE *)(v4 + 5552 + v10) = 1;
      a1 = _mutex_init(v4 + 5560 + v10, "&bus_client->lock", &cam_cpas_util_register_bus_client___key);
      ++v11;
      v10 += 408;
      if ( v11 >= *(unsigned int *)(v4 + 2784) )
        return 0;
    }
  }
  __break(0x5512u);
  return cam_cpas_util_create_debugfs(a1);
}
