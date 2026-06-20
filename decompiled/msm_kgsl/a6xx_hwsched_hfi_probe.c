__int64 __fastcall a6xx_hwsched_hfi_probe(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0

  v2 = to_a6xx_gmu(a1);
  result = kgsl_request_irq(*(_QWORD *)(a1 + 1544), "kgsl_hfi_irq", a6xx_hwsched_hfi_handler, a1);
  *(_DWORD *)(v2 + 32) = result;
  if ( (result & 0x80000000) == 0 )
  {
    *(_QWORD *)(a1 + 24544) = 32774;
    *(_DWORD *)(a1 + 24552) = 0;
    *(_QWORD *)(a1 + 24560) = a1 + 24560;
    *(_QWORD *)(a1 + 24568) = a1 + 24560;
    _init_waitqueue_head(a1 + 24584, "&hw_hfi->f2h_wq", &a6xx_hwsched_hfi_probe___key);
    _mutex_init(a1 + 24632, "&hw_hfi->msgq_mutex", &a6xx_hwsched_hfi_probe___key_5);
    return 0;
  }
  return result;
}
