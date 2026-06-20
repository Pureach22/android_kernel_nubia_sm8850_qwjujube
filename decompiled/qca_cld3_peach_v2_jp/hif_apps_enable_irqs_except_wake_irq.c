__int64 __fastcall hif_apps_enable_irqs_except_wake_irq(__int64 a1)
{
  unsigned int v2; // w20
  _DWORD *v3; // x8
  __int64 v4; // x0

  if ( !a1 )
    return 4294967274LL;
  if ( *(_DWORD *)(a1 + 656) )
  {
    v2 = 0;
    do
    {
      v3 = *(_DWORD **)(a1 + 384);
      if ( *(v3 - 1) != -577898772 )
        __break(0x8228u);
      v4 = ((__int64 (__fastcall *)(__int64, _QWORD))v3)(a1, v2);
      if ( (_DWORD)v4 != *(_DWORD *)(a1 + 2572) )
        enable_irq(v4);
      ++v2;
    }
    while ( v2 < *(_DWORD *)(a1 + 656) );
  }
  return 0;
}
