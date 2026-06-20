__int64 __fastcall qti_qpt_start_stop_telemetry(__int64 *a1, char a2)
{
  __int64 result; // x0
  int v4; // w22
  int v5; // w9
  char v6; // w8
  __int64 v8; // x23
  int v9; // w20
  __int64 v10; // x23
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  int v16; // w4
  unsigned __int64 StatusReg; // x9
  const char *v18; // x3
  __int64 *v19; // x22
  __int64 v20; // x0
  __int64 v21; // x2
  const char *v22; // x1
  __int64 v23; // x3
  char v24[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v25[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v26[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  result = 0;
  v4 = a2 & 1;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((unsigned __int8 *)a1 + 85);
  if ( (a2 & 1) != 0 )
    v6 = 0x80;
  else
    v6 = 0;
  v26[0] = 0;
  v25[0] = v6;
  v24[0] = 1;
  if ( v5 != v4 )
  {
    mutex_lock(a1 + 25);
    v8 = a1[1];
    mutex_lock(v8 + 304);
    v9 = nvmem_device_read(*(_QWORD *)(v8 + 296), 69, 1, v26);
    mutex_unlock(v8 + 304);
    if ( v9 < 0 )
    {
      v20 = *a1;
      v21 = *(unsigned int *)(v8 + 288);
      v22 = "Failed to read sdam[%d] off:%#x,size:%ld rc=%d\n";
    }
    else
    {
      v10 = a1[1];
      mutex_lock(v10 + 304);
      v9 = nvmem_device_write(*(_QWORD *)(v10 + 296), 69, 1, v25);
      mutex_unlock(v10 + 304);
      if ( (v9 & 0x80000000) == 0 )
      {
        v11 = a1[1];
        mutex_lock(v11 + 304);
        v9 = nvmem_device_write(*(_QWORD *)(v11 + 296), 229, 1, v24);
        v12 = mutex_unlock(v11 + 304);
        if ( (v9 & 0x80000000) == 0 )
        {
          *((_BYTE *)a1 + 85) = v4;
          v13 = ktime_get(v12);
          v14 = 22;
          if ( (a2 & 1) != 0 )
            v14 = 21;
          a1[v14] = v13;
          if ( a1 )
          {
            v15 = a1[14];
            if ( v15 )
            {
              v16 = *((_DWORD *)a1 + 34);
              StatusReg = _ReadStatusReg(SP_EL0);
              if ( (a2 & 1) != 0 )
                v18 = "enabled";
              else
                v18 = "disabled";
              ipc_log_string(v15, "[%s] qpt is %s with last rtc_ts:%d\n", (const char *)(StatusReg + 2320), v18, v16);
            }
          }
          if ( (a2 & 1) == 0 )
          {
            v19 = (__int64 *)a1[23];
            a1[18] = 0;
            for ( *((_DWORD *)a1 + 34) = 0; v19 != a1 + 23; v19 = (__int64 *)*v19 )
            {
              mutex_lock(v19 + 13);
              v19[11] = 0;
              v19[12] = 0;
              v19[9] = 0;
              v19[10] = 0;
              v19[7] = 0;
              v19[8] = 0;
              v19[6] = 0;
              mutex_unlock(v19 + 13);
            }
          }
          goto LABEL_25;
        }
        v20 = *a1;
        v21 = *(unsigned int *)(v11 + 288);
        v22 = "Failed to write sdam[%d] off:%#x,size:%ld rc=%d\n";
        v23 = 229;
LABEL_24:
        dev_err(v20, v22, v21, v23, 1, (unsigned int)v9);
LABEL_25:
        mutex_unlock(a1 + 25);
        result = v9 & (unsigned int)(v9 >> 31);
        goto LABEL_26;
      }
      v20 = *a1;
      v21 = *(unsigned int *)(v10 + 288);
      v22 = "Failed to write sdam[%d] off:%#x,size:%ld rc=%d\n";
    }
    v23 = 69;
    goto LABEL_24;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
