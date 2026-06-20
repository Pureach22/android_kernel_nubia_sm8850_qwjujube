__int64 __fastcall icnss_hw_power_on(_QWORD *a1)
{
  __int64 *v2; // x24
  __int64 *i; // x20
  unsigned __int64 v4; // x8
  unsigned int v5; // w0
  unsigned int v6; // w26
  unsigned __int64 v7; // x8
  __int64 *v8; // x25
  __int64 *v9; // x27
  unsigned __int64 v10; // x8
  const char *v11; // x2
  int v12; // w0
  __int64 v13; // x22
  unsigned int v14; // w0
  unsigned int v15; // w0
  int v17; // w21
  __int64 j; // x27
  __int64 v19; // x22
  unsigned __int64 v20; // x8
  const char *v21; // x2
  __int64 *k; // x20
  unsigned __int64 v23; // x8
  unsigned __int64 v30; // x9
  unsigned __int64 v33; // x10

  ipc_log_string(icnss_ipc_log_context, "HW Power on: state: 0x%lx\n", a1[229]);
  raw_spin_lock(a1 + 269);
  if ( (a1[229] & 2) != 0 )
  {
    raw_spin_unlock(a1 + 269);
    return 0;
  }
  _X8 = a1 + 229;
  __asm { PRFM            #0x11, [X8] }
  do
    v30 = __ldxr(_X8);
  while ( __stxr(v30 | 2, _X8) );
  raw_spin_unlock(a1 + 269);
  v2 = a1 + 27;
  for ( i = (__int64 *)a1[27]; i != v2; i = (__int64 *)*i )
  {
    v4 = i[2];
    if ( v4 )
    {
      if ( v4 <= 0xFFFFFFFFFFFFF000LL && *((_BYTE *)i + 53) == 1 )
      {
        v5 = icnss_vreg_on_single(i);
        if ( v5 )
        {
          v6 = v5;
          while ( 1 )
          {
            i = (__int64 *)i[1];
            if ( i == v2 )
              break;
            v7 = i[2];
            if ( v7 && v7 <= 0xFFFFFFFFFFFFF000LL )
            {
              if ( *((_DWORD *)i + 14) )
                icnss_vreg_off_single(i);
            }
          }
          printk("%sFailed to turn on vreg, err = %d\n", byte_130B32, v6);
          ipc_log_string(icnss_ipc_log_context, "%sFailed to turn on vreg, err = %d\n", (const char *)&unk_12DBF3, v6);
          goto LABEL_31;
        }
      }
    }
  }
  v8 = a1 + 29;
  v9 = (__int64 *)a1[29];
  if ( v9 == a1 + 29 )
    return 0;
  while ( 1 )
  {
    v10 = v9[2];
    if ( !v10 || v10 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_19;
    v11 = (const char *)v9[3];
    if ( !*((_DWORD *)v9 + 10) )
      break;
    ipc_log_string(icnss_ipc_log_context, "Clock %s is already enabled\n", v11);
LABEL_19:
    v9 = (__int64 *)*v9;
    if ( v9 == v8 )
      return 0;
  }
  ipc_log_string(icnss_ipc_log_context, "Clock %s is being enabled\n", v11);
  if ( !*((_DWORD *)v9 + 8) || (v12 = clk_set_rate(v9[2])) == 0 )
  {
    v13 = v9[2];
    v14 = clk_prepare(v13);
    if ( v14 )
    {
      v6 = v14;
    }
    else
    {
      v15 = clk_enable(v13);
      if ( !v15 )
      {
        *((_DWORD *)v9 + 10) = 1;
        goto LABEL_19;
      }
      v6 = v15;
      clk_unprepare(v13);
    }
    printk("%sFailed to enable clock %s, err = %d\n", byte_130B32, (const char *)v9[3], v6);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sFailed to enable clock %s, err = %d\n",
      (const char *)&unk_12DBF3,
      (const char *)v9[3],
      v6);
    goto LABEL_36;
  }
  v17 = v12;
  printk(
    "%sFailed to set frequency %u for clock %s, err = %d\n",
    byte_130B32,
    *((_DWORD *)v9 + 8),
    (const char *)v9[3],
    v12);
  v6 = v17;
  ipc_log_string(
    icnss_ipc_log_context,
    "%sFailed to set frequency %u for clock %s, err = %d\n",
    (const char *)&unk_12DBF3,
    *((_DWORD *)v9 + 8),
    (const char *)v9[3],
    v17);
LABEL_36:
  for ( j = v9[1]; (__int64 *)j != v8; j = *(_QWORD *)(j + 8) )
  {
    v20 = *(_QWORD *)(j + 16);
    if ( v20 && v20 <= 0xFFFFFFFFFFFFF000LL )
    {
      v21 = *(const char **)(j + 24);
      if ( *(_DWORD *)(j + 40) )
      {
        ipc_log_string(icnss_ipc_log_context, "Clock %s is being disabled\n", v21);
        v19 = *(_QWORD *)(j + 16);
        clk_disable(v19);
        clk_unprepare(v19);
        *(_DWORD *)(j + 40) = 0;
      }
      else
      {
        ipc_log_string(icnss_ipc_log_context, "Clock %s is already disabled\n", v21);
      }
    }
  }
  for ( k = (__int64 *)a1[28]; k != v2; k = (__int64 *)k[1] )
  {
    v23 = k[2];
    if ( v23 && v23 <= 0xFFFFFFFFFFFFF000LL )
      icnss_vreg_off_single(k);
  }
LABEL_31:
  _X8 = a1 + 229;
  __asm { PRFM            #0x11, [X8] }
  do
    v33 = __ldxr(_X8);
  while ( __stxr(v33 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  return v6;
}
