__int64 __fastcall wlan_wifi_pos_pasn_peer_delete_all(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int *v12; // x8
  __int64 v13; // x20
  __int64 result; // x0
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // [xsp+8h] [xbp-38h] BYREF
  __int64 v25; // [xsp+10h] [xbp-30h]
  __int64 v26; // [xsp+18h] [xbp-28h]
  __int64 v27; // [xsp+20h] [xbp-20h]
  __int64 v28; // [xsp+28h] [xbp-18h]
  __int64 v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v2 = a2;
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 41);
  if ( !v3 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Vdev is not found for id:%d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_wifi_pos_pasn_peer_delete_all",
      v2);
    goto LABEL_8;
  }
  v12 = (unsigned int *)*(unsigned int *)(v3 + 16);
  if ( (unsigned int)v12 >= 2 )
    goto LABEL_6;
  v13 = v3;
  if ( !(unsigned __int8)wifi_pos_get_pasn_peer_count(v3) || (wifi_pos_is_delete_all_peer_in_progress(v13) & 1) != 0 )
  {
    v3 = v13;
LABEL_6:
    wlan_objmgr_vdev_release_ref(v3, 0x29u, v12, v4, v5, v6, v7, v8, v9, v10, v11);
    goto LABEL_8;
  }
  wlan_objmgr_vdev_release_ref(v13, 0x29u, v12, v4, v5, v6, v7, v8, v9, v10, v11);
  result = _qdf_mem_malloc(6u, "wlan_wifi_pos_pasn_peer_delete_all", 105);
  if ( !result )
    goto LABEL_9;
  *(_BYTE *)(result + 4) = v2;
  v15 = result;
  v25 = result;
  LOWORD(v24) = 5297;
  if ( !(unsigned int)scheduler_post_message_debug(
                        0x25u,
                        0x35u,
                        53,
                        (unsigned __int16 *)&v24,
                        0x74u,
                        (__int64)"wlan_wifi_pos_pasn_peer_delete_all") )
  {
    result = 1;
    goto LABEL_9;
  }
  _qdf_mem_free(v15);
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: Delete all pasn peers failed",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wlan_wifi_pos_pasn_peer_delete_all");
LABEL_8:
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
