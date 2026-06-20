_QWORD *__fastcall sde_evtlog_set_filter(_QWORD *result, char *a2)
{
  _QWORD *v2; // x19
  _QWORD *v3; // x24
  __int64 v4; // x9
  _QWORD *v5; // x10
  _QWORD *v6; // x20
  _QWORD *v7; // x11
  _QWORD *v8; // x8
  _QWORD *v9; // x1
  __int64 v10; // x9
  char *v11; // x0
  const char *v12; // x22
  _QWORD *v13; // x23
  _QWORD *v14; // x8
  __int64 v15; // x9
  size_t v16; // x0
  unsigned __int64 v17; // x2
  __int64 v18; // x0
  _QWORD *v19; // x1
  _QWORD *v20; // x8
  _QWORD *v21; // x21
  _QWORD *v22; // x9
  _QWORD *v23; // [xsp+10h] [xbp-20h] BYREF
  _QWORD **v24; // [xsp+18h] [xbp-18h]
  char *stringp[2]; // [xsp+20h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  stringp[0] = a2;
  if ( result )
  {
    v2 = result;
    v3 = result + 98304;
    v23 = &v23;
    v24 = &v23;
    v4 = raw_spin_lock_irqsave((char *)result + 786476);
    v6 = v3 + 6;
    v5 = (_QWORD *)v3[6];
    if ( v5 != v3 + 6 )
    {
      do
      {
        v7 = (_QWORD *)*v5;
        v8 = (_QWORD *)v5[1];
        if ( (_QWORD *)*v8 == v5 && (_QWORD *)v7[1] == v5 )
        {
          v7[1] = v8;
          *v8 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        *v5 = v5;
        v5[1] = v5;
        v9 = v24;
        if ( v5 == &v23 || v24 == v5 || *v24 != &v23 )
        {
          _list_add_valid_or_report(v5, v24);
        }
        else
        {
          v24 = (_QWORD **)v5;
          *v5 = &v23;
          v5[1] = v9;
          *v9 = v5;
        }
        v5 = v7;
      }
      while ( v7 != v6 );
    }
    raw_spin_unlock_irqrestore((char *)v2 + 786476, v4);
    if ( stringp[0] )
    {
      _ReadStatusReg(SP_EL0);
      do
      {
        v11 = strsep(stringp, "|\r\n\t ");
        if ( !v11 )
          break;
        v12 = v11;
        if ( *v11 )
        {
          v13 = v23;
          if ( v23 == &v23 )
          {
            v13 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
            if ( !v13 )
              break;
          }
          else
          {
            v14 = (_QWORD *)v23[1];
            if ( (_QWORD *)*v14 == v23 && (v15 = *v23, *(_QWORD **)(*v23 + 8LL) == v23) )
            {
              *(_QWORD *)(v15 + 8) = v14;
              *v14 = v15;
            }
            else
            {
              _list_del_entry_valid_or_report(v23);
            }
          }
          *v13 = v13;
          v13[1] = v13;
          v16 = strnlen(v12, 0x40u);
          if ( v16 == -1 )
            goto LABEL_45;
          if ( v16 == 64 )
            v17 = 64;
          else
            v17 = v16 + 1;
          if ( v17 >= 0x41 )
          {
            v16 = _fortify_panic(7, 64, v17);
LABEL_45:
            _fortify_panic(2, -1, v16 + 1);
          }
          sized_strscpy(v13 + 2, v12);
          v18 = raw_spin_lock_irqsave((char *)v2 + 786476);
          v19 = (_QWORD *)v3[7];
          v10 = v18;
          if ( v13 == v6 || v19 == v13 || (_QWORD *)*v19 != v6 )
          {
            _list_add_valid_or_report(v13, v19);
          }
          else
          {
            v3[7] = v13;
            *v13 = v6;
            v13[1] = v19;
            *v19 = v13;
          }
          raw_spin_unlock_irqrestore((char *)v2 + 786476, v10);
        }
      }
      while ( stringp[0] );
    }
    result = v23;
    if ( v23 != &v23 )
    {
      do
      {
        v21 = (_QWORD *)*result;
        v20 = (_QWORD *)result[1];
        if ( (_QWORD *)*v20 == result && (_QWORD *)v21[1] == result )
        {
          v21[1] = v20;
          *v20 = v21;
        }
        else
        {
          _list_del_entry_valid_or_report(result);
          result = v22;
        }
        *result = 0xDEAD000000000100LL;
        result[1] = 0xDEAD000000000122LL;
        kfree(result);
        result = v21;
      }
      while ( v21 != &v23 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
