_QWORD *__fastcall wma_mgmt_pktdump_rx_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  int v17; // w23
  _QWORD *result; // x0
  _DWORD *v19; // x8
  __int64 v20; // x3
  __int64 v21; // x2
  __int64 v22; // x1

  v17 = a4;
  result = _cds_get_context(71, (__int64)"wma_mgmt_pktdump_rx_handler", a6, a7, a8, a9, a10, a11, a12, a13);
  if ( !v17 && a5 != 128 )
  {
    v19 = *(_DWORD **)(a3 + 3792);
    if ( v19 )
    {
      v20 = *(_QWORD *)(a2 + 64);
      v21 = *(unsigned __int8 *)(a2 + 47);
      v22 = *(unsigned __int8 *)(a1 + 48);
      if ( *(v19 - 1) != -915278510 )
        __break(0x8228u);
      return (_QWORD *)((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64, __int64, __int64))v19)(
                         result,
                         v22,
                         v21,
                         v20,
                         1,
                         2);
    }
  }
  return result;
}
