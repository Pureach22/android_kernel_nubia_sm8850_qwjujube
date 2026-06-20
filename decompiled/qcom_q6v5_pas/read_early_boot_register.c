__int64 __fastcall read_early_boot_register(__int64 result)
{
  _QWORD *v1; // x20
  __int64 v2; // x19
  int irqchip_state; // w0
  unsigned int v4; // w8
  __int64 v5; // x8
  int v6; // w20

  v1 = (_QWORD *)(result - 584);
  if ( result != 584 )
  {
    v2 = result;
    irq_get_irqchip_state(*(unsigned int *)(result - 492), 3, result + 746);
    if ( *(_BYTE *)(v2 + 746) == 1 )
    {
      dev_err(*v1, "Sub system has crashed before driver probe\n");
      *(_DWORD *)(*(_QWORD *)(v2 - 568) + 972LL) = 3;
    }
    irqchip_state = irq_get_irqchip_state(*(unsigned int *)(v2 - 488), 3, v2 + 745);
    if ( *(_BYTE *)(v2 + 745) == 1 )
    {
      v5 = *v1;
      v6 = irqchip_state;
      dev_info(v5, "Sub system has boot-up before driver probe\n");
      irqchip_state = v6;
      *(_DWORD *)(*(_QWORD *)(v2 - 568) + 972LL) = 6;
    }
    v4 = *(_DWORD *)(v2 + 40);
    *(_DWORD *)(v2 + 40) = v4 + 1;
    if ( v4 <= 4 && irqchip_state == -19 )
      return mod_timer(v2, jiffies + 250LL);
    else
      return complete(v2 - 352);
  }
  return result;
}
