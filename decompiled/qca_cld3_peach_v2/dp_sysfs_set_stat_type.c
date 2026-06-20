__int64 __fastcall dp_sysfs_set_stat_type(
        __int64 a1,
        int a2,
        int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  if ( a1 )
  {
    qdf_spinlock_acquire(*(_QWORD *)(a1 + 17584));
    *(_DWORD *)(*(_QWORD *)(a1 + 17584) + 136LL) = a2;
    *(_DWORD *)(*(_QWORD *)(a1 + 17584) + 140LL) = a3;
    *(_BYTE *)(*(_QWORD *)(a1 + 17584) + 144LL) = a4;
    qdf_spinlock_release(*(_QWORD *)(a1 + 17584));
    return 0;
  }
  else
  {
    qdf_trace_msg(0x89u, 2u, "%s: %pK: soc is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "dp_sysfs_set_stat_type", 0);
    return 4;
  }
}
