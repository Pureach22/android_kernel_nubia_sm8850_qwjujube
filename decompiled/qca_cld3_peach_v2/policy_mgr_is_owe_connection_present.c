__int64 __fastcall policy_mgr_is_owe_connection_present(__int64 a1, char a2)
{
  __int64 v2; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v14; // x21
  double v15; // d0
  char v16; // w0
  char v17; // w22
  unsigned int *v18; // x8
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  const char *v27; // x2
  int mode_specific_conn_info; // w21
  _QWORD *v29; // x0
  __int64 v30; // x20
  unsigned int *v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _QWORD *v40; // x0
  _QWORD *v41; // x0
  _QWORD *v42; // x0
  _QWORD *v43; // x0
  int v44; // [xsp+8h] [xbp-28h] BYREF
  char v45; // [xsp+Ch] [xbp-24h]
  _QWORD v46[2]; // [xsp+10h] [xbp-20h] BYREF
  int v47; // [xsp+20h] [xbp-10h]
  __int64 v48; // [xsp+28h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 80);
  v47 = 0;
  v46[0] = 0;
  v46[1] = 0;
  v45 = 0;
  v44 = 0;
  if ( !v2 )
    goto LABEL_9;
  if ( !policy_mgr_get_context(v2) )
  {
    v27 = "%s: Invalid Context";
LABEL_8:
    qdf_trace_msg(0x4Fu, 2u, v27, v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_is_owe_connection_present");
    goto LABEL_9;
  }
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u);
  if ( !vdev_by_id_from_pdev )
  {
    v27 = "%s: Invalid vdev Context";
    goto LABEL_8;
  }
  v14 = (__int64)vdev_by_id_from_pdev;
  v15 = ((double (*)(void))wlan_sap_is_owe_connection_present)();
  v17 = v16;
  wlan_objmgr_vdev_release_ref(v14, 7u, v18, v15, v19, v20, v21, v22, v23, v24, v25);
  if ( (v17 & 1) == 0 )
  {
    mode_specific_conn_info = (unsigned __int8)policy_mgr_get_mode_specific_conn_info(
                                                 v2,
                                                 (unsigned __int64)v46,
                                                 (unsigned __int64)&v44,
                                                 1u);
    if ( mode_specific_conn_info )
    {
      v29 = wlan_objmgr_get_vdev_by_id_from_pdev(a1, v44, 7u);
      if ( !v29 )
        goto LABEL_5;
      v30 = (__int64)v29;
      if ( (wlan_sap_is_owe_connection_present() & 1) != 0 )
      {
LABEL_14:
        wlan_objmgr_vdev_release_ref(v30, 7u, v31, v32, v33, v34, v35, v36, v37, v38, v39);
        result = 1;
        goto LABEL_10;
      }
      wlan_objmgr_vdev_release_ref(v30, 7u, v31, v32, v33, v34, v35, v36, v37, v38, v39);
      if ( mode_specific_conn_info != 1 )
      {
        v40 = wlan_objmgr_get_vdev_by_id_from_pdev(a1, SBYTE1(v44), 7u);
        if ( !v40 )
          goto LABEL_5;
        v30 = (__int64)v40;
        if ( (wlan_sap_is_owe_connection_present() & 1) != 0 )
          goto LABEL_14;
        wlan_objmgr_vdev_release_ref(v30, 7u, v31, v32, v33, v34, v35, v36, v37, v38, v39);
        if ( mode_specific_conn_info != 2 )
        {
          v41 = wlan_objmgr_get_vdev_by_id_from_pdev(a1, SBYTE2(v44), 7u);
          if ( !v41 )
            goto LABEL_5;
          v30 = (__int64)v41;
          if ( (wlan_sap_is_owe_connection_present() & 1) != 0 )
            goto LABEL_14;
          wlan_objmgr_vdev_release_ref(v30, 7u, v31, v32, v33, v34, v35, v36, v37, v38, v39);
          if ( mode_specific_conn_info != 3 )
          {
            v42 = wlan_objmgr_get_vdev_by_id_from_pdev(a1, SHIBYTE(v44), 7u);
            if ( !v42 )
              goto LABEL_5;
            v30 = (__int64)v42;
            if ( (wlan_sap_is_owe_connection_present() & 1) != 0 )
              goto LABEL_14;
            wlan_objmgr_vdev_release_ref(v30, 7u, v31, v32, v33, v34, v35, v36, v37, v38, v39);
            if ( mode_specific_conn_info != 4 )
            {
              v43 = wlan_objmgr_get_vdev_by_id_from_pdev(a1, v45, 7u);
              if ( !v43 )
                goto LABEL_5;
              v30 = (__int64)v43;
              if ( (wlan_sap_is_owe_connection_present() & 1) != 0 )
                goto LABEL_14;
              wlan_objmgr_vdev_release_ref(v30, 7u, v31, v32, v33, v34, v35, v36, v37, v38, v39);
              if ( mode_specific_conn_info != 5 )
                __break(0x5512u);
            }
          }
        }
      }
    }
LABEL_9:
    result = 0;
    goto LABEL_10;
  }
LABEL_5:
  result = 1;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
