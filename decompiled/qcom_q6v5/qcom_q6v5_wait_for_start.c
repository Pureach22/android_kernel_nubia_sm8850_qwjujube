__int64 __fastcall qcom_q6v5_wait_for_start(_QWORD *a1, int a2)
{
  unsigned __int8 ss_symbol_from_rproc_name; // w0

  if ( (unsigned int)wait_for_completion_timeout(a1 + 18, a2) )
  {
    ss_symbol_from_rproc_name = get_ss_symbol_from_rproc_name((__int64)a1);
    if ( (unsigned __int8)ss_atomic_panic_intval == ss_symbol_from_rproc_name )
    {
      dev_info(*a1, "ztedbg clear ss panic tag %x\n", (unsigned __int8)ss_atomic_panic_intval);
      ss_atomic_panic_intval = 50;
    }
    else
    {
      dev_info(
        *a1,
        "ztedbg skip clear ss panic tag %x %x\n",
        (unsigned __int8)ss_atomic_panic_intval,
        ss_symbol_from_rproc_name);
    }
    return 0;
  }
  else
  {
    disable_irq(*((unsigned int *)a1 + 19));
    dev_info(*a1, "ztedbg ss recover timeout\n");
    return 4294967186LL;
  }
}
