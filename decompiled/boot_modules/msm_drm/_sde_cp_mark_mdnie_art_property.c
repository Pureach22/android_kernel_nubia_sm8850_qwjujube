__int64 __fastcall sde_cp_mark_mdnie_art_property(_QWORD *a1)
{
  _QWORD *v2; // x9
  _QWORD *v3; // x8
  _QWORD *v4; // x11
  _QWORD *v5; // x8
  _QWORD *v6; // x10
  __int64 v7; // x12
  unsigned int v8; // w8
  _QWORD *v9; // x1
  _QWORD *v10; // x2

  mutex_lock(a1 + 583);
  v2 = a1 + 569;
  v3 = a1 + 569;
  while ( 1 )
  {
    v3 = (_QWORD *)*v3;
    if ( v3 == v2 )
      break;
    if ( *((_DWORD *)v3 - 16) == 43 )
      return mutex_unlock(a1 + 583);
  }
  v4 = a1 + 565;
  do
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == a1 + 565 )
      return mutex_unlock(a1 + 583);
  }
  while ( *((_DWORD *)v4 - 8) != 43 );
  if ( v4 == &qword_28 )
    return mutex_unlock(a1 + 583);
  v5 = (_QWORD *)v4[5];
  v6 = v4 + 4;
  if ( (_QWORD *)*v5 == v4 + 4 && (v7 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
  {
    *(_QWORD *)(v7 + 8) = v5;
    *v5 = v7;
  }
  else
  {
    _list_del_entry_valid_or_report(v4 + 4);
  }
  v4[4] = v4 + 4;
  v4[5] = v6;
  v8 = *((_DWORD *)v4 - 8);
  *(v4 - 2) = 0;
  if ( v8 <= 0x2B && ((1LL << v8) & 0x7F8000) != 0 )
  {
    v9 = (_QWORD *)a1[572];
    v10 = a1 + 571;
    if ( v6 != a1 + 571 && v6 != v9 && (_QWORD *)*v9 == v10 )
    {
      a1[572] = v6;
      v4[4] = v10;
LABEL_22:
      v4[5] = v9;
      *v9 = v6;
      return mutex_unlock(a1 + 583);
    }
  }
  else
  {
    v9 = (_QWORD *)a1[570];
    if ( v6 != v2 && v6 != v9 && (_QWORD *)*v9 == v2 )
    {
      a1[570] = v6;
      v4[4] = v2;
      goto LABEL_22;
    }
  }
  _list_add_valid_or_report(v6, v9);
  return mutex_unlock(a1 + 583);
}
