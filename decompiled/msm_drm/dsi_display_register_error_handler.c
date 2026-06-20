__int64 __fastcall dsi_display_register_error_handler(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  _QWORD *v4; // x9
  _QWORD *v5; // x9

  result = alloc_workqueue("%s", (_BYTE *)&loc_60008 + 2);
  *(_QWORD *)(a1 + 1376) = result;
  if ( !result )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to create dsi workq!\n");
  *(_QWORD *)(a1 + 1384) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 1392) = a1 + 1392;
  *(_QWORD *)(a1 + 1400) = a1 + 1392;
  *(_QWORD *)(a1 + 1408) = dsi_display_handle_fifo_underflow;
  *(_QWORD *)(a1 + 1416) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 1424) = a1 + 1424;
  *(_QWORD *)(a1 + 1432) = a1 + 1424;
  *(_QWORD *)(a1 + 1448) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 1440) = &dsi_display_handle_fifo_overflow;
  *(_QWORD *)(a1 + 1456) = a1 + 1456;
  *(_QWORD *)(a1 + 1464) = a1 + 1456;
  v3 = *(_DWORD *)(a1 + 160);
  *(_QWORD *)(a1 + 1472) = dsi_display_handle_lp_rx_timeout;
  if ( v3 )
  {
    v4 = *(_QWORD **)(a1 + 168);
    v4[247] = 0;
    v4[248] = a1;
    v4[249] = dsi_display_cb_error_handler;
    if ( *(_DWORD *)(a1 + 160) >= 2u )
    {
      v5 = *(_QWORD **)(a1 + 216);
      v5[247] = 0;
      v5[248] = a1;
      v5[249] = dsi_display_cb_error_handler;
    }
  }
  return result;
}
