__int64 __fastcall gen8_hwsched_create_hw_fence(__int64 a1, __int64 a2)
{
  __int64 v4; // x22
  __int64 v5; // x19
  unsigned int v6; // w25
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned int v9; // w9
  unsigned int v10; // w1
  __int64 v11; // x23
  __int64 v12; // x23
  __int64 v13; // x27
  __int64 v14; // x0
  unsigned int v15; // w8
  unsigned int v16; // w9
  bool v17; // cf
  unsigned int v18; // w8
  __int64 hw_fence_entry_0; // x0
  _QWORD *v20; // x1
  unsigned int v21; // w9
  unsigned int v22; // w10
  unsigned int v23; // w12
  unsigned int v24; // w12
  unsigned int v25; // w12
  _QWORD *v26; // x2
  _QWORD *v27; // x8
  __int64 v28; // x0
  __int64 v29; // x22
  int v30; // w0
  int v31; // w23
  __int64 result; // x0
  unsigned int v33; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v34[6]; // [xsp+10h] [xbp-30h] BYREF

  v34[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 72);
  v33 = 0;
  v5 = *(_QWORD *)(v4 + 80);
  raw_spin_lock(v5 + 404);
  raw_spin_lock(a1 + 23152);
  v6 = *(_DWORD *)(v5 + 2100);
  v7 = *(_DWORD *)(a2 + 100);
  if ( v6 == v7 || v6 > v7 && ((v6 - v7) & 0x80000000) == 0 )
    goto LABEL_57;
  if ( (v6 ^ 0x80000000) > (v7 ^ 0x80000000) && (v6 ^ 0x80000000) - (v7 ^ 0x80000000) < 0x80000001 )
    goto LABEL_57;
  *(_DWORD *)(v5 + 2100) = v7;
  if ( !v5 || (*(_QWORD *)(v5 + 32) & 2) != 0 || (*(_QWORD *)(v5 + 32) & 4) != 0 || (*(_QWORD *)(a1 + 23200) & 4) != 0 )
    goto LABEL_57;
  if ( (*(_QWORD *)(a1 + 23200) & 1) != 0 )
  {
    raw_spin_unlock(a1 + 23152);
    raw_spin_unlock(v5 + 404);
    raw_spin_lock(a1 + 23152);
    v11 = *(_QWORD *)(a1 + 23200);
    raw_spin_unlock(a1 + 23152);
    if ( (v11 & 1) != 0 )
    {
      memset(v34, 0, 40);
      init_wait_entry(v34, 0);
      while ( 1 )
      {
        v12 = prepare_to_wait_event(a1 + 23160, v34, 1);
        raw_spin_lock(a1 + 23152);
        v13 = *(_QWORD *)(a1 + 23200);
        v14 = raw_spin_unlock(a1 + 23152);
        if ( (v13 & 1) == 0 )
          break;
        if ( v12 )
          goto LABEL_44;
        schedule(v14);
      }
      finish_wait(a1 + 23160, v34);
    }
    LODWORD(v12) = 0;
LABEL_44:
    raw_spin_lock(v5 + 404);
    raw_spin_lock(a1 + 23152);
    if ( (_DWORD)v12 == -512
      || (*(_QWORD *)(v5 + 32) & 2) != 0
      || (*(_QWORD *)(v5 + 32) & 4) != 0
      || (*(_QWORD *)(a1 + 23200) & 2) != 0
      || (*(_QWORD *)(a1 + 23200) & 4) != 0
      || (_DWORD)v12 )
    {
      goto LABEL_57;
    }
  }
  v8 = *(_DWORD *)(a2 + 100);
  v9 = *(_DWORD *)(v5 + 2096);
  if ( v8 != v9 )
  {
    if ( v8 > v9 && ((v8 - v9) & 0x80000000) == 0
      || (v15 = v8 ^ 0x80000000, v16 = v9 ^ 0x80000000, v17 = v15 >= v16, v18 = v15 - v16, v18 != 0 && v17)
      && v18 <= 0x80000000 )
    {
      hw_fence_entry_0 = allocate_hw_fence_entry_0(a1, v5, a2);
      if ( hw_fence_entry_0 )
      {
        v20 = *(_QWORD **)(v5 + 2064);
        if ( v20 != (_QWORD *)(v5 + 2056) )
        {
          v21 = *(_DWORD *)(a2 + 100);
          v22 = v21 ^ 0x80000000;
          do
          {
            v23 = *((_DWORD *)v20 - 10);
            if ( v21 != v23 )
            {
              if ( v21 > v23 && ((v21 - v23) & 0x80000000) == 0 )
                break;
              v24 = v23 ^ 0x80000000;
              v17 = v22 >= v24;
              v25 = v22 - v24;
              if ( v25 != 0 && v17 && v25 < 0x80000001 )
                break;
            }
            v20 = (_QWORD *)v20[1];
          }
          while ( v20 != (_QWORD *)(v5 + 2056) );
        }
        v26 = (_QWORD *)*v20;
        v27 = (_QWORD *)(hw_fence_entry_0 + 64);
        if ( *(_QWORD **)(*v20 + 8LL) != v20 || v27 == v20 || v26 == v27 )
        {
          _list_add_valid_or_report(hw_fence_entry_0 + 64, v20);
        }
        else
        {
          v26[1] = v27;
          *(_QWORD *)(hw_fence_entry_0 + 64) = v26;
          *(_QWORD *)(hw_fence_entry_0 + 72) = v20;
          *v20 = v27;
        }
      }
      goto LABEL_57;
    }
  }
  kgsl_readtimestamp(a1, v5, 2, &v33);
  v10 = *(_DWORD *)(a2 + 100);
  if ( v33 == v10
    || v33 > v10 && ((v33 - v10) & 0x80000000) == 0
    || (v33 ^ 0x80000000) > (v10 ^ 0x80000000) && (v33 ^ 0x80000000) - (v10 ^ 0x80000000) <= 0x80000000 )
  {
    kgsl_sync_timeline_signal(v4);
LABEL_57:
    raw_spin_unlock(a1 + 23152);
    goto LABEL_58;
  }
  v28 = allocate_hw_fence_entry_0(a1, v5, a2);
  if ( !v28 )
    goto LABEL_57;
  v29 = v28;
  v30 = send_hw_fence_no_ack_0(a1, v28);
  if ( !v30 )
  {
    _list_add_0(v29 + 64, *(_QWORD *)(v5 + 2080), v5 + 2072);
    goto LABEL_57;
  }
  v31 = v30;
  if ( (unsigned int)__ratelimit(&gen8_hwsched_create_hw_fence__rs, "gen8_hwsched_create_hw_fence") )
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "hw fence for ctx:%d ts:%d ret:%d may not be destroyed\n",
      *(_DWORD *)(a2 + 96),
      *(_DWORD *)(a2 + 100),
      v31);
  *(_DWORD *)(v5 + 2100) = v6;
  raw_spin_unlock(a1 + 23152);
  adreno_hwsched_remove_hw_fence_entry(a1, v29);
LABEL_58:
  result = raw_spin_unlock(v5 + 404);
  _ReadStatusReg(SP_EL0);
  return result;
}
