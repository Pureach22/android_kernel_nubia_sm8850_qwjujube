__int64 __fastcall sde_hw_intr_get_intr_status_nolock(__int64 a1, unsigned int a2, char a3)
{
  unsigned int v5; // w21
  unsigned int v6; // w22

  if ( !a1 )
    return 0;
  if ( (a2 & 0x80000000) != 0 || *(_DWORD *)(a1 + 328) <= a2 )
  {
    printk(&unk_25F8CA, a2);
    return 0;
  }
  v5 = *(_DWORD *)(*(_QWORD *)(a1 + 336) + 16LL * a2 + 12);
  if ( (v5 & 0x80000000) != 0 || v5 > *(_DWORD *)(a1 + 312) )
  {
    printk(&unk_23281D, v5);
    return 0;
  }
  v6 = *(_DWORD *)(*(_QWORD *)(a1 + 336) + 16LL * a2 + 8)
     & sde_reg_read(a1, *(_DWORD *)(*(_QWORD *)(a1 + 320) + 20LL * v5 + 8));
  if ( v6 && (a3 & 1) != 0 )
    sde_reg_write(a1, *(_DWORD *)(*(_QWORD *)(a1 + 320) + 20LL * v5), v6, "intr->sde_irq_tbl[reg_idx].clr_off");
  __dsb(0xEu);
  return v6;
}
