__int64 __fastcall dp_tx_mon_soc_deinit_2_0(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x4
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v1 = *(_QWORD *)(a1 + 20112);
  dp_mon_pool_frag_unmap_and_free(a1, v1 + 696);
  dp_mon_desc_pool_deinit(*(_QWORD *)(a1 + 20112) + 696LL);
  return dp_srng_deinit(a1, (__int64 *)(v1 + 456), 0x18u, 0, v3, v4, v5, v6, v7, v8, v9, v10, v11);
}
