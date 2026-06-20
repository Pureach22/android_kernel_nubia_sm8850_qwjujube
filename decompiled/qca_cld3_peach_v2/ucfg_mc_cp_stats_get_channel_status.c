_DWORD *__fastcall ucfg_mc_cp_stats_get_channel_status(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  int v12; // w30
  __int64 v13; // x8
  __int64 v14; // x10
  _DWORD *result; // x0
  __int64 v16; // x10

  if ( !a1 || (comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Bu)) == 0 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: pdev cp stats object is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_mc_cp_stats_get_channel_status");
    return nullptr;
  }
  v13 = *(_QWORD *)(comp_private_obj + 8);
  if ( *(_BYTE *)(v13 + 20) )
  {
    v14 = 0;
    result = (_DWORD *)(v13 + 24);
    while ( v14 != 103 )
    {
      if ( *result == a2 )
        return result;
      ++v14;
      result += 31;
      if ( *(unsigned __int8 *)(v13 + 20) == v14 )
        goto LABEL_8;
    }
    goto LABEL_17;
  }
LABEL_8:
  if ( !*(_BYTE *)(v13 + 12692) )
    return nullptr;
  v16 = 0;
  result = (_DWORD *)(v13 + 12696);
  while ( v16 != 103 )
  {
    if ( *result == a2 )
      return result;
    ++v16;
    result += 31;
    if ( *(unsigned __int8 *)(v13 + 12692) == v16 )
      return nullptr;
  }
LABEL_17:
  __break(0x5512u);
  if ( v12 )
    return (_DWORD *)ucfg_mc_cp_stats_clear_channel_status(result);
  else
    return (_DWORD *)wma_de_register_mgmt_frm_client(a3, a4, a5, a6, a7, a8, a9, a10);
}
