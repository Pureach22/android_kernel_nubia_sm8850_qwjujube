__int64 __fastcall icnss_fw_crashed(__int64 a1, __int64 a2)
{
  __int64 v4; // x2
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x2
  __int64 v8; // x8
  __int64 v9; // x10
  _DWORD *v10; // x8
  unsigned __int64 v17; // x9
  unsigned int v20; // w8
  unsigned int v21; // w8
  unsigned __int64 v24; // x10
  char v25; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v26[3]; // [xsp+8h] [xbp-18h] BYREF

  v26[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 1832);
  v25 = 0;
  result = ipc_log_string(icnss_ipc_log_context, "icnss2: FW crashed, state: 0x%lx\n", v4);
  _X8 = (unsigned __int64 *)(a1 + 1832);
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stxr(v17 | 0x200, _X8) );
  _X9 = (unsigned int *)(a1 + 2920);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v20 = __ldxr(_X9);
    v21 = v20 + 1;
  }
  while ( __stlxr(v21, _X9) );
  __dmb(0xBu);
  if ( v21 == 1 )
  {
    ipc_log_string(
      icnss_ipc_log_long_context,
      "icnss2: PM stay awake, state: 0x%lx, count: %d\n",
      *(_QWORD *)(a1 + 1832),
      *(_DWORD *)(a1 + 2920));
    result = pm_stay_awake(*(_QWORD *)(a1 + 8) + 16LL);
    ++*(_DWORD *)(a1 + 2556);
  }
  if ( (*(_QWORD *)(a1 + 1832) & 8) != 0 && (*(_QWORD *)(a1 + 1832) & 4) != 0 )
  {
    _X8 = (unsigned __int64 *)(a1 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    v6 = *(_QWORD *)(a1 + 16);
    v25 = 1;
    if ( v6 )
    {
      if ( *(_QWORD *)(v6 + 288) )
      {
        v7 = *(_QWORD *)(a1 + 1832);
        v26[0] = 1;
        ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n", v7, 1);
        v9 = *(_QWORD *)(a1 + 8);
        v8 = *(_QWORD *)(a1 + 16);
        v26[1] = &v25;
        v10 = *(_DWORD **)(v8 + 288);
        if ( *(v10 - 1) != -712363570 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD *))v10)(v9 + 16, v26);
      }
    }
  }
  if ( a2 && *(_BYTE *)(a2 + 1) == 1 )
    result = wlfw_rejuvenate_ack_send_sync_msg(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
