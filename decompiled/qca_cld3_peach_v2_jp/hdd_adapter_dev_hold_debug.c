__int64 __usercall hdd_adapter_dev_hold_debug@<X0>(
        __int64 result@<X0>,
        unsigned int a2@<W1>,
        unsigned int *_X8@<X8>,
        double a4@<D0>,
        double a5@<D1>,
        double a6@<D2>,
        double a7@<D3>,
        double a8@<D4>,
        double a9@<D5>,
        double a10@<D6>,
        double a11@<D7>)
{
  __int64 v12; // x20
  __int64 v13; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x9
  unsigned int *v16; // x9
  unsigned int v17; // w12
  __int64 v18; // x9
  unsigned int v24; // w9

  v12 = result;
  if ( a2 >= 0x44 )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Invalid debug id: %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "hdd_adapter_dev_hold_debug",
               a2);
  v13 = *(_QWORD *)(v12 + 32);
  if ( v13 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v15 = *(_QWORD *)(v13 + 1320);
    v16 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v15);
    do
      v17 = __ldxr(v16);
    while ( __stxr(v17 + 1, v16) );
    v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v18;
    if ( !v18 || (_X8 = *(unsigned int **)(StatusReg + 16)) == nullptr )
    {
      result = preempt_schedule_notrace(result);
      if ( a2 < 0x45 )
        goto LABEL_9;
LABEL_11:
      __break(0x5512u);
      goto LABEL_12;
    }
  }
  if ( a2 >= 0x45 )
    goto LABEL_11;
LABEL_9:
  _X8 = (unsigned int *)(v12 + 4LL * a2 + 52524);
LABEL_12:
  __asm { PRFM            #0x11, [X8] }
  do
    v24 = __ldxr(_X8);
  while ( __stxr(v24 + 1, _X8) );
  return result;
}
