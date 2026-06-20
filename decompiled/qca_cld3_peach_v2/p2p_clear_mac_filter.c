__int64 __fastcall p2p_clear_mac_filter(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return p2p_set_mac_filter(a1, a2, a3, a4, 0, 0, 0);
}
