__int64 __fastcall sc_heap_free(__int64 a1)
{
  __int64 v2; // x20
  unsigned __int64 v3; // x26
  unsigned __int64 v4; // x25
  __int64 drvdata; // x21
  size_t v6; // x22
  __int64 v7; // x2
  void *v8; // x0
  void *v9; // x23
  __int64 v10; // x22
  __int64 v11; // x0

  v2 = a1 + 80;
  v3 = memstart_addr;
  v4 = **(_QWORD **)(a1 + 80) & 0xFFFFFFFFFFFFFFFCLL;
  drvdata = dma_heap_get_drvdata(*(_QWORD *)a1);
  if ( qcom_is_buffer_hlos_accessible(*(_DWORD *)drvdata) )
  {
    v6 = *(_QWORD *)(a1 + 72);
    v7 = arm64_use_ng_mappings ? 0x68000000000F0BLL : 0x6800000000070BLL;
    v8 = (void *)ioremap_prot(
                   (v4 + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6,
                   *(_QWORD *)(a1 + 72),
                   v7);
    if ( v8 )
    {
      v9 = v8;
      memset(v8, 0, v6);
      iounmap(v9);
    }
  }
  v10 = *(_QWORD *)(a1 + 72);
  down_read(drvdata + 16);
  v11 = *(_QWORD *)(drvdata + 80);
  if ( v11 )
    gen_pool_free_owner(v11, (v4 + ((v3 >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6, v10, 0);
  up_read(drvdata + 16);
  sg_free_table(v2);
  return kfree(a1);
}
