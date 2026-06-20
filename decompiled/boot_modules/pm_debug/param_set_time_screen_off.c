__int64 __fastcall param_set_time_screen_off(__int64 a1, __int64 a2)
{
  printk(&unk_9A90);
  LODWORD(a2) = param_set_int(a1, a2);
  time_screen_off_adsp = time_screen_off;
  time_screen_off_cdsp = time_screen_off;
  printk(&unk_9F8A);
  return (unsigned int)a2;
}
