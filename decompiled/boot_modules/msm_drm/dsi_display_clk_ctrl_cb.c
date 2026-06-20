__int64 __fastcall dsi_display_clk_ctrl_cb(__int64 a1, unsigned __int64 a2, int a3)
{
  __int64 v3; // x8
  unsigned __int64 v4; // x19
  int v6; // w20
  __int64 result; // x0
  const char *v8; // x3
  unsigned int v9; // w21

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      v3 = 1320;
      goto LABEL_7;
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid clk handle, return error\n");
    return 4294967274LL;
  }
  v3 = 1328;
LABEL_7:
  v4 = HIDWORD(a2);
  v6 = a2;
  result = dsi_display_clk_ctrl(*(_QWORD *)(a1 + v3), a2, HIDWORD(a2));
  if ( (_DWORD)result )
  {
    v8 = *(const char **)(a1 + 32);
    v9 = result;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to %d DSI %d clocks, rc=%d\n",
      v8,
      v4,
      v6,
      result);
    return v9;
  }
  return result;
}
