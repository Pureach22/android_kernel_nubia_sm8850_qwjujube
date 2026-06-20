__int64 __fastcall tdls_process_send_mgmt_rsp(unsigned __int8 *a1)
{
  __int64 comp_private_obj; // x21
  __int64 v3; // x1
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  unsigned int v14; // w22
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x5
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _DWORD *v41; // x8
  __int64 v42; // x0
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v53[4]; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v54[2]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v55; // [xsp+30h] [xbp-10h]
  __int64 v56; // [xsp+38h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = *((_QWORD *)a1 + 1);
  v3 = *a1;
  v54[1] = 0;
  v55 = 0;
  v54[0] = 0;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         comp_private_obj,
         v3,
         16);
  if ( v4 )
  {
    v13 = v4;
    if ( comp_private_obj )
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(comp_private_obj, 0xAu);
    else
      qdf_trace_msg(0, 2u, "%s: NULL psoc", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_psoc_get_tdls_soc_obj");
    v15 = wlan_objmgr_vdev_get_comp_private_obj(v13, 0xAu);
    v24 = v15;
    if ( comp_private_obj && v15 )
    {
      v14 = 0;
    }
    else
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: soc object:%pK, vdev object:%pK",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "tdls_process_send_mgmt_rsp",
        comp_private_obj,
        v15);
      v14 = 16;
    }
    qdf_trace_msg(
      0,
      8u,
      "%s: release %s",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "tdls_release_serialization_command",
      "TDLS_SEND_MGMT_CMD",
      v24,
      0xD00000000LL,
      0,
      v13,
      0);
    wlan_serialization_remove_cmd(v53, v25, v26, v27, v28, v29, v30, v31, v32);
    if ( *((_DWORD *)a1 + 1) )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: send mgmt failed. status code(=%d)",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "tdls_process_send_mgmt_rsp");
      if ( comp_private_obj )
      {
        v41 = *(_DWORD **)(comp_private_obj + 264);
        v14 = 16;
        if ( v41 )
        {
          v42 = *(_QWORD *)(comp_private_obj + 272);
          v54[0] = v13;
          LODWORD(v55) = 16;
          if ( *(v41 - 1) != 1890320457 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD *))v41)(v42, 1, v54);
        }
      }
      else
      {
        v14 = 16;
      }
    }
    _qdf_mem_free((__int64)a1);
    wlan_objmgr_vdev_release_ref(v13, 0x10u, v43, v44, v45, v46, v47, v48, v49, v50, v51);
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: invalid vdev", v5, v6, v7, v8, v9, v10, v11, v12, "tdls_process_send_mgmt_rsp");
    _qdf_mem_free((__int64)a1);
    v14 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
