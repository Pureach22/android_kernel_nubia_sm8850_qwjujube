__int64 __fastcall cm_populate_roam_chan_list(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w8
  unsigned int *v14; // x26
  int v18; // w0
  unsigned int v19; // w23
  int v20; // w24
  unsigned int v21; // w27
  __int64 is_dfs_unsafe_extra_band_chan; // x0
  __int64 v23; // x1

  v12 = *(_DWORD *)(a2 + 1032);
  if ( v12 )
  {
    v14 = *((unsigned int **)a4 + 1);
    v18 = wlan_reg_band_bitmap_to_band_info(v12);
    v19 = *(unsigned __int8 *)(a3 + 4);
    if ( !*a4 )
    {
LABEL_9:
      *(_BYTE *)(a3 + 4) = v19;
      return 0;
    }
    v20 = v18;
    v21 = 0;
    while ( 1 )
    {
      if ( !wlan_is_channel_present_in_list((int *)(a3 + 8), v19, *v14) )
      {
        is_dfs_unsafe_extra_band_chan = cm_is_dfs_unsafe_extra_band_chan(a1, a2, *v14, v20);
        if ( (is_dfs_unsafe_extra_band_chan & 1) == 0 )
        {
          if ( v19 >= 0x64 )
          {
            __break(0x5512u);
            return cm_add_denylist_ap_list(is_dfs_unsafe_extra_band_chan, v23);
          }
          *(_DWORD *)(a3 + 8 + 4LL * v19++) = *v14;
        }
      }
      ++v21;
      ++v14;
      if ( v21 >= *a4 )
        goto LABEL_9;
    }
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: Invalid band_cap(%d), roam scan offload req aborted",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "cm_populate_roam_chan_list",
    0);
  return 16;
}
