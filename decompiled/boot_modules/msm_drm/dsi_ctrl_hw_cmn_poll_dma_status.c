__int64 __fastcall dsi_ctrl_hw_cmn_poll_dma_status(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  int v4; // w4

  result = readl_13(*(_QWORD *)a1 + 272LL);
  if ( (result & 1) != 0 )
  {
LABEL_5:
    if ( (result & 1) != 0 )
      return result;
    goto LABEL_8;
  }
  v3 = 5010001;
  while ( 1 )
  {
    v3 -= 10001;
    if ( v3 < 0 )
      break;
    _const_udelay(42950);
    __yield();
    result = readl_13(*(_QWORD *)a1 + 272LL);
    if ( (result & 1) != 0 )
      goto LABEL_5;
  }
  result = readl_13(*(_QWORD *)a1 + 272LL);
  if ( (result & 1) == 0 )
  {
LABEL_8:
    if ( a1 )
      v4 = *(_DWORD *)(a1 + 56);
    else
      v4 = -1;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: CMD_MODE_DMA_DONE failed\n", v4);
    return 0;
  }
  return result;
}
