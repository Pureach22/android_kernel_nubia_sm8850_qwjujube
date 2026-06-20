__int64 __fastcall ucfg_twt_get_twt_ack_supported(__int64 a1, _BYTE *a2)
{
  return wlan_twt_tgt_caps_get_ack_supported(a1, a2);
}
