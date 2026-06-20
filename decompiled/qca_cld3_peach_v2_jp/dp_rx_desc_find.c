__int64 __fastcall dp_rx_desc_find(unsigned __int16 a1, unsigned __int16 a2, __int64 a3)
{
  return *(_QWORD *)(*(_QWORD *)(a3 + 24) + 8LL * a1) + a2 * *(unsigned __int16 *)(a3 + 4);
}
