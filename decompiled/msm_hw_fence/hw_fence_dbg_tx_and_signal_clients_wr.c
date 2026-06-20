size_t __fastcall hw_fence_dbg_tx_and_signal_clients_wr(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x20
  size_t v5; // x19
  __int64 v7; // x21
  _QWORD *v9; // x22
  _QWORD *v10; // x8
  _QWORD *v11; // x28
  _QWORD *v12; // x8
  _QWORD *v13; // x23
  unsigned __int64 v14; // x22
  unsigned __int64 v15; // x23
  __int64 v16; // x26
  __int64 v17; // x27
  __int64 v18; // x4
  __int64 v19; // x4
  __int64 v20; // x1
  __int64 v21; // x2
  int v22; // w9
  unsigned int v23; // w8
  unsigned int v24; // w26
  unsigned int v25; // w27
  __int64 v26; // x30
  void *v27; // x0
  __int64 v28; // x2
  __int64 v29; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v30; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v31; // [xsp+18h] [xbp-18h] BYREF
  __int16 v32; // [xsp+20h] [xbp-10h]
  __int64 v33; // [xsp+28h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v29 = 0;
  v32 = 0;
  v31 = 0;
  if ( !a1 || (v4 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    printk(&unk_2A0F5, "hw_fence_dbg_tx_and_signal_clients_wr", 356, v3, a1);
LABEL_9:
    v5 = -22;
    goto LABEL_7;
  }
  v5 = a3;
  if ( a3 > 9
    || (v7 = v3, _check_object_size(&v31, a3, 0), inline_copy_from_user((__int64)&v31, a2, v5))
    || (*((_BYTE *)&v31 + v5) = 0, (unsigned int)kstrtouint(&v31, 0, &v30)) )
  {
    v5 = -14;
    goto LABEL_7;
  }
  if ( !v30 )
  {
    printk(&unk_2A671, "hw_fence_dbg_tx_and_signal_clients_wr", 373, v7, 0);
    v5 = 0;
    goto LABEL_7;
  }
  if ( v30 >= 0xC9 )
  {
    printk(&unk_25E84, "hw_fence_dbg_tx_and_signal_clients_wr", 377, v7, v30);
    v30 = 200;
  }
  mutex_lock(v4 + 544);
  v9 = (_QWORD *)(v4 + 528);
  v10 = (_QWORD *)(v4 + 528);
  while ( 1 )
  {
    v10 = (_QWORD *)*v10;
    if ( v10 == v9 )
      break;
    if ( *((_DWORD *)v10 - 16) == 65 )
    {
      v11 = v10 - 8;
      goto LABEL_18;
    }
  }
  v11 = nullptr;
LABEL_18:
  mutex_unlock(v4 + 544);
  mutex_lock(v4 + 544);
  v12 = (_QWORD *)(v4 + 528);
  while ( 1 )
  {
    v12 = (_QWORD *)*v12;
    if ( v12 == v9 )
      break;
    if ( *((_DWORD *)v12 - 16) == 66 )
    {
      v13 = v12 - 8;
      goto LABEL_23;
    }
  }
  v13 = nullptr;
LABEL_23:
  mutex_unlock(v4 + 544);
  if ( !v11
    || !v13
    || (v14 = v11[3]) == 0
    || v14 > 0xFFFFFFFFFFFFF000LL
    || (v15 = v13[3]) == 0
    || v15 > 0xFFFFFFFFFFFFF000LL )
  {
    printk(&unk_27EBF, "hw_fence_dbg_tx_and_signal_clients_wr", 391, v7, 65);
    goto LABEL_9;
  }
  if ( *(_BYTE *)(v4 + 520) == 1 && v30 )
  {
    while ( 1 )
    {
      v17 = v11[1];
      v16 = v11[2];
      v11[2] = v16 + 1;
      if ( (unsigned int)hw_fence_create(v4, v14, v17, v17, v16, &v29) )
      {
        v26 = v7;
        v27 = &unk_2391F;
        v28 = 414;
        goto LABEL_44;
      }
      ((void (__fastcall *)(__int64, unsigned __int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _DWORD))hw_fence_update_queue)(
        v4,
        v14,
        v17,
        v16,
        v29,
        0,
        0,
        0,
        0);
      if ( (unsigned int)hw_fence_register_wait_client(v4, 0, v15, v17, v16, &v29, 0) )
      {
        printk(&unk_290AA, "hw_fence_dbg_tx_and_signal_clients_wr", 429, v7, v19);
        goto LABEL_9;
      }
      v20 = *(unsigned int *)(v4 + 632);
      v21 = *(unsigned int *)(v4 + 628);
      if ( (~msm_hw_fence_debug_level & 0x10040) == 0 )
      {
        v24 = *(_DWORD *)(v4 + 632);
        v25 = *(_DWORD *)(v4 + 628);
        printk(&unk_29BF2, "hw_fence_dbg_tx_and_signal_clients_wr", 451, 65, (unsigned int)v20);
        v21 = v25;
        v20 = v24;
      }
      hw_fence_ipcc_trigger_signal(v4, v20, v21, 0);
      usleep_range_state(*(unsigned int *)(v4 + 516), (unsigned int)(*(_DWORD *)(v4 + 516) + 5), 2);
      if ( (unsigned int)hw_fence_destroy_with_hash(v4, v14, v29) )
        break;
      v22 = *(unsigned __int8 *)(v4 + 520);
      v23 = --v30;
      if ( v22 != 1 || !v23 )
        goto LABEL_7;
    }
    v26 = v7;
    v27 = &unk_21D54;
    v28 = 470;
LABEL_44:
    printk(v27, "hw_fence_dbg_tx_and_signal_clients_wr", v28, v26, v18);
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v5;
}
