__int64 __fastcall wda_qmi_client_init(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x19
  __int64 v8; // x0
  __int64 v9; // x8
  unsigned int v10; // w10
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w20

  result = 4294967274LL;
  if ( a1 && a3 )
  {
    v7 = _kmalloc_cache_noprof(memset, 3520, 384);
    if ( v7 )
    {
      v8 = alloc_workqueue("%s", (const char *)0x6000A);
      *(_QWORD *)(v7 + 8) = v8;
      if ( v8 )
      {
        v9 = *(_QWORD *)a2;
        v10 = a2[2];
        *(_QWORD *)v7 = a1;
        *(_QWORD *)(v7 + 364) = v9;
        *(_QWORD *)(v7 + 16) = 0xFFFFFFFE00000LL;
        *(_DWORD *)(v7 + 376) = 0;
        *(_DWORD *)(v7 + 372) = v10;
        *(_QWORD *)(v7 + 24) = v7 + 24;
        *(_QWORD *)(v7 + 32) = v7 + 24;
        *(_QWORD *)(v7 + 40) = wda_svc_config;
        v11 = qmi_handle_init(v7 + 48, 14, server_ops_0, 0);
        if ( (v11 & 0x80000000) != 0 )
        {
          v13 = v11;
          printk(&unk_2C8CE, "wda_qmi_client_init");
        }
        else
        {
          v12 = qmi_add_lookup(v7 + 48, 26, 1, *a2);
          if ( (v12 & 0x80000000) == 0 )
          {
            *(_QWORD *)(a3 + 16) = v7;
            return 0;
          }
          v13 = v12;
          printk(&unk_2CB89, "wda_qmi_client_init");
          qmi_handle_release(v7 + 48);
        }
        destroy_workqueue(*(_QWORD *)(v7 + 8));
      }
      else
      {
        printk(&unk_2CB61, "wda_qmi_client_init");
        v13 = -12;
      }
      kfree(v7);
      return v13;
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
