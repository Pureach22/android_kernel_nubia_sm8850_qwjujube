__int64 __fastcall snd_event_find_clients(__int64 a1)
{
  _QWORD *v1; // x22
  __int64 v2; // x8
  int v3; // w23
  _QWORD *v4; // x26
  _QWORD *v5; // x27
  __int64 v6; // x1
  unsigned int (__fastcall *v7)(__int64, __int64); // x8
  __int64 v8; // x0

  v1 = *(_QWORD **)(a1 + 32);
  if ( !*v1 )
    return 0;
  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = (_QWORD *)(v1[1] + 32 * v2);
    if ( !*v4 )
      break;
    if ( (unsigned int)__ratelimit(&snd_event_find_clients__rs, "snd_event_find_clients") )
      printk(&unk_6FC1, "snd_event_find_clients");
LABEL_5:
    v2 = ++v3;
    if ( *v1 <= (unsigned __int64)v3 )
      return 0;
  }
  v5 = snd_event_client_list;
  if ( snd_event_client_list != (_UNKNOWN *)&snd_event_client_list )
  {
    while ( 1 )
    {
      if ( (v5[5] & 1) == 0 )
      {
        v6 = v4[2];
        v7 = (unsigned int (__fastcall *)(__int64, __int64))v4[3];
        v8 = v5[2];
        if ( *((_DWORD *)v7 - 1) != 848979900 )
          __break(0x8228u);
        if ( v7(v8, v6) )
          break;
      }
      v5 = (_QWORD *)*v5;
      if ( v5 == &snd_event_client_list )
        goto LABEL_15;
    }
    *v4 = v5[2];
    v4[1] = v5;
    *((_BYTE *)v5 + 40) = 1;
LABEL_15:
    if ( *v4 )
      goto LABEL_5;
  }
  return 4294967290LL;
}
