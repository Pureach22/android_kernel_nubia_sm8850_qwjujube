__int64 __fastcall qti_qpt_suspend(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  *(_DWORD *)(v1 + 88) = 1;
  if ( *(_BYTE *)(v1 + 86) == 1 )
  {
    disable_irq_nosync(*(unsigned int *)(v1 + 16));
    *(_BYTE *)(v1 + 86) = 0;
  }
  return 0;
}
