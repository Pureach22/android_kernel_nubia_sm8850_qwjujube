__int64 __fastcall dispatcher_psoc_open(__int64 a1)
{
  __int64 result; // x0
  int v3; // w0

  if ( (unsigned int)wlan_mgmt_txrx_psoc_open() )
    return 16;
  if ( (unsigned int)ucfg_scan_psoc_open(a1) )
  {
LABEL_13:
    wlan_mgmt_txrx_psoc_close(a1);
    return 16;
  }
  if ( (unsigned int)wlan_cp_stats_open(a1) )
  {
LABEL_12:
    ucfg_scan_psoc_close(a1);
    goto LABEL_13;
  }
  if ( (unsigned int)regulatory_psoc_open(a1) )
  {
LABEL_11:
    wlan_cp_stats_close(a1);
    goto LABEL_12;
  }
  if ( (unsigned int)dispatcher_ftm_psoc_open(a1) )
  {
LABEL_10:
    regulatory_psoc_close(a1);
    goto LABEL_11;
  }
  if ( (unsigned int)wlan_coex_psoc_open(a1) )
  {
LABEL_9:
    dispatcher_ftm_psoc_close(a1);
    goto LABEL_10;
  }
  if ( (unsigned int)wlan_dcs_psoc_open(a1)
    || (v3 = ((__int64 (__fastcall *)(__int64))wlan_spectral_psoc_open)(a1), v3 != 39) && v3 )
  {
LABEL_8:
    wlan_coex_psoc_close(a1);
    goto LABEL_9;
  }
  result = mlme_psoc_open(a1);
  if ( (_DWORD)result )
  {
    wlan_spectral_psoc_close(a1);
    goto LABEL_8;
  }
  return result;
}
