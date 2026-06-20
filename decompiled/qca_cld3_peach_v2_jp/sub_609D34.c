// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_609D34(unsigned int a1)
{
  int v2; // w30
  __int64 v4; // [xsp-390h] [xbp-390h]

  if ( v2 )
    return tgt_spectral_deregister_buffer_cb();
  _osif_psoc_sync_op_stop(v4, (__int64)"wlan_hdd_cfg80211_avoid_freq_ext");
  _ReadStatusReg(SP_EL0);
  return a1;
}
