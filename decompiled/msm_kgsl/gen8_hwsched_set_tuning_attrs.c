__int64 __fastcall gen8_hwsched_set_tuning_attrs(_QWORD *a1, int a2, unsigned int a3, int a4)
{
  int v8; // w24
  unsigned __int64 *v9; // x1
  int v10; // w0
  int v11; // w26
  _QWORD *v12; // x8
  unsigned __int64 v13; // x9
  __int64 result; // x0
  __int64 v15; // x8
  unsigned int v22; // w8
  unsigned int v23; // w8
  int v24[4]; // [xsp+8h] [xbp-98h] BYREF
  __int64 v25; // [xsp+18h] [xbp-88h] BYREF
  __int64 v26; // [xsp+20h] [xbp-80h]
  __int64 v27; // [xsp+28h] [xbp-78h]
  __int64 v28; // [xsp+30h] [xbp-70h]
  __int64 v29; // [xsp+38h] [xbp-68h]
  __int64 v30; // [xsp+40h] [xbp-60h]
  __int64 v31; // [xsp+48h] [xbp-58h]
  __int64 v32; // [xsp+50h] [xbp-50h]
  __int64 v33; // [xsp+58h] [xbp-48h]
  __int64 v34; // [xsp+60h] [xbp-40h]
  __int64 v35; // [xsp+68h] [xbp-38h]
  _QWORD v36[3]; // [xsp+70h] [xbp-30h] BYREF
  unsigned __int64 v37; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v38; // [xsp+90h] [xbp-10h]
  __int64 v39; // [xsp+98h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[1] = a2;
  v24[2] = a3;
  v24[3] = a4;
  _X9 = (unsigned int *)(to_gen8_gmu((__int64)a1) + 44);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v22 = __ldxr(_X9);
    v23 = v22 + 1;
  }
  while ( __stlxr(v23, _X9) );
  __dmb(0xBu);
  v8 = (v23 << 20) | 0x40D;
  v25 = 0;
  v26 = 0;
  v24[0] = v8;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  memset(v36, 0, sizeof(v36));
  v37 = 0;
  v38 = nullptr;
  _init_swait_queue_head(v36, "&x->wait", &init_completion___key_3);
  raw_write_lock_irq((char *)a1 + 24620);
  v9 = (unsigned __int64 *)a1[3080];
  if ( &v37 == a1 + 3079 || &v37 == v9 || (_QWORD *)*v9 != a1 + 3079 )
    goto LABEL_25;
  a1[3080] = &v37;
  v37 = (unsigned __int64)(a1 + 3079);
  v38 = (unsigned __int64 **)v9;
  *v9 = (unsigned __int64)&v37;
  while ( 1 )
  {
    raw_write_unlock_irq((char *)a1 + 24620);
    LODWORD(v25) = v8;
    v10 = gen8_hfi_cmdq_write((__int64)a1, v24, 0x10u);
    if ( v10 || (v10 = adreno_hwsched_wait_ack_completion(a1, a1[193] + 16LL, &v25, gen8_hwsched_process_msgq)) != 0 )
    {
      v8 = v10;
LABEL_9:
      v11 = -1;
      goto LABEL_10;
    }
    if ( (_DWORD)v27 )
    {
      dev_err(a1[193] + 16LL, "ACK error: sender id %d seqnum %d\n", (unsigned __int8)v25, (unsigned int)v25 >> 20);
      v8 = -22;
      goto LABEL_9;
    }
    v8 = 0;
    v11 = HIDWORD(v26) == -2 ? -1 : HIDWORD(v26);
LABEL_10:
    raw_write_lock_irq((char *)a1 + 24620);
    v12 = v38;
    if ( *v38 == &v37 && (v13 = v37, *(unsigned __int64 **)(v37 + 8) == &v37) )
    {
      *(_QWORD *)(v37 + 8) = v38;
      *v12 = v13;
    }
    else
    {
      _list_del_entry_valid_or_report(&v37);
    }
    v37 = 0xDEAD000000000100LL;
    v38 = (unsigned __int64 **)0xDEAD000000000122LL;
    result = raw_write_unlock_irq((char *)a1 + 24620);
    if ( v8 )
      break;
    if ( a3 < 0x11 )
    {
      v15 = (__int64)&a1[a3 + 2970];
      *(_DWORD *)v15 = v11;
      *(_BYTE *)(v15 + 4) = 0;
      goto LABEL_16;
    }
    __break(0x5512u);
LABEL_25:
    _list_add_valid_or_report(&v37, v9);
  }
  result = dev_err(a1[193] + 16LL, "Failed to set value %u for HFI type %u, ret: %d\n", a4, a2, v8);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
