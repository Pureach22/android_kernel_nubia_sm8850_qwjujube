__int64 __fastcall geni_i3c_master_i2c_xfers(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x24
  __int64 v6; // x20
  unsigned __int64 v7; // x19
  unsigned int command; // w20
  int mutex_lock; // w0
  __int64 v10; // x0
  unsigned __int64 v11; // x27
  unsigned __int16 *v12; // x23
  __int16 v13; // w8
  unsigned int v14; // w3
  __int64 v15; // x2
  __int64 v16; // x0
  int v17; // w9
  int v18; // w10
  int v19; // w9
  int v20; // w11
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x0
  char v25; // w8
  __int64 v26; // x21
  __int64 v27; // x0
  __int64 v28; // x21
  __int64 v29; // x0
  __int64 v31; // x0
  unsigned __int64 v32; // [xsp+0h] [xbp-20h] BYREF
  __int64 v33; // [xsp+8h] [xbp-18h]
  int v34; // [xsp+10h] [xbp-10h]
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 16);
  v6 = *(_QWORD *)(v5 + 2424);
  if ( v6 )
  {
    if ( *(_DWORD *)(v5 + 2432) )
    {
      v7 = sched_clock(a1);
      ipc_log_string(v6, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_i2c_xfers", v7, v7 / 0x3E8);
    }
    else
    {
      v7 = 0;
    }
  }
  else
  {
    v7 = -22;
  }
  ipc_log_string(*(_QWORD *)(v5 + 2416), "Enter %s num xfers=%d\n", "geni_i3c_master_i2c_xfers", a3);
  if ( *(_QWORD *)(v5 - 104) )
    i3c_trace_log();
  if ( a2 )
  {
    if ( (*(_BYTE *)(v5 + 21529) & 1) != 0 )
    {
      ::mutex_lock(v5 + 2504);
    }
    else
    {
      mutex_lock = i3c_geni_runtime_get_mutex_lock(v5 - 112);
      if ( mutex_lock )
      {
        command = mutex_lock;
        ipc_log_string(
          *(_QWORD *)(v5 + 2416),
          "%s: Failed:%d, usage_count:%d\n",
          "geni_i3c_master_i2c_xfers",
          mutex_lock,
          *(_DWORD *)(*(_QWORD *)(v5 - 104) + 480LL));
        v31 = *(_QWORD *)(v5 - 104);
        if ( v31 )
          dev_err(v31, "%s: Failed:%d, usage_count:%d\n", "geni_i3c_master_i2c_xfers", command, *(_DWORD *)(v31 + 480));
        else
          printk(&unk_137C1, "geni_i3c_master_i2c_xfers", command, (unsigned int)dword_1E0);
        if ( *(_QWORD *)(v5 - 104) )
          i3c_trace_log();
        goto LABEL_49;
      }
    }
    *(_BYTE *)(v5 + 21129) = 0;
    *(_BYTE *)(v5 + 21540) = 1;
    command = qcom_geni_i3c_conf(v5 - 112, 1);
    v10 = *(_QWORD *)(v5 + 2416);
    if ( command )
    {
      ipc_log_string(v10, "%s:geni i3c config failed, ret:%d\n", "geni_i3c_master_i2c_xfers", command);
      if ( *(_QWORD *)(v5 - 104) )
        i3c_trace_log();
      *(_BYTE *)(v5 + 21540) = 0;
    }
    else
    {
      ipc_log_string(
        v10,
        "i2c xfer:num:%d, msgs:len:%d,flg:%d\n",
        a3,
        *(unsigned __int16 *)(a2 + 4),
        *(unsigned __int16 *)(a2 + 2));
      if ( *(_QWORD *)(v5 - 104) )
        i3c_trace_log();
      *(_DWORD *)(v5 + 21172) = a3;
      if ( a3 >= 1 )
      {
        v11 = 0;
        v12 = (unsigned __int16 *)(a2 + 4);
        v34 = 0;
        v32 = 0;
        v33 = 0;
        do
        {
          v13 = *(v12 - 1);
          v14 = *v12;
          v15 = *(_QWORD *)(v12 + 2);
          v16 = v5 - 112;
          v17 = (*(v12 - 2) & 0x7F) << 9;
          v34 = v11;
          if ( (v13 & 1) != 0 )
            v18 = 2;
          else
            v18 = 1;
          v19 = v17 | (4 * (v11 < (unsigned int)(a3 - 1)));
          if ( v14 <= 0x20 )
            v20 = 1;
          else
            v20 = 2;
          v32 = __PAIR64__(v18, v20);
          LODWORD(v33) = v19;
          if ( (v13 & 1) != 0 )
          {
            command = i3c_geni_execute_read_command(v16, (__int64)&v32, v15, v14);
            if ( command )
              goto LABEL_35;
          }
          else
          {
            command = i3c_geni_execute_write_command(v16, (__int64)&v32, v15, v14);
            if ( command )
              goto LABEL_35;
          }
          ++v11;
          v12 += 8;
        }
        while ( a3 != v11 );
      }
      command = 0;
LABEL_35:
      if ( *(_DWORD *)(v5 - 4) == 3 )
        geni_i3c_gsi_stop_on_bus(v5 - 112);
      if ( *(_BYTE *)(v5 + 21529) == 1 && (*(_BYTE *)(v5 + 21538) & 1) == 0 )
        *(_BYTE *)(v5 + 21538) = 1;
      ipc_log_string(*(_QWORD *)(v5 + 2416), "i2c: txn ret:%d\n", command);
      v24 = *(_QWORD *)(v5 - 104);
      if ( v24 )
        i3c_trace_log();
      v25 = *(_BYTE *)(v5 + 21529);
      *(_BYTE *)(v5 + 21129) = 0;
      *(_BYTE *)(v5 + 21540) = 0;
      *(_DWORD *)(v5 + 21172) = 0;
      if ( (v25 & 1) == 0 )
      {
        v26 = *(_QWORD *)(v5 - 104);
        *(_QWORD *)(v26 + 520) = ktime_get_mono_fast_ns(v24, v21, v22, v23);
        _pm_runtime_suspend(*(_QWORD *)(v5 - 104), 13);
      }
      v27 = mutex_unlock(v5 + 2504);
      v28 = *(_QWORD *)(v5 + 2424);
      if ( v28 && v7 && *(_DWORD *)(v5 + 2432) )
      {
        v29 = sched_clock(v27);
        ipc_log_string(v28, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_master_i2c_xfers", v29 - v7, (v29 - v7) / 0x3E8);
      }
    }
  }
  else
  {
    ipc_log_string(*(_QWORD *)(v5 + 2416), "%s: client msg is NULL\n", "geni_i3c_master_i2c_xfers");
    if ( *(_QWORD *)(v5 - 104) )
      i3c_trace_log();
    command = 0;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return command;
}
