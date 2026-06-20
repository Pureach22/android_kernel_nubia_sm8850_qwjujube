__int64 __fastcall dp_rx_pdev_desc_pool_deinit(__int64 a1)
{
  unsigned __int64 v1; // x19
  __int64 v2; // x20

  v1 = *(unsigned __int8 *)(a1 + 1);
  if ( v1 >= 5 )
  {
    __break(0x5512u);
    JUMPOUT(0x4D730C);
  }
  v2 = *(_QWORD *)(a1 + 8);
  ((void (__fastcall *)(__int64, _QWORD))dp_rx_page_pool_free)(v2, *(unsigned __int8 *)(a1 + 1));
  return dp_rx_desc_pool_deinit(v2, v2 + 120LL * (unsigned int)v1 + 12368, (unsigned int)v1);
}
