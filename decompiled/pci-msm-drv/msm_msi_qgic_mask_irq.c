__int64 __fastcall msm_msi_qgic_mask_irq(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x8
  __int64 (*v3)(void); // x8

  result = irq_get_irq_data(*(unsigned int *)(a1 + 8));
  if ( result )
  {
    v2 = *(_QWORD *)(result + 24);
    if ( v2 )
    {
      v3 = *(__int64 (**)(void))(v2 + 48);
      if ( *((_DWORD *)v3 - 1) != 270158662 )
        __break(0x8228u);
      return v3();
    }
  }
  return result;
}
