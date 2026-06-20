__int64 __fastcall cm_update_tried_candidate_freq_list(__int64 result, __int64 a2, unsigned __int8 *a3)
{
  unsigned int v3; // w8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w1
  __int64 v18; // x20
  __int64 v19; // x21
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int64 v31; // x9
  int v32; // w11

  if ( *((_DWORD *)a3 + 12) )
  {
    v3 = *((_DWORD *)a3 + 14);
    if ( v3 <= 0xA && ((1 << v3) & 0x540) != 0 )
    {
      result = mlme_get_psoc_ext_obj_fl(result);
      if ( result )
      {
        v14 = result;
        v15 = *(_DWORD *)(result + 1032);
        if ( v15 )
        {
          v16 = wlan_reg_band_bitmap_to_band_info(v15);
          result = cm_is_dfs_unsafe_extra_band_chan(a2, v14, *((unsigned int *)a3 + 12), v16);
          if ( (result & 1) == 0 )
          {
            result = wlan_cm_get_rso_config_fl(a2, "cm_update_tried_candidate_freq_list", 2334);
            if ( result )
            {
              v17 = *(unsigned __int8 *)(result + 960);
              if ( v17 <= 0x63 )
              {
                v18 = result + 964;
                v19 = result;
                result = wlan_is_channel_present_in_list((int *)(result + 964), v17, *((_DWORD *)a3 + 12));
                if ( (result & 1) == 0 )
                {
                  v31 = *(unsigned __int8 *)(v19 + 960);
                  v32 = *((_DWORD *)a3 + 12);
                  *(_BYTE *)(v19 + 960) = v31 + 1;
                  if ( v31 >= 0x64 )
                  {
                    __break(0x5512u);
                    return cm_is_dfs_unsafe_extra_band_chan(result, v20, v21, v22);
                  }
                  else
                  {
                    *(_DWORD *)(v18 + 4 * v31) = v32;
                    return qdf_trace_msg(
                             0x68u,
                             8u,
                             "%s: vdev: %d added freq:%d, total num freq %d",
                             v23,
                             v24,
                             v25,
                             v26,
                             v27,
                             v28,
                             v29,
                             v30,
                             "cm_update_tried_candidate_freq_list",
                             *a3,
                             *((unsigned int *)a3 + 12),
                             (unsigned __int8)(v31 + 1));
                  }
                }
              }
            }
          }
        }
        else
        {
          return qdf_trace_msg(
                   0x68u,
                   2u,
                   "%s: vdev: %d Invalid band_cap(%d)",
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   "cm_update_tried_candidate_freq_list",
                   *a3,
                   0);
        }
      }
    }
  }
  return result;
}
