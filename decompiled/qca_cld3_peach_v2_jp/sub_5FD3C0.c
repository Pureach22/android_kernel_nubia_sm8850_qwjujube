__int64 __fastcall sub_5FD3C0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 v6; // x23

  return wifi_pos_set_peer_ltf_keyseed_required(a1, a2, a3, a4, a5, a6, (v6 >> 14) & 0xFFFFFFFFFLL);
}
