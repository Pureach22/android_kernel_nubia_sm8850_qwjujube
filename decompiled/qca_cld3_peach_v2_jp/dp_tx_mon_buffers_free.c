__int64 __fastcall dp_tx_mon_buffers_free(__int64 a1)
{
  return dp_mon_pool_frag_unmap_and_free(a1, *(_QWORD *)(a1 + 20056) + 696LL);
}
