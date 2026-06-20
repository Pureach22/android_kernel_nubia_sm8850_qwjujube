__int64 __fastcall tdls_send_mgmt_tx_completion(unsigned __int8 *a1)
{
  __int64 v2; // x21
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
  __int64 comp_private_obj; // x22
  unsigned int v15; // w21
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x8
  int v26; // w9
  __int64 v27; // x0
  _QWORD v29[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a1 + 1);
  v3 = *a1;
  v29[1] = 0;
  v30 = 0;
  v29[0] = 0;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v2, v3, 16);
  if ( v4 )
  {
    v13 = v4;
    if ( v2 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v2, 0xAu);
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: NULL psoc", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_psoc_get_tdls_soc_obj");
      comp_private_obj = 0;
    }
    v16 = wlan_objmgr_vdev_get_comp_private_obj(v13, 0xAu);
    if ( comp_private_obj && v16 )
    {
      v15 = 0;
    }
    else
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: soc object:%pK, vdev object:%pK",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "tdls_send_mgmt_tx_completion",
        comp_private_obj,
        v16);
      v15 = 16;
      if ( !comp_private_obj )
      {
LABEL_14:
        wlan_objmgr_vdev_release_ref(v13, 0x10u, v25, v17, v18, v19, v20, v21, v22, v23, v24);
        goto LABEL_15;
      }
    }
    v25 = *(unsigned int **)(comp_private_obj + 264);
    if ( v25 )
    {
      v26 = *((_DWORD *)a1 + 1);
      v27 = *(_QWORD *)(comp_private_obj + 272);
      v29[0] = v13;
      LODWORD(v30) = v26;
      if ( *(v25 - 1) != 1890320457 )
        __break(0x8228u);
      v17 = ((double (__fastcall *)(__int64, __int64, _QWORD *))v25)(v27, 1, v29);
    }
    goto LABEL_14;
  }
  qdf_trace_msg(0, 2u, "%s: invalid vdev", v5, v6, v7, v8, v9, v10, v11, v12, "tdls_send_mgmt_tx_completion");
  v15 = 4;
LABEL_15:
  _qdf_mem_free((__int64)a1);
  _ReadStatusReg(SP_EL0);
  return v15;
}
