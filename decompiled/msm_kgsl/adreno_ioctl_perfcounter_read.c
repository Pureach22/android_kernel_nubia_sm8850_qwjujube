__int64 __fastcall adreno_ioctl_perfcounter_read(__int64 *a1, __int64 a2, _QWORD *a3)
{
  __int64 v3; // x0

  v3 = *a1;
  if ( *(_BYTE *)(v3 + 23968) == 1 )
    return (int)adreno_perfcounter_read_group(v3, *a3);
  else
    return -1;
}
