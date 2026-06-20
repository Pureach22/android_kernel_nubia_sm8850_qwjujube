__int64 __fastcall hfi_core_event_callback(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x21
  __int64 v7; // x24
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  _DWORD *v15; // x19
  __int64 v16; // x8
  int v17; // w9
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  unsigned int v21; // w8
  unsigned int v22; // w9
  int v23; // w8
  __int64 *v24; // x9
  int v25; // w8
  __int64 (*v26)(void); // x8
  __int64 v27; // x0
  int v28; // w8
  __int64 v29; // x3
  void *v30; // x0
  __int64 v31; // x2
  void *v32; // x0
  __int64 v33; // x2
  __int64 result; // x0
  __int64 v35; // [xsp+18h] [xbp-78h]
  unsigned __int64 v37; // [xsp+28h] [xbp-68h] BYREF
  __int64 v38; // [xsp+30h] [xbp-60h]
  __int64 v39; // [xsp+38h] [xbp-58h]
  __int64 *v40; // [xsp+40h] [xbp-50h]
  __int128 v41; // [xsp+48h] [xbp-48h] BYREF
  __int64 v42; // [xsp+58h] [xbp-38h] BYREF
  __int64 v43; // [xsp+60h] [xbp-30h]
  __int64 *v44; // [xsp+68h] [xbp-28h] BYREF
  __int64 v45; // [xsp+70h] [xbp-20h] BYREF
  __int64 v46; // [xsp+78h] [xbp-18h] BYREF
  int v47; // [xsp+80h] [xbp-10h]
  __int64 v48; // [xsp+88h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = nullptr;
  v42 = 0;
  v41 = 0u;
  v39 = 0;
  v40 = nullptr;
  v37 = 0;
  v38 = 0;
  if ( a1 == 192 )
  {
    v30 = &unk_1F5F5;
    v31 = 691;
LABEL_30:
    printk(v30, "hfi_core_event_callback", v31, v5, a5);
    goto LABEL_36;
  }
  v6 = *(_QWORD *)(a1 - 184);
  if ( !v6 )
  {
    v30 = &unk_1AC7C;
    v31 = 697;
    goto LABEL_30;
  }
  v7 = 0;
  _ReadStatusReg(SP_EL0);
  v35 = v5;
  while ( 1 )
  {
    if ( *((_BYTE *)&g_debug_events + v7 + 68) != 1 )
      goto LABEL_5;
    if ( v7 == 200 && dword_1FB10 != 10 )
      goto LABEL_36;
    v8 = _kmalloc_cache_noprof(devm_free_irq, 3520, 40);
    v44 = (__int64 *)v8;
    if ( !v8 )
    {
      printk(&unk_1C1ED, "hfi_core_event_callback", 717, v35, 3);
      goto LABEL_36;
    }
    *(_DWORD *)(v8 + 24) = 1;
    if ( (unsigned int)get_device_tx_buffer(v6, 3u, v8, v9, v10) || (v13 = *v44) == 0 || (v14 = v44[2]) == 0 )
    {
      printk(&unk_1BCE1, "hfi_core_event_callback", 726, v35, 3);
      goto LABEL_36;
    }
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      printk(&unk_1E6B4, "hfi_core_event_callback", 733, 3, v13);
      v13 = *v44;
      v14 = v44[2];
    }
    v15 = (_DWORD *)((char *)&g_debug_events + v7);
    v16 = *(_QWORD *)((char *)&g_debug_events + v7 + 44);
    v17 = *(_DWORD *)((char *)&g_debug_events + v7 + 52);
    v42 = v13;
    LODWORD(v43) = v14;
    *(_QWORD *)((char *)&v41 + 4) = v16;
    HIDWORD(v41) = v17;
    if ( (unsigned int)hfi_create_header(&v42, &v41, v11, v12, v13) )
    {
      v32 = &unk_19261;
      v33 = 746;
      goto LABEL_35;
    }
    v21 = v15[14];
    v22 = v15[15];
    LODWORD(v39) = 2;
    v37 = __PAIR64__(v22, v21);
    v23 = v15[16];
    LODWORD(v38) = 0;
    HIDWORD(v38) = v23;
    if ( v7 == 200 )
    {
      v24 = &v45;
      v45 = 0x100000000LL;
      v25 = 8;
    }
    else
    {
      v26 = (__int64 (*)(void))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v27 = v26();
      v28 = *(_DWORD *)((char *)&g_debug_events + v7 + 72);
      v46 = __ROR8__(v27, 32);
      v24 = &v46;
      v47 = v28;
      v25 = 12;
    }
    v40 = v24;
    HIDWORD(v39) = v25;
    if ( (unsigned int)hfi_create_full_packet((__int64)&v42, (__int64)&v37, v18, v19, v20) )
    {
      v32 = &unk_1CF50;
      v33 = 772;
      goto LABEL_35;
    }
    if ( (unsigned int)set_device_tx_buffer(v6, 3u, &v44, 1, v20) )
      break;
    trigger_ipc(3u, v6, 1, v29, v20);
    kfree(v44);
    if ( v7 == 200 )
    {
      byte_1FAF0 = 0;
      dword_1FB10 = 0;
      byte_1FB14 = 0;
      qword_1FAF4 = 0;
      qword_1FAFC = 0;
      qword_1FB04 = 0;
      goto LABEL_36;
    }
    if ( v7 )
      *((_BYTE *)&g_debug_events + v7 + 68) = 0;
    else
      ++dword_1FA48;
LABEL_5:
    v7 += 40;
    if ( v7 == 240 )
      goto LABEL_36;
  }
  v32 = &unk_18FE3;
  v33 = 781;
LABEL_35:
  printk(v32, "hfi_core_event_callback", v33, v35, v20);
  kfree(v44);
LABEL_36:
  result = kthread_queue_delayed_work(a1 - 56, a1, 3);
  _ReadStatusReg(SP_EL0);
  return result;
}
