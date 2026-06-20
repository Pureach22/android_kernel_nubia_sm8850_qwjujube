__int64 __fastcall dsi_ctrl_hw_dln0_phy_err(_DWORD *a1)
{
  __int64 result; // x0
  int v3; // w19
  int v4; // w3

  result = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 180LL));
  if ( (result & 0x11111) != 0 )
  {
    v3 = result;
    writel_relaxed_16(result, (unsigned int *)(*(_QWORD *)a1 + 180LL));
    if ( a1 )
      v4 = a1[14];
    else
      v4 = -1;
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: phy_err_status = %x\n", v4, v3);
  }
  return result;
}
