__int64 __fastcall sde_plane_danger_signal_ctrl(_BYTE *a1, char a2)
{
  __int64 v4; // x19
  unsigned int v5; // w0
  unsigned int v7; // w8
  unsigned int v8; // w20
  unsigned int v15; // w10
  int v16; // w7
  char v17; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    printk(&unk_26FEB0, "sde_plane_danger_signal_ctrl");
    return 4294967274LL;
  }
  if ( a1[2381] != 1 )
    return 0;
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 8LL);
  v5 = _pm_runtime_resume(v4, 4);
  if ( (v5 & 0x80000000) == 0 )
  {
    ((void (__fastcall *)(_BYTE *, _QWORD, __int64))sde_plane_set_qos_ctrl)(a1, a2 & 1, 4);
    _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)a1 + 8LL), 4);
    return 0;
  }
  v7 = *(_DWORD *)(v4 + 480);
  v8 = v5;
  do
  {
    if ( !v7 )
      break;
    _X12 = (unsigned int *)(v4 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v15 = __ldxr(_X12);
      if ( v15 != v7 )
        break;
      if ( !__stlxr(v7 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v15 == v7;
    v7 = v15;
  }
  while ( !_ZF );
  printk(&unk_24C43E, "sde_plane_danger_signal_ctrl");
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_plane_danger_signal_ctrl", 493, -1, v8, 60333, -1059143953, v16, v17);
  return v8;
}
