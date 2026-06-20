__int64 __fastcall usb_qdss_alloc_req(__int64 a1, int a2)
{
  int v3; // w21
  __int64 v4; // x22
  __int64 *v5; // x23
  __int64 *v6; // x24
  __int64 v7; // x0
  __int64 v8; // x25
  __int64 v9; // x0
  __int64 **v10; // x8
  __int64 v11; // x9
  __int64 **v12; // x1

  if ( a1 )
  {
    v3 = a2;
    ipc_log_string(qdss_ipc_log, "%s: channel:%s num_write_buf:%d\n", "usb_qdss_alloc_req", *(const char **)a1, a2);
    if ( a1 == 296 )
    {
      printk(&unk_8739, "usb_qdss_alloc_req");
      return 4294967277LL;
    }
    else
    {
      mutex_lock(a1 + 176);
      if ( v3 < 1 )
      {
LABEL_14:
        mutex_unlock(a1 + 176);
        return 0;
      }
      else
      {
        v4 = *(_QWORD *)(a1 - 56);
        v5 = (__int64 *)(a1 + 48);
        _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v6 = (__int64 *)_kmalloc_cache_noprof(complete, 3520, 32);
          if ( !v6 )
            break;
          v7 = usb_ep_alloc_request(v4, 2080);
          if ( !v7 )
          {
            printk(&unk_805D, "usb_qdss_alloc_req");
            kfree(v6);
            break;
          }
          v8 = v7;
          v9 = raw_spin_lock_irqsave(a1 + 160);
          *v6 = v8;
          v10 = (__int64 **)(v6 + 2);
          v11 = v9;
          *(_QWORD *)(v8 + 48) = qdss_write_complete;
          *(_QWORD *)(v8 + 56) = v6;
          v12 = *(__int64 ***)(a1 + 56);
          if ( v6 + 2 == v5 || v12 == v10 || *v12 != v5 )
          {
            _list_add_valid_or_report(v6 + 2, v12, a1 + 48);
          }
          else
          {
            *(_QWORD *)(a1 + 56) = v10;
            v6[2] = (__int64)v5;
            v6[3] = (__int64)v12;
            *v12 = (__int64 *)v10;
          }
          raw_spin_unlock_irqrestore(a1 + 160, v11);
          if ( !--v3 )
            goto LABEL_14;
        }
        qdss_free_reqs(a1 - 296);
        mutex_unlock(a1 + 176);
        return 4294967284LL;
      }
    }
  }
  else
  {
    printk(&unk_81A4, "usb_qdss_alloc_req");
    return 4294967274LL;
  }
}
