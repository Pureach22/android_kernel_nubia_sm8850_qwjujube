__int64 __fastcall dp_txrx_post_data_stall_event(
        __int64 a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        int a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x24
  __int64 (__fastcall *v20)(_QWORD); // x8
  __int64 result; // x0
  const char *v22; // x2
  _DWORD v23[5]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_BYTE)a4 || (v14 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    v22 = "%s: pdev NULL!";
LABEL_9:
    result = qdf_trace_msg(0x45u, 2u, v22, a7, a8, a9, a10, a11, a12, a13, a14, "dp_txrx_post_data_stall_event");
    goto LABEL_10;
  }
  if ( !*(_QWORD *)(v14 + 96344) )
  {
    v22 = "%s: data stall cb not registered!";
    goto LABEL_9;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: data_stall_type: %x pdev_id: %d",
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    "dp_txrx_post_data_stall_event",
    a3,
    a4);
  v20 = *(__int64 (__fastcall **)(_QWORD))(v14 + 96344);
  v23[0] = a2;
  v23[1] = a3;
  v23[2] = a5;
  v23[3] = a4;
  v23[4] = a6;
  if ( *((_DWORD *)v20 - 1) != 2104101083 )
    __break(0x8228u);
  result = v20(v23);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
