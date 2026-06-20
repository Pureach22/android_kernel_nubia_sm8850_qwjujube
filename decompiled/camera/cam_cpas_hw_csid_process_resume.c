__int64 __fastcall cam_cpas_hw_csid_process_resume(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  unsigned __int64 v4; // x8
  __int64 v5; // x21
  unsigned __int64 v6; // x22
  int v7; // w23
  __int64 v8; // x9
  int v9; // w0
  unsigned int v11; // w19
  unsigned int v12; // w19

  v2 = *(_QWORD *)(a1 + 3392);
  if ( *(_BYTE *)(v2 + 1609) != 1 )
    return 0;
  v3 = *(_QWORD *)(a1 + 3680);
  v4 = *(unsigned int *)(v3 + 2780);
  if ( !(_DWORD)v4 )
    return 0;
  v5 = 0;
  v6 = 0;
  v7 = a2 + 1;
  while ( v6 != 6 )
  {
    v8 = v3 + v5;
    if ( *(_BYTE *)(v3 + v5 + 3184) == 1 && *(_BYTE *)(v8 + 3376) == 1 && *(_DWORD *)(v3 + v5 + 3360) == v7 )
    {
      v9 = cam_cpas_util_vote_drv_bus_client_bw(
             v2,
             v3,
             v8 + 3104,
             (__int64 *)(v3 + v5 + 3448),
             (_QWORD *)(v3 + v5 + 3448));
      if ( v9 )
      {
        v11 = v9;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_hw_csid_process_resume",
          4677,
          "Failed in BW update on resume rc:%d",
          v9);
        return v11;
      }
      a1 = cam_cpas_drv_channel_switch_for_dev(*(const char ***)(v3 + v5 + 3368));
      if ( (_DWORD)a1 )
      {
        v12 = a1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_hw_csid_process_resume",
          4686,
          "Port[%s] failed in channel switch during resume rc:%d",
          *(const char **)(v3 + v5 + 3096),
          a1);
        return v12;
      }
      v4 = *(unsigned int *)(v3 + 2780);
    }
    ++v6;
    v5 += 408;
    if ( v6 >= v4 )
      return 0;
  }
  __break(0x5512u);
  return cam_cpas_hw_enable_tpg_mux_sel(a1, a2);
}
