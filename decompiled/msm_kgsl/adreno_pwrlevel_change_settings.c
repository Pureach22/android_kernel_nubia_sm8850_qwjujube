__int64 __fastcall adreno_pwrlevel_change_settings(__int64 result)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(result + 14264) + 40LL) + 80LL);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != -1853322457 )
      __break(0x8228u);
    return v1();
  }
  return result;
}
