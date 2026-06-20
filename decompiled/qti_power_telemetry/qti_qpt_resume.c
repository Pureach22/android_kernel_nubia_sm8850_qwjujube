__int64 __fastcall qti_qpt_resume(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *i; // x9

  v1 = *(_QWORD *)(a1 + 152);
  if ( (ktime_get(a1) - *(_QWORD *)(v1 + 144)) / 1000000 > qpt_update_interval_ms )
  {
    for ( i = *(_QWORD **)(v1 + 184); i != (_QWORD *)(v1 + 184); i = (_QWORD *)*i )
      i[9] = 0;
  }
  if ( (*(_BYTE *)(v1 + 86) & 1) == 0 )
  {
    enable_irq(*(unsigned int *)(v1 + 16));
    *(_BYTE *)(v1 + 86) = 1;
  }
  *(_DWORD *)(v1 + 88) = 0;
  return 0;
}
