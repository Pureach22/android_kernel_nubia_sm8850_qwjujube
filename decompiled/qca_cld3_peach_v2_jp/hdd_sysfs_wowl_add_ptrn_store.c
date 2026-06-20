__int64 __fastcall hdd_sysfs_wowl_add_ptrn_store(__int64 a1, __int64 a2, __int64 a3, size_t a4)
{
  int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  bool v36; // w0
  __int64 v37; // x0
  unsigned __int8 *v38; // x22
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x20
  __int64 *v56[2]; // [xsp+0h] [xbp-10h] BYREF

  v56[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v56[0] = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, v56, (__int64)"hdd_sysfs_wowl_add_ptrn_store");
  if ( v7 )
  {
    v16 = v7;
  }
  else
  {
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_wowl_add_ptrn_store",
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14,
                         v15) )
    {
      v16 = -22;
    }
    else
    {
      v25 = *(_QWORD *)(a1 + 1336);
      v26 = _wlan_hdd_validate_context(
              v25,
              (__int64)"__hdd_sysfs_wowl_add_ptrn_store",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24);
      if ( v26 )
      {
        v16 = v26;
      }
      else
      {
        v36 = wlan_hdd_validate_modules_state(v25, v27, v28, v29, v30, v31, v32, v33, v34);
        v16 = -22;
        if ( a4 <= 0x200 && v36 )
        {
          v37 = _qdf_mem_malloc(a4, "__hdd_sysfs_wowl_add_ptrn_store", 56);
          if ( v37 )
          {
            v38 = (unsigned __int8 *)v37;
            sized_strscpy(v37, a3, a4);
            v38[a4 - 1] = 0;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: wowl_add_ptrn: count %zu buf_local:(%s)",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "__hdd_sysfs_wowl_add_ptrn_store",
              a4,
              v38);
            if ( (hdd_add_wowl_ptrn(a1 + 1312, v38) & 1) != 0 )
            {
              _qdf_mem_free((__int64)v38);
              v16 = a4;
            }
            else
            {
              v55 = jiffies;
              if ( _hdd_sysfs_wowl_add_ptrn_store___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to add wowl ptrn",
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  "__hdd_sysfs_wowl_add_ptrn_store");
                _hdd_sysfs_wowl_add_ptrn_store___last_ticks = v55;
              }
              _qdf_mem_free((__int64)v38);
              v16 = -22;
            }
          }
        }
      }
    }
    _osif_vdev_sync_op_stop((__int64)v56[0], (__int64)"hdd_sysfs_wowl_add_ptrn_store");
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
