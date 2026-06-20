__int64 __fastcall print_ictx_info(__int64 a1, __int64 a2)
{
  seq_printf(a1, "\n %s %7s %d", "nscalars", ":", *(_DWORD *)(a2 + 16));
  seq_printf(a1, "\n %s %10s %d", "nbufs", ":", *(_DWORD *)(a2 + 20));
  seq_printf(a1, "\n %s %10s %d", "retval", ":", *(_DWORD *)(a2 + 24));
  seq_printf(a1, "\n %s %12s %px", "crc", ":", *(const void **)(a2 + 48));
  seq_printf(a1, "\n %s %1s %d", "early_wake_time", ":", *(_DWORD *)(a2 + 56));
  seq_printf(a1, "\n %s %5s %px", "perf_kernel", ":", *(const void **)(a2 + 64));
  seq_printf(a1, "\n %s %7s %px", "perf_dsp", ":", *(const void **)(a2 + 72));
  seq_printf(a1, "\n %s %12s %d", "pid", ":", *(_DWORD *)(a2 + 28));
  seq_printf(a1, "\n %s %11s %d", "tgid", ":", *(_DWORD *)(a2 + 32));
  seq_printf(a1, "\n %s %13s 0x%x", "sc", ":", *(_DWORD *)(a2 + 36));
  seq_printf(a1, "\n %s %10s %llu", "ctxid", ":", *(_QWORD *)(a2 + 80));
  seq_printf(a1, "\n %s %3s %d", "is_work_done", ":", *(unsigned __int8 *)(a2 + 96));
  return seq_printf(a1, "\n %s %9s %llu", "msg_sz", ":", *(_QWORD *)(a2 + 88));
}
