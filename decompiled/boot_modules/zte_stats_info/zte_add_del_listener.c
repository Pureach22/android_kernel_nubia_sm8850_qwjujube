__int64 __fastcall zte_add_del_listener(int a1, _DWORD *a2, int a3)
{
  unsigned int v6; // w22
  char v8; // w8
  char *v9; // x22
  __int64 v10; // x8
  unsigned __int64 v11; // x23
  __int64 v12; // x0
  unsigned __int64 v13; // x28
  char *v14; // x23
  char *v15; // x1
  char *v16; // x2
  char *v17; // x8
  char v18; // w8
  char *v19; // x9
  char *v20; // x0
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x27
  char *v23; // x21
  char *v24; // x8
  int v25; // w10
  char **v26; // x9

  if ( (*a2 & ~_cpu_possible_mask) == 0 && (_UNKNOWN *)task_active_pid_ns(_ReadStatusReg(SP_EL0)) == &init_pid_ns )
  {
    if ( a3 )
    {
      v6 = 0;
LABEL_24:
      v18 = 0;
      do
      {
        v21 = (unsigned int)(-1LL << v18) & *a2;
        if ( !(_DWORD)v21 )
          break;
        v22 = __clz(__rbit64(v21));
        v23 = (char *)&zte_listener_array + _per_cpu_offset[v22];
        down_write(v23);
        v24 = *((char **)v23 + 8);
        while ( v24 != v23 + 64 )
        {
          v25 = *((_DWORD *)v24 + 4);
          v20 = v24;
          v24 = *(char **)v24;
          if ( v25 == a1 )
          {
            v26 = *((char ***)v20 + 1);
            if ( *v26 == v20 && *((char **)v24 + 1) == v20 )
            {
              *((_QWORD *)v24 + 1) = v26;
              *v26 = v24;
            }
            else
            {
              _list_del_entry_valid_or_report();
              v20 = v19;
            }
            *(_QWORD *)v20 = 0xDEAD000000000100LL;
            *((_QWORD *)v20 + 1) = 0xDEAD000000000122LL;
            kfree(v20);
            break;
          }
        }
        up_write(v23);
        v18 = v22 + 1;
      }
      while ( v22 < 0x1F );
    }
    else
    {
      v8 = 0;
      while ( 1 )
      {
        v10 = -1LL << v8;
        v11 = (unsigned int)v10 & *a2;
        if ( ((unsigned int)v10 & *a2) == 0 )
          return 0;
        v12 = _kmalloc_cache_node_noprof(_list_del_entry_valid_or_report, 3264, 0, 24);
        v9 = (char *)v12;
        if ( !v12 )
        {
          v6 = -12;
          goto LABEL_24;
        }
        *(_DWORD *)(v12 + 16) = a1;
        *(_BYTE *)(v12 + 20) = 1;
        v13 = __clz(__rbit64(v11));
        v14 = (char *)&zte_listener_array + _per_cpu_offset[v13];
        down_write(v14);
        v15 = v14 + 64;
        v16 = *((char **)v14 + 8);
        if ( v16 == v14 + 64 )
        {
LABEL_19:
          if ( *((char **)v16 + 1) != v15 || v9 == v15 || v16 == v9 )
          {
            _list_add_valid_or_report(v9);
          }
          else
          {
            *((_QWORD *)v16 + 1) = v9;
            *(_QWORD *)v9 = v16;
            *((_QWORD *)v9 + 1) = v15;
            *(_QWORD *)v15 = v9;
          }
          v9 = nullptr;
        }
        else
        {
          v17 = *((char **)v14 + 8);
          while ( *((_DWORD *)v17 + 4) != a1 || !v17[20] )
          {
            v17 = *(char **)v17;
            if ( v17 == v15 )
              goto LABEL_19;
          }
        }
        up_write(v14);
        kfree(v9);
        v6 = 0;
        v8 = v13 + 1;
        if ( v13 > 0x1E )
          return v6;
      }
    }
  }
  else
  {
    return (unsigned int)-22;
  }
  return v6;
}
