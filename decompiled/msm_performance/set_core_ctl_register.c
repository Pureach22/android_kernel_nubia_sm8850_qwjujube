__int64 __fastcall set_core_ctl_register(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w21
  unsigned int v6; // w0
  __int64 v7; // x2
  unsigned int v9; // w20

  v4 = (unsigned __int8)core_ctl_register;
  v6 = kstrtobool(a3);
  if ( (v6 & 0x80000000) != 0 )
  {
    v9 = v6;
    printk(&unk_BB8F, v6, v7);
    return (int)v9;
  }
  else if ( (unsigned __int8)core_ctl_register != v4 )
  {
    if ( core_ctl_register )
      core_ctl_notifier_register(&msm_perf_nb);
    else
      core_ctl_notifier_unregister(&msm_perf_nb);
  }
  return a4;
}
