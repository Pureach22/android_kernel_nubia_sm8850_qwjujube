__int64 __fastcall hif_napi_schedule(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  unsigned int v11; // w20
  __int64 v12; // x8
  __int64 v14; // x19
  unsigned int v17; // w10
  unsigned int v24; // w10

  if ( a2 >= 0xC )
    goto LABEL_12;
  v10 = *(_QWORD *)(a1 + 8LL * a2 + 784);
  if ( !v10 )
  {
    v14 = a1;
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: scheduling unallocated napi (ce:%d)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hif_napi_schedule",
      a2);
    _X8 = (unsigned int *)(v14 + 672);
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 - 1, _X8) );
    return 0;
  }
  v11 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
  v12 = *(_QWORD *)(v10 + 2712);
  if ( (v12 & 1) != 0 )
  {
LABEL_13:
    _X8 = (unsigned int *)(a1 + 672);
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 - 1, _X8) );
    return 0;
  }
  a1 = hif_record_ce_desc_event(a1, a2, 23, 0, 0, 0, v12);
  if ( v11 > 0x1F )
  {
LABEL_12:
    __break(0x5512u);
    goto LABEL_13;
  }
  ++*(_DWORD *)(v10 + 72LL * v11 + 3144);
  if ( (napi_schedule_prep(v10 + 2696) & 1) != 0 )
    _napi_schedule(v10 + 2696);
  return 1;
}
