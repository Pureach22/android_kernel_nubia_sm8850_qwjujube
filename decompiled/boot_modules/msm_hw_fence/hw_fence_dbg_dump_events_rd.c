__int64 __fastcall hw_fence_dbg_dump_events_rd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x30
  __int64 v5; // x25
  __int64 v6; // x24
  __int64 v10; // x4
  __int64 v11; // x20
  unsigned __int64 v12; // x6
  __int64 v13; // x10
  __int64 *v14; // x9
  unsigned __int64 i; // x11
  __int64 v16; // x12
  __int64 v17; // t1
  __int64 v18; // x24
  char v19; // w8
  unsigned int v20; // w25
  signed int v21; // w3
  _QWORD *v22; // x1
  __int64 v23; // x8
  int v24; // w0
  unsigned int v25; // w9
  __int64 v26; // x4
  __int64 v27; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v36; // x8
  __int64 v37; // x0
  unsigned __int64 v38; // x8
  unsigned __int64 v40; // x9
  unsigned int v41; // w25
  __int64 qtime; // x0
  unsigned int v43; // w26
  __int64 v44; // x0
  _QWORD *v46; // [xsp+8h] [xbp-88h]
  __int64 v47; // [xsp+10h] [xbp-80h]
  _QWORD v48[13]; // [xsp+18h] [xbp-78h] BYREF
  int v49; // [xsp+80h] [xbp-10h]
  __int64 v50; // [xsp+88h] [xbp-8h]

  v5 = v4;
  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v6 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    printk(&unk_2A0F5, "hw_fence_dbg_dump_events_rd", 708, v4, a1);
    v18 = -22;
    goto LABEL_55;
  }
  if ( !*(_QWORD *)(v6 + 88) )
  {
    printk(&unk_2A02D, "hw_fence_dbg_dump_events_rd", 714, v4, a1);
    v18 = -22;
    goto LABEL_55;
  }
  if ( hw_fence_dbg_dump_events_rd_wraparound == 1
    && hw_fence_dbg_dump_events_rd_index >= hw_fence_dbg_dump_events_rd_start_index )
  {
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      printk(
        &unk_290E4,
        "hw_fence_dbg_dump_events_rd",
        720,
        (unsigned int)hw_fence_dbg_dump_events_rd_index,
        *(unsigned int *)(v6 + 96));
    v18 = 0;
    hw_fence_dbg_dump_events_rd_index = 0;
    hw_fence_dbg_dump_events_rd_start_time = 0;
    hw_fence_dbg_dump_events_rd_wraparound = 0;
    goto LABEL_55;
  }
  if ( a3 <= 0x1F )
  {
    printk(&unk_208E3, "hw_fence_dbg_dump_events_rd", 729, v4, a3);
    v18 = -22;
    goto LABEL_55;
  }
  v11 = _kmalloc_cache_noprof(kvfree, 3520, 4096);
  if ( !v11 )
  {
    v18 = -12;
    goto LABEL_55;
  }
  if ( !hw_fence_dbg_dump_events_rd_start_time )
  {
    __dsb(0xFu);
    v12 = *(unsigned int *)(v6 + 96);
    if ( (_DWORD)v12 )
    {
      v13 = hw_fence_dbg_dump_events_rd_start_time;
      v14 = *(__int64 **)(v6 + 88);
      for ( i = 0; i < v12; ++i )
      {
        v17 = *v14;
        v14 += 8;
        v16 = v17;
        if ( v17 - 1 < (unsigned __int64)(v13 - 1) )
        {
          v13 = v16;
          hw_fence_dbg_dump_events_rd_start_time = v16;
          hw_fence_dbg_dump_events_rd_start_index = i;
        }
      }
    }
    v10 = (unsigned int)hw_fence_dbg_dump_events_rd_start_index;
    hw_fence_dbg_dump_events_rd_index = hw_fence_dbg_dump_events_rd_start_index;
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      printk(
        &unk_2AC9A,
        "hw_fence_dbg_dump_events_rd",
        742,
        *(_QWORD *)(v6 + 88),
        (unsigned int)hw_fence_dbg_dump_events_rd_start_index);
  }
  v46 = a4;
  v47 = v5;
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
  {
    v41 = hw_fence_dbg_dump_events_rd_index;
    qtime = hw_fence_get_qtime(v6);
    printk(&unk_21D8C, "hw_fence_dbg_dump_events_rd", 745, v41, qtime);
  }
  v19 = hw_fence_dbg_dump_events_rd_wraparound;
  v20 = 0;
  while ( (v19 & 1) == 0 )
  {
    if ( v20 > 0xFDF )
      goto LABEL_32;
    v21 = hw_fence_dbg_dump_events_rd_index;
LABEL_28:
    v49 = 0;
    v22 = (_QWORD *)(*(_QWORD *)(v6 + 88) + ((__int64)v21 << 6));
    memset(v48, 0, sizeof(v48));
    if ( *v22 )
    {
      dump_event(4, (__int64)v22, (__int64)v48, v21);
      v23 = *(_QWORD *)(v6 + 88) + ((__int64)hw_fence_dbg_dump_events_rd_index << 6);
      v24 = scnprintf(
              v11 + v20,
              4096 - v20,
              "[%d][cpu:%d][%llu] data[%d]:%s\n",
              hw_fence_dbg_dump_events_rd_index,
              *(_DWORD *)(v23 + 8),
              *(_QWORD *)v23,
              *(_DWORD *)(v23 + 12),
              (const char *)v48);
      v19 = hw_fence_dbg_dump_events_rd_wraparound;
      v21 = hw_fence_dbg_dump_events_rd_index;
      v20 += v24;
    }
    v25 = *(_DWORD *)(v6 + 96);
    hw_fence_dbg_dump_events_rd_index = v21 + 1;
    if ( v21 + 1 >= v25 )
    {
      v19 = 1;
      hw_fence_dbg_dump_events_rd_index = 0;
      hw_fence_dbg_dump_events_rd_wraparound = 1;
    }
  }
  v21 = hw_fence_dbg_dump_events_rd_index;
  if ( hw_fence_dbg_dump_events_rd_index < hw_fence_dbg_dump_events_rd_start_index && v20 < 0xFE0 )
    goto LABEL_28;
