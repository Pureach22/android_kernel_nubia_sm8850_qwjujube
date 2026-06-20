__int64 __fastcall reset_bdev(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x8

  result = a1[30];
  if ( result )
  {
    filp_close(result, 0);
    v3 = a1[3];
    a1[30] = 0;
    a1[33] = 0;
    *(_QWORD *)(v3 + 72) = &zram_devops;
    result = kvfree(a1[34]);
    a1[34] = 0;
  }
  return result;
}
