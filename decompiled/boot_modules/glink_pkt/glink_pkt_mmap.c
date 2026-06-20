__int64 __fastcall glink_pkt_mmap(__int64 a1, __int64 a2)
{
  __int64 v3; // x8

  if ( (*(_BYTE *)(a2 + 32) & 6) != 0 )
    return 0xFFFFFFFFLL;
  v3 = *(_QWORD *)(a2 + 16);
  if ( (*(_QWORD *)(v3 + 136) & 1) == 0 )
  {
    __break(0x800u);
    v3 = *(_QWORD *)(a2 + 16);
  }
  if ( *(_DWORD *)(a2 + 40) != *(_DWORD *)(v3 + 224) )
  {
    _vma_start_write(a2);
    v3 = *(_QWORD *)(a2 + 16);
  }
  *(_QWORD *)(a2 + 32) &= 0xFFFFFFFFFFFFFF9FLL;
  if ( (*(_QWORD *)(v3 + 136) & 1) == 0 )
  {
    __break(0x800u);
    v3 = *(_QWORD *)(a2 + 16);
  }
  if ( *(_DWORD *)(a2 + 40) != *(_DWORD *)(v3 + 224) )
    _vma_start_write(a2);
  *(_QWORD *)(a2 + 32) |= 0x10000000uLL;
  *(_QWORD *)(a2 + 72) = &glink_pkt_vm_ops;
  return 0;
}
