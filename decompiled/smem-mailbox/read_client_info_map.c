__int64 read_client_info_map()
{
  __int64 v0; // x19
  unsigned __int64 v1; // x0
  unsigned __int64 v2; // x25
  int *v3; // x28
  int v4; // w22
  int v5; // w27
  int v6; // w23
  int v7; // w26
  __int64 v8; // x21
  const char *v9; // x22
  size_t v10; // x0
  unsigned __int64 v11; // x2
  __int64 *v12; // x1
  _UNKNOWN **v13; // x21
  unsigned int byname; // w2
  void *v15; // x0
  __int64 result; // x0
  __int64 v17; // [xsp+10h] [xbp-60h] BYREF
  __int64 v18; // [xsp+18h] [xbp-58h] BYREF
  __int64 v19; // [xsp+20h] [xbp-50h]
  __int64 v20; // [xsp+28h] [xbp-48h]
  _QWORD v21[6]; // [xsp+30h] [xbp-40h] BYREF
  __int64 v22; // [xsp+60h] [xbp-10h]
  __int64 v23; // [xsp+68h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v22 = 0;
  v0 = *(_QWORD *)(dev + 744);
  v20 = 0;
  memset(v21, 0, sizeof(v21));
  v19 = 0;
  v1 = qcom_smem_get(1, 655, &v17);
  if ( v1 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_73B6);
LABEL_29:
    result = 1;
    goto LABEL_30;
  }
  _memcpy_fromio(&v18, v1, 80);
  info_validated = 0;
  if ( (_DWORD)v18 == -1091581186 )
  {
    if ( HIDWORD(v18) == 1 )
    {
      if ( (_DWORD)v19 )
      {
        v2 = 0;
        v3 = (int *)v21;
        _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v4 = *(v3 - 3);
          v5 = *(v3 - 2);
          v6 = *(v3 - 1);
          v7 = *v3;
          v8 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
          *(_DWORD *)(v8 + 16) = v4;
          *(_DWORD *)(v8 + 20) = v5;
          v9 = IRQ_NAMES[v2];
          *(_DWORD *)(v8 + 24) = v6;
          *(_DWORD *)(v8 + 28) = v7;
          v10 = strnlen(v9, 0x18u);
          if ( v10 == -1 )
            break;
          if ( v10 == 24 )
            v11 = 24;
          else
            v11 = v10 + 1;
          if ( v11 >= 0x19 )
            goto LABEL_32;
          sized_strscpy(v8 + 33, v9);
          *(_QWORD *)v8 = v8;
          *(_QWORD *)(v8 + 8) = v8;
          v12 = (__int64 *)off_98;
          if ( off_98 == (_UNKNOWN *)v8 || *(_UNKNOWN ***)off_98 != &smem_client_channel_list_head )
          {
            _list_add_valid_or_report(v8);
            if ( v2 > 2 )
              goto LABEL_17;
          }
          else
          {
            off_98 = (_UNKNOWN *)v8;
            *(_QWORD *)v8 = &smem_client_channel_list_head;
            *(_QWORD *)(v8 + 8) = v12;
            *v12 = v8;
            if ( v2 > 2 )
              goto LABEL_17;
          }
          ++v2;
          v3 += 4;
          if ( v2 >= (unsigned int)v19 )
            goto LABEL_17;
        }
        _fortify_panic(2, -1, 0);
LABEL_32:
        _fortify_panic(7, 24, v11);
      }
LABEL_17:
      if ( HIDWORD(v22) == 267194349 )
      {
        v13 = &smem_client_channel_list_head;
        info_validated = 1;
        while ( 1 )
        {
          v13 = (_UNKNOWN **)*v13;
          if ( v13 == &smem_client_channel_list_head )
            goto LABEL_29;
          byname = of_irq_get_byname(v0, (char *)v13 + 33);
          if ( (byname & 0x80000000) != 0 )
          {
            printk(&unk_70CA);
            goto LABEL_29;
          }
          if ( (devm_request_threaded_irq(dev, byname, 0, smem_read_ready, 3, (char *)v13 + 33, v13) & 0x80000000) != 0 )
          {
            printk(&unk_7145);
            goto LABEL_29;
          }
        }
      }
      v15 = &unk_7334;
    }
    else
    {
      v15 = &unk_7524;
    }
  }
  else
  {
    v15 = &unk_75DE;
  }
  printk(v15);
  result = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
