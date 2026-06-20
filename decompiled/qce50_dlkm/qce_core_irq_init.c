__int64 __fastcall qce_core_irq_init(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w0

  if ( *(_BYTE *)(result + 70261) == 1 )
  {
    v1 = result;
    v2 = request_threaded_irq(*(unsigned int *)(result + 64), qce_core_irq_handler, 0, 2097153, "qcedev", result);
    if ( v2 )
      return printk(&unk_1664D, "qce_core_irq_init", v2);
    else
      return enable_irq(*(unsigned int *)(v1 + 64));
  }
  return result;
}
