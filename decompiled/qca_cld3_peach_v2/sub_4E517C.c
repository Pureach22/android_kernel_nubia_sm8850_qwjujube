__int64 sub_4E517C()
{
  __int64 v0; // x18

  if ( (v0 & 0x2000000000000000LL) != 0 )
    JUMPOUT(0x4E0D18);
  return wma_objmgr_set_peer_mlme_nss();
}
