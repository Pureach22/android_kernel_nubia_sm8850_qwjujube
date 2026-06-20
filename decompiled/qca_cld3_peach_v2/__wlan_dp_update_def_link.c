__int64 __fastcall _wlan_dp_update_def_link(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 comp_private_obj; // x0
  __int64 intf_by_macaddr; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char v25; // w14
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  unsigned __int8 *v30; // x8
  int v31; // w9
  int v32; // w10
  int v33; // w11
  int v34; // w13
  int v35; // w12
  int v36; // w16
  int v37; // w14
  __int64 v38; // x15
  int v39; // w17
  __int64 result; // x0
  unsigned __int8 *v41; // x13
  int v42; // w9
  int v43; // w10
  int v44; // w11
  int v45; // w12
  int v46; // w13
  __int64 v47; // x20

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  intf_by_macaddr = dp_get_intf_by_macaddr(comp_private_obj, (__int64)a2);
  if ( !intf_by_macaddr )
  {
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
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "__wlan_dp_update_def_link",
             v26,
             v27,
             v28,
             v29);
  }
  v15 = intf_by_macaddr;
  if ( !a3 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", v7, v8, v9, v10, v11, v12, v13, v14, "dp_get_vdev_priv_obj");
    v16 = 0;
    goto LABEL_9;
  }
  v16 = wlan_objmgr_vdev_get_comp_private_obj(a3, 0x2Eu);
  if ( !v16 )
  {
LABEL_9:
    v25 = 1;
LABEL_10:
    v30 = *(unsigned __int8 **)(v15 + 3664);
    if ( v30 == (unsigned __int8 *)-25LL )
    {
      v33 = 0;
      v31 = 0;
      v32 = 0;
      v34 = 0;
      v35 = *(unsigned __int8 *)(v15 + 25);
      if ( (v25 & 1) != 0 )
        goto LABEL_12;
    }
    else
    {
      v31 = v30[25];
      v32 = v30[26];
      v33 = v30[27];
      v34 = v30[30];
      v35 = *(unsigned __int8 *)(v15 + 25);
      if ( (v25 & 1) != 0 )
      {
LABEL_12:
        v36 = 0;
        v37 = 0;
        v38 = 0;
        v39 = 255;
        return qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: Update failed dp_intf %pK(%02x:%02x:%02x:**:**:%02x) from %pK(%02x:%02x:%02x:**:**:%02x) to %pK(%02"
                 "x:%02x:%02x:**:**:%02x) (intf %pK(%02x:%02x:%02x:**:**:%02x) id %d) ",
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 "__wlan_dp_update_def_link",
                 v15,
                 *(unsigned __int8 *)(v15 + 20),
                 *(unsigned __int8 *)(v15 + 21),
                 *(unsigned __int8 *)(v15 + 22),
                 v35,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v16,
                 v37,
                 0,
                 0,
                 0,
                 v38,
                 v36,
                 0,
                 0,
                 0,
                 v39);
      }
    }
    if ( v16 == -25 )
      v37 = 0;
    else
      v37 = *(unsigned __int8 *)(v16 + 30);
    v38 = *(_QWORD *)(v16 + 32);
    if ( v38 == -20 )
      v36 = 0;
    else
      v36 = *(unsigned __int8 *)(v38 + 25);
    v39 = *(unsigned __int8 *)(v16 + 24);
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: Update failed dp_intf %pK(%02x:%02x:%02x:**:**:%02x) from %pK(%02x:%02x:%02x:**:**:%02x) to %pK(%02x:%0"
             "2x:%02x:**:**:%02x) (intf %pK(%02x:%02x:%02x:**:**:%02x) id %d) ",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "__wlan_dp_update_def_link",
             v15,
             *(unsigned __int8 *)(v15 + 20),
             *(unsigned __int8 *)(v15 + 21),
             *(unsigned __int8 *)(v15 + 22),
             v35,
             v30,
             v31,
             v32,
             v33,
             v34,
             v16,
             v37,
             0,
             0,
             0,
             v38,
             v36,
             0,
             0,
             0,
             v39);
  }
  if ( *(_QWORD *)(v16 + 32) != v15 )
  {
    v25 = 0;
    goto LABEL_10;
  }
  v41 = *(unsigned __int8 **)(v15 + 3664);
  v42 = v41[24];
  if ( v41 == (unsigned __int8 *)-25LL )
  {
    v45 = 0;
    v43 = 0;
    v44 = 0;
    v46 = 0;
  }
  else
  {
    v43 = v41[25];
    v44 = v41[26];
    v45 = v41[27];
    v46 = v41[30];
  }
  v47 = v16;
  result = qdf_trace_msg(
             0x45u,
             5u,
             "%s: change dp_intf %pK(%02x:%02x:%02x:**:**:%02x) def_link %d(%02x:%02x:%02x:**:**:%02x) -> %d(%02x:%02x:%02x:**:**:%02x)",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "__wlan_dp_update_def_link",
             v15,
             *(unsigned __int8 *)(v15 + 20),
             *(unsigned __int8 *)(v15 + 21),
             *(unsigned __int8 *)(v15 + 22),
             *(unsigned __int8 *)(v15 + 25),
             v42,
             v43,
             v44,
             v45,
             v46,
             *(unsigned __int8 *)(v16 + 24),
             *(unsigned __int8 *)(v16 + 25),
             *(unsigned __int8 *)(v16 + 26),
             *(unsigned __int8 *)(v16 + 27),
             *(unsigned __int8 *)(v16 + 30));
  *(_QWORD *)(v15 + 3664) = v47;
  return result;
}
