__int64 __fastcall fastrpc_internal_control(__int64 a1, int *a2)
{
  int v2; // w8
  __int64 v3; // x22
  __int64 result; // x0
  __int64 v6; // x23
  unsigned int v7; // w20
  unsigned int v8; // w8
  __int64 v9; // x0
  int v10; // w8
  unsigned int v11; // w20
  int v12; // w21
  int v13; // w2
  __int64 v14; // x22
  unsigned __int64 i; // x21
  __int64 cpu_device; // x0
  int updated; // w0
  unsigned int v18; // w2
  unsigned int v19; // w20
  unsigned int v20; // w9
  int v21; // [xsp+4h] [xbp-9Ch] BYREF
  _QWORD v22[15]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v23[4]; // [xsp+80h] [xbp-20h] BYREF

  v23[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = 4294967287LL;
    goto LABEL_48;
  }
  if ( !a2 )
  {
LABEL_16:
    result = 4294967274LL;
    goto LABEL_48;
  }
  v2 = *a2;
  v3 = *(_QWORD *)(a1 + 128);
  result = 4294967240LL;
  if ( *a2 > 4 )
  {
    switch ( v2 )
    {
      case 5:
        if ( !*(_DWORD *)(a1 + 300) )
        {
          result = 4294967283LL;
          goto LABEL_48;
        }
        v8 = a2[1];
        if ( v8 >= 0x32 )
          v8 = 50;
        *(_DWORD *)(a1 + 292) = v8;
        mutex_lock(v3 + 64056);
        v9 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 64048LL);
        if ( v9 )
          pm_wakeup_ws_event(v9, *(unsigned int *)(a1 + 292), 1);
        mutex_unlock(v3 + 64056);
        break;
      case 6:
        v21 = *(_DWORD *)(a1 + 244);
        v23[0] = &v21;
        v23[1] = 4;
        v23[2] = 0xFFFFFFFFLL;
        v22[0] = 0x101000000000001LL;
        v22[1] = v23;
        memset(&v22[2], 0, 104);
        result = fastrpc_internal_invoke(a1, 2u, (int *)v22);
        if ( (_DWORD)result )
          goto LABEL_48;
        fastrpc_queue_pd_status(a1, **(_DWORD **)(a1 + 128), 2, *(_DWORD *)(a1 + 284));
        break;
      case 7:
        if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)(v3 + 24) + 60LL) - 1) > 1
          || (v10 = *(_DWORD *)(a1 + 268), v12 = a2[1], v11 = a2[2], v10 != 7) && v10 != 9 )
        {
          dev_err(*(_QWORD *)(v3 + 168), "poll mode only allowed for dynamic CDSP and ADSP process\n");
          goto LABEL_47;
        }
        if ( v11 >= 0x2711 )
        {
          dev_err(*(_QWORD *)(v3 + 168), "poll timeout %u is greater than max allowed value %u\n", v11, 10000);
          result = 4294967222LL;
          goto LABEL_48;
        }
        raw_spin_lock(a1 + 320);
        if ( v12 )
          v20 = v11;
        else
          v20 = 0;
        *(_BYTE *)(a1 + 305) = v12 != 0;
        *(_DWORD *)(a1 + 288) = v20;
        raw_spin_unlock(a1 + 320);
        dev_info(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL), "updated poll mode to %d, timeout %u\n", v12, v11);
        break;
      default:
        goto LABEL_48;
    }
    result = 0;
    goto LABEL_48;
  }
  switch ( v2 )
  {
    case 1:
      v6 = v3 + 49152;
      if ( a2[1] )
      {
        v7 = *(_DWORD *)(v3 + 52700);
        if ( !v7 )
          goto LABEL_16;
      }
      else
      {
        v7 = 0x7FFFFFFF;
      }
      v13 = *(_DWORD *)(v3 + 52696);
      if ( v13 && *(_QWORD *)(a1 + 536) )
      {
        mutex_lock(a1 + 424);
        if ( *(_DWORD *)(v3 + 52696) )
        {
          v14 = 0;
          for ( i = 0; i < *(unsigned int *)(v6 + 3544); ++i )
          {
            if ( *(_DWORD *)(a1 + 296) )
            {
              updated = dev_pm_qos_update_request(*(_QWORD *)(a1 + 536) + v14, v7);
              if ( updated < 0 )
              {
LABEL_40:
                v18 = v7;
                v19 = updated;
                dev_err(
                  *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
                  "QoS with lat %u failed for CPU %d, err %d, req %d\n",
                  v18,
                  i,
                  updated,
                  *(_DWORD *)(a1 + 296));
                goto LABEL_42;
              }
            }
            else
            {
              cpu_device = get_cpu_device((unsigned int)i);
              updated = dev_pm_qos_add_request(cpu_device, *(_QWORD *)(a1 + 536) + v14, 1, v7);
              if ( updated < 0 )
                goto LABEL_40;
            }
            v14 += 80;
          }
        }
        v19 = 0;
        *(_DWORD *)(a1 + 296) = 1;
LABEL_42:
        mutex_unlock(a1 + 424);
        result = v19;
      }
      else
      {
        dev_err(*(_QWORD *)(v3 + 168), "Skipping PM QoS latency voting, core count: %u\n", v13);
        result = 4294967274LL;
      }
      break;
    case 2:
      result = 0;
      *(_BYTE *)(a1 + 308) = a2[1] != 0;
      break;
    case 4:
      if ( (*(_BYTE *)(a1 + 304) & 1) != 0 )
      {
        result = 0;
        *(_DWORD *)(a1 + 300) = a2[1];
        break;
      }
      dev_err(*(_QWORD *)(v3 + 168), "PM voting not allowed for non-secure device node");
LABEL_47:
      result = 0xFFFFFFFFLL;
      break;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
