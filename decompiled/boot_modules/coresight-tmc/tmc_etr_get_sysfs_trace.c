__int64 __fastcall tmc_etr_get_sysfs_trace(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 result; // x0
  __int64 (__fastcall *v6)(_QWORD); // x9

  v3 = *(_QWORD *)(a1 + 288);
  v4 = *(_QWORD *)(v3 + 40);
  if ( a3 + a2 <= v4 )
    result = a3;
  else
    result = v4 - a2;
  if ( result >= 1 )
  {
    v6 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 48) + 16LL);
    if ( *((_DWORD *)v6 - 1) != -256312645 )
      __break(0x8229u);
    return v6(v3);
  }
  return result;
}
