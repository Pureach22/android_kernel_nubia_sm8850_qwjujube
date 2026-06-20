__int64 __fastcall gen8_process_syncobj_query_work(__int64 a1)
{
  _QWORD *v3; // x21
  _QWORD *i; // x8
  __int64 v5; // x27
  unsigned int v6; // w22
  unsigned int v7; // w23
  __int64 v8; // x9
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x22
  unsigned __int64 v12; // x28
  unsigned __int64 v13; // x24
  _QWORD *v14; // x23
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 v17; // x8
  unsigned int v18; // w3
  unsigned int v19; // w9
  unsigned int v20; // w9
  unsigned int v22; // w9
  void (__fastcall *v23)(_QWORD); // x8
  int v28; // w8
  __int64 result; // x0
  __int64 v30; // [xsp+10h] [xbp-B0h]
  __int64 v31; // [xsp+20h] [xbp-A0h] BYREF
  unsigned __int64 v32; // [xsp+28h] [xbp-98h]
  _QWORD v33[2]; // [xsp+30h] [xbp-90h]
  _QWORD v34[4]; // [xsp+40h] [xbp-80h] BYREF
  _QWORD v35[9]; // [xsp+60h] [xbp-60h] BYREF
  __int16 v36; // [xsp+A8h] [xbp-18h]
  __int64 v37; // [xsp+B0h] [xbp-10h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _X20 = *(_QWORD *)(a1 - 8);
  v3 = *(_QWORD **)(_X20 + 40);
  mutex_lock(v3 + 2806);
  rt_mutex_lock(v3 + 1386);
  for ( i = (_QWORD *)v3[2846]; ; i = (_QWORD *)*i )
  {
    if ( i == v3 + 2846 )
    {
      v17 = *(_QWORD *)(_X20 + 1648);
      v18 = *(_DWORD *)(a1 - 28);
      v19 = *(_DWORD *)(v17 + 16);
      if ( v18 != v19 )
      {
        if ( v18 > v19 && ((v18 - v19) & 0x80000000) == 0
          || (v20 = v19 ^ 0x80000000, _CF = (v18 ^ 0x80000000) >= v20, v22 = (v18 ^ 0x80000000) - v20, v22 != 0 && _CF)
          && v22 <= 0x80000000 )
        {
          dev_err(
            v3[193] + 16LL,
            "Missing sync object ctx:%d ts:%d retired:%d\n",
            *(_DWORD *)(_X20 + 4),
            v18,
            *(_DWORD *)(v17 + 16));
          gmu_core_fault_snapshot(v3, 14);
          gen8_hwsched_fault((__int64)v3, 32);
        }
      }
      goto LABEL_31;
    }
    v5 = *(i - 1);
    if ( (*(_BYTE *)(v5 + 16) & 4) != 0 )
    {
      v6 = *(_DWORD *)(*(_QWORD *)(v5 + 8) + 4LL);
      if ( v6 == *(_DWORD *)(a1 - 32) )
      {
        v7 = *(_DWORD *)(v5 + 20);
        if ( v7 == *(_DWORD *)(a1 - 28) )
          break;
      }
    }
  }
  v8 = v3[1783];
  v9 = *(unsigned int *)(v5 + 136);
  v33[0] = 0;
  v33[1] = 0;
  v31 = 0;
  v32 = 0;
  v10 = *(_QWORD *)(v8 + 40);
  if ( (_DWORD)v9 )
  {
    v30 = v10;
    v11 = 0;
    v12 = 0;
    _ReadStatusReg(SP_EL0);
    while ( v12 != 128 )
    {
      v13 = v12 >> 5;
      if ( ((*(unsigned int *)(a1 - 24 + 4 * (v12 >> 5)) >> (v12 & 0x1F)) & 1) != 0 )
      {
        v14 = *(_QWORD **)(*(_QWORD *)(v5 + 144) + v11);
        v36 = 0;
        strcpy((char *)v34, "unknown");
        memset(&v34[1], 0, 24);
        v15 = v14[1];
        memset(v35, 0, sizeof(v35));
        v16 = *(_DWORD **)(v15 + 64);
        if ( v16 )
        {
          if ( *(v16 - 1) != -938580849 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, _QWORD *, __int64))v16)(v14, v34, 32);
        }
        if ( (v14[6] & 1) != 0 )
        {
          dev_err(
            v3[193] + 16LL,
            "GMU is waiting for signaled fence(ctx:%llu seqno:%llu value:%s)\n",
            v14[4],
            v14[5],
            (const char *)v34);
          if ( v13 == 4 )
            goto LABEL_35;
          *((_DWORD *)v33 + v13) |= 1 << (v12 & 0x1F);
        }
        kgsl_get_fence_name(v14, v35, 74);
        v9 = *(unsigned int *)(v5 + 136);
      }
      ++v12;
      v11 += 16;
      if ( v12 >= v9 )
      {
        v6 = *(_DWORD *)(a1 - 32);
        v7 = *(_DWORD *)(a1 - 28);
        v10 = v30;
        goto LABEL_28;
      }
    }
    __break(0x5512u);
LABEL_35:
    __break(1u);
    goto LABEL_36;
  }
LABEL_28:
  v32 = __PAIR64__(v7, v6);
  LODWORD(v31) = 153;
  v23 = *(void (__fastcall **)(_QWORD))(v10 + 152);
  if ( *((_DWORD *)v23 - 1) != -944375624 )
    __break(0x8228u);
  v23(v3);
  gen8_hfi_send_cmd_async((__int64)v3, (int *)&v31, 0x20u);
LABEL_31:
  rt_mutex_unlock(v3 + 1386);
  mutex_unlock(v3 + 2806);
  if ( !_X20 )
    goto LABEL_41;
LABEL_36:
  __asm { PRFM            #0x11, [X20] }
  do
    v28 = __ldxr((unsigned int *)_X20);
  while ( __stlxr(v28 - 1, (unsigned int *)_X20) );
  if ( v28 == 1 )
  {
    __dmb(9u);
    kgsl_context_destroy(_X20);
  }
  else if ( v28 <= 0 )
  {
    refcount_warn_saturate(_X20, 3);
  }
LABEL_41:
  result = kfree(a1 - 40);
  _ReadStatusReg(SP_EL0);
  return result;
}
