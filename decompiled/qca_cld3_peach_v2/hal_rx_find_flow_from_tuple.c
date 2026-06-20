__int64 __fastcall hal_rx_find_flow_from_tuple(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned int a3,
        const void *a4,
        unsigned int *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v14; // w8
  unsigned int i; // w21
  __int64 v20; // x26
  unsigned int v21; // w25
  _DWORD *v22; // x9
  int v23; // w0
  __int64 result; // x0
  __int64 v25; // [xsp+0h] [xbp-30h] BYREF
  __int64 v26; // [xsp+8h] [xbp-28h]
  __int64 v27; // [xsp+10h] [xbp-20h]
  __int64 v28; // [xsp+18h] [xbp-18h]
  __int64 v29; // [xsp+20h] [xbp-10h]
  __int64 v30; // [xsp+28h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a2[13];
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v25 = 0;
  if ( !v14 )
  {
LABEL_15:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Max skid length reached for hash %u",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "hal_rx_find_flow_from_tuple",
      a3,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30);
    result = 46;
    goto LABEL_17;
  }
  for ( i = 0; i < v14; ++i )
  {
    v21 = a3 + i;
    if ( a3 + i >= a2[12] )
      v21 &= a2[14];
    v22 = *(_DWORD **)(*(_QWORD *)(a1 + 74392) + 1040LL);
    if ( !v22 )
    {
      v20 = 0;
      continue;
    }
    if ( *(v22 - 1) != 2046309326 )
      __break(0x8229u);
    v20 = ((__int64 (__fastcall *)(unsigned __int16 *, _QWORD, __int64 *))v22)(a2, v21, &v25);
    if ( !v20 )
    {
      v14 = a2[13];
      continue;
    }
    v23 = qdf_mem_cmp(&v25, a4, 0x28u);
    v14 = a2[13];
    if ( !v23 )
      break;
  }
  if ( i == v14 )
    goto LABEL_15;
  *a5 = v21;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: flow_hash = %u, skid_entry = %d, flow_addr = %pK flow_idx = %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "hal_rx_find_flow_from_tuple",
    a3,
    i,
    v20,
    v21,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30);
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
