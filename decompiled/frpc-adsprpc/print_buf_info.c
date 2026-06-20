__int64 __fastcall print_buf_info(__int64 a1, __int64 a2)
{
  seq_printf(a1, "\n %s %2s 0x%p", "virt", ":", *(const void **)(a2 + 48));
  seq_printf(a1, "\n %s %2s 0x%llx", "phys", ":", *(_QWORD *)(a2 + 64));
  seq_printf(a1, "\n %s %2s 0x%lx", "raddr", ":", *(_QWORD *)(a2 + 144));
  seq_printf(a1, "\n %s %2s 0x%x", "type", ":", *(_DWORD *)(a2 + 56));
  seq_printf(a1, "\n %s %2s 0x%llx", "size", ":", *(_QWORD *)(a2 + 72));
  return seq_printf(a1, "\n %s %s %d", "in_use", ":", *(unsigned __int8 *)(a2 + 152));
}
