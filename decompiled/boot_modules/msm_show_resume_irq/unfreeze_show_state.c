__int64 __fastcall unfreeze_show_state(__int64 a1, __int64 a2, char *a3)
{
  printk(&unk_7133, (unsigned int)state, a3);
  return snprintf(a3, 0xAu, "%d\n", state);
}
