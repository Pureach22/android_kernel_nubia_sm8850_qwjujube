__int64 __fastcall gpr_device_match(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  _DWORD *i; // x8
  int v6; // w9

  v3 = *(_QWORD *)(a2 + 176);
  if ( of_match_device(*(_QWORD *)(a2 + 40), a1) )
    return 1;
  if ( v3 )
  {
    for ( i = (_DWORD *)(v3 + 36); ; i += 14 )
    {
      v6 = *(i - 1);
      if ( !v6 && !*i )
        break;
      if ( v6 == *(unsigned __int16 *)(a1 + 914) && *i == *(unsigned __int16 *)(a1 + 912) )
        return 1;
    }
  }
  return 0;
}
