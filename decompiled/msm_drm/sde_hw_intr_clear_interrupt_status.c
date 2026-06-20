__int64 __fastcall sde_hw_intr_clear_interrupt_status(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 v6; // x1

  if ( result )
  {
    v2 = result;
    v4 = raw_spin_lock_irqsave(result + 344);
    if ( (a2 & 0x80000000) != 0 || *(_DWORD *)(v2 + 328) <= a2 )
    {
      printk(&unk_25F8CA, a2);
    }
    else
    {
      v5 = *(_QWORD *)(v2 + 336) + 16LL * a2;
      v6 = *(unsigned int *)(v5 + 12);
      if ( (v6 & 0x80000000) != 0 || (unsigned int)v6 > *(_DWORD *)(v2 + 312) )
      {
        printk(&unk_23281D, v6);
      }
      else
      {
        sde_reg_write(
          v2,
          *(_DWORD *)(*(_QWORD *)(v2 + 320) + 20LL * (unsigned int)v6),
          *(_DWORD *)(v5 + 8),
          "intr->sde_irq_tbl[reg_idx].clr_off");
        __dsb(0xEu);
      }
    }
    return raw_spin_unlock_irqrestore(v2 + 344, v4);
  }
  return result;
}
