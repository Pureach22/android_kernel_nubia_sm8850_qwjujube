__int64 __fastcall hdd_send_dbam_config(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 v15; // x22
  __int64 v16; // x0
  __int64 vdev_by_user; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x23
  unsigned int v27; // w21
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w20
  const char *v37; // x2
  const char *v38; // x3
  unsigned int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  __int64 v49; // [xsp+0h] [xbp-10h] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _hdd_validate_adapter(a1, "hdd_send_dbam_config");
  if ( !(_DWORD)result )
  {
    v5 = osif_request_alloc(hdd_send_dbam_config_params);
    if ( v5 )
    {
      v14 = v5;
      v15 = osif_request_cookie(v5);
      v16 = *(_QWORD *)(a1 + 52832);
      LODWORD(v49) = *(unsigned __int8 *)(v16 + 8);
      HIDWORD(v49) = a2;
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(v16, 6, "hdd_send_dbam_config");
      if ( vdev_by_user )
      {
        v26 = vdev_by_user;
        v27 = ucfg_coex_send_dbam_config(vdev_by_user, &v49, hdd_dbam_config_resp_cb, v15);
        _hdd_objmgr_put_vdev_by_user(v26, 6, "hdd_send_dbam_config");
        if ( v27 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Unable to set dbam config to [%u]",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "hdd_send_dbam_config",
            a2,
            v49,
            v50);
          v36 = qdf_status_to_os_return(v27);
LABEL_13:
          osif_request_put(v14);
          result = v36;
          goto LABEL_14;
        }
        v39 = osif_request_wait_for_response(v14);
        if ( v39 )
        {
          v36 = v39;
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: DBAM config operation timed out",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "hdd_send_dbam_config",
            v49,
            v50);
          goto LABEL_13;
        }
        v48 = *(unsigned int *)osif_request_priv(v14);
        if ( (unsigned int)v48 < 3 )
        {
          v36 = dword_AF7474[v48];
          goto LABEL_13;
        }
        v37 = "%s: Invalid dbam config resp received from FW";
        v38 = "hdd_convert_dbam_comp_status";
      }
      else
      {
        v37 = "%s: vdev is NULL";
        v38 = "hdd_send_dbam_config";
      }
      qdf_trace_msg(0x33u, 2u, v37, v18, v19, v20, v21, v22, v23, v24, v25, v38, v49, v50);
      v36 = -22;
      goto LABEL_13;
    }
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Request allocation failure",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_send_dbam_config");
    result = 4294967284LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
