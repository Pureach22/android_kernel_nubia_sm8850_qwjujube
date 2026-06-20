__int64 __fastcall param_set_forcetrigger_which(__int64 a1, __int64 a2)
{
  printk(&unk_A4AC);
  LODWORD(a2) = param_set_int(a1, a2);
  printk(&unk_9AC9);
  return (unsigned int)a2;
}
