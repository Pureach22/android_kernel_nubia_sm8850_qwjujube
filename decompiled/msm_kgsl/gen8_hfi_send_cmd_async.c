__int64 __fastcall gen8_hfi_send_cmd_async(__int64 a1, int *a2, unsigned int a3)
{
  int v6; // w10
  int v7; // w24
  unsigned __int64 *v8; // x1
  unsigned int v9; // w21
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  _QWORD *v12; // x8
  unsigned __int64 v13; // x9
  __int64 v15; // x21
  int v16; // w3
  unsigned int v23; // w8
  unsigned int v24; // w8
  __int64 v25; // [xsp+8h] [xbp-88h] BYREF
  __int64 v26; // [xsp+10h] [xbp-80h]
  __int64 v27; // [xsp+18h] [xbp-78h]
  __int64 v28; // [xsp+20h] [xbp-70h]
  __int64 v29; // [xsp+28h] [xbp-68h]
  __int64 v30; // [xsp+30h] [xbp-60h]
  __int64 v31; // [xsp+38h] [xbp-58h]
  __int64 v32; // [xsp+40h] [xbp-50h]
  __int64 v33; // [xsp+48h] [xbp-48h]
  __int64 v34; // [xsp+50h] [xbp-40h]
  __int64 v35; // [xsp+58h] [xbp-38h]
  _QWORD v36[3]; // [xsp+60h] [xbp-30h] BYREF
  unsigned __int64 v37; // [xsp+78h] [xbp-18h] BYREF
  unsigned __int64 **v38; // [xsp+80h] [xbp-10h]
  __int64 v39; // [xsp+88h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _X9 = (unsigned int *)(to_gen8_gmu(a1) + 44);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v23 = __ldxr(_X9);
    v24 = v23 + 1;
  }
  while ( __stlxr(v24, _X9) );
  __dmb(0xBu);
  v6 = *a2;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v7 = v6 | (a3 << 6) & 0xFF00 | (v24 << 20);
  v31 = 0;
  v32 = 0;
  *a2 = v7;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  memset(v36, 0, sizeof(v36));
  v37 = 0;
  v38 = nullptr;
  _init_swait_queue_head(v36, "&x->wait", &init_completion___key_3);
  raw_write_lock_irq(a1 + 24620);
  v8 = *(unsigned __int64 **)(a1 + 24640);
  if ( &v37 == (unsigned __int64 *)(a1 + 24632) || &v37 == v8 || *v8 != a1 + 24632 )
  {
    _list_add_valid_or_report(&v37, v8);
  }
  else
  {
    *(_QWORD *)(a1 + 24640) = &v37;
    v37 = a1 + 24632;
    v38 = (unsigned __int64 **)v8;
    *v8 = (unsigned __int64)&v37;
  }
  raw_write_unlock_irq(a1 + 24620);
  LODWORD(v25) = v7;
  v9 = gen8_hfi_cmdq_write(a1, a2, a3);
  if ( !v9 )
  {
    v9 = adreno_hwsched_wait_ack_completion(a1, *(_QWORD *)(a1 + 1544) + 16LL, &v25, gen8_hwsched_process_msgq);
    if ( !v9 )
    {
      v10 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 152LL);
      if ( *((_DWORD *)v10 - 1) != -944375624 )
        __break(0x8228u);
      v11 = v10(a1);
      if ( HIDWORD(v26) == -1 )
      {
        v15 = v11;
        dev_err(
          *(_QWORD *)(a1 + 1544) + 16LL,
          "ACK error: sender id %d seqnum %d\n",
          (unsigned __int8)v25,
          (unsigned int)v25 >> 20);
        v16 = *(_DWORD *)(a1 + 1536);
        if ( (v16 & 0x400) != 0 )
        {
          dev_err(
            *(_QWORD *)(a1 + 1544) + 16LL,
            "GMU always on ticks: %llx gf_policy: 0x%x gf_trigger: 0x%lx\n",
            v15,
            v16,
            1024);
          __break(0x800u);
          JUMPOUT(0xD00F8);
        }
        v9 = -22;
      }
      else
      {
        v9 = 0;
      }
    }
  }
  raw_write_lock_irq(a1 + 24620);
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
  raw_write_unlock_irq(a1 + 24620);
  _ReadStatusReg(SP_EL0);
  return v9;
}
