__int64 __fastcall sde_core_irq_callback_handler(_QWORD *a1, int a2)
{
  const char *v4; // x22
  _QWORD *v5; // x23
  _QWORD *v6; // x24
  int v7; // w21
  _QWORD *v9; // x26
  _QWORD *v10; // x9
  _DWORD *v11; // x9
  __int64 v12; // x0
  __int64 v13; // x8
  int v14; // w7
  __int64 result; // x0
  __int64 (*v16)(void); // x8
  unsigned int v22; // w9
  char vars0; // [xsp+0h] [xbp+0h]

  v4 = (const char *)raw_spin_lock_irqsave(a1 + 242);
  v5 = (_QWORD *)(a1[239] + 16LL * a2);
  v6 = (_QWORD *)*v5;
  if ( (_QWORD *)*v5 == v5 )
    v7 = *(_DWORD *)(a1[240] + 4LL * a2);
  else
    v7 = 0;
  _X8 = a1[241] + 4LL * a2;
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr((unsigned int *)_X8);
    while ( __stxr(v22 + 1, (unsigned int *)_X8) );
    v13 = a1[239];
    v10 = (_QWORD *)(v13 + 16LL * a2);
    v9 = (_QWORD *)*v10;
    while ( v9 != v10 )
    {
      v11 = (_DWORD *)v9[2];
      if ( v11 )
      {
        v12 = v9[3];
        if ( *(v11 - 1) != 1607364836 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v11)(v12, (unsigned int)a2);
        v13 = a1[239];
      }
      v9 = (_QWORD *)*v9;
      v10 = (_QWORD *)(v13 + 16LL * a2);
    }
    raw_spin_unlock_irqrestore(a1 + 242, v4);
    if ( v6 == v5 )
    {
      if ( v7 )
      {
        v4 = "sde_core_irq_callback_handler";
        printk(&unk_24CAA1, "sde_core_irq_callback_handler");
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_core_irq_callback_handler", 66, 2, a2, v7, 60333, -1059143953, vars0);
      }
      else
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "irq has no callback, idx %d enables %d\n", a2, 0);
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_core_irq_callback_handler", 62, 2, a2, 0, -1059143953, v14, vars0);
      }
    }
    result = a1[237];
    _X8 = *(unsigned int *)(result + 28);
    if ( (unsigned int)_X8 < 3 )
      break;
    __break(0x5512u);
  }
  v16 = *(__int64 (**)(void))(result + 8 * _X8 + 200);
  if ( v16 )
  {
    if ( *((_DWORD *)v16 - 1) != 267728445 )
      __break(0x8228u);
    return v16();
  }
  return result;
}
