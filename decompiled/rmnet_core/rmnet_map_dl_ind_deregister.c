__int64 __fastcall rmnet_map_dl_ind_deregister(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  _QWORD *v4; // x9
  _QWORD *v5; // x8
  _QWORD *v6; // x8
  _QWORD *v7; // x0
  __int64 v8; // x9
  _QWORD *v9; // x9

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v4 = *(_QWORD **)(a1 + 2480);
      if ( v4 )
      {
        v5 = (_QWORD *)(a1 + 2480);
        if ( v4 == v5 )
        {
          return 0;
        }
        else
        {
          while ( v4 - 3 != a2 )
          {
            v4 = (_QWORD *)*v4;
            if ( v4 == v5 )
              return 0;
          }
          v6 = (_QWORD *)a2[4];
          v7 = a2 + 3;
          if ( (_QWORD *)*v6 == a2 + 3 && (v8 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
          {
            *(_QWORD *)(v8 + 8) = v6;
            *v6 = v8;
          }
          else
          {
            _list_del_entry_valid_or_report(v7);
            a2 = v9;
          }
          a2[4] = 0xDEAD000000000122LL;
          return 0;
        }
      }
    }
  }
  return result;
}
