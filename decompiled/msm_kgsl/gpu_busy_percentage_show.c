__int64 __fastcall gpu_busy_percentage_show(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v3; // x20
  unsigned int v4; // w8
  unsigned int v5; // w3
  int v6; // w19

  v3 = *(_DWORD **)(a1 + 152);
  v4 = v3[2591];
  if ( v4 )
    v5 = 100 * v3[2590] / v4;
  else
    v5 = 0;
  v6 = scnprintf(a3, 4096, "%d %%\n", v5);
  if ( !v3[2782] )
  {
    mutex_lock(v3 + 2754);
    *((_QWORD *)v3 + 1295) = 0;
    mutex_unlock(v3 + 2754);
  }
  return v6;
}
