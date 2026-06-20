__int64 __fastcall carveout_heap_free(__int64 a1)
{
  __int64 v2; // x20
  unsigned __int64 v3; // x25
  unsigned __int64 v4; // x24
  __int64 drvdata; // x0
  size_t v6; // x22
  __int64 v7; // x21
  __int64 v8; // x2
  void *v9; // x0
  void *v10; // x23
  __int64 v11; // x22
  __int64 v12; // x0

  v2 = a1 + 80;
  v3 = memstart_addr;
  v4 = **(_QWORD **)(a1 + 80) & 0xFFFFFFFFFFFFFFFCLL;
  drvdata = dma_heap_get_drvdata(*(_QWORD *)a1);
  v6 = *(_QWORD *)(a1 + 72);
  v7 = drvdata;
  if ( arm64_use_ng_mappings )
    v8 = 0x68000000000F0BLL;
  else
    v8 = 0x6800000000070BLL;
  v9 = (void *)ioremap_prot(
                 (v4 + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6,
                 *(_QWORD *)(a1 + 72),
                 v8);
  if ( v9 )
  {
    v10 = v9;
    memset(v9, 0, v6);
    iounmap(v10);
  }
  v11 = *(_QWORD *)(a1 + 72);
  down_read(v7 + 8);
  v12 = *(_QWORD *)(v7 + 72);
  if ( v12 )
    gen_pool_free_owner(v12, (v4 + ((v3 >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6, v11, 0);
  up_read(v7 + 8);
  sg_free_table(v2);
  return kfree(a1);
}
