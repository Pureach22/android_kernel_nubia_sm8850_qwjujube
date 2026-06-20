__int64 __fastcall param_set_aod_state(__int64 a1, __int64 a2)
{
  printk(&unk_A125);
  LODWORD(a2) = param_set_int(a1, a2);
  printk(&unk_998F);
  return (unsigned int)a2;
}
