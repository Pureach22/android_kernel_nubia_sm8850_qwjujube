// positive sp value has been detected, the output may be wrong!
__int64 sub_20DEBC()
{
  unsigned __int8 *v0; // x19
  int v1; // w20
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v4; // x23
  __int64 v5; // x26
  __int64 v6; // x27
  __int64 v7; // x28
  int *v9; // x24
  int v10; // w25
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 **v22; // x25
  __int64 *i; // x8
  int v24; // w9

  if ( (v3 & 0x8000000000000LL) != 0 )
    return wlan_reg_get_min_max_bw_for_chan_index();
LABEL_4:
  while ( ++v7 < (unsigned __int64)*v0 )
  {
    if ( v7 == 102 )
    {
      __break(0x5512u);
      JUMPOUT(0x210208);
    }
    v9 = (int *)(v5 + v7 * v3);
    v10 = *v9;
    if ( *v9 && wlan_reg_is_6ghz_chan_freq(v10) )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v2, 3u);
      if ( comp_private_obj )
      {
        v20 = comp_private_obj + v4;
        v21 = 60;
        while ( *(_DWORD *)v20 != v10 )
        {
          --v21;
          v20 += 48;
          if ( !v21 )
            goto LABEL_4;
        }
        if ( v20 )
        {
          v22 = (__int64 **)(v20 + 24);
          if ( !qdf_list_empty((_QWORD *)(v20 + 24)) )
          {
            for ( i = *v22; v22 != (__int64 **)i; i = (__int64 *)*i )
            {
              if ( i )
              {
                v24 = *((_DWORD *)i + 6);
                if ( v24 )
                {
                  if ( v24 == v1 )
                  {
                    v9[2] &= ~1u;
                    goto LABEL_4;
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: %s:%u, Failed to get scan object",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wlan_psoc_get_scan_obj_fl",
          "scm_get_rnr_channel_db",
          68);
      }
    }
  }
  return qdf_mutex_release(v6 + 23920);
}
