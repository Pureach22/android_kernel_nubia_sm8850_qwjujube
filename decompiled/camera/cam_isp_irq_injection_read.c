__int64 __fastcall cam_isp_irq_injection_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v7; // x0
  _QWORD *v9; // x22
  __int64 v10; // x23
  size_t v11; // x0
  __int64 v13; // x8
  size_t v14; // x2
  void *v15; // x0
  __int64 v16; // x19
  __int64 v17; // x23
  int v18; // w28
  char *v19; // x20
  const char *v20; // x4
  int v21; // w8
  __int64 v22; // x20
  _QWORD *v23; // x21
  _QWORD *v24; // x19
  _QWORD *v25; // x21
  __int64 v26; // x8
  _QWORD *v27; // x19
  __int64 v28; // x8
  __int64 v29; // x8
  _QWORD *v30; // x21
  const char *v31; // x3
  __int64 v32; // x8
  const char *v33; // x3
  __int64 v34; // x8
  _QWORD *v35; // x19
  __int64 v36; // x8
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x9
  __int64 v39; // x0
  unsigned __int64 v40; // x9
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v48; // x9
  size_t v49; // x0
  int v50; // w19
  unsigned __int64 StatusReg; // x19
  __int64 v52; // x20
  __int64 *v53; // [xsp+28h] [xbp-8h]

  if ( !irq_inject_display_buf )
    return -22;
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(1500, 0xCC0u, 0, "cam_isp_irq_injection_read", 0x4C71u);
  else
    v7 = _kvmalloc_node_noprof(1500, 0, 3520, 0xFFFFFFFFLL);
  v9 = (_QWORD *)v7;
  if ( !v7 )
    return -12;
  while ( 1 )
  {
    v10 = irq_inject_display_buf;
    if ( *a4 )
    {
      if ( !*(_BYTE *)irq_inject_display_buf )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v9, 0);
        else
          kvfree(v9);
        return 0;
      }
    }
    else if ( *(_BYTE *)irq_inject_display_buf )
    {
      goto LABEL_65;
    }
    v11 = strnlen((const char *)irq_inject_display_buf, 0x1000u);
    if ( v11 != -1 )
      break;
    _fortify_panic(2, -1, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    v52 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_isp_irq_injection_read__alloc_tag;
    v9 = (_QWORD *)_kvmalloc_node_noprof(1500, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v52;
    if ( !v9 )
      return -12;
  }
  if ( v11 <= 0xFFF )
  {
    _CF = v11 >= 0xCE7;
    v13 = v11 + 793;
    if ( v11 >= 0xCE7 )
      v14 = 4095 - v11;
    else
      v14 = 793;
    v15 = (void *)(v10 + v11);
    if ( _CF )
      v16 = 4095;
    else
      v16 = v13;
    memcpy(
      v15,
      "######################################################\n"
      "Usage:\n"
      "$INJECT_NODE : /sys/kernel/debug/camera/ife/isp_irq_inject\n"
      "\n"
      "  - cat $INJECT_NODE\n"
      "    print Usage, injected params and current active HW info.\n"
      "    Also we need to cat the node to get output info after echo params to node.\n"
      "\n"
      "  - echo ?:?:?:? > $INJECT_NODE\n"
      "    print query info, entering '?' to any param besides req_id to query.\n"
      "\n"
      "  - echo hw_type:hw_idx:res_id:irq_mask:req_id > $INJECT_NODE\n"
      "    hw_type  : Hw to inject IRQ\n"
      "    hw_idx   : Index of the selected hw\n"
      "    reg_unit : Register to set irq\n"
      "    irq_mask : IRQ to be triggered\n"
      "    req_id   : Req to trigger the IRQ, entering 'now' to this param will trigger irq immediately\n"
      "\n"
      "Up to 10 sets of inject params are supported.\n"
      "######################################################\n",
      v14);
    *(_BYTE *)(v10 + v16) = 0;
  }
  v17 = 0;
  v18 = 0;
  v19 = &byte_3A86B0;
  do
  {
    if ( *v19 == 1 )
    {
      v21 = *((_DWORD *)v19 - 6);
      if ( v21 )
      {
        if ( v21 == 7 )
        {
          v20 = "SFE";
        }
        else if ( v21 == 2 )
        {
          if ( dword_3A8694 == 65555 )
            v20 = "MC_TFE";
          else
            v20 = "VFE";
        }
        else
        {
          v20 = "Invalid hw_type";
        }
      }
      else
      {
        v20 = "CSID";
      }
      v18 += scnprintf(
               (char *)v9 + v18,
               1500 - v18,
               "injected param[%d] : hw_type:%s hw_idx:%d reg_unit:%d irq_mask:%#x req_id:%lld\n",
               v17,
               v20,
               *((_DWORD *)v19 - 5),
               *((_DWORD *)v19 - 4),
               *((_DWORD *)v19 - 3),
               *((_QWORD *)v19 - 1));
    }
    ++v17;
    v19 += 40;
  }
  while ( v17 != 10 );
  mutex_lock(&unk_394A30);
  v22 = qword_394A78;
  if ( (__int64 *)qword_394A78 == &qword_394A78 )
  {
    scnprintf((char *)v9 + v18, 1500 - v18, "Currently no ctx in use\n");
  }
  else
  {
    do
    {
      v23 = *(_QWORD **)(v22 + 208);
      v53 = *(__int64 **)v22;
      if ( v23 != (_QWORD *)(v22 + 208) )
      {
        do
        {
          v26 = v23[4];
          v27 = (_QWORD *)*v23;
          if ( v26 )
            v18 += scnprintf(
                     (char *)v9 + v18,
                     1500 - v18,
                     "hw_type:CSID hw_idx:%d ctx id:%u res: %s\n",
                     *(_DWORD *)(*(_QWORD *)(v26 + 16) + 4LL),
                     *(_DWORD *)(v22 + 56),
                     (const char *)(v26 + 128));
          v28 = v23[5];
          if ( v28 )
            v18 += scnprintf(
                     (char *)v9 + v18,
                     1500 - v18,
                     "hw_type:CSID hw_idx:%d ctx id:%u res: %s\n",
                     *(_DWORD *)(*(_QWORD *)(v28 + 16) + 4LL),
                     *(_DWORD *)(v22 + 56),
                     (const char *)(v28 + 128));
          v23 = v27;
        }
        while ( v27 != (_QWORD *)(v22 + 208) );
      }
      v24 = *(_QWORD **)(v22 + 224);
      if ( v24 != (_QWORD *)(v22 + 224) )
      {
        do
        {
          v29 = v24[4];
          v30 = (_QWORD *)*v24;
          if ( v29 )
          {
            if ( dword_3A8694 == 65555 )
              v31 = "MC_TFE";
            else
              v31 = "VFE";
            v18 += scnprintf(
                     (char *)v9 + v18,
                     1500 - v18,
                     "hw_type:%s hw_idx:%d ctx id:%u res: %s\n",
                     v31,
                     *(_DWORD *)(*(_QWORD *)(v29 + 16) + 4LL),
                     *(_DWORD *)(v22 + 56),
                     (const char *)(v29 + 128));
          }
          v32 = v24[5];
          if ( v32 )
          {
            if ( dword_3A8694 == 65555 )
              v33 = "MC_TFE";
            else
              v33 = "VFE";
            v18 += scnprintf(
                     (char *)v9 + v18,
                     1500 - v18,
                     "hw_type:%s hw_idx:%d ctx id:%u res: %s\n",
                     v33,
                     *(_DWORD *)(*(_QWORD *)(v32 + 16) + 4LL),
                     *(_DWORD *)(v22 + 56),
                     (const char *)(v32 + 128));
          }
          v24 = v30;
        }
        while ( v30 != (_QWORD *)(v22 + 224) );
      }
      v25 = *(_QWORD **)(v22 + 240);
      if ( v25 != (_QWORD *)(v22 + 240) )
      {
        do
        {
          v34 = v25[4];
          v35 = (_QWORD *)*v25;
          if ( v34 )
            v18 += scnprintf(
                     (char *)v9 + v18,
                     1500 - v18,
                     "hw_type:SFE hw_idx:%d ctx id:%u res: %s\n",
                     *(_DWORD *)(*(_QWORD *)(v34 + 16) + 4LL),
                     *(_DWORD *)(v22 + 56),
                     (const char *)(v34 + 128));
          v36 = v25[5];
          if ( v36 )
            v18 += scnprintf(
                     (char *)v9 + v18,
                     1500 - v18,
                     "hw_type:SFE hw_idx:%d ctx id:%u res: %s\n",
                     *(_DWORD *)(*(_QWORD *)(v36 + 16) + 4LL),
                     *(_DWORD *)(v22 + 56),
                     (const char *)(v36 + 128));
          v25 = v35;
        }
        while ( v35 != (_QWORD *)(v22 + 240) );
      }
      v22 = (__int64)v53;
    }
    while ( v53 != &qword_394A78 );
  }
  mutex_unlock(&unk_394A30);
  strlcat(irq_inject_display_buf, v9, 4096);
LABEL_65:
  v37 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v37 + 70) & 0x20) != 0 || (v38 = a2, (*(_QWORD *)v37 & 0x4000000) != 0) )
    v38 = a2 & ((__int64)(a2 << 8) >> 8);
  v39 = a3;
  if ( a3 <= 0x8000000000LL )
  {
    v39 = a3;
    if ( 0x8000000000LL - a3 >= v38 )
    {
      v40 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v45 = *(_QWORD *)(v37 + 8);
      _WriteStatusReg(TTBR1_EL1, v45 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v45);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v40);
      v39 = _arch_clear_user(a2 & 0xFF7FFFFFFFFFFFFFLL, a3);
      v46 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v48 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v48 - 4096);
      _WriteStatusReg(TTBR1_EL1, v48);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v46);
    }
  }
  if ( v39 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v9, 0);
    else
      kvfree(v9);
    return -5;
  }
  else
  {
    v49 = strlen((const char *)irq_inject_display_buf);
    v50 = simple_read_from_buffer(a2, a3, a4, irq_inject_display_buf, v49);
    memset((void *)irq_inject_display_buf, 0, 0x1000u);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v9, 0);
    else
      kvfree(v9);
    return v50;
  }
}
