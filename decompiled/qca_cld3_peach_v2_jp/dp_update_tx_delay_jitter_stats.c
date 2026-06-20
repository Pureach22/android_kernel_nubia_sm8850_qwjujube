__int64 __fastcall dp_update_tx_delay_jitter_stats(__int64 a1, unsigned __int8 a2, unsigned __int8 a3)
{
  __int64 v3; // x8
  int v4; // w9
  int v5; // w10
  __int64 v6; // x1

  if ( a2 > 9u || a3 >= 5u )
  {
    __break(0x5512u);
    return dp_update_no_ack_stats();
  }
  else
  {
    v3 = a1 + 6768LL * a3 + 752LL * a2;
    v4 = *(_DWORD *)(v3 + 9096);
    v5 = v4 - *(_DWORD *)(v3 + 9100);
    *(_DWORD *)(v3 + 9100) = v4;
    if ( v5 >= 0 )
      v6 = (unsigned int)v5;
    else
      v6 = (unsigned int)-v5;
    return ((__int64 (__fastcall *)(__int64, __int64))dp_update_jitter_stats)(v3 + 8584, v6);
  }
}
