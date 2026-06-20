__int64 __fastcall hdd_update_sub20_chan_width(__int64 a1, unsigned int a2)
{
  __int64 v3; // x21
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int updated; // w20
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w0
  const char *v23; // x2
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w0
  __int64 v34; // x20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w0
  unsigned int v44; // w0
  unsigned int v45; // w0

  v3 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  if ( !(unsigned int)ucfg_policy_mgr_get_connection_count(*(_QWORD *)v3) )
  {
    v13 = cds_set_sub_20_channel_width(a2, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( v13 )
    {
      updated = v13;
      if ( v13 == 6 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: sub20MHz chan width is already %u",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "hdd_update_sub20_chan_width",
          a2);
        return 0;
      }
      v23 = "%s: failed to set sub20MHz chan width: %u";
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: sub20MHz chan width to set: %u",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_update_sub20_chan_width",
        a2);
      v22 = wlan_mlme_set_sub_20_chan_width(*(_QWORD *)v3, a2);
      if ( v22 )
      {
        updated = v22;
        v23 = "%s: failed to set mlme sub20MHz chan width: %u";
      }
      else
      {
        hdd_update_vdev_nss((__int64 *)v3);
        v33 = hdd_cfg_xlate_to_csr_phy_mode(**(_DWORD **)(v3 + 104), v25, v26, v27, v28, v29, v30, v31, v32);
        sme_update_score_config(*(_QWORD *)(v3 + 16), v33, *(unsigned int *)(v3 + 1248));
        v34 = *(_QWORD *)(v3 + 16);
        v43 = hdd_cfg_xlate_to_csr_phy_mode(**(_DWORD **)(v3 + 104), v35, v36, v37, v38, v39, v40, v41, v42);
        v44 = sme_set_phy_mode(v34, v43);
        if ( v44 )
        {
          updated = v44;
          v23 = "%s: failed to set phy mode: %u";
        }
        else
        {
          if ( !hdd_update_config_cfg() )
            return 16;
          v45 = hdd_set_policy_mgr_user_cfg((__int64 *)v3);
          if ( v45 )
          {
            updated = v45;
            v23 = "%s: failed to set policy mgr user config: %u";
          }
          else
          {
            updated = sme_update_channel_list(*(_QWORD *)(v3 + 16));
            if ( !updated )
            {
              *(_DWORD *)(*(_QWORD *)(v3 + 104) + 196LL) = a2;
              return updated;
            }
            v23 = "%s: failed to update channel list: %u";
          }
        }
      }
    }
    qdf_trace_msg(0x33u, 2u, v23, v14, v15, v16, v17, v18, v19, v20, v21, "hdd_update_sub20_chan_width", updated);
    return updated;
  }
  updated = 4;
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: sub20MHz chan width updating is not allowed when connection is present",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "hdd_update_sub20_chan_width");
  return updated;
}
