__int64 __fastcall fan_enable_show(__int64 a1, __int64 a2, char *a3)
{
  printk(&unk_8264, "NB_FAN", "fan_enable_show", 304);
  return sprintf(a3, "%d\n", *(unsigned __int8 *)(*(_QWORD *)(chip + 8) + 12LL));
}
