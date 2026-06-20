__int64 __fastcall snd_event_notify(__int64 a1, int a2)
{
  _QWORD *v4; // x9
  __int64 v5; // x8
  unsigned int v6; // w19

  if ( a1 )
  {
    mutex_lock(&snd_event_mutex);
    v4 = snd_event_client_list;
    v5 = master;
    if ( snd_event_client_list == (_UNKNOWN *)&snd_event_client_list && !master )
    {
      if ( (unsigned int)__ratelimit(&snd_event_notify__rs_10, "snd_event_notify") )
        dev_err(a1, "%s: No device registered\n", "snd_event_notify");
      v6 = -19;
LABEL_26:
      mutex_unlock(&snd_event_mutex);
      return v6;
    }
    while ( 1 )
    {
      if ( v4 == &snd_event_client_list )
        goto LABEL_17;
      if ( v4[2] == a1 && v4[3] )
        break;
      v4 = (_QWORD *)*v4;
    }
    if ( v4 )
    {
      *((_BYTE *)v4 + 41) = a2 != 0;
      if ( !v5 )
      {
LABEL_25:
        v6 = 0;
        goto LABEL_26;
      }
    }
    else
    {
LABEL_17:
      if ( !master || *(_QWORD *)master != a1 )
      {
        if ( (unsigned int)__ratelimit(&snd_event_notify__rs_12, "snd_event_notify") )
          dev_err(a1, "%s: No snd dev entry found\n", "snd_event_notify");
        v6 = -6;
        goto LABEL_26;
      }
      *(_BYTE *)(master + 24) = a2 != 0;
    }
    if ( *(_BYTE *)(v5 + 26) == 1 )
    {
      v6 = check_and_update_fwk_state();
      goto LABEL_26;
    }
    goto LABEL_25;
  }
  if ( (unsigned int)__ratelimit(&snd_event_notify__rs, "snd_event_notify") )
    printk(&unk_6FE7, "snd_event_notify");
  return (unsigned int)-22;
}
