__int64 __fastcall qtee_shmbridge_register(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        int *a4,
        unsigned int a5,
        unsigned int a6,
        __int64 *a7)
{
  unsigned int v7; // w26
  int *v8; // x23
  _DWORD *v9; // x24
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  __int64 *v17; // x8
  unsigned int v18; // w20
  __int64 v19; // x25
  unsigned __int64 v20; // x28
  __int64 v21; // x9
  char v22; // w10
  int v23; // t1
  unsigned int v24; // t1
  __int64 v25; // x8
  __int64 v26; // x10
  __int64 v27; // x22
  unsigned int shm_bridge; // w0
  __int64 v29; // x21
  __int64 v30; // x0
  __int64 *v31; // x1
  __int64 *v32; // x8
  __int64 v33; // x10
  unsigned int v35; // w21
  unsigned __int16 v36; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( qtee_shmbridge_enabled != 1 )
  {
    v18 = 0;
    goto LABEL_34;
  }
  v7 = a5;
  v36 = 0;
  if ( a5 > 4 || (v8 = a4) == nullptr || (v9 = a3) == nullptr || !a7 )
  {
    printk(&unk_12C57, 298, a3);
    v18 = -22;
    goto LABEL_34;
  }
  mutex_lock(&unk_13920);
  v17 = &bridge_list_head;
  while ( 1 )
  {
    v17 = (__int64 *)*v17;
    if ( v17 == &bridge_list_head )
      break;
    if ( v17[2] == a1 )
      goto LABEL_29;
  }
  if ( v7 == 1 && (support_hyp & 1) != 0 )
  {
    if ( (unsigned int)gh_rm_get_this_vmid(&v36) )
    {
      v7 = 1;
      goto LABEL_17;
    }
    v7 = *v9 != v36;
  }
  if ( v7 )
  {
LABEL_17:
    v19 = 0;
    v20 = 0;
    v21 = v7;
    do
    {
      v23 = *v8++;
      v22 = v23;
      --v21;
      v24 = *(unsigned __int16 *)v9++;
      v19 = v24 | (unsigned __int64)(v19 << 16);
      v20 = v22 & 7 | (8 * v20);
    }
    while ( v21 );
    v25 = v7 << 9;
    goto LABEL_21;
  }
  v25 = 0;
  v20 = 0;
  v19 = 0;
  LOBYTE(v21) = 1;
LABEL_21:
  v26 = a6;
  if ( ((unsigned __int8)v21 & (unsigned __int8)support_hyp) != 0 )
    v27 = 26;
  else
    v27 = v25;
  shm_bridge = qcom_scm_create_shm_bridge(v20 | a1, v26 | a1, v27 | a2, v19, a7, v14, v15, v16);
  if ( shm_bridge )
  {
    v35 = shm_bridge;
    printk(&unk_11ED4, 351, shm_bridge);
    if ( v35 != 15 )
      goto LABEL_38;
    printk(&unk_12537, 360, "qtee_shmbridge_register");
  }
  v29 = *a7;
  v30 = _kmalloc_cache_noprof(down, 3520, 40);
  if ( v30 )
  {
    *(_QWORD *)(v30 + 16) = a1;
    *(_QWORD *)(v30 + 24) = v29;
    v31 = (__int64 *)qword_13918;
    *(_DWORD *)(v30 + 32) = 0;
    if ( v31 == (__int64 *)v30 || (__int64 *)*v31 != &bridge_list_head )
    {
      _list_add_valid_or_report();
    }
    else
    {
      qword_13918 = v30;
      *(_QWORD *)v30 = &bridge_list_head;
      *(_QWORD *)(v30 + 8) = v31;
      *v31 = v30;
    }
  }
LABEL_29:
  v32 = &bridge_list_head;
  while ( 1 )
  {
    v32 = (__int64 *)*v32;
    if ( v32 == &bridge_list_head )
      break;
    if ( v32[2] == a1 )
    {
      v33 = v32[3];
      v18 = 0;
      ++*((_DWORD *)v32 + 8);
      *a7 = v33;
      goto LABEL_33;
    }
  }
  printk(&unk_123A5, 244, "qtee_shmbridge_list_inc_refcount_locked");
LABEL_38:
  v18 = -22;
LABEL_33:
  mutex_unlock(&unk_13920);
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v18;
}
