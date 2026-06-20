__int64 __fastcall cam_cpas_dump_axi_vote_info(__int64 result, const char *a2, unsigned int *a3)
{
  int v4; // w6
  __int64 v6; // x21
  unsigned __int64 v7; // x25
  unsigned int *v8; // x26
  int v9; // w27
  int v10; // w28
  int v11; // w24
  const char *v12; // x0

  if ( (cpas_dump & 1) == 0 )
    return result;
  if ( !a3 )
  {
    v4 = -1;
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x2000000,
             1,
             "cam_cpas_dump_axi_vote_info",
             219,
             "Invalid num_paths %d",
             v4);
  }
  v4 = *a3;
  if ( *a3 > 0xF )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x2000000,
             1,
             "cam_cpas_dump_axi_vote_info",
             219,
             "Invalid num_paths %d",
             v4);
  if ( v4 )
  {
    v6 = result;
    v7 = 0;
    v8 = a3 + 5;
    do
    {
      if ( v7 == 15 )
      {
        __break(0x5512u);
        JUMPOUT(0x7949484);
      }
      v10 = *(v8 - 2);
      v9 = *(v8 - 1);
      v11 = *(_DWORD *)(v6 + 128);
      v12 = (const char *)cam_cpas_axi_util_drv_vote_lvl_to_string(*v8);
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 0x2000000,
                 3,
                 "cam_cpas_dump_axi_vote_info",
                 233,
                 "Client [%s][%d] : [%s], Path=[%d] [%d], [%s], camnoc[%llu], mnoc_ab[%llu], mnoc_ib[%llu]",
                 (const char *)v6,
                 v11,
                 a2,
                 v9,
                 v10,
                 v12,
                 *(_QWORD *)(v8 + 1),
                 *(_QWORD *)(v8 + 3),
                 *(_QWORD *)(v8 + 5));
      ++v7;
      v8 += 10;
    }
    while ( v7 < *a3 );
  }
  return result;
}
