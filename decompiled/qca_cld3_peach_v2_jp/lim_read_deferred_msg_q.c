__int64 __fastcall lim_read_deferred_msg_q(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  unsigned int v10; // w9
  unsigned __int16 v11; // w8
  __int64 v12; // x19
  __int16 v13; // w5
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v9 = a1 + 0x2000;
  if ( !*(_WORD *)(a1 + 8688) )
    return 0;
  v10 = *(unsigned __int16 *)(a1 + 8690);
  v11 = *(_WORD *)(a1 + 8688) - 1;
  *(_WORD *)(a1 + 8688) = v11;
  if ( v10 >= 0x51 )
  {
    __break(0x5512u);
    JUMPOUT(0x3C0708);
  }
  v12 = a1 + 4848 + 48LL * v10;
  if ( v10 <= 0x4E )
    v13 = v10 + 1;
  else
    v13 = 0;
  *(_WORD *)(a1 + 8690) = v13;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: DeQueue a deferred message size: %d read: %d - type: 0x%x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "lim_read_deferred_msg_q",
    v11);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: DQ msg -- global sme: %d global mlme: %d addts: %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "lim_read_deferred_msg_q",
    *(unsigned int *)(a1 + 4056),
    *(unsigned int *)(a1 + 4020),
    *(unsigned __int8 *)(v9 + 684));
  return v12;
}
