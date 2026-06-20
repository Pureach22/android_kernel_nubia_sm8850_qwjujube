__int64 __fastcall swr_pm_suspend(__int64 a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  __int64 (__fastcall *v4)(__int64, __int64); // x9

  v1 = *(_QWORD *)(a1 + 136);
  if ( v1 && *(_QWORD *)(v1 + 120) )
    return pm_generic_suspend();
  if ( *(_UNKNOWN **)(a1 + 120) != &swr_dev_type )
    return 0;
  result = 0;
  if ( a1 && a1 != 72 && v1 )
  {
    v4 = *(__int64 (__fastcall **)(__int64, __int64))(v1 - 48);
    if ( !v4 )
      return 0;
    if ( *((_DWORD *)v4 - 1) != -142251602 )
      __break(0x8229u);
    return v4(a1 - 72, 2);
  }
  return result;
}
