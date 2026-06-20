__int64 __fastcall aer_rootport_total_err_nonfatal_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 3056LL);
  if ( v3 )
    return (int)sysfs_emit(a3, "%llu\n", *(_QWORD *)(v3 + 600));
  else
    return -19;
}
