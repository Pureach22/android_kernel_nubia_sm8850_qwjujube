__int64 __fastcall dsi_ctrl_validate_timing(__int64 a1, __int64 a2)
{
  const char *v3; // x3

  if ( a1 && a2 )
    return 0;
  if ( a1 )
    v3 = *(const char **)(a1 + 16);
  else
    v3 = "inv";
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", v3);
  return 4294967274LL;
}
