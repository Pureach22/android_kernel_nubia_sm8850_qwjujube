__int64 __fastcall dsi_clk_update_parent(__int64 a1, _QWORD *a2)
{
  unsigned int v3; // w0
  unsigned int v4; // w19
  __int64 result; // x0

  v3 = clk_set_parent(*a2);
  if ( v3 )
  {
    v4 = v3;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set byte clk parent\n");
  }
  else
  {
    result = clk_set_parent(a2[1]);
    if ( !(_DWORD)result )
      return result;
    v4 = result;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set pixel clk parent\n");
  }
  return v4;
}
