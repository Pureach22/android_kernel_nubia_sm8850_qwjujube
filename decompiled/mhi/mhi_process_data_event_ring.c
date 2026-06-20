__int64 __fastcall mhi_process_data_event_ring(__int64 a1, __int64 *a2, int a3)
{
  unsigned int v3; // w8
  unsigned int v4; // w21
  __int64 v5; // x12
  __int64 v8; // x28
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x9
  unsigned __int64 *v11; // x28
  unsigned __int64 v12; // t1
  unsigned __int64 v13; // x8
  __int64 *v14; // x25
  int v15; // w22
  int v16; // w26
  __int64 v17; // x8
  unsigned __int64 v18; // x8
  __int64 v19; // x2
  __int64 v20; // x10
  unsigned __int64 v21; // x8
  _QWORD *v22; // x9
  __int64 v23; // x11
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x10
  void (__fastcall *v27)(__int64, __int64 *, __int64, __int64); // x9
  __int64 v28; // x0
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v32; // x19
  __int64 v33; // x19
  __int64 v34; // [xsp+8h] [xbp-8h]

  v3 = *(_DWORD *)(a1 + 336);
  v4 = -5;
  if ( v3 == 1 || v3 > 0x7F )
    return v4;
  v5 = *(_QWORD *)(a1 + 16);
  v8 = **(_QWORD **)(a1 + 264) + 44LL * *((unsigned int *)a2 + 4);
  v9 = a2[6];
  v12 = *(_QWORD *)(v8 + 28);
  v11 = (unsigned __int64 *)(v8 + 28);
  v10 = v12;
  v13 = v12 - v9;
  if ( v12 >= v9 && (v10 & 0xF) == 0 && a2[13] + v9 > v10 )
  {
    v14 = (__int64 *)a2[10];
    v4 = 0;
    if ( (__int64 *)(a2[9] + v13) == v14 || (v15 = a3, v34 = *(_QWORD *)(a1 + 16), !a3) )
    {
LABEL_31:
      raw_read_lock_bh(a1 + 320);
      if ( (*(_DWORD *)(a1 + 340) & *(_DWORD *)(a1 + 336)) != 0 && v4 )
      {
        v27 = (void (__fastcall *)(__int64, __int64 *, __int64, __int64))a2[20];
        v28 = *a2;
        v29 = a2[16];
        v30 = *(_QWORD *)a2[7];
        if ( *((_DWORD *)v27 - 1) != -396405511 )
          __break(0x8229u);
        v27(v28, a2 + 17, v29, v30);
      }
      raw_read_unlock_bh(a1 + 320);
      return v4;
    }
    v4 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v16 = *((_DWORD *)v14 + 3);
      v17 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      if ( v17 && !*(_DWORD *)(v17 + 24) )
        ipc_log_string(
          *(_QWORD *)(v17 + 32),
          "[D][%s] Processing Event:0x%llx 0x%08x 0x%08x\n",
          "mhi_process_data_event_ring",
          *v14,
          *((_DWORD *)v14 + 2),
          v16);
      v18 = (unsigned __int64)*((unsigned int *)v14 + 3) >> 24;
      if ( (unsigned int)v18 < *(_DWORD *)(a1 + 208) || (__break(0x800u), (unsigned int)v18 < *(_DWORD *)(a1 + 208)) )
      {
        v19 = *(_QWORD *)(a1 + 176) + 400LL * (unsigned int)v18;
        if ( *(_BYTE *)(v19 + 393) == 1 )
        {
          if ( BYTE2(v16) == 34 )
          {
            parse_xfer_event(a1, v14, v19);
LABEL_16:
            --v15;
            goto LABEL_17;
          }
          if ( BYTE2(v16) == 40 )
          {
            parse_rsc_event(v14, v19);
            goto LABEL_16;
          }
        }
      }
LABEL_17:
      v20 = a2[9];
      v21 = a2[11] + a2[12];
      v23 = a2[6];
      v22 = (_QWORD *)a2[7];
      if ( v21 >= v20 + a2[13] )
        v21 = a2[9];
      a2[11] = v21;
      *v22 = v23 - v20 + v21;
      v24 = a2[10] + a2[12];
      if ( v24 >= a2[9] + a2[13] )
        v24 = a2[9];
      a2[10] = v24;
      __dmb(0xAu);
      v25 = *v11;
      v26 = a2[6];
      if ( *v11 < v26 || (v25 & 0xF) != 0 || a2[13] + v26 <= v25 )
      {
        v33 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        dev_err(v34 + 40, "[E][%s] Event ring rp points outside of the event ring\n", "mhi_process_data_event_ring");
        if ( v33 && *(_DWORD *)(v33 + 24) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v33 + 32),
            "[E][%s] Event ring rp points outside of the event ring\n",
            "mhi_process_data_event_ring");
        return (unsigned int)-5;
      }
      v14 = (__int64 *)a2[10];
      ++v4;
      if ( (__int64 *)(a2[9] + *v11 - v26) == v14 || !v15 )
        goto LABEL_31;
    }
  }
  v32 = *(_QWORD *)(v5 + 192);
  dev_err(v5 + 40, "[E][%s] Event ring rp points outside of the event ring\n", "mhi_process_data_event_ring");
  if ( v32 && *(_DWORD *)(v32 + 24) <= 2u )
    ipc_log_string(
      *(_QWORD *)(v32 + 32),
      "[E][%s] Event ring rp points outside of the event ring\n",
      "mhi_process_data_event_ring");
  return v4;
}
