__int64 __fastcall a6xx_hwsched_send_recurring_cmdobj(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x10
  unsigned int i; // w8
  unsigned int v5; // w20
  unsigned int v8; // w22
  int *v9; // x21
  __int64 v10; // x0
  __int64 v11; // x23
  unsigned int v12; // w0
  unsigned int v13; // w19
  __int64 v14; // x1
  unsigned int v15; // w0
  unsigned int v16; // w20
  unsigned int v17; // w20
  unsigned __int64 StatusReg; // x23
  __int64 v19; // x24

  __dmb(9u);
  if ( *(_DWORD *)(a1 + 20412) )
    return 4294967280LL;
  __dmb(9u);
  if ( *(_DWORD *)(a1 + 24448) )
    return 4294967280LL;
  if ( (*(_QWORD *)(a2 + 56) & 0x40) != 0 )
  {
    *(_DWORD *)(a2 + 160) = 0;
    v5 = 32;
  }
  else
  {
    v3 = *(_QWORD **)(a2 + 88);
    for ( i = *(_DWORD *)(a2 + 160); v3 != (_QWORD *)(a2 + 88); v3 = (_QWORD *)*v3 )
      *(_DWORD *)(a2 + 160) = ++i;
    if ( i > 0x7D0 )
      return 4294967274LL;
    if ( i <= 0x52 )
      v5 = 12 * i + 32;
    else
      v5 = 32;
  }
  v8 = v5;
  v9 = (int *)_kmalloc_noprof(v5, 3520);
  if ( !v9 )
    return 4294967284LL;
  while ( 1 )
  {
    v10 = a1;
    v11 = a2;
    if ( (*(_QWORD *)(a2 + 56) & 0x20) != 0 )
      break;
    if ( (v8 & 0x7FFFFFFC) != 8 )
    {
      v9[2] |= 0x80000u;
      goto LABEL_24;
    }
LABEL_34:
    __break(1u);
    v8 = v5;
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &a6xx_hwsched_send_recurring_cmdobj__alloc_tag;
    v9 = (int *)_kmalloc_noprof(v5, 3520);
    *(_QWORD *)(StatusReg + 80) = v19;
    if ( !v9 )
      return 4294967284LL;
  }
  if ( (a6xx_hwsched_send_recurring_cmdobj_active & 1) == 0 )
  {
    v12 = adreno_active_count_get(a1);
    if ( v12 )
    {
      v13 = v12;
      kfree(v9);
      return v13;
    }
    a6xx_hwsched_send_recurring_cmdobj_active = 1;
  }
  if ( (v8 & 0x7FFFFFFC) == 8 )
    goto LABEL_34;
  v11 = a2;
  v9[2] |= 0x40000u;
  populate_ibs(a1, v9, a2);
  v10 = a1;
LABEL_24:
  if ( (v8 & 0x7FFFFFFC) == 4 )
    goto LABEL_34;
  v14 = *(_QWORD *)(v11 + 8);
  v9[1] = *(_DWORD *)(v14 + 4);
  v15 = hfi_context_register(v10, v14);
  if ( v15 )
  {
    v16 = v15;
    adreno_active_count_put(a1);
    a6xx_hwsched_send_recurring_cmdobj_active = 0;
    kfree(v9);
    return v16;
  }
  else
  {
    *v9 = 141;
    v17 = a6xx_hfi_send_cmd_async(a1, v9, v5);
    kfree(v9);
    if ( v17 )
    {
      adreno_active_count_put(a1);
      a6xx_hwsched_send_recurring_cmdobj_active = 0;
      return v17;
    }
    else if ( (*(_QWORD *)(a2 + 56) & 0x40) != 0 )
    {
      adreno_hwsched_retire_cmdobj(a1 + 20904, *(_QWORD *)(a1 + 22840));
      *(_QWORD *)(a1 + 22840) = 0;
      timer_delete_sync(a1 + 22848);
      if ( a6xx_hwsched_send_recurring_cmdobj_active == 1 )
        adreno_active_count_put(a1);
      a6xx_hwsched_send_recurring_cmdobj_active = 0;
      return 0;
    }
    else
    {
      *(_QWORD *)(a1 + 22840) = a2;
      mod_timer(a1 + 22848);
      return 0;
    }
  }
}
