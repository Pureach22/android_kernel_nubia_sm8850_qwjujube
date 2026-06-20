bool __fastcall mhi_scan_rddm_cookie(__int64 a1, int a2)
{
  _BOOL4 v2; // w8
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x20
  __int64 v7; // x8

  v2 = 0;
  _ReadStatusReg(SP_EL0);
  if ( a2 && *(_QWORD *)(a1 + 160) )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v4 && !*(_DWORD *)(v4 + 24) )
    {
      v5 = a1;
      ipc_log_string(*(_QWORD *)(v4 + 32), "[D][%s] Checking BHI debug register for 0x%x\n", "mhi_scan_rddm_cookie", a2);
      a1 = v5;
    }
    if ( (*(_WORD *)(a1 + 336) & 0xFDE) != 0 && (v6 = a1, !(unsigned int)mhi_read_reg(a1)) )
    {
      v7 = *(_QWORD *)(*(_QWORD *)(v6 + 16) + 192LL);
      if ( v7 && !*(_DWORD *)(v7 + 24) )
        ipc_log_string(*(_QWORD *)(v7 + 32), "[D][%s] BHI_ERRDBG2 value:0x%x\n", "mhi_scan_rddm_cookie", 0);
      v2 = a2 == 0;
    }
    else
    {
      v2 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
