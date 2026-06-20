__int64 __fastcall dsi_clk_set_pixel_clk_rate(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x15
  __int64 v4; // x8
  __int64 result; // x0
  int v6; // w20
  __int64 v7; // x19
  unsigned int v8; // w19

  v4 = *(_QWORD *)(a1 + 80);
  if ( *(_DWORD *)(v4 + 384) == 1 || (*(_BYTE *)(v4 + 441) & 1) != 0 )
    return 0;
  if ( a3 >= 2 )
  {
    __break(0x5512u);
    if ( (v3 & 0x2000000000000000LL) == 0 )
      JUMPOUT(0x1FB644);
    JUMPOUT(0x20079C);
  }
  v6 = a2;
  v7 = v4 + 48LL * a3;
  result = clk_set_rate(*(_QWORD *)(v7 + 224), a2);
  if ( (_DWORD)result )
  {
    v8 = result;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set clk rate for pixel clk, rc=%d\n", result);
    return v8;
  }
  else
  {
    *(_DWORD *)(v7 + 256) = v6;
  }
  return result;
}
