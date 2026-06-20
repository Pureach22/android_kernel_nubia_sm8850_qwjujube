__int64 __fastcall l23_rdy_poll_timeout_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  __int64 v6; // x4
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8[0] = 0;
  if ( (unsigned int)kstrtoull(a3, 0, v8) )
  {
    a4 = -22;
  }
  else
  {
    v6 = v8[0];
    *(_QWORD *)(v5 + 1560) = v8[0];
    if ( v5 )
    {
      ipc_log_string(
        *(_QWORD *)(v5 + 1704),
        "DBG1:%s: PCIe: RC%d: L23_Ready poll timeout: %llu\n",
        "l23_rdy_poll_timeout_store",
        *(_DWORD *)(v5 + 1348),
        v6);
      ipc_log_string(
        *(_QWORD *)(v5 + 1696),
        "%s: PCIe: RC%d: L23_Ready poll timeout: %llu\n",
        "l23_rdy_poll_timeout_store",
        *(_DWORD *)(v5 + 1348),
        *(_QWORD *)(v5 + 1560));
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
