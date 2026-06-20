__int64 __fastcall cm_roam_send_vendor_handoff_param_req(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  unsigned int v6; // w21
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  __int64 ext_hdl; // x0
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20
  __int64 v29; // x25
  _DWORD *v30; // x0
  __int64 v31; // x23
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v6 = a2;
  v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v8 )
  {
    v17 = v8;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v8, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( ext_hdl )
    {
      if ( *(_BYTE *)(ext_hdl + 288) == 1 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vendor handoff request is already in progress",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "cm_roam_send_vendor_handoff_param_req");
        v28 = 16;
      }
      else
      {
        v29 = ext_hdl;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: Set vendor handoff req in progress context",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "cm_roam_send_vendor_handoff_param_req");
        *(_BYTE *)(v29 + 288) = 1;
        *(_QWORD *)(v29 + 280) = a4;
        v30 = (_DWORD *)_qdf_mem_malloc(8u, "cm_roam_send_vendor_handoff_param_req", 953);
        if ( v30 )
        {
          v31 = (__int64)v30;
          *v30 = (unsigned __int8)v6;
          v30[1] = a3;
          v28 = wlan_cm_tgt_send_roam_vendor_handoff_config(a1, v30);
          if ( v28 )
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: fail to send roam rt stats config",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "cm_roam_send_vendor_handoff_param_req");
          _qdf_mem_free(v31);
        }
        else
        {
          cm_roam_reset_vendor_handoff_req(a1, v6);
          v28 = 2;
        }
      }
    }
    else
    {
      v28 = 16;
    }
    wlan_objmgr_vdev_release_ref(v17, 0x4Du, v19, v20, v21, v22, v23, v24, v25, v26, v27);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: get vdev failed",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "cm_roam_send_vendor_handoff_param_req");
    return 16;
  }
  return v28;
}
