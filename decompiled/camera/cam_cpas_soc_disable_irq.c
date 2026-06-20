__int64 cam_cpas_soc_disable_irq()
{
  unsigned int v0; // w19

  v0 = ((__int64 (*)(void))cam_soc_util_irq_disable)();
  if ( v0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_soc_disable_irq",
      2058,
      "disable irq failed, rc=%d",
      v0);
  return v0;
}
