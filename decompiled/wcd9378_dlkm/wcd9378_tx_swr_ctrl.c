__int64 __fastcall wcd9378_tx_swr_ctrl(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v5; // x0

  v3 = *(_QWORD *)(a1 + 40);
  if ( a3 == 8 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL) + 64LL);
    return swr_slvdev_datapath_control(v5, *(unsigned __int8 *)(v5 + 64), 0);
  }
  else
  {
    if ( a3 == 1 )
      wcd9378_tx_connect_port(v3 - 208, *(unsigned __int8 *)(a1 + 76), 2400000, 1);
    return 0;
  }
}
