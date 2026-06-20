__int64 __fastcall hdd_local_unsafe_channel_updated(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int128 v6; // q25
  __int64 v7; // x10
  __int64 v8; // x12
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( *(unsigned __int16 *)(a1 + 640) == a3 )
  {
    if ( !a3 )
      return 0;
    v7 = 0;
    while ( 2 )
    {
      v8 = 0;
      while ( 1 )
      {
        if ( v8 == 204 )
        {
          __break(0x5512u);
          *(_OWORD *)(a6 + 28) = v6;
          return wlan_hdd_get_link_info_from_objmgr();
        }
        if ( *(unsigned __int16 *)(a2 + 2 * v7) == *(unsigned __int16 *)(a1 + v8 + 642) )
          break;
        v8 += 2;
        if ( 2LL * a3 == v8 )
        {
          ucfg_mlme_get_coex_unsafe_chan_nb_user_prefer(*(_QWORD *)a1);
          return 1;
        }
      }
      if ( ++v7 != a3 )
        continue;
      break;
    }
    if ( (ucfg_mlme_get_coex_unsafe_chan_nb_user_prefer(*(_QWORD *)a1) & 1) == 0 || *(_DWORD *)(a1 + 848) == a4 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: unsafe chan list same",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "hdd_local_unsafe_channel_updated");
      return 0;
    }
  }
  return 1;
}
