__int64 __fastcall print_map_info(__int64 a1, __int64 a2)
{
  seq_printf(a1, "%s %4s %d\n", "fd", ":", *(_DWORD *)(a2 + 24));
  seq_printf(a1, "%s %s 0x%llx\n", "phys", ":", *(_QWORD *)(a2 + 64));
  seq_printf(a1, "%s %s 0x%llx\n", "size", ":", *(_QWORD *)(a2 + 72));
  seq_printf(a1, "%s %4s 0x%p\n", "va", ":", *(const void **)(a2 + 80));
  seq_printf(a1, "%s %3s 0x%llx\n", "len", ":", *(_QWORD *)(a2 + 88));
  seq_printf(a1, "%s %2s 0x%llx\n", "raddr", ":", *(_QWORD *)(a2 + 96));
  seq_printf(a1, "%s %2s 0x%x\n", "attr", ":", *(_DWORD *)(a2 + 104));
  return seq_printf(a1, "%s %2s 0x%x\n", "flags", ":", *(_DWORD *)(a2 + 108));
}
