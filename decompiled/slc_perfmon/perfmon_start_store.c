__int64 __fastcall perfmon_start_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x22
  __int64 v8; // x1
  char v9; // w8
  __int64 v10; // x0
  _DWORD **v11; // x9
  _DWORD *v12; // x9
  int v13; // w0
  int v14; // w8
  __int64 v15; // x20
  __int64 v17; // x0
  _BYTE v18[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v19[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 152);
  v19[0] = 0;
  v18[0] = 0;
  mutex_lock(v7 + 136);
  if ( (*(_BYTE *)(v7 + 132) & 1) == 0 )
  {
    dev_err(a1, "PERF_STRT_ERR: PERFMON is not configured.\n");
LABEL_17:
    a4 = -22;
    goto LABEL_18;
  }
  if ( !*(_DWORD *)(v7 + 40) )
  {
    dev_err(a1, "PERF_STRT_ERR: Timer is not configured.\n");
    goto LABEL_17;
  }
  if ( (unsigned int)kstrtou8(a3, 0, v19) )
  {
    dev_err(a1, "PERF_STRT_ERR: Invalid start configuration, try again.\n");
    goto LABEL_17;
  }
  v9 = v19[0];
  if ( v19[0] >= 2u )
  {
    dev_err(a1, "PERF_STRT_ERR: Incorrect start configuration, try again.\n");
    goto LABEL_17;
  }
  if ( v19[0] )
  {
    v17 = *(_QWORD *)(v7 + 104);
    if ( v17 && (*(_BYTE *)v7 & 1) == 0 )
    {
      if ( (unsigned int)clk_prepare_enable(v17, v8) )
      {
        dev_err(a1, "PERF_STRT_ERR: clock not enabled.\n");
        goto LABEL_17;
      }
      *(_BYTE *)v7 = 1;
    }
    dev_info(a1, "%u Counters are configured, PERFMON started.\n", *(unsigned __int8 *)(v7 + 133));
    v9 = v19[0];
  }
  v10 = *(_QWORD *)(v7 + 88);
  v11 = *(_DWORD ***)(v7 + 96);
  v18[0] = v9;
  v12 = *v11;
  if ( *(v12 - 1) != 1737159351 )
    __break(0x8229u);
  v13 = ((__int64 (__fastcall *)(__int64, _BYTE *, __int64, __int64, __int64))v12)(v10, v18, 0x534C432D50455246LL, 3, 1);
  if ( v13 )
  {
    dev_err(a1, "Send SCMI: attr %d err: %d, %s\n", 3, v13, "remove and try again.");
    goto LABEL_17;
  }
  v14 = v19[0];
  *(_BYTE *)(v7 + 131) = v19[0] != 0;
  if ( !v14 )
  {
    v15 = *(_QWORD *)(v7 + 104);
    if ( v15 )
    {
      if ( *(_BYTE *)v7 == 1 )
      {
        clk_disable(*(_QWORD *)(v7 + 104));
        clk_unprepare(v15);
        *(_BYTE *)v7 = 0;
      }
    }
  }
LABEL_18:
  mutex_unlock(v7 + 136);
  _ReadStatusReg(SP_EL0);
  return a4;
}
