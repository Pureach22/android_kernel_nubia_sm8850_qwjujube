__int64 __fastcall gunyah_trace_buf_irq_handler(__int64 a1, __int64 a2)
{
  _wake_up(a2 + 32, 3, 0, 0);
  return 1;
}
