__int64 __fastcall wlan_cfg_get_host2rxdma_mon_ring_mask(__int64 a1, unsigned int a2)
{
  __int64 v2; // x15
  int v3; // s27
  int v4; // s28

  if ( a2 >= 0x12 )
  {
    __break(0x5512u);
    *(_DWORD *)(v2 - 120) = v4;
    *(_DWORD *)(v2 - 116) = v3;
    JUMPOUT(0x5819F8);
  }
  return *(unsigned __int8 *)(a1 + a2 + 224);
}
