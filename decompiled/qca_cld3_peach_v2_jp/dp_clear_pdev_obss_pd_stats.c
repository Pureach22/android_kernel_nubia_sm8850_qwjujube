__int64 __fastcall dp_clear_pdev_obss_pd_stats(__int64 a1, char a2, __int64 a3)
{
  __int64 v3; // x0
  __int64 v4; // x4
  __int64 v5; // x5
  char v6; // w10

  if ( a2 )
    return 4;
  v3 = *(_QWORD *)(a1 + 72);
  if ( !v3 )
    return 4;
  v4 = *(unsigned int *)(a3 + 12);
  v5 = *(unsigned int *)(a3 + 16);
  v6 = *(_BYTE *)(a3 + 24);
  *(_QWORD *)a3 = 0x1700000000LL;
  *(_DWORD *)(a3 + 8) = 1;
  return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64, __int64, _QWORD, _QWORD, char))dp_h2t_ext_stats_msg_send)(
           v3,
           0,
           23,
           1,
           v4,
           v5,
           0,
           0,
           v6);
}
