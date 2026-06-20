__int64 __fastcall lpass_cdc_clk_rsc_request_clock(__int64 a1, unsigned int a2, unsigned int a3, char a4)
{
  __int64 rsc_clk_device_ptr; // x0
  _QWORD *v8; // x19
  __int64 v9; // x0
  unsigned int v10; // w20
  unsigned int v11; // w0
  _BOOL4 v13; // w8
  int v14; // w9
  int v15; // w8
  int v16; // w8
  int v17; // w8
  __int64 v18; // x20
  int v19; // w8
  int v20; // w8
  __int64 v21; // x20
  int v22; // w8
  int v23; // w8
  int v24; // w8
  int v25; // w8
  __int64 v26; // x23
  void *v27; // x0
  int v29; // w8
  int v30; // w8
  __int64 v31; // x20
  int v32; // w8

  if ( !a1 )
  {
    v27 = &unk_DCD3;
LABEL_56:
    printk(v27, "lpass_cdc_clk_rsc_request_clock");
    return 4294967274LL;
  }
  if ( a2 >= 8 && a3 >= 8 )
  {
    printk(&unk_D9C6, "lpass_cdc_clk_rsc_request_clock");
    return 4294967274LL;
  }
  rsc_clk_device_ptr = lpass_cdc_get_rsc_clk_device_ptr(*(_QWORD *)(a1 + 96));
  if ( !rsc_clk_device_ptr )
  {
    v27 = &unk_D96C;
    goto LABEL_56;
  }
  v8 = *(_QWORD **)(rsc_clk_device_ptr + 152);
  if ( !v8 )
  {
    v27 = &unk_DF67;
    goto LABEL_56;
  }
  v9 = mutex_lock(v8 + 1);
  if ( (a4 & 1) != 0 && (v8[26] & 1) == 0 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_clk_rsc_request_clock__rs, "lpass_cdc_clk_rsc_request_clock") )
      dev_err(*v8, "%s: SSR is in progress..\n", "lpass_cdc_clk_rsc_request_clock");
    v10 = -22;
    goto LABEL_59;
  }
  if ( a3 < 8 )
  {
    *((_DWORD *)v8 + a3 + 56) = a2;
    if ( a2 == a3 )
    {
      v11 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD))lpass_cdc_clk_rsc_mux0_clk_request)(v8, a3, a4 & 1);
      if ( (v11 & 0x80000000) != 0 )
        goto LABEL_58;
    }
    else if ( a3 != 3 )
    {
      v11 = lpass_cdc_clk_rsc_mux1_clk_request(v8);
      if ( (v11 & 0x80000000) != 0 )
        goto LABEL_58;
    }
    v13 = a3 == 3 && a2 != 3;
    if ( (a4 & 1) != 0 )
    {
      v14 = *((_DWORD *)v8 + 42);
      if ( !v13 )
      {
        if ( v14 >= 1 && *((int *)v8 + 45) >= 1 )
        {
          while ( 1 )
          {
            v11 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))lpass_cdc_clk_rsc_mux0_clk_request)(v8, 0, 1);
            if ( (v11 & 0x80000000) != 0 )
              goto LABEL_58;
            v19 = *((_DWORD *)v8 + 45);
            if ( v19 <= 0 )
            {
              if ( (unsigned int)__ratelimit(
                                   &lpass_cdc_clk_rsc_mux1_clk_request__rs_10,
                                   "lpass_cdc_clk_rsc_mux1_clk_request") )
                dev_err(*v8, "%s: clk_id: %d is already disabled\n", "lpass_cdc_clk_rsc_mux1_clk_request", 3);
              v15 = *((_DWORD *)v8 + 51);
              *((_DWORD *)v8 + 45) = 0;
              goto LABEL_70;
            }
            v20 = v19 - 1;
            *((_DWORD *)v8 + 45) = v20;
            if ( !v20 )
            {
              v21 = v8[16];
              clk_disable(v21);
              clk_unprepare(v21);
              v20 = *((_DWORD *)v8 + 45);
            }
            ++*((_DWORD *)v8 + 51);
            if ( v20 <= 0 )
              goto LABEL_76;
          }
        }
        goto LABEL_76;
      }
      if ( v14 )
      {
        v11 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))lpass_cdc_clk_rsc_mux0_clk_request)(v8, 0, 1);
        if ( (v11 & 0x80000000) == 0 )
        {
          v15 = *((_DWORD *)v8 + 51);
LABEL_70:
          v32 = v15 + 1;
          goto LABEL_75;
        }
