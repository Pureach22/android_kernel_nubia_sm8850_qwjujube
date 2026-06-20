__int64 __fastcall hdd_debugfs_mws_tdm_state_read(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  int *first_valid_adapter; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  int *v16; // x22
  __int64 v17; // x0
  __int64 v18; // x20
  __int64 v19; // x0
  unsigned int mws_coex_info; // w0
  unsigned int v21; // w19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  __int64 v40[2]; // [xsp+0h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 24);
  v40[0] = 0;
  v5 = _osif_psoc_sync_op_start(*(_QWORD *)(v4 + 488), v40, (__int64)"hdd_debugfs_mws_tdm_state_read");
  if ( !(_DWORD)v5 )
  {
    first_valid_adapter = hdd_get_first_valid_adapter(a2);
    if ( first_valid_adapter )
    {
      if ( (*((_QWORD *)first_valid_adapter + 203) & 4) != 0 )
      {
        if ( *(__int64 *)(a1 + 40) > 0 )
          goto LABEL_16;
        v16 = first_valid_adapter;
        v17 = osif_request_alloc(_hdd_debugfs_mws_tdm_state_read_params);
        if ( v17 )
        {
          v18 = v17;
          v19 = osif_request_cookie(v17);
          mws_coex_info = sme_get_mws_coex_info(
                            *(_QWORD *)(a2 + 16),
                            *(unsigned __int8 *)(*((_QWORD *)v16 + 6603) + 8LL),
                            3,
                            (__int64)hdd_debugfs_mws_coex_info_cb,
                            v19);
          if ( mws_coex_info )
          {
            v21 = qdf_status_to_os_return(mws_coex_info);
          }
          else if ( (unsigned int)osif_request_wait_for_response(v18) )
          {
            qdf_debugfs_printf(
              a1,
              "Timedout while retrieving MWS coex tdm state",
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29);
            v21 = -110;
          }
          else
          {
            v30 = (unsigned int *)osif_request_priv(v18);
            qdf_debugfs_printf(
              a1,
              "vdev_id = %u\ntdm_policy_bitmap = %u\ntdm_sf_bitmap = %u\n",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              *v30,
              v30[1],
              v30[2]);
            v21 = 0;
          }
          osif_request_put(v18);
          qdf_status_from_os_return(v21);
          goto LABEL_16;
        }
        v15 = "%s: Request allocation failure";
      }
      else
      {
        v15 = "%s: Interface is not enabled";
      }
    }
    else
    {
      v15 = "%s: Failed to get adapter";
    }
    qdf_trace_msg(0x33u, 2u, v15, v7, v8, v9, v10, v11, v12, v13, v14, "__hdd_debugfs_mws_tdm_state_read");
LABEL_16:
    _osif_psoc_sync_op_stop(v40[0], (__int64)"hdd_debugfs_mws_tdm_state_read");
    v5 = 0;
  }
  result = qdf_status_from_os_return(v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
