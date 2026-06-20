__int64 __fastcall enable_ts_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w9
  __int64 v4; // x9
  __int64 v5; // x10

  v3 = *(_DWORD *)(a2 + 32);
  if ( v3 == 4 )
  {
    v4 = 360;
    v5 = 40;
    return (int)sysfs_emit(
                  a3,
                  "%u\n",
                  *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + v5) + v4));
  }
  if ( v3 == 9 )
  {
    v4 = 164;
    v5 = 48;
    return (int)sysfs_emit(
                  a3,
                  "%u\n",
                  *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + v5) + v4));
  }
  return -22;
}
