__int64 __fastcall dp_nud_capture_stats(__int64 result, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x11

  v2 = result;
  v3 = 3488;
  v4 = 3492;
  v5 = 3484;
  if ( a2 != 1 && a2 != 5 )
  {
    if ( a2 != 6 )
      return result;
    v3 = 3500;
    v4 = 3504;
    v5 = 3496;
  }
  v6 = *(_QWORD *)(result + 2888);
  *(_DWORD *)(result + v5) = *(_QWORD *)(result + 2896);
  *(_DWORD *)(result + v4) = v6;
  result = dp_txrx_get_tx_ack_count(result);
  *(_DWORD *)(v2 + v3) = result;
  return result;
}
