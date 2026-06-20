__int64 __fastcall mem_event_callback(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v4; // x9
  __int64 v5; // x19
  unsigned __int64 v6; // x2
  unsigned __int64 v7; // x9
  __int64 result; // x0
  unsigned __int64 v9; // x8
  __int64 v10; // x0
  unsigned __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x0
  __int64 v15; // x0
  unsigned __int64 v16; // x20
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned __int64 v20; // x0
  unsigned __int64 v27; // x10
  unsigned __int64 v30; // x10

  _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(a3 + 16);
  if ( (v4 & 0x7FFF) != 0 || ((*(_QWORD *)(a3 + 24) + v4 + 0x7FFF) & 0xFFFFFFFFFFFF8000LL) != *(_QWORD *)(a3 + 24) + v4 )
  {
    _warn_printk("mem_event_callback");
    __break(0x800u);
    printk(&unk_9D8D);
    result = 4294967274LL;
    goto LABEL_19;
  }
  v5 = v4 << 12;
  v6 = v4 >> 15;
  if ( v4 >> 15 > end_section_nr || (v7 = v6 - start_section_nr, v6 < start_section_nr) )
  {
    if ( a2 == 4 || a2 == 1 )
      printk(&unk_9BA4);
    goto LABEL_18;
  }
  if ( a2 <= 3 )
  {
    if ( a2 == 2 )
    {
      v9 = mem_info
         + 72 * ((v7 + (unsigned int)(end_section_nr - start_section_nr + 1)) / (unsigned int)sections_per_block);
      ++*(_QWORD *)(v9 + 8);
      v10 = cancel_work_sync(&fill_movable_zone_work);
      mem_event_callback_cur = ktime_get(v10);
    }
    else if ( a2 == 1 )
    {
      v11 = v6;
      v12 = ((__int64 (*)(void))ktime_get)();
      record_stat(v11, (v12 - mem_event_callback_cur) / 1000, 0);
      mem_event_callback_cur = 0;
      set_memblk_bitmap_online(v5);
      v13 = printk(&unk_951F);
      v14 = memory_block_size_bytes(v13);
      _X9 = &totalram_pages;
      __asm { PRFM            #0x11, [X9] }
      do
        v27 = __ldxr((unsigned __int64 *)&totalram_pages);
      while ( __stxr(v27 - (v14 >> 12), (unsigned __int64 *)&totalram_pages) );
    }
    goto LABEL_18;
  }
  if ( a2 != 8 )
  {
    if ( a2 == 4 )
    {
      v15 = a3;
      v16 = v6;
      v17 = mem_change_refresh_state(v15, 1);
      v18 = ktime_get(v17);
      record_stat(v16, (v18 - mem_event_callback_cur) / 1000, 1);
      mem_event_callback_cur = 0;
      set_memblk_bitmap_offline(v5);
      v19 = printk(&unk_9DFA);
      v20 = memory_block_size_bytes(v19);
      _X9 = &totalram_pages;
      __asm { PRFM            #0x11, [X9] }
      do
        v30 = __ldxr((unsigned __int64 *)&totalram_pages);
      while ( __stxr(v30 + (v20 >> 12), (unsigned __int64 *)&totalram_pages) );
    }
    else if ( a2 == 16 )
    {
      printk(&unk_95AA);
      mem_change_refresh_state(a3, 1);
    }
    goto LABEL_18;
  }
  ++*(_QWORD *)(mem_info + 72 * (v7 / (unsigned int)sections_per_block) + 8);
  mem_event_callback_cur = ktime_get(a1);
  if ( !(unsigned int)mem_change_refresh_state(a3, 0) )
  {
LABEL_18:
    result = 1;
    goto LABEL_19;
  }
  result = 32770;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
