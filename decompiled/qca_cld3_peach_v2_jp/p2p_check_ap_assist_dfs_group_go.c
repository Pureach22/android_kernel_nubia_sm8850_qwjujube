__int64 __fastcall p2p_check_ap_assist_dfs_group_go(__int64 a1)
{
  __int64 v1; // x19
  __int64 comp_private_obj; // x0
  char v4; // w11
  int v5; // w9
  __int16 v6; // w12
  char v7; // w8
  __int64 result; // x0
  unsigned int v9; // w21
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int operation_chan_freq; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _QWORD *peer_by_mac; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x19
  const char *v37; // x2
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w20
  unsigned int v48; // w0
  __int64 v49; // [xsp+0h] [xbp-10h] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    goto LABEL_10;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj )
    goto LABEL_10;
  v4 = *(_BYTE *)(comp_private_obj + 958);
  v5 = *(unsigned __int8 *)(comp_private_obj + 963);
  v6 = *(_WORD *)(comp_private_obj + 971);
  v7 = *(_BYTE *)(comp_private_obj + 960);
  LODWORD(v49) = *(_DWORD *)(comp_private_obj + 967);
  WORD2(v49) = v6;
  if ( (v4 & 1) == 0 )
  {
    if ( v5 )
    {
      if ( (v7 & 1) != 0 )
        goto LABEL_4;
      v9 = *(unsigned __int8 *)(comp_private_obj + 974);
      if ( (unsigned int)wlan_vdev_mlme_is_init_state(a1) )
      {
        operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a1);
        if ( (wlan_reg_is_dfs_for_freq(v1, operation_chan_freq, v19, v20, v21, v22, v23, v24, v25, v26) & 1) == 0 )
          goto LABEL_4;
      }
      else
      {
        operation_chan_freq = wlan_reg_legacy_chan_to_freq(v1, v9, v10, v11, v12, v13, v14, v15, v16, v17);
      }
      peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(v1 + 80), &v49, 0xFu);
      if ( !peer_by_mac )
      {
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: No entity with MAC %02x:%02x:%02x:**:**:%02x",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "p2p_check_ap_assist_dfs_group_go",
          (unsigned __int8)v49,
          BYTE1(v49),
          BYTE2(v49),
          BYTE5(v49));
        result = 16;
        goto LABEL_11;
      }
      v36 = (__int64)peer_by_mac;
      if ( *((_DWORD *)peer_by_mac + 17) == 1 )
      {
        v37 = "%s: Invalid peer type";
      }
      else
      {
        v38 = peer_by_mac[11];
        if ( !*(_DWORD *)(v38 + 16) )
        {
          v48 = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)v38);
          if ( v48 == operation_chan_freq )
          {
            v47 = 0;
            goto LABEL_21;
          }
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: Conc VDEV freq %d, GO freq %d",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "p2p_check_ap_assist_dfs_group_go",
            v48,
            operation_chan_freq);
LABEL_20:
          v47 = 16;
LABEL_21:
          wlan_objmgr_peer_release_ref(v36, 0xFu, v39, v40, v41, v42, v43, v44, v45, v46);
          result = v47;
          goto LABEL_11;
        }
        v37 = "%s: Conc VDEV is not STA";
      }
      qdf_trace_msg(
        0x4Eu,
        8u,
        v37,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "p2p_check_ap_assist_dfs_group_go",
        v49,
        v50);
      goto LABEL_20;
    }
LABEL_10:
    result = 4;
    goto LABEL_11;
  }
LABEL_4:
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
