void __fastcall sub_4680E8(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20

  v3 = *(_QWORD *)(v2 + 80);
  *(_QWORD *)(v2 + 80) = &pld_sdio_get_virt_ramdump_mem__alloc_tag;
  _kmalloc_large_noprof(0x200000, a2);
  *(_QWORD *)(v2 + 80) = v3;
  JUMPOUT(0x4680CC);
}
