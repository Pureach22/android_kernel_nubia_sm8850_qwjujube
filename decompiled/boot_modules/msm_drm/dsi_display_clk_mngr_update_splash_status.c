__int64 __fastcall dsi_display_clk_mngr_update_splash_status(__int64 result, char a2)
{
  if ( !result )
    return drm_dev_printk((unsigned __int8)result, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  if ( *(_DWORD *)(result + 384) != 1 )
    *(_BYTE *)(result + 440) = a2 & 1;
  return result;
}
