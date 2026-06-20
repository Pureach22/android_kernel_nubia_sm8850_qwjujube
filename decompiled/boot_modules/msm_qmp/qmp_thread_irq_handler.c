__int64 __fastcall qmp_thread_irq_handler(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x19
  _QWORD *v3; // x20

  v2 = (_QWORD *)(a2 + 16);
  v3 = *(_QWORD **)(a2 + 16);
  if ( v3 != (_QWORD *)(a2 + 16) )
  {
    do
    {
      _qmp_rx_worker(v3);
      v3 = (_QWORD *)*v3;
    }
    while ( v3 != v2 );
  }
  return 1;
}
