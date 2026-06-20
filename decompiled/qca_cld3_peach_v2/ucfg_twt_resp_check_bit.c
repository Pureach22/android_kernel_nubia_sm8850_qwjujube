__int64 __fastcall ucfg_twt_resp_check_bit(__int64 a1, unsigned __int8 a2, int a3, unsigned __int8 a4)
{
  return wlan_twt_check_responder_bit(a1, a2, a3, a4) & 1;
}
