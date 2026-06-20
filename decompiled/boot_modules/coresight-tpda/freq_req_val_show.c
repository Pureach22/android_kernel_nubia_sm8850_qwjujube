__int64 __fastcall freq_req_val_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)sysfs_emit(a3, "%#lx\n", *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 44LL));
}
