__int64 __fastcall dp_get_fw_peer_stats(__int64 a1, char a2, unsigned int *a3, char a4, int a5)
{
  __int64 v5; // x19
  unsigned int v6; // w20
  int v7; // w22
  unsigned int v8; // w21

  if ( a2 )
    return 16;
  v5 = *(_QWORD *)(a1 + 72);
  if ( !v5 )
    return 16;
  v6 = *a3;
  v7 = 1 << (a4 + 1);
  v8 = *((unsigned __int16 *)a3 + 2);
  if ( a5 )
  {
    qdf_event_reset(v5 + 95248);
    ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD, __int64, _BYTE))dp_h2t_ext_stats_msg_send)(
      v5,
      11,
      v7 | 1u,
      0x7FFFFFFF,
      v6,
      v8,
      0,
      8,
      0);
    qdf_wait_single_event(v5 + 95248, 0x1388u);
  }
  else
  {
    ((void (__fastcall *)(_QWORD, __int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _BYTE))dp_h2t_ext_stats_msg_send)(
      *(_QWORD *)(a1 + 72),
      11,
      v7 | 1u,
      0x7FFFFFFF,
      v6,
      *((unsigned __int16 *)a3 + 2),
      0,
      0,
      0);
  }
  return 0;
}
