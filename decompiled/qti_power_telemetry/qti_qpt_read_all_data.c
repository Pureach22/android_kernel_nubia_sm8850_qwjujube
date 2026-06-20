__int64 __fastcall qti_qpt_read_all_data(_QWORD *a1, const char *a2, __int64 a3, int a4)
{
  unsigned __int16 v6; // w22
  __int64 v8; // x0
  __int64 v9; // x26
  unsigned int v10; // w23
  unsigned int v11; // w24
  int v12; // w26
  __int64 v13; // x27
  __int64 v14; // x27
  bool v15; // cc
  __int64 v16; // x24
  __int64 v17; // x4
  __int64 v18; // x5
  int v19; // w23
  __int64 v20; // x0
  int v21; // w25
  __int64 *v22; // x27
  unsigned __int64 v23; // x28
  __int64 v24; // x21
  unsigned __int64 v25; // x23
  __int64 v26; // x22
  __int64 v27; // x10
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x11
  unsigned __int64 v31; // x12
  __int64 v32; // x8
  __int64 v33; // x20
  unsigned __int64 v34; // x21
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x2
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-A8h]
  int v40; // [xsp+24h] [xbp-9Ch] BYREF
  int *v41; // [xsp+28h] [xbp-98h] BYREF
  _QWORD v42[14]; // [xsp+30h] [xbp-90h] BYREF
  _QWORD v43[4]; // [xsp+A0h] [xbp-20h]

  v6 = (unsigned __int16)a2;
  v43[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)((char *)v43 + 7) = 0;
  v43[0] = 0;
  memset(v42, 0, sizeof(v42));
  v40 = 0;
  v8 = ktime_get(a1);
  v9 = a1[1];
  a1[18] = v8;
  v41 = &v40;
  mutex_lock(v9 + 304);
  if ( a4 == 1 )
    v10 = 72;
  else
    v10 = 71;
  v11 = nvmem_device_read(*(_QWORD *)(v9 + 296), (const char *)v10, 1, &v41);
  mutex_unlock(v9 + 304);
  if ( (v11 & 0x80000000) != 0 )
  {
    v36 = *a1;
    v37 = *(unsigned int *)(v9 + 288);
LABEL_34:
    dev_err(v36, "Failed to read sdam[%d] off:%#x,size:%ld rc=%d\n", v37, v10, 1, v11);
  }
  else
  {
    v12 = v40;
    do
    {
      v13 = a1[1];
      mutex_lock(v13 + 304);
      v11 = nvmem_device_read(*(_QWORD *)(v13 + 296), (const char *)v6, a3, v42);
      mutex_unlock(v13 + 304);
      if ( (v11 & 0x80000000) != 0 )
      {
        dev_err(*a1, "Failed to read sdam[%d] off:%#x,size:%ld rc=%d\n", *(unsigned int *)(v13 + 288), v6, a3, v11);
        goto LABEL_35;
      }
      v14 = a1[1];
      v41 = &v40;
      mutex_lock(v14 + 304);
      v11 = nvmem_device_read(*(_QWORD *)(v14 + 296), (const char *)v10, 1, &v41);
      mutex_unlock(v14 + 304);
      if ( (v11 & 0x80000000) != 0 )
      {
        v36 = *a1;
        v37 = *(unsigned int *)(v14 + 288);
        goto LABEL_34;
      }
      v15 = v40 < v12;
      v12 = v40;
    }
    while ( v15 );
    v16 = a1[1];
    LODWORD(v41) = 0;
    mutex_lock(v16 + 304);
    v19 = nvmem_device_read(*(_QWORD *)(v16 + 296), &print_fmt_qpt_update_channel_data[1], 4, &v41, v17, v18);
    v20 = mutex_unlock(v16 + 304);
    if ( v19 < 0 )
    {
      v20 = dev_err(*a1, "Failed to read sdam[%d] off:%#x,size:%ld rc=%d\n", *(_DWORD *)(v16 + 288), 73, 4, v19);
      v21 = 0;
    }
    else
    {
      v21 = (int)v41;
    }
    v22 = (__int64 *)a1[23];
    if ( v22 != a1 + 23 )
    {
      v23 = a3 + v6;
      if ( a4 == 1 )
        v24 = 128;
      else
        v24 = 124;
      StatusReg = _ReadStatusReg(SP_EL0);
      do
      {
        if ( *((_BYTE *)v22 + 36) == 1 && *((_DWORD *)v22 + 8) == a4 )
        {
          v25 = *((unsigned __int8 *)v22 + 42);
          if ( v23 > v25 )
          {
            if ( (unsigned int)v25 >= 0x7C )
              goto LABEL_38;
            v26 = v22[2];
            mutex_lock(v22 + 13);
            if ( (v25 & 0x7C) == 0x78 || (unsigned int)v25 > 0x76 )
            {
              __break(1u);
LABEL_38:
              __break(0x5512u);
            }
            v27 = *(unsigned int *)(v26 + v24);
            v28 = (v21 - *(_DWORD *)(v26 + 136)) / (unsigned int)v27;
            v29 = *(unsigned int *)((char *)v42 + v25) | ((unsigned __int64)*((unsigned __int8 *)v42 + v25 + 4) << 32);
            v30 = v29 * *(unsigned int *)(v26 + 120);
            v31 = v30 - v22[7];
            v22[6] = v29;
            v22[7] = v30;
            v22[8] = v22[10] + v30 * v27 / 0x3E8;
            v22[9] = v31 / v28;
            v20 = mutex_unlock(v22 + 13);
            v32 = v22[2];
            if ( v32 )
            {
              v20 = *(_QWORD *)(v32 + 104);
              if ( v20 )
                v20 = ipc_log_string(
                        v20,
                        "[%s] qpt[0x%x]: tot_power:%lluuw ADC:0x%llx tot_energy:%lluuj powavg %lluuw\n",
                        (const char *)(StatusReg + 2320),
                        *((unsigned __int16 *)v22 + 20),
                        v22[7],
                        v22[6],
                        v22[8],
                        v22[9]);
            }
          }
        }
        v22 = (__int64 *)*v22;
      }
      while ( v22 != a1 + 23 );
    }
    v11 = 0;
    *((_DWORD *)a1 + 34) = v21;
    if ( a1 && a4 != 1 )
    {
      v33 = a1[13];
      if ( v33 )
      {
        v34 = _ReadStatusReg(SP_EL0);
        v35 = ktime_get(v20);
        ipc_log_string(
          v33,
          "[%s] Time(us) to read all channel:%lldus & RTC Time:%u\n",
          (const char *)(v34 + 2320),
          (v35 - a1[18]) / 1000,
          *((_DWORD *)a1 + 34));
      }
      v11 = 0;
    }
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return v11;
}
