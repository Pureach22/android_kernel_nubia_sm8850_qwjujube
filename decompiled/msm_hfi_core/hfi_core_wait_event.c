__int64 __fastcall hfi_core_wait_event(__int64 a1, int *a2)
{
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x24
  int v8; // w21
  __int64 v9; // x0
  __int64 v10; // x21
  int v11; // w8
  bool v12; // zf
  __int64 v13; // x3
  __int64 v14; // x4
  int v15; // w8
  __int64 result; // x0
  unsigned int v17; // w19
  __int64 v18; // x24
  _QWORD v19[6]; // [xsp+0h] [xbp-30h] BYREF

  v19[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 168);
  v4 = ((__int64 (*)(void))ktime_get)();
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v18 = v4;
    printk(&unk_1E83A, "hfi_core_wait_event", 759, v5, v6);
    v4 = v18;
  }
  v7 = v4 + 100000000000LL;
  do
  {
    if ( *a2 == 1 )
    {
      v8 = 25000;
    }
    else
    {
      memset(v19, 0, 40);
      init_wait_entry(v19, 0);
      prepare_to_wait_event(v3, v19, 2);
      LODWORD(v9) = 25000;
      if ( *a2 != 1 )
      {
        do
        {
          v10 = schedule_timeout();
          prepare_to_wait_event(v3, v19, 2);
          v11 = *a2;
          if ( v10 )
            v12 = 0;
          else
            v12 = v11 == 1;
          if ( v12 )
            v9 = 1;
          else
            v9 = v10;
        }
        while ( v11 != 1 && v9 );
      }
      v8 = v9;
      v4 = finish_wait(v3, v19);
    }
    v4 = ktime_get(v4);
  }
  while ( *a2 != 1 && !v8 && v7 != v4 && ((v7 - v4) & 0x8000000000000000LL) == 0 );
  v15 = msm_hfi_core_debug_level;
  if ( *a2 != 1 )
  {
    result = 4294967186LL;
    if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
      goto LABEL_24;
LABEL_26:
    v17 = result;
    printk(&unk_1C28B, "hfi_core_wait_event", 775, v13, v14);
    result = v17;
    goto LABEL_24;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1F598, "hfi_core_wait_event", 769, v13, v14);
    v15 = msm_hfi_core_debug_level;
  }
  result = 0;
  if ( (~v15 & 0x10001) == 0 )
    goto LABEL_26;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
