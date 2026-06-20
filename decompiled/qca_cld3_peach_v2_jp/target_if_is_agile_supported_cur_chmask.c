__int64 __fastcall target_if_is_agile_supported_cur_chmask(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x2
  __int64 v11; // x22
  __int64 v12; // x23
  _QWORD *vdev; // x0
  __int64 v15; // x20
  __int64 cmpt_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w19
  unsigned int ch_width; // w0
  unsigned int *v27; // x8
  const char *v28; // x2
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v39; // w24
  __int64 v40; // x20
  __int64 mac_phy_cap; // x0
  __int64 v42; // x1
  __int64 v43; // x5
  int v44; // w10
  int v45; // w9
  unsigned __int8 *v46; // x12
  char v47; // w11

  if ( !a2 )
  {
    v10 = "%s: is supported argument is null";
    goto LABEL_17;
  }
  if ( *(_DWORD *)(a1 + 1252) <= 1u )
  {
    v10 = "%s: HW Agile mode is not supported up to gen 2";
LABEL_17:
    qdf_trace_msg(0x56u, 2u, v10, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_is_agile_supported_cur_chmask");
    return 16;
  }
  v11 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
  {
    v10 = "%s: pdev is null";
    goto LABEL_17;
  }
  v12 = *(_QWORD *)(v11 + 80);
  if ( !v12 )
  {
    v10 = "%s: psoc is null";
    goto LABEL_17;
  }
  vdev = target_if_spectral_get_vdev((__int64 *)a1, 1u, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !vdev )
  {
    v10 = "%s: First vdev is NULL";
    goto LABEL_17;
  }
  v15 = (__int64)vdev;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj((__int64)vdev, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( cmpt_obj && (v25 = *(unsigned __int8 *)(cmpt_obj + 401), *(_BYTE *)(cmpt_obj + 401)) )
  {
    ch_width = target_if_vdev_get_ch_width(v15);
    if ( ch_width != 8 )
    {
      v39 = ch_width;
      wlan_objmgr_vdev_release_ref(v15, 0x1Bu, v27, v17, v18, v19, v20, v21, v22, v23, v24);
      v40 = *(_QWORD *)(v12 + 2800);
      if ( v40 )
      {
        mac_phy_cap = target_psoc_get_mac_phy_cap(*(_QWORD *)(v12 + 2800));
        if ( mac_phy_cap )
        {
          if ( mac_phy_cap + ((unsigned __int64)*(unsigned __int8 *)(v11 + 40) << 8) )
          {
            v43 = *(unsigned int *)(mac_phy_cap + ((unsigned __int64)*(unsigned __int8 *)(v11 + 40) << 8) + 212);
            if ( (unsigned int)v43 >= 6 )
            {
              __break(0x5512u);
              return target_if_get_curr_band(mac_phy_cap, v42);
            }
            if ( v40 + 16 * v43 != -848 )
            {
              v44 = *(_DWORD *)(v40 + 16 * v43 + 852);
              if ( v44 )
              {
                v45 = 0;
                while ( 1 )
                {
                  v46 = (unsigned __int8 *)(*(_QWORD *)(v40 + 16 * v43 + 856) + 8LL * v45);
                  if ( *((_DWORD *)v46 + 1) == v25 )
                    break;
                  if ( v44 == ++v45 )
                  {
                    v45 = *(_DWORD *)(v40 + 16 * v43 + 852);
                    goto LABEL_38;
                  }
                }
                v47 = 5;
                if ( v39 >= 3 )
                  v47 = 6;
                *a2 = (*v46 >> v47) & 1;
              }
              else
              {
                v45 = 0;
              }
LABEL_38:
              if ( v45 != *(_DWORD *)(v40 + 16 * v43 + 852) )
                return 0;
              qdf_trace_msg(
                0x56u,
                2u,
                "%s: vdev rx chainmask %u not found in table id = %u",
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                "target_if_is_agile_supported_cur_chmask",
                v25);
              return 16;
            }
            v10 = "%s: chainmask table not found";
          }
          else
          {
            v10 = "%s: mac phy cap is null";
          }
        }
        else
        {
          v10 = "%s: mac phy cap array is null";
        }
      }
      else
      {
        v10 = "%s: target_psoc_info is null";
      }
      goto LABEL_17;
    }
    v28 = "%s: Invalid channel width";
  }
  else
  {
    v28 = "%s: vdev rx chainmask is zero";
  }
  qdf_trace_msg(0x56u, 2u, v28, v17, v18, v19, v20, v21, v22, v23, v24, "target_if_is_agile_supported_cur_chmask");
  wlan_objmgr_vdev_release_ref(v15, 0x1Bu, v29, v30, v31, v32, v33, v34, v35, v36, v37);
  return 16;
}
