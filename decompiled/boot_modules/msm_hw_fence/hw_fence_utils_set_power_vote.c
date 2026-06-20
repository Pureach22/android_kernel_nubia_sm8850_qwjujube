__int64 __fastcall hw_fence_utils_set_power_vote(__int64 a1, unsigned int a2, char a3)
{
  __int64 v3; // x30
  __int64 v4; // x21
  __int64 v9; // x1
  unsigned int v10; // w22
  unsigned int v11; // w27
  unsigned int v12; // w23
  __int64 v13; // x4
  unsigned int v14; // w24
  unsigned int v15; // w25
  int signal_id; // w0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x4
  __int64 v20; // x25
  int v21; // w24
  __int64 v22; // x0
  __int64 v23; // x24
  int v24; // w8
  __int64 result; // x0
  __int64 v27; // x4
  unsigned int v32; // w8
  int v34; // w8
  _QWORD v35[5]; // [xsp+10h] [xbp-70h] BYREF
  __int64 v36[2]; // [xsp+38h] [xbp-48h] BYREF
  __int64 v37; // [xsp+48h] [xbp-38h]
  __int64 v38; // [xsp+50h] [xbp-30h]
  __int64 v39; // [xsp+58h] [xbp-28h]
  __int64 v40; // [xsp+60h] [xbp-20h]
  __int128 v41; // [xsp+68h] [xbp-18h]
  __int64 v42; // [xsp+78h] [xbp-8h]

  v4 = v3;
  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (*(_BYTE *)(a1 + 33520) & 1) == 0 )
  {
    printk(&unk_26754, "hw_fence_utils_set_power_vote", 922, v3, a1);
    result = 4294967274LL;
    goto LABEL_37;
  }
  mutex_lock(a1 + 33624);
  _X0 = (unsigned int *)(a1 + 33676);
  if ( (a3 & 1) != 0 )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v32 = __ldxr(_X0);
    while ( __stxr(v32 + 1, _X0) );
    if ( v32 )
    {
      if ( (((v32 + 1) | v32) & 0x80000000) == 0 )
        goto LABEL_9;
      v9 = 1;
    }
    else
    {
      v9 = 2;
    }
    goto LABEL_49;
  }
  if ( *_X0 == 1 )
  {
    mutex_unlock(a1 + 33624);
    printk(&unk_240A1, "hw_fence_utils_set_power_vote", 933, v4, v27);
    result = 4294967274LL;
    goto LABEL_37;
  }
  __asm { PRFM            #0x11, [X0] }
  do
    v34 = __ldxr(_X0);
  while ( __stlxr(v34 - 1, _X0) );
  if ( v34 <= 1 )
  {
    v9 = 4;
LABEL_49:
    refcount_warn_saturate(_X0, v9);
  }
LABEL_9:
  v10 = *(unsigned __int8 *)(a1 + 33672);
  v11 = *(_DWORD *)(a1 + 33676);
  v12 = v11 > 1;
  if ( v10 == v12 )
  {
    v12 = *(unsigned __int8 *)(a1 + 33672);
  }
  else
  {
    v41 = 0u;
    v39 = 0;
    v40 = 0;
    v37 = 0;
    v38 = 0;
    v36[1] = 0;
    if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
      printk(&unk_27484, "_set_soccp_fw_state", 820, a2, v11 > 1);
    LODWORD(v37) = a2;
    HIDWORD(v37) = v11 > 1;
    v36[0] = 0x100002100000040LL;
    *(_QWORD *)((char *)&v41 + 4) = hw_fence_get_qtime();
    if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
      printk(&unk_2A39C, "hw_fence_utils_update_power_payload", 765, 33, 256);
    if ( (unsigned int)hw_fence_update_queue_helper(a1, 0, a1 + 216, v36, 0) )
    {
      printk(&unk_281E8, "_set_soccp_fw_state", 829, v4, v13);
    }
    else
    {
      v14 = *(_DWORD *)(a1 + 632);
      v15 = *(_DWORD *)(a1 + 636);
      signal_id = hw_fence_ipcc_get_signal_id(a1, 0);
      v17 = hw_fence_ipcc_trigger_signal(a1, v14, v15, signal_id);
      v18 = ktime_get(v17);
      LOBYTE(v19) = *(_BYTE *)(a1 + 33672);
      v20 = v18 + 20000000;
      do
      {
        if ( v12 == (unsigned __int8)v19 )
        {
          v21 = 5;
        }
        else
        {
          memset(v35, 0, sizeof(v35));
          init_wait_entry(v35, 0);
          prepare_to_wait_event(a1 + 33736, v35, 2);
          v22 = 5;
          if ( *(unsigned __int8 *)(a1 + 33672) != v12 )
          {
            do
            {
              v23 = schedule_timeout(v22);
              prepare_to_wait_event(a1 + 33736, v35, 2);
              v24 = *(unsigned __int8 *)(a1 + 33672);
              if ( v23 )
                _ZF = 0;
              else
                _ZF = v24 == v12;
              if ( _ZF )
                v22 = 1;
              else
                v22 = v23;
            }
            while ( v24 != v12 && v22 );
          }
          v21 = v22;
          v18 = finish_wait(a1 + 33736, v35);
        }
        v18 = ktime_get(v18);
        v19 = *(unsigned __int8 *)(a1 + 33672);
      }
      while ( (_DWORD)v19 != v12 && !v21 && v20 != v18 && ((v20 - v18) & 0x8000000000000000LL) == 0 );
      if ( (_DWORD)v19 == v12 )
        goto LABEL_34;
      printk(&unk_2B00E, "_set_soccp_fw_state", 843, v4, v19);
    }
    v12 = *(unsigned __int8 *)(a1 + 33672);
  }
LABEL_34:
  mutex_unlock(a1 + 33624);
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    printk(&unk_279F1, "hw_fence_utils_set_power_vote", 947, v10, v12);
  result = 0;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
