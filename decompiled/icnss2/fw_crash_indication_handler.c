__int64 __fastcall fw_crash_indication_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x2
  __int64 v5; // x8
  __int64 v6; // x10
  _DWORD *v7; // x8
  unsigned __int64 v15; // x9
  unsigned __int64 v18; // x10
  unsigned __int64 v21; // x10
  char v22; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v23[3]; // [xsp+8h] [xbp-18h] BYREF

  v23[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  printk("%sicnss2: Received early crash indication from FW\n", byte_130B32);
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: Received early crash indication from FW\n",
    (const char *)&unk_12DBF3);
  if ( a2 )
  {
    if ( *(_BYTE *)(a2 + 6096) == 1 )
      mod_timer(a2 + 6056, jiffies + 1250LL);
    _X8 = (unsigned __int64 *)(a2 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 | 0x2000, _X8) );
    icnss_ignore_fw_timeout(1);
    _X8 = (unsigned __int64 *)(a2 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 & 0xFFFFFFFFF7FFFFFFLL, _X8) );
    complete(a2 + 5808);
    if ( (*(_QWORD *)(a2 + 1832) & 4) != 0 )
    {
      _X8 = (unsigned __int64 *)(a2 + 1832);
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
      v3 = *(_QWORD *)(a2 + 16);
      v22 = 1;
      if ( v3 )
      {
        if ( *(_QWORD *)(v3 + 288) )
        {
          v4 = *(_QWORD *)(a2 + 1832);
          v23[0] = 1;
          ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n", v4, 1);
          v6 = *(_QWORD *)(a2 + 8);
          v5 = *(_QWORD *)(a2 + 16);
          v23[1] = &v22;
          v7 = *(_DWORD **)(v5 + 288);
          if ( *(v7 - 1) != -712363570 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD *))v7)(v6 + 16, v23);
        }
      }
    }
  }
  icnss_driver_event_post(a2, 6u, 0, 0);
  _ReadStatusReg(SP_EL0);
  return 1;
}
