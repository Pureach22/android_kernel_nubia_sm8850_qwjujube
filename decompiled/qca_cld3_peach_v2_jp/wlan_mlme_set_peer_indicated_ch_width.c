__int64 __fastcall wlan_mlme_set_peer_indicated_ch_width(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 *peer_by_mac; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int8 *v20; // x19
  __int64 comp_private_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20

  if ( a2 )
  {
    peer_by_mac = (unsigned __int8 *)wlan_objmgr_get_peer_by_mac(a1, a2, 2u);
    if ( peer_by_mac )
    {
      v20 = peer_by_mac;
      comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0);
      if ( comp_private_obj )
      {
        v30 = comp_private_obj;
        v31 = target_if_wmi_chan_width_to_phy_ch_width(*((_DWORD *)a2 + 4));
        v40 = 0;
        *(_DWORD *)(v30 + 72) = v31;
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: peer priv not found for mac: %02x:%02x:%02x:**:**:%02x",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "wlan_mlme_set_peer_indicated_ch_width",
          v20[48],
          v20[49],
          v20[50],
          v20[53]);
        v40 = 29;
      }
      wlan_objmgr_peer_release_ref((__int64)v20, 2u, v32, v33, v34, v35, v36, v37, v38, v39);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: peer not found for mac: %02x:%02x:%02x:**:**:%02x",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_mlme_set_peer_indicated_ch_width",
        *a2,
        a2[1],
        a2[2],
        a2[5]);
      return 29;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Data params is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_mlme_set_peer_indicated_ch_width");
    return 4;
  }
  return v40;
}
