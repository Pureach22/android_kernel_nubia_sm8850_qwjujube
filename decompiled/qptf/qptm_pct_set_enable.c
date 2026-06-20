__int64 __fastcall qptm_pct_set_enable(__int64 a1, char a2)
{
  __int64 result; // x0
  _UNKNOWN **v3; // x8
  _DWORD **v4; // x10
  _DWORD *v5; // x10
  __int64 v7; // x1
  __int64 v8; // x3
  const char *v9; // x2
  unsigned int v10; // w19

  if ( *(_QWORD *)(qh + 8) != a1 )
    return 4294967274LL;
  v3 = (_UNKNOWN **)qptm_list;
  if ( qptm_list == (_UNKNOWN *)&qptm_list )
    return 0;
  while ( 1 )
  {
    v4 = (_DWORD **)*(v3 - 9);
    if ( v4 )
    {
      v5 = *v4;
      if ( v5 )
        break;
    }
    v3 = (_UNKNOWN **)*v3;
    if ( v3 == &qptm_list )
      return 0;
  }
  v7 = a2 & 1;
  if ( *(v5 - 1) != 2081452947 )
    __break(0x822Au);
  result = ((__int64 (__fastcall *)(_UNKNOWN **, __int64))v5)(v3 - 148, v7);
  if ( (_DWORD)result )
  {
    if ( (a2 & 1) != 0 )
      v9 = "disable";
    else
      v9 = "enable";
    v10 = result;
    printk(&unk_80A1, "qptm_pct_set_enable", v9, v8);
    return v10;
  }
  return result;
}
