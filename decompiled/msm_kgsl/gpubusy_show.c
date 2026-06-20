__int64 __fastcall gpubusy_show(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v3; // x20
  int v4; // w19

  v3 = *(_DWORD **)(a1 + 152);
  v4 = scnprintf(a3, 4096, "%7d %7d\n", v3[2590], v3[2591]);
  if ( !v3[2782] )
  {
    mutex_lock(v3 + 2754);
    *((_QWORD *)v3 + 1295) = 0;
    mutex_unlock(v3 + 2754);
  }
  return v4;
}
