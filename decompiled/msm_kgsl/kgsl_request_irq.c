__int64 __fastcall kgsl_request_irq(__int64 a1, const char *a2, __int64 a3, __int64 a4)
{
  unsigned int irq_byname; // w20
  int v9; // w0

  irq_byname = platform_get_irq_byname();
  if ( (irq_byname & 0x80000000) == 0 )
  {
    v9 = devm_request_threaded_irq(a1 + 16, irq_byname, a3, 0, 4, a2, a4);
    if ( v9 )
    {
      irq_byname = v9;
      dev_err(a1 + 16, "Unable to get interrupt %s: %d\n", a2, v9);
    }
    else
    {
      disable_irq(irq_byname);
    }
  }
  return irq_byname;
}
