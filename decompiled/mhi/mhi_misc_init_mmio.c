__int64 __fastcall mhi_misc_init_mmio(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x21
  __int64 v8; // x20
  int v9; // w8
  __int64 v10; // x9
  _DWORD *v11; // x10
  int v12; // w9
  __int64 v13; // x8
  _DWORD *v14; // x10
  int v15; // w20
  unsigned int v16; // w8
  __int64 v17; // x8
  int v18; // w20
  __int64 v19; // x8
  __int64 v20; // x20
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 result; // x0
  __int64 v24; // x19
  unsigned int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 16);
  if ( !(unsigned int)mhi_read_reg(a1) )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( !*(_QWORD *)(v3 + 72) )
      goto LABEL_4;
    v4 = *(_QWORD *)(a1 + 32);
    v25 = 0;
    if ( (unsigned int)mhi_get_capability_offset(a1, 3, &v25) )
      goto LABEL_4;
    v9 = *(_DWORD *)(a1 + 212);
    if ( !v9 )
      goto LABEL_4;
    v10 = v4 + 1008;
    v11 = (_DWORD *)(*(_QWORD *)(a1 + 248) + 36LL);
    while ( *v11 != 2 )
    {
      --v9;
      v11 += 66;
      if ( !v9 )
        goto LABEL_4;
    }
    v15 = *(v11 - 5);
    if ( v15 < 0 )
    {
LABEL_4:
      v5 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      if ( v5 && *(_DWORD *)(v5 + 24) <= 1u )
        ipc_log_string(*(_QWORD *)(v5 + 32), "[I][%s] BW scale setup failure\n", "mhi_misc_init_mmio");
    }
    else
    {
      v16 = v25;
      *(_QWORD *)(v3 + 64) = v10;
      v25 = v16 + 4;
      mhi_write_reg(a1);
      v17 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      if ( v17 && !*(_DWORD *)(v17 + 24) )
        ipc_log_string(
          *(_QWORD *)(v17 + 32),
          "[D][%s] Bandwidth scaling setup complete. Event ring:%d\n",
          "mhi_init_bw_scale",
          v15);
    }
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    v7 = *(_QWORD *)(v6 + 104);
    if ( v7 )
    {
      v8 = *(_QWORD *)(a1 + 32);
      v25 = 0;
      if ( !(unsigned int)mhi_get_capability_offset(a1, 2, &v25) )
      {
        *(_QWORD *)(v7 + 24) = *(_QWORD *)(a1 + 32) + v25;
        _mutex_init(v7 + 128, "&mhi_tsync->mutex", &mhi_init_timesync___key);
        v12 = *(_DWORD *)(a1 + 212);
        if ( v12 )
        {
          v13 = v8 + 1000;
          v14 = (_DWORD *)(*(_QWORD *)(a1 + 248) + 36LL);
          while ( *v14 != 3 )
          {
            --v12;
            v14 += 66;
            if ( !v12 )
              goto LABEL_31;
          }
          v18 = *(v14 - 5);
          if ( (v18 & 0x80000000) == 0 )
          {
            *(_DWORD *)(v7 + 104) = 0;
            *(_QWORD *)(v7 + 112) = v7 + 112;
            *(_QWORD *)(v7 + 120) = v7 + 112;
            *(_QWORD *)(v7 + 32) = v13;
            mhi_write_reg(a1);
            v19 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
            if ( v19 )
            {
              if ( !*(_DWORD *)(v19 + 24) )
                ipc_log_string(
                  *(_QWORD *)(v19 + 32),
                  "[D][%s] Time synchronization DB mode setup complete. Event ring:%d\n",
                  "mhi_init_timesync",
                  v18);
            }
          }
        }
        goto LABEL_31;
      }
      v6 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    }
    if ( v6 && *(_DWORD *)(v6 + 24) <= 1u )
      ipc_log_string(*(_QWORD *)(v6 + 32), "[I][%s] Time synchronization setup failure\n", "mhi_misc_init_mmio");
LABEL_31:
    v20 = *(_QWORD *)(a1 + 32);
    v25 = 0;
    if ( (unsigned int)mhi_get_capability_offset(a1, 6, &v25) )
    {
      v21 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      if ( v21 && *(_DWORD *)(v21 + 24) <= 1u )
        ipc_log_string(
          *(_QWORD *)(v21 + 32),
          "[I][%s] Host notification doorbell setup failure\n",
          "mhi_misc_init_mmio");
    }
    else
    {
      v25 += 4;
      *(_QWORD *)(a1 + 64) = v20 + 992;
      mhi_write_reg(a1);
      v22 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      if ( v22 && !*(_DWORD *)(v22 + 24) )
        ipc_log_string(
          *(_QWORD *)(v22 + 32),
          "[D][%s] Host notification DB setup complete.\n",
          "mhi_init_host_notification");
    }
    result = 0;
    goto LABEL_39;
  }
  v24 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  dev_err(v2 + 40, "[E][%s] Unable to read CHDBOFF register\n", "mhi_misc_init_mmio");
  if ( v24 && *(_DWORD *)(v24 + 24) <= 2u )
    ipc_log_string(*(_QWORD *)(v24 + 32), "[E][%s] Unable to read CHDBOFF register\n", "mhi_misc_init_mmio");
  result = 4294967291LL;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
