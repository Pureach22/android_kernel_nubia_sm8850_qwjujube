__int64 __fastcall qcom_glink_rx_done_supported(__int64 a1)
{
  if ( a1 )
    return (*(unsigned __int8 *)(*(_QWORD *)(a1 + 112) + 208LL) >> 3) & 1;
  __break(0x800u);
  return 1;
}
