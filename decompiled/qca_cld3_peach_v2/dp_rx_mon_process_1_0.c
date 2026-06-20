__int64 __fastcall dp_rx_mon_process_1_0(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 20112) + 257LL) & 1) == 0 )
    return (unsigned int)dp_rx_mon_status_process();
  return a4;
}
