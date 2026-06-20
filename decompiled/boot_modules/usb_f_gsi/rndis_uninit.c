__int64 __fastcall rndis_uninit(__int64 result)
{
  __int64 v1; // x19
  _QWORD **v2; // x20
  _QWORD **v3; // x23
  _QWORD *v4; // x23
  _QWORD *v5; // x0
  _QWORD *v6; // x9
  _QWORD *v7; // x24
  _QWORD *v8; // x8

  if ( result )
  {
    v1 = result;
    v2 = (_QWORD **)(result + 80);
    *(_DWORD *)(result + 8) = 0;
LABEL_3:
    raw_spin_lock(v1 + 96);
    v3 = v2;
    while ( 1 )
    {
      v3 = (_QWORD **)*v3;
      if ( v3 == v2 )
        return raw_spin_unlock(v1 + 96);
      if ( !*((_DWORD *)v3 + 7) )
      {
        *((_DWORD *)v3 + 7) = 1;
        result = raw_spin_unlock(v1 + 96);
        v4 = v3[2];
        if ( !v4 )
          return result;
        raw_spin_lock(v1 + 96);
        v5 = *v2;
        if ( *v2 != v2 )
        {
          do
          {
            v7 = (_QWORD *)*v5;
            if ( (_QWORD *)v5[2] == v4 )
            {
              v8 = (_QWORD *)v5[1];
              if ( (_QWORD *)*v8 == v5 && (_QWORD *)v7[1] == v5 )
              {
                v7[1] = v8;
                *v8 = v7;
              }
              else
              {
                _list_del_entry_valid_or_report(v5);
                v5 = v6;
              }
              *v5 = 0xDEAD000000000100LL;
              v5[1] = 0xDEAD000000000122LL;
              kfree(v5);
            }
            v5 = v7;
          }
          while ( v7 != v2 );
        }
        raw_spin_unlock(v1 + 96);
        goto LABEL_3;
      }
    }
  }
  return result;
}
