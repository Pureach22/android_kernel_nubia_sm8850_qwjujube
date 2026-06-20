__int64 __fastcall cfg80211_put_bss(__int64 result, _QWORD *a2)
{
  __int64 v3; // x19
  _QWORD *v4; // x22
  __int64 v5; // x8
  __int64 v6; // x1
  __int64 v7; // x1
  _QWORD *v8; // x0
  _QWORD *v9; // x8
  _QWORD *v10; // x9
  _QWORD *v11; // x22
  __int64 v12; // x8
  __int64 v13; // x1
  __int64 v14; // x1
  _QWORD *v15; // x0
  _QWORD *v16; // x8
  _QWORD *v17; // x9
  __int64 v18; // x8
  __int64 v19; // x1
  __int64 v20; // x1
  _QWORD *v21; // x0
  _QWORD *v22; // x8
  _QWORD *v23; // x9

  if ( !result )
  {
    __break(0x800u);
    return cfg80211_unlink_bss();
  }
  if ( a2 )
  {
    v3 = result - 808;
    raw_spin_lock_bh(result - 808);
    v4 = (_QWORD *)a2[4];
    if ( v4 )
    {
      v5 = *(v4 - 5) - 1LL;
      *(v4 - 5) = v5;
      if ( !v5 )
      {
        if ( *((_DWORD *)v4 - 8) )
        {
          __break(0x800u);
          v11 = (_QWORD *)a2[5];
          if ( v11 )
          {
LABEL_18:
            v12 = *(v11 - 5) - 1LL;
            *(v11 - 5) = v12;
            if ( !v12 )
            {
              if ( *((_DWORD *)v11 - 8) )
              {
                __break(0x800u);
              }
              else
              {
                v13 = v11[2];
                if ( v13 && !v11[4] )
                  kvfree_call_rcu(v13 + 8, v13);
                v14 = v11[3];
                if ( v14 )
                  kvfree_call_rcu(v14 + 8, v14);
                v15 = v11 - 12;
                v16 = (_QWORD *)*(v11 - 12);
                if ( v16 != v11 - 12 )
                {
                  v17 = (_QWORD *)*(v11 - 11);
                  if ( (_QWORD *)*v17 == v15 && (_QWORD *)v16[1] == v15 )
                  {
                    v16[1] = v17;
                    *v17 = v16;
                  }
                  else
                  {
                    _list_del_entry_valid_or_report(v15);
                  }
                  *(v11 - 12) = 0xDEAD000000000100LL;
                  *(v11 - 11) = 0xDEAD000000000122LL;
                }
                kfree(v11 - 14);
              }
            }
          }
LABEL_31:
          v18 = *(a2 - 5) - 1LL;
          *(a2 - 5) = v18;
          if ( !v18 )
          {
            if ( *((_DWORD *)a2 - 8) )
            {
              __break(0x800u);
            }
            else
            {
              v19 = a2[2];
              if ( v19 && !a2[4] )
                kvfree_call_rcu(v19 + 8, v19);
              v20 = a2[3];
              if ( v20 )
                kvfree_call_rcu(v20 + 8, v20);
              v21 = a2 - 12;
              v22 = (_QWORD *)*(a2 - 12);
              if ( v22 != a2 - 12 )
              {
                v23 = (_QWORD *)*(a2 - 11);
                if ( (_QWORD *)*v23 == v21 && (_QWORD *)v22[1] == v21 )
                {
                  v22[1] = v23;
                  *v23 = v22;
                }
                else
                {
                  _list_del_entry_valid_or_report(v21);
                }
                *(a2 - 12) = 0xDEAD000000000100LL;
                *(a2 - 11) = 0xDEAD000000000122LL;
              }
              kfree(a2 - 14);
            }
          }
          return raw_spin_unlock_bh(v3);
        }
        v6 = v4[2];
        if ( v6 && !v4[4] )
          kvfree_call_rcu(v6 + 8, v6);
        v7 = v4[3];
        if ( v7 )
          kvfree_call_rcu(v7 + 8, v7);
        v8 = v4 - 12;
        v9 = (_QWORD *)*(v4 - 12);
        if ( v9 != v4 - 12 )
        {
          v10 = (_QWORD *)*(v4 - 11);
          if ( (_QWORD *)*v10 == v8 && (_QWORD *)v9[1] == v8 )
          {
            v9[1] = v10;
            *v10 = v9;
          }
          else
          {
            _list_del_entry_valid_or_report(v8);
          }
          *(v4 - 12) = 0xDEAD000000000100LL;
          *(v4 - 11) = 0xDEAD000000000122LL;
        }
        kfree(v4 - 14);
      }
    }
    v11 = (_QWORD *)a2[5];
    if ( v11 )
      goto LABEL_18;
    goto LABEL_31;
  }
  return result;
}
