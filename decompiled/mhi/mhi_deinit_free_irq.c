__int64 __fastcall mhi_deinit_free_irq(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v3; // x20
  unsigned int i; // w21

  v1 = *(_DWORD *)(a1 + 212);
  if ( v1 )
  {
    v3 = *(_QWORD *)(a1 + 248);
    for ( i = 0; i < v1; ++i )
    {
      if ( (*(_BYTE *)(v3 + 258) & 1) == 0 )
      {
        free_irq(*(unsigned int *)(*(_QWORD *)(a1 + 200) + 4LL * *(unsigned int *)(v3 + 24)), v3);
        v1 = *(_DWORD *)(a1 + 212);
      }
      v3 += 264;
    }
  }
  return free_irq(**(unsigned int **)(a1 + 200), a1);
}
