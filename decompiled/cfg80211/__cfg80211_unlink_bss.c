__int64 __fastcall _cfg80211_unlink_bss(__int64 a1, __int64 *a2)
{
  __int64 *v4; // x8
  __int64 *v5; // x20
  __int64 **v6; // x9
  __int64 **v7; // x8
  __int64 *v8; // x9
  __int64 *v9; // x9
  __int64 **v10; // x8
  __int64 *v11; // x10
  __int64 v12; // x21
  __int64 v13; // t1
  int v14; // w1
  _QWORD *v15; // x22
  __int64 v16; // x8
  __int64 v17; // x1
  __int64 v18; // x1
  _QWORD *v19; // x0
  _QWORD *v20; // x8
  _QWORD *v21; // x9
  _QWORD *v22; // x22
  __int64 v23; // x8
  __int64 v24; // x1
  __int64 v25; // x1
  _QWORD *v26; // x0
  _QWORD *v27; // x8
  _QWORD *v28; // x9
  __int64 v29; // x8
  __int64 v30; // x1
  __int64 v31; // x1
  __int64 *v32; // x8
  __int64 **v33; // x9

  v5 = a2 + 2;
  v4 = (__int64 *)a2[2];
  if ( v4 != a2 + 2 )
  {
    if ( !a2[18] )
      return 0;
    v6 = (__int64 **)a2[3];
    if ( *v6 == v5 && (__int64 *)v4[1] == v5 )
    {
      v4[1] = (__int64)v6;
      *v6 = v4;
    }
    else
    {
      _list_del_entry_valid_or_report(a2 + 2);
    }
    a2[2] = (__int64)(a2 + 2);
    a2[3] = (__int64)v5;
  }
  v7 = (__int64 **)a2[1];
  if ( *v7 == a2 && (v8 = (__int64 *)*a2, *(__int64 **)(*a2 + 8) == a2) )
  {
    v8[1] = (__int64)v7;
    *v7 = v8;
  }
  else
  {
    _list_del_entry_valid_or_report(a2);
  }
  *a2 = (__int64)a2;
  v9 = a2 + 20;
  a2[1] = (__int64)a2;
  v10 = (__int64 **)a2[21];
  if ( *v10 == a2 + 20 && (v11 = (__int64 *)*v9, *(__int64 **)(*v9 + 8) == v9) )
  {
    v11[1] = (__int64)v10;
    *v10 = v11;
  }
  else
  {
    _list_del_entry_valid_or_report(a2 + 20);
  }
  a2[20] = (__int64)(a2 + 20);
  a2[21] = (__int64)v9;
  rb_erase(a2 + 4, a1 + 208);
  v13 = *(_QWORD *)(a1 + 192);
  v12 = a1 + 192;
  v14 = *(_DWORD *)(v12 + 28) - 1;
  *(_DWORD *)(v12 + 28) = v14;
  if ( (v14 != 0) != (v13 == v12) || (_cfg80211_unlink_bss___already_done & 1) != 0 )
  {
    v15 = (_QWORD *)a2[18];
    if ( v15 )
      goto LABEL_16;
  }
  else
  {
    _cfg80211_unlink_bss___already_done = 1;
    _warn_printk("rdev bss entries[%d]/list[empty:%d] corruption\n");
    __break(0x800u);
    v15 = (_QWORD *)a2[18];
    if ( v15 )
    {
LABEL_16:
      v16 = *(v15 - 5) - 1LL;
      *(v15 - 5) = v16;
      if ( !v16 )
      {
        if ( *((_DWORD *)v15 - 8) )
        {
          __break(0x800u);
        }
        else
        {
          v17 = v15[2];
          if ( v17 && !v15[4] )
            kvfree_call_rcu(v17 + 8, v17);
          v18 = v15[3];
          if ( v18 )
            kvfree_call_rcu(v18 + 8, v18);
          v19 = v15 - 12;
          v20 = (_QWORD *)*(v15 - 12);
          if ( v20 != v15 - 12 )
          {
            v21 = (_QWORD *)*(v15 - 11);
            if ( (_QWORD *)*v21 == v19 && (_QWORD *)v20[1] == v19 )
            {
              v20[1] = v21;
              *v21 = v20;
            }
            else
            {
              _list_del_entry_valid_or_report(v19);
            }
            *(v15 - 12) = 0xDEAD000000000100LL;
            *(v15 - 11) = 0xDEAD000000000122LL;
          }
          kfree(v15 - 14);
        }
      }
    }
  }
  v22 = (_QWORD *)a2[19];
  if ( v22 )
  {
    v23 = *(v22 - 5) - 1LL;
    *(v22 - 5) = v23;
    if ( !v23 )
    {
      if ( *((_DWORD *)v22 - 8) )
      {
        __break(0x800u);
      }
      else
      {
        v24 = v22[2];
        if ( v24 && !v22[4] )
          kvfree_call_rcu(v24 + 8, v24);
        v25 = v22[3];
        if ( v25 )
          kvfree_call_rcu(v25 + 8, v25);
        v26 = v22 - 12;
        v27 = (_QWORD *)*(v22 - 12);
        if ( v27 != v22 - 12 )
        {
          v28 = (_QWORD *)*(v22 - 11);
          if ( (_QWORD *)*v28 == v26 && (_QWORD *)v27[1] == v26 )
          {
            v27[1] = v28;
            *v28 = v27;
          }
          else
          {
            _list_del_entry_valid_or_report(v26);
          }
          *(v22 - 12) = 0xDEAD000000000100LL;
          *(v22 - 11) = 0xDEAD000000000122LL;
        }
        kfree(v22 - 14);
      }
    }
  }
  v29 = a2[9] - 1;
  a2[9] = v29;
  if ( !v29 )
  {
    if ( *((_DWORD *)a2 + 20) )
    {
      __break(0x800u);
    }
    else
    {
      v30 = a2[16];
      if ( v30 && !a2[18] )
        kvfree_call_rcu(v30 + 8, v30);
      v31 = a2[17];
      if ( v31 )
        kvfree_call_rcu(v31 + 8, v31);
      v32 = (__int64 *)*v5;
      if ( (__int64 *)*v5 != v5 )
      {
        v33 = (__int64 **)a2[3];
        if ( *v33 == v5 && (__int64 *)v32[1] == v5 )
        {
          v32[1] = (__int64)v33;
          *v33 = v32;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        a2[2] = 0xDEAD000000000100LL;
        a2[3] = 0xDEAD000000000122LL;
      }
      kfree(a2);
    }
  }
  return 1;
}
