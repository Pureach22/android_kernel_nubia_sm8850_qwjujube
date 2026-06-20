__int64 __fastcall syna_tcm_allocate_device(__int64 *a1, __int64 a2, __int64 a3)
{
  void *v3; // x0
  __int64 result; // x0
  __int64 *v8; // x23
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x2
  __int64 v12; // x0
  void *v13; // x0
  const char *v14; // x1
  int v15; // w8
  int v16; // w9
  __int64 v17; // x19
  __int64 v18; // x2
  unsigned int v19; // w21
  void *v20; // x0
  void *v21; // x20
  __int64 v22; // x0
  __int64 v23; // x2
  _QWORD *v24; // x20
  __int64 v25; // x0
  __int64 v26; // x2
  __int64 v27; // x2
  char v28; // w8
  __int64 v29; // x2
  __int64 v30; // x20
  __int64 v31; // x0
  __int64 v32; // x2
  __int64 v33; // x2
  __int64 v34; // x20
  __int64 v35; // x0
  __int64 v36; // x2
  __int64 v37; // x2
  __int64 v38; // x20
  __int64 v39; // x0
  __int64 v40; // x2
  __int64 v41; // x0
  __int64 v42; // x2
  char v43; // w8
  const char *v44; // x2
  const char *v45; // x2

  if ( !a2 )
  {
    v3 = &unk_3AC64;
LABEL_7:
    printk(v3, "syna_tcm_allocate_device", a3);
    return 4294967055LL;
  }
  if ( !*(_QWORD *)(a2 + 32) )
  {
    v3 = &unk_384CE;
    goto LABEL_7;
  }
  if ( !*(_QWORD *)(a2 + 40) )
  {
    v3 = &unk_343EB;
    goto LABEL_7;
  }
  printk(&unk_367BF, "syna_tcm_allocate_device", a3);
  v8 = a1;
  *a1 = 0;
  v9 = syna_request_managed_device();
  if ( !v9 )
  {
    printk(&unk_3BE43, "syna_pal_mem_alloc", v10);
LABEL_12:
    v13 = &unk_35C97;
    v14 = "syna_tcm_allocate_device";
    goto LABEL_13;
  }
  v12 = devm_kmalloc(v9, 9192, 3520);
  if ( !v12 )
    goto LABEL_12;
  v16 = *(_DWORD *)(a2 + 12);
  v15 = *(_DWORD *)(a2 + 16);
  *(_QWORD *)v12 = a3;
  v17 = v12;
  *(_QWORD *)(v12 + 72) = a2;
  *(_QWORD *)(v12 + 912) = 0;
  *(_QWORD *)(v12 + 920) = 0;
  *(_QWORD *)(v12 + 928) = 0;
  *(_QWORD *)(v12 + 936) = 0;
  *(_DWORD *)(v12 + 64) = v15;
  *(_DWORD *)(v12 + 68) = v16;
  *(_DWORD *)(v12 + 56) = v15;
  *(_DWORD *)(v12 + 60) = v16;
  _mutex_init(v12 + 80, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_7);
  *(_BYTE *)(v17 + 320) = 0;
  *(_QWORD *)(v17 + 256) = 0;
  *(_QWORD *)(v17 + 264) = 0;
  _mutex_init(v17 + 272, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_7);
  *(_BYTE *)(v17 + 392) = 0;
  *(_QWORD *)(v17 + 328) = 0;
  *(_QWORD *)(v17 + 336) = 0;
  _mutex_init(v17 + 344, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_7);
  *(_BYTE *)(v17 + 464) = 0;
  *(_QWORD *)(v17 + 400) = 0;
  *(_QWORD *)(v17 + 408) = 0;
  _mutex_init(v17 + 416, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_7);
  *(_BYTE *)(v17 + 640) = 0;
  *(_QWORD *)(v17 + 576) = 0;
  *(_QWORD *)(v17 + 584) = 0;
  _mutex_init(v17 + 592, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_7);
  *(_BYTE *)(v17 + 712) = 0;
  *(_QWORD *)(v17 + 648) = 0;
  *(_QWORD *)(v17 + 656) = 0;
  _mutex_init(v17 + 664, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_7);
  *(_BYTE *)(v17 + 784) = 0;
  *(_QWORD *)(v17 + 720) = 0;
  *(_QWORD *)(v17 + 728) = 0;
  _mutex_init(v17 + 736, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_7);
  *(_DWORD *)(v17 + 544) = 0;
  _init_swait_queue_head(v17 + 552, "&x->wait", &init_completion___key_2);
  _mutex_init(v17 + 792, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_7);
  _mutex_init(v17 + 840, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_7);
  *(_DWORD *)(v17 + 504) = 0;
  v18 = *(unsigned __int8 *)(v17 + 640);
  *(_WORD *)(v17 + 508) = 0;
  *(_DWORD *)(v17 + 512) = 0;
  *(_BYTE *)(v17 + 516) = 0;
  if ( (_DWORD)v18 )
    printk(&unk_38244, "syna_tcm_buf_lock", v18);
  mutex_lock(v17 + 592);
  v19 = *(_DWORD *)(v17 + 584);
  v20 = *(void **)(v17 + 576);
  ++*(_BYTE *)(v17 + 640);
  if ( v19 <= 3 )
  {
    if ( v20 )
    {
      v21 = v20;
      v22 = syna_request_managed_device();
      if ( v22 )
        devm_kfree(v22, v21);
      else
        printk(&unk_3BE43, "syna_pal_mem_free", v23);
    }
    v24 = (_QWORD *)(v17 + 576);
    v25 = syna_request_managed_device();
    if ( !v25 )
    {
      printk(&unk_3BE43, "syna_pal_mem_alloc", v26);
      *v24 = 0;
LABEL_25:
      printk(&unk_3703C, "syna_tcm_buf_alloc", 4);
      *(_QWORD *)(v17 + 584) = 0;
      printk(&unk_35CC7, "syna_tcm_init_message_handler", 4);
      v27 = *(unsigned __int8 *)(v17 + 640);
      *(_QWORD *)(v17 + 584) = 0;
      if ( (_DWORD)v27 == 1 )
      {
        v28 = 0;
      }
      else
      {
        printk(&unk_38244, "syna_tcm_buf_unlock", v27);
        v28 = *(_BYTE *)(v17 + 640) - 1;
      }
      *(_BYTE *)(v17 + 640) = v28;
      mutex_unlock(v17 + 592);
      printk(&unk_3B375, "syna_tcm_allocate_device", v29);
      if ( *(_BYTE *)(v17 + 464) )
        printk(&unk_34845, "syna_tcm_buf_release", *(unsigned __int8 *)(v17 + 464));
      v30 = *(_QWORD *)(v17 + 400);
      v31 = syna_request_managed_device();
      if ( v31 )
      {
        if ( v30 )
          devm_kfree(v31, v30);
      }
      else
      {
        printk(&unk_3BE43, "syna_pal_mem_free", v32);
      }
      v33 = *(unsigned __int8 *)(v17 + 320);
      *(_QWORD *)(v17 + 408) = 0;
      *(_BYTE *)(v17 + 464) = 0;
      if ( (_DWORD)v33 )
        printk(&unk_34845, "syna_tcm_buf_release", v33);
      v34 = *(_QWORD *)(v17 + 256);
      v35 = syna_request_managed_device();
      if ( v35 )
      {
        if ( v34 )
          devm_kfree(v35, v34);
      }
      else
      {
        printk(&unk_3BE43, "syna_pal_mem_free", v36);
      }
      v37 = *(unsigned __int8 *)(v17 + 392);
      *(_QWORD *)(v17 + 264) = 0;
      *(_BYTE *)(v17 + 320) = 0;
      if ( (_DWORD)v37 )
        printk(&unk_34845, "syna_tcm_buf_release", v37);
      v38 = *(_QWORD *)(v17 + 328);
      v39 = syna_request_managed_device();
      if ( v39 )
      {
        if ( v38 )
          devm_kfree(v39, v38);
      }
      else
      {
        printk(&unk_3BE43, "syna_pal_mem_free", v40);
      }
      *(_QWORD *)(v17 + 336) = 0;
      *(_BYTE *)(v17 + 392) = 0;
      *(_QWORD *)(v17 + 72) = 0;
      v41 = syna_request_managed_device();
      if ( v41 )
      {
        devm_kfree(v41, v17);
        return 4294967053LL;
      }
      v13 = &unk_3BE43;
      v14 = "syna_pal_mem_free";
LABEL_13:
      printk(v13, v14, v11);
      return 4294967053LL;
    }
    v19 = 4;
    v20 = (void *)devm_kmalloc(v25, 4, 3520);
    *v24 = v20;
    if ( !v20 )
      goto LABEL_25;
    *(_DWORD *)(v17 + 584) = 4;
  }
  memset(v20, 0, v19);
  v42 = *(unsigned __int8 *)(v17 + 640);
  v43 = 0;
  *(_QWORD *)(v17 + 584) = 4;
  if ( (_DWORD)v42 != 1 )
  {
    printk(&unk_38244, "syna_tcm_buf_unlock", v42);
    v43 = *(_BYTE *)(v17 + 640) - 1;
  }
  *(_BYTE *)(v17 + 640) = v43;
  mutex_unlock(v17 + 592);
  *(_BYTE *)(v17 + 890) = 0;
  *(_DWORD *)(v17 + 898) = 0;
  *(_DWORD *)(v17 + 892) = 0;
  *(_QWORD *)(v17 + 520) = 0x1400000BB8LL;
  *(_BYTE *)(v17 + 896) = 0;
  *(_QWORD *)(v17 + 528) = 0x6400000032LL;
  *(_DWORD *)(v17 + 536) = 10;
  *(_BYTE *)(v17 + 9) = 0;
  *(_QWORD *)(v17 + 488) = 0x6400000064LL;
  *v8 = v17;
  printk(&unk_3B99D, "syna_tcm_allocate_device", 2);
  if ( *(_BYTE *)(a2 + 20) )
    v44 = "yes";
  else
    v44 = (const char *)&unk_398C0;
  printk(&unk_36C2A, "syna_tcm_allocate_device", v44);
  result = 0;
  if ( *(_BYTE *)(a2 + 21) == 1 )
  {
    if ( *(_DWORD *)(a2 + 24) )
      v45 = "yes";
    else
      v45 = (const char *)&unk_398C0;
    printk(&unk_3CCBD, "syna_tcm_allocate_device", v45);
    return 0;
  }
  return result;
}
