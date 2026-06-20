__int64 __fastcall show_channel_number(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x23
  __int64 v31; // x8
  unsigned __int8 v33; // w0
  int v34; // w0
  __int64 *v35[2]; // [xsp+0h] [xbp-10h] BYREF

  v35[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v35[0] = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, v35, (__int64)"show_channel_number");
  if ( !v5 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v6, v7, v8, v9, v10, v11, v12, v13, "__show_channel_number", a1 - 1080);
    v5 = _hdd_validate_adapter(a1 + 1312, (__int64)"__show_channel_number", v14, v15, v16, v17, v18, v19, v20, v21);
    if ( !v5 )
    {
      if ( *(_DWORD *)(a1 + 1352) != 1 )
      {
LABEL_6:
        v5 = 0;
        goto LABEL_7;
      }
      v30 = *(_QWORD *)(a1 + 1336);
      v5 = _wlan_hdd_validate_context(v30, (__int64)"__show_channel_number", v22, v23, v24, v25, v26, v27, v28, v29);
      if ( !v5 )
      {
        v31 = *(_QWORD *)(a1 + 54144);
        if ( (*(_QWORD *)(v31 + 5968) & 2) != 0 )
        {
          v33 = wlan_reg_freq_to_chan(
                  *(_QWORD *)(v30 + 8),
                  *(_DWORD *)(v31 + 2424),
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29);
          v22 = scnprintf(a3, 4096, "%s    getchannel:%d\n", (const char *)(a1 - 1080), v33);
          v5 = v34;
          goto LABEL_7;
        }
        goto LABEL_6;
      }
    }
LABEL_7:
    qdf_trace_msg(0x33u, 8u, "%s: exit", v22, v23, v24, v25, v26, v27, v28, v29, "__show_channel_number");
    _osif_vdev_sync_op_stop((__int64)v35[0], (__int64)"show_channel_number");
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
