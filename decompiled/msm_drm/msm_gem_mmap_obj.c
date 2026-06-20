__int64 __fastcall msm_gem_mmap_obj(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v5; // w8
  __int64 v7; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 v15; // x9

  v2 = *(_QWORD *)(a2 + 16);
  if ( (*(_QWORD *)(v2 + 136) & 1) == 0 )
  {
    __break(0x800u);
    v2 = *(_QWORD *)(a2 + 16);
  }
  if ( *(_DWORD *)(a2 + 40) != *(_DWORD *)(v2 + 224) )
    _vma_start_write(a2);
  *(_QWORD *)(a2 + 32) = *(_QWORD *)(a2 + 32) & 0xFFFFFFFFEFFFFBFFLL | 0x10000000;
  v5 = *(_DWORD *)(a1 + 368);
  if ( (v5 & 0x20000) != 0 )
  {
    v8 = ((__int64 (*)(void))vm_get_page_prot)() & 0xFF9FFFFFFFFFFFE3LL | 0x60000000000008LL;
LABEL_13:
    *(_QWORD *)(a2 + 24) = v8;
    return 0;
  }
  if ( (v5 & 0x40000) != 0 )
  {
    v8 = ((__int64 (*)(void))vm_get_page_prot)() & 0xFF9FFFFFFFFFFFE3LL | 0x6000000000000CLL;
    goto LABEL_13;
  }
  fput(*(_QWORD *)(a2 + 88));
  _X8 = *(unsigned __int64 **)(a1 + 16);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 + 1, _X8) );
  if ( !v15 && (get_file___already_done & 1) == 0 )
  {
    get_file___already_done = 1;
    _warn_printk("struct file::f_count incremented from zero; use-after-free condition present!\n");
    __break(0x800u);
  }
  *(_QWORD *)(a2 + 80) = 0;
  v7 = *(_QWORD *)(a2 + 32);
  *(_QWORD *)(a2 + 88) = *(_QWORD *)(a1 + 16);
  *(_QWORD *)(a2 + 24) = vm_get_page_prot(v7);
  return 0;
}
