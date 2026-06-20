__int64 __fastcall qos_rec_irq_read(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x22

  v2 = 0;
  v3 = *(_QWORD *)(a1 + 128) + 2596LL;
  do
  {
    seq_printf(a1, "%d ", *(_DWORD *)(v3 + v2));
    v2 += 4;
  }
  while ( v2 != 200 );
  seq_putc(a1, 10);
  return 0;
}