LABEL_32:
  if ( (~msm_hw_fence_debug_level & 0x10001) != 0 )
  {
    if ( (v20 & 0x80000000) == 0 )
      goto LABEL_34;
LABEL_47:
    printk(&unk_277B7, "hw_fence_dbg_dump_events_rd", 765, v47, v20);
    goto LABEL_48;
  }
  v43 = hw_fence_dbg_dump_events_rd_index;
  v44 = hw_fence_get_qtime(v6);
  printk(&unk_2A196, "hw_fence_dbg_dump_events_rd", 762, v43, v44);
  if ( (v20 & 0x80000000) != 0 )
    goto LABEL_47;
LABEL_34:
  v18 = v20;
  if ( v20 > a3 )
    goto LABEL_47;
  if ( v20 )
  {
    if ( v20 > 0x1000 )
    {
      _copy_overflow(4096, v20);
      v27 = v47;
    }
    else
    {
      _check_object_size(v11, v20, 1);
      v27 = v47;
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v29 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v29 = a2 & ((__int64)(a2 << 8) >> 8);
      if ( 0x8000000000LL - (unsigned __int64)v20 >= v29 )
      {
        v30 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v36 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v36 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v36);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v30);
        v37 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v11, v20);
        v38 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v40 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v40 - 4096);
        _WriteStatusReg(TTBR1_EL1, v40);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v38);
        if ( !v37 )
        {
          *v46 += v20;
          goto LABEL_51;
        }
      }
    }
    printk(&unk_24E1F, "hw_fence_dbg_dump_events_rd", 776, v27, v26);
    v18 = -14;
  }
  else
  {
LABEL_48:
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      printk(&unk_2B238, "hw_fence_dbg_dump_events_rd", 771, a3, v10);
    v18 = 0;
  }
LABEL_51:
  kfree(v11);
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return v18;
}
