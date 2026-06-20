__int64 __fastcall swr_pm_resume(__int64 a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  __int64 (__fastcall *v4)(_QWORD); // x9

  v1 = *(_QWORD *)(a1 + 136);
  if ( v1 && *(_QWORD *)(v1 + 120) )
    return pm_generic_resume();
  if ( *(_UNKNOWN **)(a1 + 120) != &swr_dev_type )
    return 0;
  result = 0;
  if ( a1 && a1 != 72 && v1 )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(v1 - 40);
    if ( !v4 )
      return 0;
    if ( *((_DWORD *)v4 - 1) != 1952588086 )
      __break(0x8229u);
    return v4(a1 - 72);
  }
  return result;
}
