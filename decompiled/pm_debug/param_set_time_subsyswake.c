__int64 __fastcall param_set_time_subsyswake(__int64 a1, __int64 a2)
{
  printk(&unk_9E90);
  LODWORD(a2) = param_set_int(a1, a2);
  time_subsyswake_adsp = time_subsyswake;
  time_subsyswake_cdsp = time_subsyswake;
  printk(&unk_969D);
  return (unsigned int)a2;
}