LABEL_58:
        v10 = v11;
LABEL_59:
        mutex_unlock(v8 + 1);
        return v10;
      }
      v11 = lpass_cdc_clk_rsc_mux1_clk_request(v8);
      if ( (v11 & 0x80000000) != 0 )
        goto LABEL_58;
    }
    else
    {
      if ( !v13 )
      {
        v22 = *((_DWORD *)v8 + 51);
        if ( v22 && v22 == *((_DWORD *)v8 + 42) )
        {
          while ( 1 )
          {
            v11 = lpass_cdc_clk_rsc_mux1_clk_request(v8);
            if ( (v11 & 0x80000000) != 0 )
              goto LABEL_58;
            v24 = *((_DWORD *)v8 + 42);
            if ( v24 <= 0 )
            {
              if ( (unsigned int)__ratelimit(
                                   &lpass_cdc_clk_rsc_mux0_clk_request__rs_13,
                                   "lpass_cdc_clk_rsc_mux0_clk_request") )
                dev_err(*v8, "%s: clk_id: %d is already disabled\n", "lpass_cdc_clk_rsc_mux0_clk_request", 0);
              *((_DWORD *)v8 + 42) = 0;
            }
            else
            {
              v25 = v24 - 1;
              *((_DWORD *)v8 + 42) = v25;
              if ( !v25 )
              {
                v26 = v8[13];
                clk_disable(v26);
                clk_unprepare(v26);
              }
            }
            v23 = *((_DWORD *)v8 + 51) - 1;
            *((_DWORD *)v8 + 51) = v23;
            if ( !v23 )
              goto LABEL_76;
          }
        }
        goto LABEL_76;
      }
      v16 = *((_DWORD *)v8 + 45);
      if ( v16 )
      {
        if ( v16 <= 0 )
        {
          if ( (unsigned int)__ratelimit(
                               &lpass_cdc_clk_rsc_mux1_clk_request__rs_10,
                               "lpass_cdc_clk_rsc_mux1_clk_request") )
            dev_err(*v8, "%s: clk_id: %d is already disabled\n", "lpass_cdc_clk_rsc_mux1_clk_request", 3);
          *((_DWORD *)v8 + 45) = 0;
        }
        else
        {
          v17 = v16 - 1;
          *((_DWORD *)v8 + 45) = v17;
          if ( !v17 )
          {
            v18 = v8[16];
            clk_disable(v18);
            clk_unprepare(v18);
          }
        }
        goto LABEL_76;
      }
      if ( *((_DWORD *)v8 + 51) )
      {
        v29 = *((_DWORD *)v8 + 42);
        if ( v29 <= 0 )
        {
          if ( (unsigned int)__ratelimit(
                               &lpass_cdc_clk_rsc_mux0_clk_request__rs_13,
                               "lpass_cdc_clk_rsc_mux0_clk_request") )
            dev_err(*v8, "%s: clk_id: %d is already disabled\n", "lpass_cdc_clk_rsc_mux0_clk_request", 0);
          *((_DWORD *)v8 + 42) = 0;
        }
        else
        {
          v30 = v29 - 1;
          *((_DWORD *)v8 + 42) = v30;
          if ( !v30 )
          {
            v31 = v8[13];
            clk_disable(v31);
            clk_unprepare(v31);
          }
        }
        v32 = *((_DWORD *)v8 + 51) - 1;
LABEL_75:
        *((_DWORD *)v8 + 51) = v32;
      }
    }
LABEL_76:
    mutex_unlock(v8 + 1);
    return 0;
  }
  __break(0x5512u);
  return lpass_cdc_clk_rsc_mux1_clk_request(v9);
}
