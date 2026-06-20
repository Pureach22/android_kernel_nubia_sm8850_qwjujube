__int64 __fastcall dsb_trig_type_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)sysfs_emit(
                a3,
                "%u\n",
                *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 40LL) + 363LL));
}
