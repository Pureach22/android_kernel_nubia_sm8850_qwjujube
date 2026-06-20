__int64 __fastcall dp_get_htt_stats(__int64 a1, char a2, unsigned int *a3)
{
  __int64 v3; // x0

  if ( a2 )
    return 16;
  v3 = *(_QWORD *)(a1 + 72);
  if ( !v3 )
    return 16;
  ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _BYTE))dp_h2t_ext_stats_msg_send)(
    v3,
    *((unsigned __int8 *)a3 + 20),
    *a3,
    a3[1],
    a3[2],
    a3[3],
    a3[4],
    0,
    0);
  return 0;
}
