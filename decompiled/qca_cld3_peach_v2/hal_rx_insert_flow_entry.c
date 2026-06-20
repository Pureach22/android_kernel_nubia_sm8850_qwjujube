__int64 __fastcall hal_rx_insert_flow_entry(
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
  unsigned int v19; // w21
  unsigned int v20; // w22
  _DWORD *v21; // x9
  __int64 v22; // x26
  __int64 result; // x0
  __int64 v24; // [xsp+0h] [xbp-30h] BYREF
  __int64 v25; // [xsp+8h] [xbp-28h]
  __int64 v26; // [xsp+10h] [xbp-20h]
  __int64 v27; // [xsp+18h] [xbp-18h]
  __int64 v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a2[13];
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v24 = 0;
  if ( v14 )
  {
    v19 = 0;
    while ( 1 )
    {
      v20 = a3 + v19;
      if ( a3 + v19 >= a2[12] )
        v20 &= a2[14];
      v21 = *(_DWORD **)(*(_QWORD *)(a1 + 74392) + 1040LL);
      if ( !v21 )
      {
        v22 = 0;
LABEL_13:
        if ( v19 == v14 )
          goto LABEL_14;
LABEL_16:
        *a5 = v20;
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
          "hal_rx_insert_flow_entry",
          a3,
          v19,
          v22,
          v20,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29);
        result = 0;
        goto LABEL_18;
      }
      if ( *(v21 - 1) != 2046309326 )
        __break(0x8229u);
      v22 = ((__int64 (__fastcall *)(unsigned __int16 *, _QWORD, __int64 *))v21)(a2, v20, &v24);
      if ( !v22 )
      {
        if ( v19 == a2[13] )
          goto LABEL_14;
        goto LABEL_16;
      }
      if ( !(unsigned int)qdf_mem_cmp(&v24, a4, 0x28u) )
        break;
      v14 = a2[13];
      if ( ++v19 >= v14 )
        goto LABEL_13;
    }
    *a5 = v20;
    result = 14;
  }
  else
  {
LABEL_14:
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
      "hal_rx_insert_flow_entry",
      a3,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29);
    result = 46;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
