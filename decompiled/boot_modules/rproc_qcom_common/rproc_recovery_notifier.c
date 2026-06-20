__int64 __fastcall rproc_recovery_notifier(__int64 a1, __int64 a2)
{
  size_t v3; // x0
  __int64 result; // x0
  __int64 (__fastcall *v5)(__int64); // x8

  printk(&unk_8574);
  v3 = strlen(*(const char **)(a2 + 24));
  result = strnstr(*(_QWORD *)(a2 + 24), "spss", v3);
  if ( !result )
  {
    v5 = (__int64 (__fastcall *)(__int64))rproc_recovery_set_fn;
    if ( rproc_recovery_set_fn )
    {
      if ( *((_DWORD *)rproc_recovery_set_fn - 1) != 923710114 )
        __break(0x8228u);
      return v5(a2);
    }
  }
  return result;
}
