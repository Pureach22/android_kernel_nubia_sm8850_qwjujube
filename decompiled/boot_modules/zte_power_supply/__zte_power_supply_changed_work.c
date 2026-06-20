__int64 __fastcall _zte_power_supply_changed_work(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  const char *v4; // x20
  unsigned __int64 v5; // x22
  unsigned __int64 v6; // x8
  int v7; // w23
  __int64 v8; // x22
  const char **v9; // x21
  const char *v10; // x20
  unsigned __int64 v11; // x23
  unsigned __int64 v12; // x8
  int v13; // w24
  const char *v14; // x8

  v2 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v2 + 24);
  if ( v3 )
  {
    v4 = **(const char ***)a2;
    if ( !v4 )
      return 0;
    v5 = *(_QWORD *)(v2 + 32);
    if ( !v5 )
      return 0;
    v6 = 0;
    v7 = 1;
    while ( strcmp(v4, *(const char **)(v3 + 8 * v6)) )
    {
      v6 = v7++;
      if ( v5 <= v6 )
        return 0;
    }
    v9 = *(const char ***)v2;
  }
  else
  {
    v8 = *(_QWORD *)(a2 + 8);
    if ( !v8 )
      return 0;
    v9 = *(const char ***)v2;
    v10 = **(const char ***)v2;
    if ( !v10 )
      return 0;
    v11 = *(_QWORD *)(a2 + 16);
    if ( !v11 )
      return 0;
    v12 = 0;
    v13 = 1;
    while ( strcmp(*(const char **)(v8 + 8 * v12), v10) )
    {
      v12 = v13++;
      if ( v11 <= v12 )
        return 0;
    }
  }
  v14 = v9[9];
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != 1866051055 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64))v14)(v2);
  }
  return 0;
}
