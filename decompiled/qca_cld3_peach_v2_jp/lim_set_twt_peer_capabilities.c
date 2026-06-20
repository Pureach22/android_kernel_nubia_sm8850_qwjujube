__int64 __fastcall lim_set_twt_peer_capabilities(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return wlan_set_peer_twt_capabilities(
           *(_QWORD *)(a1 + 21552),
           a2,
           (*(_DWORD *)(a3 + 1) >> 18) & 4
         | (*(_DWORD *)(a3 + 1) >> 1) & 3
         | (*(_DWORD *)(a3 + 1) >> 27) & 8
         | (16 * ((*(unsigned __int8 *)(a4 + 1) >> 3) & 1u)));
}
