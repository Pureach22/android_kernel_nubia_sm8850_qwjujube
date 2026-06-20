__int64 __fastcall param_set_trigger_wakepercent(__int64 a1, __int64 a2)
{
  printk(&unk_9D5B);
  LODWORD(a2) = param_set_int(a1, a2);
  printk(&unk_A46B);
  return (unsigned int)a2;
}
