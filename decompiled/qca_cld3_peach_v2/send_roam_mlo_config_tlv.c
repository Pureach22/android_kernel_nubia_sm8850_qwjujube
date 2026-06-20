__int64 __fastcall send_roam_mlo_config_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x24
  __int64 v6; // x19
  unsigned int v7; // w22
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  __int64 v18; // x0
  unsigned int *max_allowed_11be_failure; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x7
  __int64 v38; // x6
  __int64 v39; // x4
  __int64 v40; // x5
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // [xsp+0h] [xbp-30h]
  int v58; // [xsp+8h] [xbp-28h]
  int v59; // [xsp+10h] [xbp-20h]
  int v60; // [xsp+18h] [xbp-18h]
  int v61; // [xsp+20h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x24u, "send_roam_mlo_config_tlv", 0x14ADu);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 66125856;
  v5[3] = *a2;
  v5[4] = *((_DWORD *)a2 + 2);
  v5[5] = *((_DWORD *)a2 + 3) & 7;
  v7 = *a2;
  v8 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         **(_QWORD **)(a1 + 760),
         *a2,
         1);
  if ( v8 )
  {
    v17 = v8;
    v18 = *(_QWORD *)(v8 + 216);
    if ( v18 )
    {
      max_allowed_11be_failure = (unsigned int *)(unsigned __int8)dlm_get_max_allowed_11be_failure(v18);
      v5[8] = (_DWORD)max_allowed_11be_failure;
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: For vdev:%d object is NULL",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "cmd_update_max_11be_connection_allowed",
        v7);
    }
    wlan_objmgr_vdev_release_ref(v17, 1u, max_allowed_11be_failure, v20, v21, v22, v23, v24, v25, v26, v27);
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: For vdev:%d object is NULL",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "cmd_update_max_11be_connection_allowed",
      v7);
  }
  v37 = (unsigned int)v5[7];
  if ( !*((_DWORD *)a2 + 4) )
  {
    v37 = (unsigned int)v37 | 1;
    v5[7] = v37;
  }
  v38 = (unsigned int)v5[5];
  v5[1] = *(_DWORD *)(a2 + 1);
  v39 = (unsigned int)v5[3];
  v40 = (unsigned int)v5[4];
  v5[2] = *(unsigned __int16 *)(a2 + 5);
  v60 = a2[3];
  v61 = a2[6];
  v59 = a2[2];
  v58 = a2[1];
  v57 = v5[8];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: RSO_CFG MLO: vdev_id:%d support_link_num:%d support_link_band:0x%0x disallow_connect_mode %d max 11be con allowe"
    "d %d link addr:%02x:%02x:%02x:**:**:%02x",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "send_roam_mlo_config_tlv",
    v39,
    v40,
    v38,
    v37,
    v57,
    v58,
    v59,
    v60,
    v61);
  wmi_mtrace(0xB01Au, v5[3], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x24u,
             0xB01Au,
             "send_roam_mlo_config_tlv",
             0x14CBu,
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_ROAM_MLO_CONFIG_CMDID",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "send_roam_mlo_config_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
