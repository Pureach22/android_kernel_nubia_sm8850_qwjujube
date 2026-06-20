__int64 __fastcall sde_hw_intr_clear_irqs(__int64 a1)
{
  unsigned int v2; // w21

  if ( !a1 )
    return 4294967274LL;
  if ( *(_DWORD *)(a1 + 312) )
  {
    v2 = 0;
    do
      sde_reg_write(
        a1,
        *(_DWORD *)(*(_QWORD *)(a1 + 320) + 20LL * (int)v2++),
        0xFFFFFFFF,
        "intr->sde_irq_tbl[i].clr_off");
    while ( v2 < *(_DWORD *)(a1 + 312) );
  }
  __dsb(0xEu);
  return 0;
}
