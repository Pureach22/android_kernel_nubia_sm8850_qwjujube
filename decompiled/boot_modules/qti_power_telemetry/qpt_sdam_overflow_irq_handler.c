__int64 __fastcall qpt_sdam_overflow_irq_handler(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x4
  __int64 v4; // x5
  int all_data; // w0
  int v6; // w20
  __int64 v7; // x0
  __int64 *v8; // x22
  __int64 v9; // x9
  int v10; // w10
  unsigned __int64 StatusReg; // x23
  __int64 v12; // x4
  __int64 v13; // x11
  __int64 v14; // x12
  __int64 v15; // x8
  __int64 v16; // x10
  __int64 v17; // x0
  __int64 v18; // x21
  int v19; // w20
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a2 + 25);
  all_data = qti_qpt_read_all_data(
               a2,
               &print_fmt_qpt_update_channel_data[5],
               (unsigned int)*((unsigned __int8 *)a2 + 79) + 5,
               0,
               v3,
               v4);
  if ( *((_BYTE *)a2 + 78) )
    all_data = qti_qpt_read_all_data(
                 a2,
                 (const char *)((unsigned int)*((unsigned __int8 *)a2 + 80) + 69),
                 *((unsigned __int8 *)a2 + 81) + 5LL,
                 1);
  v6 = all_data;
  mutex_unlock(a2 + 25);
  if ( v6 < 0 )
  {
    dev_err(*a2, "qpt channel read error\n");
    if ( !a2 )
      goto LABEL_7;
  }
  else if ( !a2 )
  {
    goto LABEL_7;
  }
  v7 = a2[14];
  if ( v7 )
    ipc_log_string(
      v7,
      "[%s] Channel overflow: rtc timestamp:%u\n",
      (const char *)(_ReadStatusReg(SP_EL0) + 2320),
      *((_DWORD *)a2 + 34));
LABEL_7:
  v8 = (__int64 *)a2[23];
  v10 = *((_DWORD *)a2 + 33);
  v9 = *((unsigned int *)a2 + 34);
  a2[19] = a2[18];
  a2[20] = v9;
  *((_DWORD *)a2 + 33) = v10 + 1;
  if ( v8 != a2 + 23 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      if ( *((_BYTE *)v8 + 36) == 1 )
      {
        v12 = v8[7];
        v13 = v8[6];
        v14 = v8[12];
        v15 = v8[2];
        v16 = v8[11] + v12;
        v8[10] += v8[8];
        v8[11] = v16;
        v8[12] = v14 + v13;
        if ( v15 )
        {
          v17 = *(_QWORD *)(v15 + 112);
          if ( v17 )
            ipc_log_string(
              v17,
              "[%s] overflow: qpt[0x%x]:last data uw:%llu\n",
              (const char *)(StatusReg + 2320),
              *((unsigned __int16 *)v8 + 20),
              v12);
        }
      }
      v8 = (__int64 *)*v8;
    }
    while ( v8 != a2 + 23 );
  }
  v18 = a2[1];
  v21 = 1;
  mutex_lock(v18 + 160);
  v19 = nvmem_device_write(*(_QWORD *)(v18 + 152), 229, 1, &v21);
  mutex_unlock(v18 + 160);
  if ( v19 < 0 )
  {
    dev_err(*a2, "Failed to write sdam[%d] off:%#x,size:%ld rc=%d\n", *(_DWORD *)(v18 + 144), 229, 1, v19);
    dev_err(*a2, "qpt channel overflow ack error\n");
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
