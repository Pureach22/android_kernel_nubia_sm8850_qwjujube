__int64 __fastcall gen7_hwsched_hfi_get_value(_QWORD *a1, int a2)
{
  __int64 v4; // x22
  int v5; // w24
  unsigned __int64 *v6; // x1
  _BOOL4 v7; // w22
  _QWORD *v8; // x8
  unsigned __int64 v9; // x9
  unsigned int v18; // w8
  unsigned int v19; // w8
  int v20[3]; // [xsp+Ch] [xbp-94h] BYREF
  __int64 v21; // [xsp+18h] [xbp-88h] BYREF
  __int64 v22; // [xsp+20h] [xbp-80h]
  __int64 v23; // [xsp+28h] [xbp-78h]
  __int64 v24; // [xsp+30h] [xbp-70h]
  __int64 v25; // [xsp+38h] [xbp-68h]
  __int64 v26; // [xsp+40h] [xbp-60h]
  __int64 v27; // [xsp+48h] [xbp-58h]
  __int64 v28; // [xsp+50h] [xbp-50h]
  __int64 v29; // [xsp+58h] [xbp-48h]
  __int64 v30; // [xsp+60h] [xbp-40h]
  __int64 v31; // [xsp+68h] [xbp-38h]
  _QWORD v32[3]; // [xsp+70h] [xbp-30h] BYREF
  unsigned __int64 v33; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v34; // [xsp+90h] [xbp-10h]
  __int64 v35; // [xsp+98h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[193];
  _X9 = (unsigned int *)(to_gen7_gmu((__int64)a1) + 44);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v18 = __ldxr(_X9);
    v19 = v18 + 1;
  }
  while ( __stlxr(v19, _X9) );
  __dmb(0xBu);
  v5 = (v19 << 20) | 0x30C;
  v20[1] = a2;
  v20[2] = 0;
  v20[0] = v5;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  memset(v32, 0, sizeof(v32));
  v33 = 0;
  v34 = nullptr;
  _init_swait_queue_head(v32, "&x->wait", &init_completion___key_2);
  raw_write_lock_irq((char *)a1 + 24556);
  v6 = (unsigned __int64 *)a1[3072];
  if ( &v33 == a1 + 3071 || &v33 == v6 || (_QWORD *)*v6 != a1 + 3071 )
  {
    _list_add_valid_or_report(&v33, v6);
  }
  else
  {
    a1[3072] = &v33;
    v33 = (unsigned __int64)(a1 + 3071);
    v34 = (unsigned __int64 **)v6;
    *v6 = (unsigned __int64)&v33;
  }
  raw_write_unlock_irq((char *)a1 + 24556);
  LODWORD(v21) = v5;
  if ( (unsigned int)gen7_hfi_cmdq_write((__int64)a1, v20, 0xCu) )
    v7 = 1;
  else
    v7 = adreno_hwsched_wait_ack_completion(a1, v4 + 16, &v21, gen7_hwsched_process_msgq) != 0;
  raw_write_lock_irq((char *)a1 + 24556);
  v8 = v34;
  if ( *v34 == &v33 && (v9 = v33, *(unsigned __int64 **)(v33 + 8) == &v33) )
  {
    *(_QWORD *)(v33 + 8) = v34;
    *v8 = v9;
  }
  else
  {
    _list_del_entry_valid_or_report(&v33);
  }
  v33 = 0xDEAD000000000100LL;
  v34 = (unsigned __int64 **)0xDEAD000000000122LL;
  raw_write_unlock_irq((char *)a1 + 24556);
  _ZF = HIDWORD(v22) == -1;
  _ReadStatusReg(SP_EL0);
  if ( _ZF || v7 )
    return 0;
  else
    return HIDWORD(v22);
}
