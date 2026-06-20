__int64 __fastcall unfreeze_set_state(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x2

  kstrtoint(a3, 10, &state);
  printk(&unk_735B, (unsigned int)state, v5);
  return a4;
}
