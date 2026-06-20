__int64 __fastcall gpu_busy_show(_DWORD *a1, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int v4; // w3
  int v5; // w20

  v2 = a1[2591];
  if ( v2 )
    v4 = 100 * a1[2590] / v2;
  else
    v4 = 0;
  v5 = scnprintf(a2, 4096, "%d %%\n", v4);
  if ( !a1[2782] )
  {
    mutex_lock(a1 + 2754);
    *((_QWORD *)a1 + 1295) = 0;
    mutex_unlock(a1 + 2754);
  }
  return v5;
}
