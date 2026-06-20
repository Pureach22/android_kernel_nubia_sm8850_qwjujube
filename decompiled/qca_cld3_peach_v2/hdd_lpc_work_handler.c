__int64 __fastcall hdd_lpc_work_handler(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x19
  __int64 v11; // x0
  __int16 v12; // w8
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
  __int64 v29; // x0
  __int64 v30; // [xsp+8h] [xbp-18h] BYREF
  int v31; // [xsp+10h] [xbp-10h] BYREF
  __int16 v32; // [xsp+14h] [xbp-Ch]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v9 = *(_QWORD *)(result + 8304);
    v10 = result;
    v30 = 0;
    if ( v9 )
    {
      v11 = *(_QWORD *)(v9 + 32);
      v12 = *(_WORD *)(v9 + 1621);
      v31 = *(_DWORD *)(v9 + 1617);
      v32 = v12;
      result = _osif_vdev_sync_trans_start_wait(v11, &v30, "hdd_lpc_work_handler");
      if ( !(_DWORD)result )
      {
        osif_vdev_sync_unregister(*(_QWORD *)(v9 + 32));
        v13 = osif_vdev_sync_wait_for_ops(v30);
        hdd_close_adapter((__int64 *)v10, v9, 0, v13, v14, v15, v16, v17, v18, v19, v20);
        wlan_hdd_release_intf_addr(v10, (unsigned __int8 *)&v31, v21, v22, v23, v24, v25, v26, v27, v28);
        v29 = v30;
        *(_BYTE *)(v10 + 8296) = 0;
        osif_vdev_sync_trans_stop(v29);
        result = osif_vdev_sync_destroy(v30);
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: There is no monitor adapter",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "hdd_lpc_work_handler");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
