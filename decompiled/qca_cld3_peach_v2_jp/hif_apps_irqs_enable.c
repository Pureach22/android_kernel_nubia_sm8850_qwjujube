__int64 __fastcall hif_apps_irqs_enable(__int64 a1)
{
  unsigned int v2; // w20
  _DWORD *v3; // x8

  if ( !a1 )
    return 4294967274LL;
  if ( (pld_is_one_msi(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL)) & 1) == 0 && *(_DWORD *)(a1 + 656) )
  {
    v2 = 0;
    do
    {
      v3 = *(_DWORD **)(a1 + 384);
      if ( *(v3 - 1) != -577898772 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, _QWORD))v3)(a1, v2) != *(_DWORD *)(a1 + 2572) )
        enable_irq();
      ++v2;
    }
    while ( v2 < *(_DWORD *)(a1 + 656) );
  }
  return 0;
}
