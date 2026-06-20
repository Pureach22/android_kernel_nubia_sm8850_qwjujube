__int64 __fastcall param_set_time_nexttrigger(__int64 a1, __int64 a2)
{
  printk(&unk_985F);
  LODWORD(a2) = param_set_int(a1, a2);
  printk(&unk_96D6);
  return (unsigned int)a2;
}
