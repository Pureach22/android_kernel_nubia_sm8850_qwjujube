__int64 __fastcall qti_qpt_sync_common_telemetry_config(_QWORD *a1)
{
  __int64 v1; // x8
  unsigned __int8 *v3; // x21
  __int64 v4; // x22
  int v5; // w20
  int v6; // w3
  unsigned int v7; // w4
  unsigned int v8; // w10
  unsigned int v9; // w5
  unsigned int v10; // w10
  int v11; // w6
  unsigned __int8 v12; // w8
  int v13; // w10
  int v14; // w8
  __int64 v15; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v17; // x0

  v1 = a1[1];
  if ( *(_QWORD *)(v1 + 296) && *(_QWORD *)(v1 + 8) )
  {
    v3 = (unsigned __int8 *)a1[12];
    if ( v3 )
    {
      *(_DWORD *)(v3 + 71) = 0;
      *((_QWORD *)v3 + 7) = 0;
      *((_QWORD *)v3 + 8) = 0;
      *((_QWORD *)v3 + 5) = 0;
      *((_QWORD *)v3 + 6) = 0;
      *((_QWORD *)v3 + 3) = 0;
      *((_QWORD *)v3 + 4) = 0;
      *((_QWORD *)v3 + 1) = 0;
      *((_QWORD *)v3 + 2) = 0;
      *(_QWORD *)v3 = 0;
    }
    else
    {
      v3 = (unsigned __int8 *)devm_kmalloc(*a1, 75, 3520);
      if ( !v3 )
        return 4294967284LL;
    }
    mutex_lock(a1 + 25);
    v4 = a1[1];
    mutex_lock(v4 + 16);
    v5 = nvmem_device_read(*(_QWORD *)(v4 + 8), 69, 75, v3);
    mutex_unlock(v4 + 16);
    if ( v5 < 0 )
    {
      dev_err(*a1, "Failed to read sdam[%d] off:%#x,size:%ld rc=%d\n", *(_DWORD *)v4, 69, 75, v5);
    }
    else
    {
      v6 = *v3;
      *((_BYTE *)a1 + 82) = v6;
      v7 = v3[1];
      *((_BYTE *)a1 + 83) = v7;
      *((_BYTE *)a1 + 84) = v3[2];
      if ( (v3[6] & 8) != 0 )
        v8 = 10;
      else
        v8 = 32000;
      qpt_update_interval_ms = 1000 * v6 * (unsigned int)*((unsigned __int16 *)v3 + 2) / v8;
      v9 = qpt_update_interval_ms / v7;
      if ( (v3[6] & 8) != 0 )
        v10 = 10;
      else
        v10 = 32000;
      v11 = 1000 * (*((unsigned __int16 *)v3 + 2) << v3[7]) / v10;
      *((_DWORD *)a1 + 31) = v11;
      *((_DWORD *)a1 + 32) = v9;
      v12 = v3[6];
      v13 = v3[3];
      a1[12] = v3;
      v14 = 400 << (v12 & 7);
      if ( v13 )
        v14 = 6400;
      *((_DWORD *)a1 + 30) = v14;
      if ( a1 )
      {
        v15 = a1[14];
        if ( v15 )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          ipc_log_string(
            v15,
            "[%s] ready_cnt:%d bob count:%d b_tperiod:%d tperiod:%d\n",
            (const char *)(StatusReg + 2320),
            v6,
            v7,
            v9,
            v11);
          v17 = a1[14];
          if ( v17 )
            ipc_log_string(
              v17,
              "[%s] scaling_factor:%d reporting sampling:%d\n",
              (const char *)(StatusReg + 2320),
              *((_DWORD *)a1 + 30),
              qpt_update_interval_ms);
        }
      }
    }
    mutex_unlock(a1 + 25);
    return v5 & (unsigned int)(v5 >> 31);
  }
  else
  {
    dev_err(*a1, "Invalid sdam nvmem\n");
    return 4294967274LL;
  }
}
