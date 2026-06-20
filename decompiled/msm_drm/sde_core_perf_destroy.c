__int64 __fastcall sde_core_perf_destroy(_QWORD *a1)
{
  __int64 result; // x0

  if ( !a1 )
    return printk(&unk_27D28A, "sde_core_perf_destroy");
  result = debugfs_remove(a1[1]);
  a1[7] = 0;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  a1[4] = 0;
  a1[5] = 0;
  return result;
}
