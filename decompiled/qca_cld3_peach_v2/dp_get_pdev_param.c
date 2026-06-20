__int64 __fastcall dp_get_pdev_param(
        __int64 a1,
        char a2,
        int a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x0
  unsigned int v13; // w8
  __int64 v14; // x8
  __int64 v15; // x8
  _BYTE *v16; // x19
  __int64 (*v17)(void); // x8
  const char *v18; // x2
  __int64 v19; // x8
  __int64 v20; // x8
  char v21; // w9
  __int64 v22; // x8
  __int64 v23; // x8
  char v24; // w0
  int rx_dma_buf_ring_size; // w0
  const char *v27; // x3

  if ( a2 )
    return 16;
  v12 = *(_QWORD *)(a1 + 72);
  if ( !v12 )
    return 16;
  v13 = 16;
  if ( a3 <= 21 )
  {
    if ( a3 != 16 )
    {
      if ( a3 == 19 )
      {
        v13 = 0;
        *a4 = *(_DWORD *)(v12 + 94396);
      }
      else if ( a3 == 21 )
      {
        v19 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20112LL);
        if ( v19 )
        {
          v20 = *(_QWORD *)(v19 + 416);
          v16 = a4;
          if ( v20 )
          {
            v17 = *(__int64 (**)(void))(v20 + 432);
            if ( v17 )
              goto LABEL_27;
          }
          v18 = "%s: callback not registered";
        }
        else
        {
          v16 = a4;
          v18 = "%s: monitor soc is NULL";
        }
        v27 = "dp_monitor_pdev_get_filter_ucast_data";
        goto LABEL_39;
      }
      return v13;
    }
    v21 = *(_BYTE *)(v12 + 95939);
LABEL_23:
    v13 = 0;
    *(_BYTE *)a4 = v21;
    return v13;
  }
  if ( a3 <= 30 )
  {
    if ( a3 == 22 )
    {
      v22 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20112LL);
      if ( v22 )
      {
        v23 = *(_QWORD *)(v22 + 416);
        v16 = a4;
        if ( v23 )
        {
          v17 = *(__int64 (**)(void))(v23 + 448);
          if ( v17 )
            goto LABEL_27;
        }
        v18 = "%s: callback not registered";
      }
      else
      {
        v16 = a4;
        v18 = "%s: monitor soc is NULL";
      }
      v27 = "dp_monitor_pdev_get_filter_mcast_data";
LABEL_39:
      qdf_trace_msg(0x92u, 8u, v18, a5, a6, a7, a8, a9, a10, a11, a12, v27);
      v24 = 0;
LABEL_40:
      v13 = 0;
      *v16 = v24 & 1;
      return v13;
    }
    if ( a3 == 23 )
    {
      v14 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20112LL);
      if ( !v14 )
      {
        v16 = a4;
        v18 = "%s: monitor soc is NULL";
        goto LABEL_36;
      }
      v15 = *(_QWORD *)(v14 + 416);
      v16 = a4;
      if ( !v15 || (v17 = *(__int64 (**)(void))(v15 + 440)) == nullptr )
      {
        v18 = "%s: callback not registered";
LABEL_36:
        v27 = "dp_monitor_pdev_get_filter_non_data";
        goto LABEL_39;
      }
LABEL_27:
      if ( *((_DWORD *)v17 - 1) != -1964129701 )
        __break(0x8228u);
      v24 = v17();
      goto LABEL_40;
    }
    return v13;
  }
  if ( a3 == 31 )
  {
    rx_dma_buf_ring_size = wlan_cfg_get_rx_dma_buf_ring_size(*(_QWORD *)(v12 + 288));
    v13 = 0;
    *a4 = rx_dma_buf_ring_size;
    return v13;
  }
  if ( a3 == 32 )
  {
    v21 = *(_BYTE *)(v12 + 95938);
    goto LABEL_23;
  }
  return v13;
}
