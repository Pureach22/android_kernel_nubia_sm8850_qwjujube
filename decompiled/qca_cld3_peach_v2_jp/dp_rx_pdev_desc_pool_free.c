__int64 __fastcall dp_rx_pdev_desc_pool_free(__int64 a1)
{
  if ( *(unsigned __int8 *)(a1 + 1) >= 5uLL )
  {
    __break(0x5512u);
    JUMPOUT(0x4D7124);
  }
  return dp_rx_desc_pool_free(*(_QWORD *)(a1 + 8), *(_QWORD *)(a1 + 8) + 120LL * *(unsigned __int8 *)(a1 + 1) + 12368);
}
