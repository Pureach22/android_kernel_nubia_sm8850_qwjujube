__int64 __fastcall spss_set_saved_uefi_apps_cmac(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 *v5; // x21
  __int64 result; // x0
  __int64 v7; // x2
  __int64 v8; // x2
  __int64 v9; // x2

  v3 = cmac_mem;
  if ( !cmac_mem )
    return printk(&unk_866E, "spss_set_saved_uefi_apps_cmac");
  v4 = -224;
  v5 = &qword_97A8;
  do
  {
    result = *((unsigned int *)v5 - 2);
    if ( (_DWORD)result == *((_DWORD *)v5 - 1) )
      break;
    writel_relaxed(result, v3 + v4 + 256, a3);
    writel_relaxed(*((unsigned int *)v5 - 1), v3 + v4 + 260, v7);
    writel_relaxed(*(unsigned int *)v5, v3 + v4 + 264, v8);
    result = writel_relaxed(*((unsigned int *)v5 + 1), v3 + v4 + 268, v9);
    v4 += 32;
    v5 += 2;
  }
  while ( v4 );
  return result;
}
