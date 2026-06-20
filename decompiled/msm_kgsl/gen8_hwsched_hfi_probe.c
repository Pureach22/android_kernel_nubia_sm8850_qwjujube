__int64 __fastcall gen8_hwsched_hfi_probe(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0

  v2 = to_gen8_gmu(a1);
  result = kgsl_request_irq(*(_QWORD *)(a1 + 1544), "hfi", gen8_hwsched_hfi_handler, a1);
  *(_DWORD *)(v2 + 40) = result;
  if ( (result & 0x80000000) == 0 )
  {
    *(_QWORD *)(a1 + 24616) = 32774;
    *(_DWORD *)(a1 + 24624) = 0;
    *(_QWORD *)(a1 + 24632) = a1 + 24632;
    *(_QWORD *)(a1 + 24640) = a1 + 24632;
    *(_QWORD *)(a1 + 24816) = a1 + 24816;
    *(_QWORD *)(a1 + 24824) = a1 + 24816;
    _init_waitqueue_head(a1 + 24656, "&hw_hfi->f2h_wq", &gen8_hwsched_hfi_probe___key);
    _init_waitqueue_head(a1 + 23160, "&hwf->unack_wq", &gen8_hwsched_hfi_probe___key_10);
    *(_DWORD *)(a1 + 23152) = 0;
    _mutex_init(a1 + 24696, "&hw_hfi->msgq_mutex", &gen8_hwsched_hfi_probe___key_12);
    *(_QWORD *)(a1 + 24784) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 24792) = a1 + 24792;
    *(_QWORD *)(a1 + 24800) = a1 + 24792;
    *(_QWORD *)(a1 + 24808) = gen8_hwsched_hw_fence_timeout;
    init_timer_key(a1 + 24744, gen8_hwsched_hw_fence_timer, 0, 0, 0);
    return 0;
  }
  return result;
}
