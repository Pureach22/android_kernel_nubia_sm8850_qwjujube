__int64 __fastcall msm_msi_irq_set_affinity(__int64 a1)
{
  __int64 irq_data; // x0
  __int64 (*v2)(void); // x8

  irq_data = irq_get_irq_data(*(unsigned int *)(a1 + 8));
  if ( !irq_data )
    return 4294967277LL;
  v2 = *(__int64 (**)(void))(*(_QWORD *)(irq_data + 24) + 80LL);
  if ( !v2 )
    return 4294967274LL;
  if ( *((_DWORD *)v2 - 1) != 466884035 )
    __break(0x8228u);
  return v2();
}
