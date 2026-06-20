__int64 __fastcall snd_event_client_register(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x22
  __int64 *v7; // x1

  if ( a1 )
  {
    v6 = _kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 48);
    if ( v6 )
    {
      *(_QWORD *)(v6 + 16) = a1;
      *(_QWORD *)(v6 + 24) = a2;
      *(_QWORD *)(v6 + 32) = a3;
      mutex_lock(&snd_event_mutex);
      v7 = (__int64 *)off_108;
      if ( off_108 == (_UNKNOWN **)v6 || *off_108 != (_UNKNOWN *)&snd_event_client_list )
      {
        _list_add_valid_or_report(v6);
      }
      else
      {
        off_108 = (_UNKNOWN **)v6;
        *(_QWORD *)v6 = &snd_event_client_list;
        *(_QWORD *)(v6 + 8) = v7;
        *v7 = v6;
      }
      if ( master && (*(_BYTE *)(master + 26) & 1) == 0 && !(unsigned int)snd_event_find_clients() )
        *(_BYTE *)(master + 26) = 1;
      mutex_unlock(&snd_event_mutex);
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&snd_event_client_register__rs, "snd_event_client_register") )
      printk(&unk_6FE7, "snd_event_client_register");
    return 4294967274LL;
  }
}
