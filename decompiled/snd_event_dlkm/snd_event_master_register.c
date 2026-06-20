__int64 __fastcall snd_event_master_register(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  _QWORD *v8; // x0
  __int64 v9; // x19
  int clients; // w0
  unsigned int v11; // w19

  if ( a1 )
  {
    mutex_lock(&snd_event_mutex);
    if ( master )
    {
      dev_err(a1, "%s: master already allocated with %pK\n", "snd_event_master_register", *(const void **)master);
      v11 = -114;
    }
    else
    {
      mutex_unlock(&snd_event_mutex);
      if ( !a3 || a3 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(a1, "%s: Invalid clients ptr\n", "snd_event_master_register");
        return (unsigned int)-22;
      }
      v8 = (_QWORD *)_kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 40);
      if ( !v8 )
        return (unsigned int)-12;
      *v8 = a1;
      v8[1] = a2;
      v8[2] = a4;
      v9 = (__int64)v8;
      v8[4] = a3;
      mutex_lock(&snd_event_mutex);
      master = v9;
      clients = snd_event_find_clients(v9);
      v11 = 0;
      if ( !clients )
        *(_BYTE *)(master + 26) = 1;
    }
    mutex_unlock(&snd_event_mutex);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&snd_event_master_register__rs, "snd_event_master_register") )
      printk(&unk_6FE7, "snd_event_master_register");
    return (unsigned int)-22;
  }
  return v11;
}
