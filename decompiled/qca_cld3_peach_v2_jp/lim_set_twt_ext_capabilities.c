__int64 __fastcall lim_set_twt_ext_capabilities(__int64 a1, __int64 a2, __int64 a3)
{
  return wlan_set_peer_twt_capabilities(*(_QWORD *)(a1 + 21552), a2, (*(unsigned __int16 *)(a3 + 8) >> 13) & 3);
}
