__int64 __fastcall gen8_hwsched_hfi_get_value(_QWORD *a1, int a2, int a3)
{
  __int64 v6; // x23
  int v7; // w24
  unsigned __int64 *v8; // x1
  _BOOL4 v9; // w23
  _QWORD *v10; // x8
  unsigned __int64 v11; // x9
  unsigned int v20; // w8
  unsigned int v21; // w8
  int v22[3]; // [xsp+Ch] [xbp-94h] BYREF
  __int64 v23; // [xsp+18h] [xbp-88h] BYREF
  __int64 v24; // [xsp+20h] [xbp-80h]
  __int64 v25; // [xsp+28h] [xbp-78h]
  __int64 v26; // [xsp+30h] [xbp-70h]
  __int64 v27; // [xsp+38h] [xbp-68h]
  __int64 v28; // [xsp+40h] [xbp-60h]
  __int64 v29; // [xsp+48h] [xbp-58h]
  __int64 v30; // [xsp+50h] [xbp-50h]
  __int64 v31; // [xsp+58h] [xbp-48h]
  __int64 v32; // [xsp+60h] [xbp-40h]
  __int64 v33; // [xsp+68h] [xbp-38h]
  _QWORD v34[3]; // [xsp+70h] [xbp-30h] BYREF
  unsigned __int64 v35; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v36; // [xsp+90h] [xbp-10h]
  __int64 v37; // [xsp+98h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1[193];
  _X9 = (unsigned int *)(to_gen8_gmu((__int64)a1) + 44);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v20 = __ldxr(_X9);
    v21 = v20 + 1;
  }
  while ( __stlxr(v21, _X9) );
  __dmb(0xBu);
  v7 = (v21 << 20) | 0x30C;
  v22[1] = a2;
  v22[2] = a3;
  v22[0] = v7;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  memset(v34, 0, sizeof(v34));
  v35 = 0;
  v36 = nullptr;
  _init_swait_queue_head(v34, "&x->wait", &init_completion___key_3);
  raw_write_lock_irq((char *)a1 + 24620);
  v8 = (unsigned __int64 *)a1[3080];
  if ( &v35 == a1 + 3079 || &v35 == v8 || (_QWORD *)*v8 != a1 + 3079 )
  {
    _list_add_valid_or_report(&v35, v8);
  }
  else
  {
    a1[3080] = &v35;
    v35 = (unsigned __int64)(a1 + 3079);
    v36 = (unsigned __int64 **)v8;
    *v8 = (unsigned __int64)&v35;
  }
  raw_write_unlock_irq((char *)a1 + 24620);
  LODWORD(v23) = v7;
  if ( (unsigned int)gen8_hfi_cmdq_write((__int64)a1, v22, 0xCu) )
    v9 = 1;
  else
    v9 = adreno_hwsched_wait_ack_completion(a1, v6 + 16, &v23, gen8_hwsched_process_msgq) != 0;
  raw_write_lock_irq((char *)a1 + 24620);
  v10 = v36;
  if ( *v36 == &v35 && (v11 = v35, *(unsigned __int64 **)(v35 + 8) == &v35) )
  {
    *(_QWORD *)(v35 + 8) = v36;
    *v10 = v11;
  }
  else
  {
    _list_del_entry_valid_or_report(&v35);
  }
  v35 = 0xDEAD000000000100LL;
  v36 = (unsigned __int64 **)0xDEAD000000000122LL;
  raw_write_unlock_irq((char *)a1 + 24620);
  _ZF = HIDWORD(v24) == -1;
  _ReadStatusReg(SP_EL0);
  if ( _ZF || v9 )
    return 0;
  else
    return HIDWORD(v24);
}
