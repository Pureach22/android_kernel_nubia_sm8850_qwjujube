__int64 fan_hrtimer_hander()
{
  __int64 v0; // x8
  int v1; // w9
  __int64 v3; // x8

  v0 = *(_QWORD *)(chip + 8);
  v1 = *(unsigned __int8 *)(v0 + 2);
  if ( v1 == 2 )
  {
    *(_BYTE *)(v0 + 2) = 3;
    v3 = chip;
    *(_DWORD *)(*(_QWORD *)(chip + 8) + 8LL) = *(_DWORD *)(*(_QWORD *)(chip + 8) + 4LL);
    disable_irq_nosync(*(unsigned int *)(*(_QWORD *)(v3 + 8) + 28LL));
    printk(&unk_7E2C, "NB_FAN", "fan_hrtimer_hander", 137);
  }
  else if ( v1 == 1 )
  {
    *(_DWORD *)(v0 + 4) = 0;
    *(_BYTE *)(*(_QWORD *)(chip + 8) + 2LL) = 2;
    hrtimer_start_range_ns(*(_QWORD *)(chip + 8) + 40LL, 500000000, 0, 1);
    enable_irq(*(unsigned int *)(*(_QWORD *)(chip + 8) + 28LL));
    printk(&unk_7A11, "NB_FAN", "fan_hrtimer_hander", 130);
    return 1;
  }
  return 0;
}
