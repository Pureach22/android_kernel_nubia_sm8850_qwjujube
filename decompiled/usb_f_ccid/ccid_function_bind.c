__int64 __fastcall ccid_function_bind(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x20
  unsigned int v4; // w0
  _QWORD *v5; // x0
  __int64 v6; // x2
  _QWORD *v7; // x0
  __int64 v8; // x2
  _QWORD *v9; // x0
  __int64 v10; // x2
  __int64 v11; // x21
  __int64 v12; // x0
  __int64 v13; // x2
  _QWORD *v14; // x20
  __int64 v15; // x0
  __int64 v16; // x21
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // x0
  _QWORD *v20; // x21
  int v21; // w23
  __int64 v22; // x22
  __int64 v23; // x0
  __int64 v24; // x2
  __int64 v25; // x0
  __int64 v26; // x0
  _QWORD *v27; // x8
  _QWORD *v28; // x1
  __int64 v29; // x9
  _QWORD *v30; // x21
  __int64 v31; // x22

  v2 = *(_QWORD **)(a1 + 48);
  v4 = usb_interface_id();
  *(_DWORD *)(a2 + 224) = v4;
  if ( (v4 & 0x80000000) != 0 )
  {
    printk(&unk_81BD, "ccid_function_bind", v4);
    LODWORD(v2) = *(_DWORD *)(a2 + 224);
  }
  else
  {
    byte_162 = v4;
    v5 = (_QWORD *)usb_ep_autoconfig(*v2, &ccid_fs_notify_desc);
    if ( v5 )
    {
      *(_QWORD *)(a2 + 240) = v5;
      *v5 = v2;
      v7 = (_QWORD *)usb_ep_autoconfig(*v2, &ccid_fs_in_desc);
      if ( !v7 )
      {
        printk(&unk_80C1, "ccid_function_bind", v8);
        LODWORD(v2) = -19;
LABEL_41:
        **(_QWORD **)(a2 + 240) = 0;
        *(_QWORD *)(a2 + 240) = 0;
        return (unsigned int)v2;
      }
      *(_QWORD *)(a2 + 248) = v7;
      *v7 = v2;
      v9 = (_QWORD *)usb_ep_autoconfig(*v2, &ccid_fs_out_desc);
      if ( !v9 )
      {
        printk(&unk_80E3, "ccid_function_bind", v10);
        LODWORD(v2) = -19;
LABEL_40:
        **(_QWORD **)(a2 + 248) = 0;
        *(_QWORD *)(a2 + 248) = 0;
        goto LABEL_41;
      }
      *(_QWORD *)(a2 + 256) = v9;
      *v9 = v2;
      byte_186 = byte_174;
      byte_18F = byte_17D;
      byte_198 = byte_16B;
      byte_1A1 = byte_174;
      byte_1AA = byte_17D;
      byte_1B3 = byte_16B;
      LODWORD(v2) = usb_assign_descriptors(a2, &ccid_fs_descs, &ccid_hs_descs, &ccid_ss_descs, &ccid_ss_descs);
      if ( (_DWORD)v2 )
      {
LABEL_39:
        **(_QWORD **)(a2 + 256) = 0;
        *(_QWORD *)(a2 + 256) = 0;
        goto LABEL_40;
      }
      v11 = *(_QWORD *)(a2 + 240);
      v12 = usb_ep_alloc_request(v11, 3264);
      if ( v12 )
      {
        v14 = (_QWORD *)v12;
        *(_DWORD *)(v12 + 8) = 4;
        v15 = _kmalloc_cache_noprof(strlen, 3264, 4);
        *v14 = v15;
        if ( v15 )
        {
          *(_QWORD *)(a2 + 264) = v14;
          if ( (unsigned __int64)v14 < 0xFFFFFFFFFFFFF001LL )
          {
            v14[6] = ccid_notify_complete;
            *(_QWORD *)(*(_QWORD *)(a2 + 264) + 56LL) = a2;
            v16 = *(_QWORD *)(a2 + 256);
            v17 = usb_ep_alloc_request(v16, 3264);
            if ( v17 )
            {
              v2 = (_QWORD *)v17;
              *(_DWORD *)(v17 + 8) = 1024;
              v19 = _kmalloc_cache_noprof(device_destroy, 3264, 1024);
              *v2 = v19;
              if ( v19 )
              {
                if ( (unsigned __int64)v2 < 0xFFFFFFFFFFFFF001LL )
                {
                  v20 = (_QWORD *)(a2 + 544);
                  v21 = 4;
                  v2[6] = ccid_bulk_complete_out;
                  v2[7] = a2;
                  _ReadStatusReg(SP_EL0);
                  *(_QWORD *)(a2 + 528) = v2;
                  while ( 1 )
                  {
                    v22 = *(_QWORD *)(a2 + 248);
                    v23 = usb_ep_alloc_request(v22, 3264);
                    if ( !v23 )
                      break;
                    v2 = (_QWORD *)v23;
                    *(_DWORD *)(v23 + 8) = 523;
                    v25 = _kmalloc_cache_noprof(device_destroy, 3264, 523);
                    *v2 = v25;
                    if ( !v25 )
                    {
                      usb_ep_free_request(v22, v2);
                      break;
                    }
                    if ( (unsigned __int64)v2 >= 0xFFFFFFFFFFFFF001LL )
                      goto LABEL_25;
                    v2[6] = ccid_bulk_complete_in;
                    v2[7] = a2;
                    v26 = raw_spin_lock_irqsave(a2 + 228);
                    v27 = v2 + 8;
                    v28 = *(_QWORD **)(a2 + 552);
                    v29 = v26;
                    if ( v2 + 8 == v20 || v28 == v27 || (_QWORD *)*v28 != v20 )
                    {
                      _list_add_valid_or_report(v2 + 8, v28, a2 + 544);
                    }
                    else
                    {
                      *(_QWORD *)(a2 + 552) = v27;
                      v2[8] = v20;
                      v2[9] = v28;
                      *v28 = v27;
                    }
                    raw_spin_unlock_irqrestore(a2 + 228, v29);
                    if ( !--v21 )
                    {
                      LODWORD(v2) = 0;
                      return (unsigned int)v2;
                    }
                  }
                  LODWORD(v2) = -12;
LABEL_25:
                  printk(&unk_800C, "ccid_function_bind", v24);
                  ccid_request_free(*(_QWORD **)(a2 + 528), *(_QWORD *)(a2 + 256));
                  goto LABEL_36;
                }
LABEL_35:
                printk(&unk_7FDF, "ccid_function_bind", v18);
LABEL_36:
                v30 = *(_QWORD **)(a2 + 264);
                if ( v30 )
                {
                  v31 = *(_QWORD *)(a2 + 240);
                  kfree(*v30);
                  usb_ep_free_request(v31, v30);
                }
                goto LABEL_38;
              }
              usb_ep_free_request(v16, v2);
            }
            LODWORD(v2) = -12;
            goto LABEL_35;
          }
LABEL_32:
          printk(&unk_8065, "ccid_function_bind", v13);
          LODWORD(v2) = 0;
LABEL_38:
          usb_free_all_descriptors(a2);
          goto LABEL_39;
        }
        usb_ep_free_request(v11, v14);
      }
      *(_QWORD *)(a2 + 264) = -12;
      goto LABEL_32;
    }
    printk(&unk_8403, "ccid_function_bind", v6);
    LODWORD(v2) = -19;
  }
  return (unsigned int)v2;
}
