__int64 sub_6B3E5C()
{
  __asm { LDTR            D27, [X19,#1] }
  return mlo_mlme_bridge_peer_create();
}
