__int64 __fastcall cam_cpas_dump_cons_axi_vote_info(__int64 result, const char *a2, unsigned int *a3)
{
  int v4; // w6
  __int64 v6; // x21
  unsigned __int64 v7; // x24
  _QWORD *v8; // x25

  if ( (cpas_dump & 1) == 0 )
    return result;
  if ( !a3 )
  {
    v4 = -1;
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x2000000,
             1,
             "cam_cpas_dump_cons_axi_vote_info",
             185,
             "Invalid num_paths %d",
             v4);
  }
  v4 = *a3;
  if ( *a3 > 0xF )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x2000000,
             1,
             "cam_cpas_dump_cons_axi_vote_info",
             185,
             "Invalid num_paths %d",
             v4);
  if ( v4 )
  {
    v6 = result;
    v7 = 0;
    v8 = a3 + 8;
    while ( v7 != 15 )
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 0x2000000,
                 3,
                 "cam_cpas_dump_cons_axi_vote_info",
                 201,
                 "Client [%s][%d] : [%s], Path=[%d] [%d],[HIGH LOW] camnoc[%llu %llu], mnoc_ab[%llu %llu], mnoc_ib[%llu %llu]",
                 (const char *)v6,
                 *(_DWORD *)(v6 + 128),
                 a2,
                 *((_DWORD *)v8 - 5),
                 *((_DWORD *)v8 - 6),
                 *v8,
                 v8[3],
                 *(v8 - 2),
                 v8[1],
                 *(v8 - 1),
                 v8[2]);
      ++v7;
      v8 += 7;
      if ( v7 >= *a3 )
        return result;
    }
    __break(0x5512u);
    return cam_cpas_dump_axi_vote_info();
  }
  return result;
}
