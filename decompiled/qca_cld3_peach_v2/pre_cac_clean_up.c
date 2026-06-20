__int64 __fastcall pre_cac_clean_up(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  char v37; // w8
  __int64 v38; // x1
  _BYTE v39[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v40[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v41[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Du);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    v39[0] = 0;
    v40[0] = 0;
    result = wlan_objmgr_iterate_obj_list(a1, 2, pre_cac_is_active_vdev_handler, (__int64)v40, 1, 0x60u);
    if ( v40[0] == 1 )
    {
      v41[0] = 0;
      wlan_objmgr_iterate_obj_list(a1, 2, pre_cac_is_active_vdev_handler, (__int64)v41, 1, 0x60u);
      if ( v41[0] == 1 && *(_QWORD *)(v11 + 32) )
      {
        result = qdf_trace_msg(
                   0x98u,
                   8u,
                   "%s: pre_cac_work already shceduled",
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   "pre_cac_clean_up");
      }
      else
      {
        wlan_objmgr_iterate_obj_list(a1, 2, pre_cac_get_vdev_id_handler, (__int64)v39, 1, 0x60u);
        qdf_trace_msg(
          0x98u,
          8u,
          "%s: schedue pre_cac_work vdev %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "pre_cac_clean_up",
          v39[0]);
        v37 = v39[0];
        *(_QWORD *)(v11 + 32) = pre_cac_handle_failure;
        *(_QWORD *)(v11 + 40) = a1;
        *(_BYTE *)(v11 + 48) = v37;
        *(_QWORD *)v11 = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v11 + 8) = v11 + 8;
        *(_QWORD *)(v11 + 16) = v11 + 8;
        v38 = system_wq;
        *(_QWORD *)(v11 + 24) = _qdf_defer_func;
        result = queue_work_on(32, v38, v11);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x98u, 2u, "%s:%u: psoc_priv is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "pre_cac_clean_up", 200);
    result = qdf_trace_msg(0x98u, 2u, "%s: invalid psoc", v21, v22, v23, v24, v25, v26, v27, v28, "pre_cac_clean_up");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
