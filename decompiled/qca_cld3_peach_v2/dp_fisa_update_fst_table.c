__int64 __fastcall dp_fisa_update_fst_table(
        __int64 result,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *v11; // x25
  __int64 v12; // x27
  __int64 v14; // x20
  int i; // w26
  unsigned __int16 *v17; // x22
  unsigned int v18; // w24
  __int64 v19; // x28
  char v20; // w5
  __int64 v21; // x4
  unsigned int v22; // w8
  int v23; // w3
  __int64 v24; // x19
  unsigned int v31; // w8
  unsigned int v32; // w8

  v11 = *(__int64 **)(result + 1480);
  if ( a3 )
  {
    v12 = *v11;
    v14 = result;
    for ( i = 0; i != a3; ++i )
    {
      v17 = (unsigned __int16 *)(a2 + 4LL * i);
      v18 = *v17;
      v19 = v12 + 336LL * *v17;
      v20 = *(_BYTE *)(v19 + 144);
      *(_BYTE *)(v19 + 146) = 1;
      v21 = *(unsigned int *)(v19 + 16);
      *(_BYTE *)(v19 + 145) = v20;
      *(_BYTE *)(v19 + 144) = *((_BYTE *)v17 + 2);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: moving flow %d from napi_id%d to napi_id%d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "dp_fisa_update_fst_table",
        v21);
      v22 = *((unsigned __int8 *)v17 + 2);
      if ( v22 <= 3 )
        v23 = v22 | 0x10;
      else
        v23 = v22 + 15;
      *(_DWORD *)(v19 + 244) = v23;
      result = hal_rx_flow_cmem_update_reo_dst_ind_0(*(_QWORD *)(v14 + 256), *((unsigned int *)v11 + 109), v18);
    }
  }
  if ( *((_BYTE *)v11 + 152) == 1 )
  {
    _X9 = (unsigned int *)(v11 + 11);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v31 = __ldxr(_X9);
      v32 = v31 + 1;
    }
    while ( __stlxr(v32, _X9) );
    __dmb(0xBu);
    if ( v32 == 1 )
    {
      v24 = jiffies;
      v11[14] = v24 + 2LL * (unsigned int)qdf_timer_get_multiplier();
      return add_timer(v11 + 12);
    }
  }
  return result;
}
