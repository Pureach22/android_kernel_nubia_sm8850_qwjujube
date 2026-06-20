__int64 __fastcall adreno_track_context(__int64 a1, __int64 a2, _QWORD *a3)
{
  _QWORD *v6; // x8
  _QWORD *v7; // x9
  __int64 v8; // x10
  char *v9; // x11
  _QWORD *v10; // x2
  _QWORD **v11; // x10
  int v12; // w8
  _QWORD *v13; // x12
  int v14; // w8

  raw_spin_lock(a1 + 20816);
  v6 = (_QWORD *)a3[203];
  v7 = a3 + 202;
  if ( (_QWORD *)*v6 == a3 + 202 && (v8 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
  {
    *(_QWORD *)(v8 + 8) = v6;
    *v6 = v8;
  }
  else
  {
    _list_del_entry_valid_or_report(a3 + 202);
  }
  v9 = "";
  a3[202] = a3 + 202;
  a3[203] = v7;
  a3[204] = jiffies;
  v10 = *(_QWORD **)(a1 + 20800);
  v11 = (_QWORD **)(a1 + 20800);
  if ( v10[1] != a1 + 20800 || v7 == v11 || v10 == v7 )
  {
    _list_add_valid_or_report(v7, a1 + 20800);
    v7 = *v11;
    if ( *v11 != v11 )
      goto LABEL_8;
  }
  else
  {
    v10[1] = v7;
    a3[202] = v10;
    a3[203] = v11;
    *v11 = v7;
    if ( v7 != v11 )
    {
LABEL_8:
      v12 = 0;
      v13 = v7;
      do
      {
        if ( v13[2] - *((_QWORD *)v9 + 288) + 25LL < 0 )
          break;
        v13 = (_QWORD *)*v13;
        ++v12;
      }
      while ( v13 != v11 );
      *(_DWORD *)(a1 + 12984) = v12;
      if ( a2 )
      {
        v14 = 0;
        do
        {
          if ( v7[2] - *((_QWORD *)v9 + 288) + 25LL < 0 )
            break;
          if ( *(v7 - 10) + 208LL != a2 )
            break;
          v7 = (_QWORD *)*v7;
          ++v14;
        }
        while ( v7 != v11 );
        goto LABEL_20;
      }
      return raw_spin_unlock(a1 + 20816);
    }
  }
  v14 = 0;
  *(_DWORD *)(a1 + 12984) = 0;
  if ( a2 )
LABEL_20:
    *(_DWORD *)(a2 + 1036) = v14;
  return raw_spin_unlock(a1 + 20816);
}
