__int64 __fastcall get_core_ctl_register(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x3

  if ( core_ctl_register )
    v3 = 89;
  else
    v3 = 78;
  return (int)scnprintf(a3, 4096, "%c\n", v3);
}
