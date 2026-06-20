__int64 __fastcall gen7_hwsched_hfi_probe(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0

  v2 = to_gen7_gmu(a1);
  result = kgsl_request_irq(*(_QWORD *)(a1 + 1544), "hfi", gen7_hwsched_hfi_handler, a1);
  *(_DWORD *)(v2 + 40) = result;
  if ( (result & 0x80000000) == 0 )
  {
    *(_QWORD *)(a1 + 24552) = 32774;
    *(_DWORD *)(a1 + 24560) = 0;
    *(_QWORD *)(a1 + 24568) = a1 + 24568;
    *(_QWORD *)(a1 + 24576) = a1 + 24568;
    *(_QWORD *)(a1 + 24760) = a1 + 24760;
    *(_QWORD *)(a1 + 24768) = a1 + 24760;
    _init_waitqueue_head(a1 + 24592, "&hw_hfi->f2h_wq", &gen7_hwsched_hfi_probe___key);
    _mutex_init(a1 + 24640, "&hw_hfi->msgq_mutex", &gen7_hwsched_hfi_probe___key_4);
    *(_QWORD *)(a1 + 24728) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 24736) = a1 + 24736;
    *(_QWORD *)(a1 + 24744) = a1 + 24736;
    *(_QWORD *)(a1 + 24752) = gen7_hwsched_hw_fence_timeout;
    init_timer_key(a1 + 24688, gen7_hwsched_hw_fence_timer, 0, 0, 0);
    return 0;
  }
  return result;
}
