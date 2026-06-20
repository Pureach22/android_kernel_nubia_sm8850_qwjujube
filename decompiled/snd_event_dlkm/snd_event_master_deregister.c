__int64 __fastcall snd_event_master_deregister(__int64 a1)
{
  __int64 v2; // x8
  unsigned int v3; // w19
  int v4; // w9
  unsigned int v5; // w0

  if ( a1 )
  {
    mutex_lock(&snd_event_mutex);
    v2 = master;
    if ( master )
    {
      if ( *(_QWORD *)master == a1 )
      {
        v4 = *(unsigned __int8 *)(master + 26);
        v3 = 0;
        *(_BYTE *)(master + 24) = 0;
        if ( v4 == 1 )
        {
          v5 = check_and_update_fwk_state();
          v2 = master;
          v3 = v5;
        }
        kfree(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 8LL));
        kfree(*(_QWORD *)(master + 32));
        kfree(master);
        master = 0;
      }
      else
      {
        v3 = -6;
      }
    }
    else
    {
      v3 = -19;
    }
    mutex_unlock(&snd_event_mutex);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&snd_event_master_deregister__rs, "snd_event_master_deregister") )
      printk(&unk_6FE7, "snd_event_master_deregister");
    return (unsigned int)-22;
  }
  return v3;
}
