__int64 __fastcall mlme_get_cfg_wlm_reset(__int64 a1, _BYTE *a2)
{
  __int64 ext_hdl; // x0
  __int64 v4; // x8

  ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( !ext_hdl )
    return 16;
  v4 = ext_hdl;
  *a2 = *(_BYTE *)(v4 + 5901);
  return 0;
}
