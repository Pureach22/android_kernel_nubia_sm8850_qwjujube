__int64 __fastcall dfc_qmi_client_init(__int64 a1, unsigned int a2, unsigned int *a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 v11; // x0
  unsigned int v12; // w0
  unsigned int v13; // w0
  unsigned int v14; // w20
  unsigned __int64 StatusReg; // x24
  __int64 v16; // x25
  void *(*v17)(void *, int, size_t); // x0

  result = 4294967274LL;
  if ( a1 && a4 )
  {
    v9 = _kmalloc_cache_noprof(memset, 3520, 440);
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = *(_QWORD *)a3;
        *(_QWORD *)v9 = a1;
        a1 = 0xFFFFFFFE00000LL;
        *(_DWORD *)(v9 + 428) = a2;
        *(_QWORD *)(v9 + 364) = v10;
        LODWORD(v10) = a3[2];
        *(_DWORD *)(v9 + 432) = 0;
        *(_DWORD *)(v9 + 372) = v10;
        *(_QWORD *)(v9 + 376) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v9 + 384) = v9 + 384;
        *(_QWORD *)(v9 + 392) = v9 + 384;
        *(_QWORD *)(v9 + 400) = dfc_qmi_ind_work;
        *(_QWORD *)(v9 + 408) = v9 + 408;
        *(_QWORD *)(v9 + 416) = v9 + 408;
        *(_DWORD *)(v9 + 424) = 0;
        v11 = alloc_workqueue("%s", (const char *)0x6000A);
        *(_QWORD *)(v9 + 8) = v11;
        if ( !v11 )
        {
          printk(&unk_2CB61, "dfc_qmi_client_init");
          v14 = -12;
          goto LABEL_13;
        }
        *(_QWORD *)(v9 + 16) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v9 + 24) = v9 + 24;
        *(_QWORD *)(v9 + 32) = v9 + 24;
        *(_QWORD *)(v9 + 40) = dfc_svc_init;
        v12 = qmi_handle_init(v9 + 48, 543, server_ops, &qmi_indication_handler);
        if ( (v12 & 0x80000000) != 0 )
        {
          v14 = v12;
          printk(&unk_2D55A, "dfc_qmi_client_init");
          goto LABEL_12;
        }
        v13 = qmi_add_lookup(v9 + 48, 78, 1, *a3);
        if ( (v13 & 0x80000000) != 0 )
          break;
        if ( a2 < 2 )
        {
          *(_QWORD *)(a4 + 8LL * a2 + 40) = v9;
          return 0;
        }
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v16 = *(_QWORD *)(StatusReg + 80);
        v17 = memset;
        *(_QWORD *)(StatusReg + 80) = &dfc_qmi_client_init__alloc_tag;
        v9 = _kmalloc_cache_noprof(v17, 3520, 440);
        *(_QWORD *)(StatusReg + 80) = v16;
        if ( !v9 )
          return 4294967284LL;
      }
      v14 = v13;
      printk(&unk_2C75B, "dfc_qmi_client_init");
      qmi_handle_release(v9 + 48);
LABEL_12:
      destroy_workqueue(*(_QWORD *)(v9 + 8));
LABEL_13:
      kfree(v9);
      return v14;
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
