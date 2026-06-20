__int64 __fastcall dsb_mode_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)sysfs_emit(a3, &unk_ACEC, **(unsigned int **)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 40LL));
}
