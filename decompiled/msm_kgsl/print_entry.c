__int64 __fastcall print_entry(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  const char *v7; // x4
  const char *v8; // x5
  _QWORD v9[5]; // [xsp+8h] [xbp-28h] BYREF

  v9[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v9, 0, 32);
  if ( a2 )
  {
    kgsl_get_memory_usage((char *)v9, 0x20u, *(_QWORD *)(a2 + 80));
    if ( (*(_DWORD *)(a2 + 56) & 1) != 0 )
      v7 = "(+guard)";
    else
      v7 = (const char *)&unk_13C708;
    if ( *(_DWORD *)(a2 + 264) )
      v8 = "(pending free)";
    else
      v8 = (const char *)&unk_13C708;
    result = dev_err(
               a1,
               "[%016llX - %016llX] %s %s (pid = %d) (%s)\n",
               *(_QWORD *)(a2 + 32),
               *(_QWORD *)(a2 + 32) + *(_QWORD *)(a2 + 48) - 1LL,
               v7,
               v8,
               a3,
               (const char *)v9);
  }
  else
  {
    result = dev_crit(a1, "**EMPTY**\n");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
