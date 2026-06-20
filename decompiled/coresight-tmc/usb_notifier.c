__int64 __fastcall usb_notifier(__int64 result, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v5; // x22
  __int64 v6; // x19
  __int64 rwp_offset; // x0
  int v9; // w23
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x19
  __int64 v14; // x19
  int v15; // w0
  __int64 v16; // x19
  void *v17; // x8
  __int64 v18; // x19
  __int64 v19; // x8
  int v20; // w19
  unsigned int v26; // w9

  if ( !result )
    return result;
  if ( *(_DWORD *)(result + 332) != 2 )
    return dev_err(*(_QWORD *)(result + 16) + 56LL, "%s: ETR is not USB mode.\n", "usb_notifier");
  if ( a2 == 3 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(result + 336) + 8LL) == 1 )
    {
      _X8 = (unsigned int *)(*(_QWORD *)(result + 304) + 164LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v26 = __ldxr(_X8);
      while ( __stxr(v26 + 1, _X8) );
      if ( *(_DWORD *)(a3 + 16) )
      {
        v14 = a3;
        v15 = __ratelimit(&usb_write_done__rs, "usb_write_done");
        a3 = v14;
        if ( v15 )
        {
          printk(&unk_101D2, *(unsigned int *)(v14 + 16));
          a3 = v14;
        }
      }
      v16 = a3;
      kfree(*(_QWORD *)(a3 + 32));
      return kfree(v16);
    }
    return result;
  }
  if ( a2 == 1 )
  {
    if ( (unsigned int)*(_QWORD *)(*(_QWORD *)(result + 16) + 968LL) )
    {
      if ( *(_DWORD *)(*(_QWORD *)(result + 336) + 8LL) == 1 )
      {
        v13 = result;
        usb_bypass_stop(*(_QWORD *)(result + 304));
        flush_work(*(_QWORD *)(v13 + 304) + 232LL);
        return usb_qdss_free_req(**(_QWORD **)(v13 + 336));
      }
      return result;
    }
    v17 = &usb_notifier__rs_6;
LABEL_27:
    v18 = result;
    result = __ratelimit(v17, "usb_notifier");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)(v18 + 16) + 56LL, "%s: ETR is disabled.\n", "usb_notifier");
    return result;
  }
  if ( a2 )
    return result;
  if ( !(unsigned int)*(_QWORD *)(*(_QWORD *)(result + 16) + 968LL) )
  {
    v17 = &usb_notifier__rs;
    goto LABEL_27;
  }
  if ( *(_DWORD *)(*(_QWORD *)(result + 336) + 8LL) == 1 )
  {
    v4 = *(_QWORD *)(result + 304);
    if ( v4 )
    {
      v5 = result;
      v6 = *(_QWORD *)(v4 + 368);
      mutex_lock(v4 + 264);
      dev_info(*(_QWORD *)(v6 + 16) + 56LL, "%s: Start usb bypass\n", "usb_bypass_start");
      if ( (unsigned int)*(_QWORD *)(*(_QWORD *)(v6 + 16) + 968LL) != 1 )
        return mutex_unlock(v4 + 264);
      rwp_offset = tmc_get_rwp_offset(v6);
      if ( (rwp_offset & 0x8000000000000000LL) == 0 )
      {
        *(_QWORD *)(v4 + 400) = rwp_offset;
        *(_QWORD *)(v4 + 424) = 0;
        *(_QWORD *)(*(_QWORD *)(v6 + 336) + 32LL) = 0;
        *(_BYTE *)(*(_QWORD *)(v6 + 336) + 24LL) = 0;
        if ( !**(_QWORD **)(v6 + 336) )
        {
          v9 = -100;
          while ( !__CFADD__(v9++, 1) )
          {
            _const_udelay(4295);
            if ( **(_QWORD **)(v6 + 336) )
              goto LABEL_15;
          }
          dev_err(*(_QWORD *)(v6 + 16) + 56LL, "timeout while waiting usbch to be ready\n");
          return mutex_unlock(v4 + 264);
        }
LABEL_15:
        *(_DWORD *)(v4 + 164) = 255;
        v11 = *(_QWORD *)(v4 + 360);
        v12 = *(unsigned int *)(v4 + 392);
        *(_BYTE *)(v4 + 145) = 1;
        coresight_csr_set_byte_cntr(v11, v12, 0x2000);
        *(_DWORD *)(v4 + 160) = 0;
        *(_QWORD *)(v4 + 416) = 0;
        mutex_unlock(v4 + 264);
        result = a4;
LABEL_16:
        usb_qdss_alloc_req(result, 255);
        return queue_work_on(32, *(_QWORD *)(*(_QWORD *)(v5 + 304) + 216LL), *(_QWORD *)(v5 + 304) + 232LL);
      }
      v19 = *(_QWORD *)(v6 + 16);
      v20 = rwp_offset;
      dev_err(v19 + 56, "%s: invalid rwp offset value\n", "usb_bypass_start");
      mutex_unlock(v4 + 264);
      result = a4;
      if ( (v20 & 0x80000000) == 0 )
        goto LABEL_16;
    }
  }
  return result;
}
