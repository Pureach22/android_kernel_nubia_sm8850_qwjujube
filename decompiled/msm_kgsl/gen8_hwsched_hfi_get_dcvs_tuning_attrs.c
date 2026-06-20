void *__fastcall gen8_hwsched_hfi_get_dcvs_tuning_attrs(_QWORD *a1, int a2, void *a3)
{
  __int64 v6; // x22
  int v7; // w26
  unsigned __int64 *v8; // x1
  _QWORD *v9; // x8
  unsigned __int64 v10; // x9
  void *result; // x0
  int v12; // w22
  _QWORD *v13; // x8
  unsigned __int64 v14; // x9
  unsigned int v15; // w8
  unsigned int v22; // w8
  unsigned int v23; // w8
  int v24[3]; // [xsp+Ch] [xbp-94h] BYREF
  _QWORD v25[11]; // [xsp+18h] [xbp-88h] BYREF
  _QWORD v26[3]; // [xsp+70h] [xbp-30h] BYREF
  unsigned __int64 v27; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v28; // [xsp+90h] [xbp-10h]
  __int64 v29; // [xsp+98h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1[193];
  _X9 = (unsigned int *)(to_gen8_gmu((__int64)a1) + 44);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v22 = __ldxr(_X9);
    v23 = v22 + 1;
  }
  while ( __stlxr(v23, _X9) );
  __dmb(0xBu);
  v7 = (v23 << 20) | 0x30C;
  v24[1] = 132;
  v24[2] = a2;
  v24[0] = v7;
  memset(v25, 0, sizeof(v25));
  memset(v26, 0, sizeof(v26));
  v27 = 0;
  v28 = nullptr;
  _init_swait_queue_head(v26, "&x->wait", &init_completion___key_3);
  raw_write_lock_irq((char *)a1 + 24620);
  v8 = (unsigned __int64 *)a1[3080];
  if ( &v27 == a1 + 3079 || &v27 == v8 || (_QWORD *)*v8 != a1 + 3079 )
  {
    _list_add_valid_or_report(&v27, v8);
  }
  else
  {
    a1[3080] = &v27;
    v27 = (unsigned __int64)(a1 + 3079);
    v28 = (unsigned __int64 **)v8;
    *v8 = (unsigned __int64)&v27;
  }
  raw_write_unlock_irq((char *)a1 + 24620);
  LODWORD(v25[0]) = v7;
  if ( (unsigned int)gen8_hfi_cmdq_write((__int64)a1, v24, 0xCu) )
  {
    raw_write_lock_irq((char *)a1 + 24620);
    v9 = v28;
    if ( *v28 == &v27 && (v10 = v27, *(unsigned __int64 **)(v27 + 8) == &v27) )
    {
      *(_QWORD *)(v27 + 8) = v28;
      *v9 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(&v27);
    }
    v27 = 0xDEAD000000000100LL;
    v28 = (unsigned __int64 **)0xDEAD000000000122LL;
    result = (void *)raw_write_unlock_irq((char *)a1 + 24620);
  }
  else
  {
    v12 = adreno_hwsched_wait_ack_completion(a1, v6 + 16, v25, gen8_hwsched_process_msgq);
    raw_write_lock_irq((char *)a1 + 24620);
    v13 = v28;
    if ( *v28 == &v27 && (v14 = v27, *(unsigned __int64 **)(v27 + 8) == &v27) )
    {
      *(_QWORD *)(v27 + 8) = v28;
      *v13 = v14;
    }
    else
    {
      _list_del_entry_valid_or_report(&v27);
    }
    v27 = 0xDEAD000000000100LL;
    v28 = (unsigned __int64 **)0xDEAD000000000122LL;
    result = (void *)raw_write_unlock_irq((char *)a1 + 24620);
    if ( !v12 )
    {
      v15 = BYTE5(v25[0]) - 2;
      if ( BYTE5(v25[0]) >= 2u )
      {
        if ( v15 >= 0x11 )
          v15 = 17;
        result = memcpy(a3, (char *)&v25[1] + 4, 4 * v15);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
