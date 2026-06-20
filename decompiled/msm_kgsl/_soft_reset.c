__int64 __fastcall soft_reset(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x20
  unsigned __int64 v9; // x10
  __int64 (__fastcall *v10)(_QWORD); // x8

  v1 = result;
  v2 = *(_QWORD **)(*(_QWORD *)(result + 14264) + 40LL);
  if ( *(_DWORD *)(*v2 + 68LL) <= 0xFFFFFFFD )
  {
    result = kgsl_regmap_write(result + 13200, 1);
    if ( *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(v1 + 14264) + 40LL) + 68LL) <= 0xFFFFFFFD )
    {
      result = kgsl_regmap_read(v1 + 13200);
      if ( *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(v1 + 14264) + 40LL) + 68LL) <= 0xFFFFFFFD )
        result = kgsl_regmap_write(v1 + 13200, 0);
    }
  }
  _X8 = (unsigned __int64 *)(v1 + 14240);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
  v10 = (__int64 (__fastcall *)(_QWORD))v2[8];
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != -83892780 )
      __break(0x8228u);
    return v10(v1);
  }
  return result;
}
