__int64 __fastcall target_if_wow_coap_buf_info_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_from_scn_hdl; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 (__fastcall *v23)(__int64, __int64, __int64 *); // x9
  __int64 v24; // x22
  unsigned int v25; // w0
  unsigned int v26; // w21
  __int64 v27; // x20
  __int64 result; // x0
  const char *v29; // x2
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int *comp_private_obj; // x0
  void (__fastcall *v40)(__int64, __int64 *); // x9
  __int64 v41; // x0
  __int64 v42; // x4
  const char *v43; // x2
  _QWORD *v44; // x22
  _QWORD *v45; // x23
  __int64 v46; // [xsp+0h] [xbp-30h] BYREF
  __int64 v47; // [xsp+8h] [xbp-28h]
  _QWORD v48[4]; // [xsp+10h] [xbp-20h] BYREF

  v48[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x9Cu,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_wow_coap_buf_info_event_handler",
      a1,
      a2,
      v46,
      v47);
    result = 4294967274LL;
    goto LABEL_30;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v29 = "%s: null psoc";
    goto LABEL_14;
  }
  v20 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v20 || (v21 = *(_QWORD *)(v20 + 16)) == 0 )
  {
    v29 = "%s: wmi_handle is null";
LABEL_14:
    qdf_trace_msg(
      0x9Cu,
      2u,
      v29,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_wow_coap_buf_info_event_handler",
      v46,
      v47);
    result = 4294967274LL;
    goto LABEL_30;
  }
  v48[0] = v48;
  v48[1] = v48;
  v22 = *(_QWORD *)(v21 + 728);
  v48[2] = 0;
  v23 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(v22 + 4728);
  if ( v23 )
  {
    v24 = psoc_from_scn_hdl;
    if ( *((_DWORD *)v23 - 1) != -660638634 )
      __break(0x8229u);
    v25 = v23(v21, a2, &v46);
    if ( v25 )
    {
      v26 = v25;
      v27 = 0;
    }
    else
    {
      v30 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              v24,
              (unsigned __int8)v46,
              99);
      v27 = v30;
      if ( v30 )
      {
        comp_private_obj = (unsigned int *)wlan_objmgr_vdev_get_comp_private_obj(v30, 0x30u);
        v40 = *((void (__fastcall **)(__int64, __int64 *))comp_private_obj + 1);
        if ( v40 && *((_QWORD *)comp_private_obj + 2) )
        {
          v41 = *((_QWORD *)comp_private_obj + 2);
          if ( *((_DWORD *)v40 - 1) != -1503750356 )
            __break(0x8229u);
          v40(v41, &v46);
          v26 = 0;
          goto LABEL_25;
        }
        v42 = *comp_private_obj;
        v43 = "%s: req id %d: callback or context is NULL";
      }
      else
      {
        v42 = (unsigned __int8)v46;
        v43 = "%s: vdev is NULL, vdev_id: %d";
      }
      qdf_trace_msg(
        0x9Cu,
        2u,
        v43,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "target_if_wow_coap_buf_info_event_handler",
        v42,
        v46,
        v47);
      v26 = 4;
    }
  }
  else
  {
    v27 = 0;
    v26 = 11;
  }
LABEL_25:
  v44 = (_QWORD *)v48[0];
  if ( (_QWORD *)v48[0] != v48 )
  {
    do
    {
      v45 = (_QWORD *)*v44;
      qdf_list_remove_node((__int64)v48, v44);
      _qdf_mem_free(v44[4]);
      _qdf_mem_free((__int64)v44);
      v44 = v45;
    }
    while ( v45 != v48 );
  }
  if ( v27 )
    wlan_objmgr_vdev_release_ref(v27, 0x63u, (unsigned int *)v21, v12, v13, v14, v15, v16, v17, v18, v19);
  result = qdf_status_to_os_return(v26);
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
