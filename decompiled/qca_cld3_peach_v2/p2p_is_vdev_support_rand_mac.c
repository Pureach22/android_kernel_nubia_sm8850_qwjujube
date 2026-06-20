bool __fastcall p2p_is_vdev_support_rand_mac(__int64 a1)
{
  int v1; // w8

  v1 = *(_DWORD *)(a1 + 16);
  return (v1 & 0xFFFFFFFD) == 0 || v1 == 7 || v1 == 16;
}
