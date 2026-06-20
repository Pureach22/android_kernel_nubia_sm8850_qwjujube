__int64 __fastcall tsens_combined_irq_thread(unsigned int a1, __int64 a2)
{
  __int64 result; // x0

  result = tsens_critical_irq_thread();
  if ( (_DWORD)result == 1 )
  {
    tsens_irq_thread(a1, a2);
    return 1;
  }
  return result;
}
