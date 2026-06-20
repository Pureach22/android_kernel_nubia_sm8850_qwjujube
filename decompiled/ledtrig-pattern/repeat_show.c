__int64 __fastcall repeat_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x21
  int v5; // w20

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 336LL);
  mutex_lock(v4 + 8216);
  v5 = *(_DWORD *)(v4 + 8272);
  mutex_unlock(v4 + 8216);
  return (int)sysfs_emit(a3, "%d\n", v5);
}
