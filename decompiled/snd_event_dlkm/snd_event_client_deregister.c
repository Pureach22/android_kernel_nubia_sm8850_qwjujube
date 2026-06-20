__int64 __fastcall snd_event_client_deregister(void *a1)
{
  _UNKNOWN **v2; // x0
  unsigned int v3; // w19
  unsigned __int64 *v4; // x8
  unsigned __int64 v5; // x10
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x20
  int v8; // w11
  void **v9; // x8
  _QWORD *v10; // x9
  _UNKNOWN **v12; // x22
  __int64 v13; // x9
  _UNKNOWN **v14; // x9

  if ( a1 )
  {
    mutex_lock(&snd_event_mutex);
    v2 = (_UNKNOWN **)snd_event_client_list;
    if ( snd_event_client_list == (_UNKNOWN *)&snd_event_client_list )
      goto LABEL_3;
    while ( v2[2] != a1 || !v2[3] )
    {
      v2 = (_UNKNOWN **)*v2;
      if ( v2 == &snd_event_client_list )
        goto LABEL_3;
    }
    if ( !v2 )
    {
LABEL_3:
      v3 = -19;
    }
    else
    {
      *((_BYTE *)v2 + 41) = 0;
      if ( master && (v4 = *(unsigned __int64 **)(master + 32), (v5 = *v4) != 0) )
      {
        v6 = v4[1];
        v7 = 0;
        v8 = 1;
        while ( *(void **)(*(_QWORD *)(v6 + 32 * v7 + 8) + 16LL) != a1 )
        {
          v7 = v8++;
          if ( v5 <= v7 )
            goto LABEL_14;
        }
        if ( *(_BYTE *)(master + 26) == 1 )
        {
          v12 = v2;
          v3 = check_and_update_fwk_state();
          v2 = v12;
          v13 = *(_QWORD *)(master + 32);
          *(_BYTE *)(master + 26) = 0;
          v6 = *(_QWORD *)(v13 + 8);
        }
        else
        {
          v3 = 0;
        }
        *(_QWORD *)(v6 + 32 * v7) = 0;
      }
      else
      {
LABEL_14:
        v3 = 0;
      }
      v9 = (void **)v2[1];
      if ( *v9 == v2 && (v10 = *v2, *((_UNKNOWN ***)*v2 + 1) == v2) )
      {
        v10[1] = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report();
        v2 = v14;
      }
      *v2 = (_UNKNOWN *)0xDEAD000000000100LL;
      v2[1] = (_UNKNOWN *)0xDEAD000000000122LL;
      kfree();
    }
    mutex_unlock(&snd_event_mutex);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&snd_event_client_deregister__rs, "snd_event_client_deregister") )
      printk(&unk_6FE7, "snd_event_client_deregister");
    return (unsigned int)-22;
  }
  return v3;
}
