__int64 __fastcall perfmon_timer_configure_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x22
  __int64 v9; // x0
  __int64 (__fastcall **v10)(__int64, int *, __int64, __int64, __int64); // x9
  __int64 (__fastcall *v11)(__int64, int *, __int64, __int64, __int64); // x9
  int v12; // w0
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 152);
  v13 = 0;
  mutex_lock(v7 + 136);
  if ( (*(_BYTE *)(v7 + 132) & 1) != 0 )
  {
    if ( *(_BYTE *)(v7 + 131) == 1 )
    {
      dev_err(a1, "PERF_TMR_ERR: Can't configure timer while PERFMON is running.\n");
    }
    else if ( (unsigned int)kstrtouint(a3, 0, v7 + 40) )
    {
      dev_err(a1, "PERF_TMR_ERR: Invalid timer configuration.\n");
    }
    else if ( *(_DWORD *)(v7 + 40) )
    {
      v9 = *(_QWORD *)(v7 + 88);
      v10 = *(__int64 (__fastcall ***)(__int64, int *, __int64, __int64, __int64))(v7 + 96);
      v13 = *(_DWORD *)(v7 + 40);
      v11 = *v10;
      if ( *((_DWORD *)v11 - 1) != 1737159351 )
        __break(0x8229u);
      v12 = v11(v9, &v13, 0x534C432D50455246LL, 2, 4);
      if ( !v12 )
      {
        dev_info(a1, "Timer configured: %dms.\n", *(_DWORD *)(v7 + 40));
        goto LABEL_6;
      }
      dev_err(a1, "Send SCMI: attr %d err: %d, %s\n", 2, v12, "remove and try again.");
    }
    else
    {
      dev_err(a1, "PERF_TMR_ERR: Timer is not configured.\n");
    }
  }
  else
  {
    dev_err(a1, "PERF_TMR_ERR: PERFMON is not configured.\n");
  }
  a4 = -22;
LABEL_6:
  mutex_unlock(v7 + 136);
  _ReadStatusReg(SP_EL0);
  return a4;
}
