__int64 __fastcall aoss_dsb_en_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  unsigned __int64 v5; // x8

  v3 = *(_QWORD *)(a1 + 96);
  result = -22;
  v5 = *(_QWORD *)(v3 + 152);
  if ( v5 )
  {
    if ( v5 <= 0xFFFFFFFFFFFFF000LL )
      return (int)sysfs_emit(a3, "%u\n", *(_DWORD *)(v5 + 112));
  }
  return result;
}
