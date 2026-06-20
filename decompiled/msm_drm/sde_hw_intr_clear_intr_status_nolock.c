__int64 __fastcall sde_hw_intr_clear_intr_status_nolock(__int64 result, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x1

  if ( result )
  {
    if ( (a2 & 0x80000000) != 0 || *(_DWORD *)(result + 328) <= a2 )
    {
      return printk(&unk_25F8CA, a2);
    }
    else
    {
      v2 = *(_QWORD *)(result + 336) + 16LL * a2;
      v3 = *(unsigned int *)(v2 + 12);
      if ( (v3 & 0x80000000) != 0 || (unsigned int)v3 > *(_DWORD *)(result + 312) )
      {
        return printk(&unk_23281D, v3);
      }
      else
      {
        result = sde_reg_write(
                   result,
                   *(_DWORD *)(*(_QWORD *)(result + 320) + 20LL * (unsigned int)v3),
                   *(_DWORD *)(v2 + 8),
                   "intr->sde_irq_tbl[reg_idx].clr_off");
        __dsb(0xEu);
      }
    }
  }
  return result;
}
