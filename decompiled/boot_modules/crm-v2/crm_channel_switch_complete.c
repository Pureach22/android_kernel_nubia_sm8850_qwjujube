__int64 __fastcall crm_channel_switch_complete(__int64 a1, int a2)
{
  __int64 v3; // x21
  int v5; // w22
  int v6; // w8
  int v7; // w23
  __int64 v8; // x24
  unsigned int v10; // w21

  v3 = 1LL << a2;
  if ( a2 )
    v5 = 2;
  else
    v5 = 1;
  v6 = -99;
  do
  {
    v7 = v6;
    v8 = (unsigned int)readl_relaxed(
                         *(_QWORD *)(a1 + 24)
                       + (unsigned int)(**(_DWORD **)(a1 + 40)
                                      + *(_DWORD *)(*(_QWORD *)(a1 + 40) + 12LL) * *(_DWORD *)(a1 + 32)))
       & v5;
    _const_udelay(429500);
    v6 = v7 + 1;
  }
  while ( v3 != v8 && v7 != 0 );
  if ( v7 )
    v10 = 0;
  else
    v10 = -16;
  ipc_log_string(*(_QWORD *)(a1 + 184), "Switch Channel: ch: %u ret: %d", a2, v10);
  return v10;
}
