__int64 __fastcall btfmcodec_dai_prepare(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x8
  unsigned int v4; // w21
  unsigned int v5; // w22
  unsigned int v6; // w20
  char *v7; // x25
  __int64 *v8; // x24
  __int64 *v9; // x23
  __int64 v10; // x0
  __int64 *v11; // x27
  __int64 **v12; // x8
  __int64 *v13; // x9
  char v14; // w8
  char v15; // w9
  __int64 v16; // x2
  __int64 v17; // x8
  __int64 result; // x0
  unsigned int current_transport; // w0
  __int64 v20; // x19
  int v21; // w8
  __int64 v22; // x20
  void *v23; // x0
  bool v24; // zf
  char v25; // [xsp+Ch] [xbp-44h]
  _QWORD v26[5]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v27; // [xsp+3Ch] [xbp-14h] BYREF
  char v28; // [xsp+44h] [xbp-Ch]
  char v29; // [xsp+45h] [xbp-Bh]
  __int64 v30; // [xsp+48h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(a2 + 96) + 24LL) + 152LL);
  v3 = v2[123];
  if ( v3 )
    v3 = *(_QWORD *)(v3 + 80);
  v4 = *(_DWORD *)(a2 + 80);
  v5 = *(_DWORD *)(a1 + 60);
  v6 = *(_DWORD *)(a2 + 8);
  v7 = *(char **)(*(_QWORD *)(v3 + 112) + 56LL);
  printk(&unk_D01A, "btfmcodec_dai_prepare");
  v8 = (__int64 *)v2[124];
  v9 = v2 + 124;
  v25 = *v7;
  if ( v8 != v2 + 124 )
  {
    do
    {
      v11 = (__int64 *)*v8;
      if ( v6 == *((unsigned __int8 *)v8 - 24) )
      {
        printk(&unk_CD53, "btfmcodec_check_and_cache_configs");
        v12 = (__int64 **)v8[1];
        if ( *v12 == v8 && (v13 = (__int64 *)*v8, *(__int64 **)(*v8 + 8) == v8) )
        {
          v13[1] = (__int64)v12;
          *v12 = v13;
        }
        else
        {
          _list_del_entry_valid_or_report(v8);
        }
        *v8 = 0xDEAD000000000100LL;
        v8[1] = 0xDEAD000000000122LL;
      }
      v8 = v11;
    }
    while ( v11 != v9 );
  }
  v10 = _kmalloc_cache_noprof(device_initialize, 3520, 48);
  if ( v10 )
  {
    *(_BYTE *)(v10 + 8) = v6;
    v14 = bits_per_second;
    *(_DWORD *)(v10 + 12) = v4;
    *(_BYTE *)(v10 + 17) = v25;
    v15 = num_channels;
    *(_BYTE *)(v10 + 16) = v14;
    *(_DWORD *)(v10 + 20) = v5;
    *(_BYTE *)(v10 + 24) = v15;
    v16 = *v9;
    v17 = v10 + 32;
    if ( *(__int64 **)(*v9 + 8) != v9 || (__int64 *)v17 == v9 || v16 == v17 )
    {
      _list_add_valid_or_report(v10 + 32, v2 + 124);
    }
    else
    {
      *(_QWORD *)(v16 + 8) = v17;
      *(_QWORD *)(v10 + 32) = v16;
      *(_QWORD *)(v10 + 40) = v9;
      *v9 = v17;
    }
    printk(&unk_BF23, "btfmcodec_check_and_cache_configs");
  }
  else
  {
    printk(&unk_CD85, "btfmcodec_check_and_cache_configs");
  }
  if ( (unsigned int)btfmcodec_get_current_transport((__int64)(v2 + 114))
    && (unsigned int)btfmcodec_get_current_transport((__int64)(v2 + 114)) != 2 )
  {
    current_transport = btfmcodec_get_current_transport((__int64)(v2 + 114));
    coverttostring(current_transport);
    printk(&unk_C5B0, "btfmcodec_dai_prepare");
    v20 = v2[122];
    *(_BYTE *)(v20 + 751) = 0;
    v27 = 0x258000008LL;
    v28 = 2;
    v29 = v6;
    result = btfmcodec_dev_enqueue_pkt(v20, &v27, 0xAu);
    if ( (result & 0x80000000) == 0 )
    {
      printk(&unk_C696, "btfmcodec_notify_usecase_start");
      v21 = *(unsigned __int8 *)(v20 + 751);
      if ( *(_BYTE *)(v20 + 751) )
      {
        result = 1250;
      }
      else
      {
        memset(v26, 0, sizeof(v26));
        init_wait_entry(v26, 0);
        result = prepare_to_wait_event(v20 + 720, v26, 1);
        if ( *(_BYTE *)(v20 + 751) )
        {
          v22 = 1250;
LABEL_28:
          finish_wait(v20 + 720, v26);
          result = v22;
        }
        else
        {
          v22 = 1250;
          while ( !result )
          {
            v22 = schedule_timeout(v22);
            result = prepare_to_wait_event(v20 + 720, v26, 1);
            if ( v22 )
              v24 = 1;
            else
              v24 = *(_BYTE *)(v20 + 751) == 0;
            if ( !v24 )
              v22 = 1;
            if ( *(_BYTE *)(v20 + 751) || !v22 )
              goto LABEL_28;
          }
        }
        if ( !(_DWORD)result )
        {
          printk(&unk_C6C9, "btfmcodec_notify_usecase_start");
          result = 4294967293LL;
          goto LABEL_22;
        }
        v21 = *(unsigned __int8 *)(v20 + 751);
      }
      switch ( v21 )
      {
        case 1:
          result = 0;
          goto LABEL_22;
        case 3:
          v23 = &unk_BEE1;
          break;
        case 2:
          v23 = &unk_D7F9;
          break;
        default:
          goto LABEL_22;
      }
      printk(v23, "btfmcodec_notify_usecase_start");
      result = 0xFFFFFFFFLL;
    }
  }
  else
  {
    result = btfmcodec_hwep_prepare((__int64)v2, v4, v5, v6, 0);
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
