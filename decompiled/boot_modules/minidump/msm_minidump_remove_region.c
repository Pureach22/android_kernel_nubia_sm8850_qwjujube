__int64 __fastcall msm_minidump_remove_region(const char *a1)
{
  unsigned __int8 v1; // w8
  __int64 (*v2)(void); // x8
  const char *v3; // x19
  __int64 result; // x0
  unsigned int v5; // w20

  if ( !a1 )
    return 4294967274LL;
  v1 = atomic_load((unsigned __int8 *)&md_init_done);
  if ( (v1 & 1) == 0 )
    return 4294967274LL;
  if ( !md_core_0 )
  {
    v3 = a1;
    v5 = -22;
    goto LABEL_12;
  }
  v2 = *(__int64 (**)(void))(md_core_0 + 24);
  v3 = a1;
  if ( *((_DWORD *)v2 - 1) != -1087585291 )
    __break(0x8228u);
  result = v2();
  if ( (_DWORD)result )
  {
    v5 = result;
LABEL_12:
    printk_deferred("Failed to remove region:%s\n", v3);
    return v5;
  }
  return result;
}
