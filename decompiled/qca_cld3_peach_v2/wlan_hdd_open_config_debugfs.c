__int64 __fastcall wlan_hdd_open_config_debugfs(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 result; // x0
  __int64 *v14; // x21
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *v24; // x20
  unsigned int v25; // w0
  unsigned int v26; // w0
  unsigned int v27; // w21
  __int64 v28; // [xsp+0h] [xbp-10h] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a10 + 40);
  v28 = 0;
  v12 = *(_QWORD *)(v11 + 696);
  result = _wlan_hdd_validate_context(v12, (__int64)"wlan_hdd_open_config_debugfs", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !(_DWORD)result )
  {
    result = _osif_psoc_sync_op_start(
               *(_QWORD *)(*(_QWORD *)(v12 + 24) + 488LL),
               &v28,
               (__int64)"wlan_hdd_open_config_debugfs");
    if ( !(_DWORD)result )
    {
      v14 = *(__int64 **)(*(_QWORD *)(a10 + 40) + 696LL);
      v15 = _qdf_mem_malloc(0x8008u, "__wlan_hdd_open_config_debugfs", 159);
      if ( v15 )
      {
        v24 = (_QWORD *)v15;
        qdf_trace_msg(
          0x33u,
          8u,
          "WLAN configuration written to debug log",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v28,
          v29);
        ucfg_cfg_store_print(*v14);
        v25 = ucfg_cfg_ini_config_print(*v14, (__int64)(v24 + 1), v24, 0x8000);
        v26 = qdf_status_to_os_return(v25);
        if ( v26 )
        {
          v27 = v26;
          _qdf_mem_free((__int64)v24);
        }
        else
        {
          v27 = 0;
          *(_QWORD *)(a10 + 32) = v24;
        }
      }
      else
      {
        v27 = -12;
      }
      _osif_psoc_sync_op_stop(v28, (__int64)"wlan_hdd_open_config_debugfs");
      result = v27;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
