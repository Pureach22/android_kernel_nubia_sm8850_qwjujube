__int64 __fastcall ucfg_dp_update_intf_mac(__int64 a1, unsigned __int8 *a2, unsigned __int8 *a3, __int64 a4)
{
  __int64 comp_private_obj; // x0
  __int64 intf_by_macaddr; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  int v22; // w8
  int v23; // w9
  int v24; // w10
  int v25; // w11
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w9
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x5
  __int64 v49; // x20
  __int64 result; // x0
  __int64 v51; // [xsp+0h] [xbp-20h]

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  intf_by_macaddr = dp_get_intf_by_macaddr(comp_private_obj, (__int64)a2);
  if ( intf_by_macaddr )
  {
    v17 = intf_by_macaddr;
    if ( a2 )
    {
      v18 = *a2;
      v19 = a2[1];
      v20 = a2[2];
      v21 = a2[5];
      if ( a3 )
      {
LABEL_4:
        v22 = *a3;
        v23 = a3[1];
        v24 = a3[2];
        v25 = a3[5];
        goto LABEL_9;
      }
    }
    else
    {
      v20 = 0;
      v18 = 0;
      v19 = 0;
      v21 = 0;
      if ( a3 )
        goto LABEL_4;
    }
    v24 = 0;
    v22 = 0;
    v23 = 0;
    v25 = 0;
LABEL_9:
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: MAC update from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "ucfg_dp_update_intf_mac",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25);
    v38 = *(_DWORD *)a3;
    *(_WORD *)(v17 + 24) = *((_WORD *)a3 + 2);
    *(_DWORD *)(v17 + 20) = v38;
    if ( a4 )
    {
      v39 = wlan_objmgr_vdev_get_comp_private_obj(a4, 0x2Eu);
      v48 = *(_QWORD *)(v17 + 3664);
      if ( v39 )
      {
        v49 = v39;
        LODWORD(v51) = *(unsigned __int8 *)(v39 + 24);
        result = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: Try def_link update for dp_intf %pK from %pK to %pK (intf %pK id %d)",
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45,
                   v46,
                   v47,
                   "ucfg_dp_update_intf_mac",
                   v17,
                   v48,
                   v39,
                   *(_QWORD *)(v39 + 32),
                   v51);
        if ( *(_QWORD *)(v49 + 32) == v17 )
          *(_QWORD *)(v17 + 3664) = v49;
        return result;
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 2u, "%s: vdev is null", v30, v31, v32, v33, v34, v35, v36, v37, "dp_get_vdev_priv_obj");
      v48 = *(_QWORD *)(v17 + 3664);
    }
    LODWORD(v51) = 255;
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: Try def_link update for dp_intf %pK from %pK to %pK (intf %pK id %d)",
             v40,
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             "ucfg_dp_update_intf_mac",
             v17,
             v48,
             0,
             0,
             v51);
  }
  if ( a2 )
  {
    v26 = *a2;
    v27 = a2[1];
    v28 = a2[2];
    v29 = a2[5];
  }
  else
  {
    v28 = 0;
    v26 = 0;
    v27 = 0;
    v29 = 0;
  }
  return qdf_trace_msg(
           0x45u,
           2u,
           "%s: DP interface not found addr:%02x:%02x:%02x:**:**:%02x",
           v9,
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           "ucfg_dp_update_intf_mac",
           v26,
           v27,
           v28,
           v29);
}
