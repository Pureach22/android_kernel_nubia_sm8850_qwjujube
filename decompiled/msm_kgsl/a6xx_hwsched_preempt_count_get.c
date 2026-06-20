__int64 __fastcall a6xx_hwsched_preempt_count_get(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w20
  _QWORD *v4; // x8
  unsigned __int64 v5; // x9
  __int64 result; // x0
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x0
  __int64 v9; // x20
  int v10; // w3
  unsigned int v17; // w9
  unsigned int v18; // w9
  unsigned int v19; // [xsp+Ch] [xbp-94h] BYREF
  __int64 v20; // [xsp+10h] [xbp-90h]
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
  __int64 v32; // [xsp+70h] [xbp-30h]
  __int64 v33; // [xsp+78h] [xbp-28h]
  __int64 v34; // [xsp+80h] [xbp-20h]
  unsigned __int64 v35; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v36; // [xsp+90h] [xbp-10h]
  __int64 v37; // [xsp+98h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = to_a6xx_gmu(a1);
  if ( *(_DWORD *)(a1 + 11120) != 2 )
  {
    result = 0;
    goto LABEL_13;
  }
  v34 = 0;
  v35 = 0;
  v36 = nullptr;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  _X10 = (unsigned int *)(v2 + 36);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v17 = __ldxr(_X10);
    v18 = v17 + 1;
  }
  while ( __stlxr(v18, _X10) );
  __dmb(0xBu);
  v20 = 120;
  v19 = (v18 << 20) | 0x30C;
  add_waiter(a1 + 24544, v19, &v21);
  if ( (unsigned int)a6xx_hfi_cmdq_write(a1, (int *)&v19, 0xCu)
    || (unsigned int)adreno_hwsched_wait_ack_completion(
                       a1,
                       *(_QWORD *)(a1 + 1544) + 16LL,
                       &v21,
                       a6xx_hwsched_process_msgq) )
  {
    goto LABEL_5;
  }
  v7 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 152LL);
  if ( *((_DWORD *)v7 - 1) != -944375624 )
    __break(0x8228u);
  v8 = v7(a1);
  if ( HIDWORD(v22) == -1 )
  {
    v9 = v8;
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "ACK error: sender id %d seqnum %d\n",
      (unsigned __int8)v21,
      (unsigned int)v21 >> 20);
    v10 = *(_DWORD *)(a1 + 1536);
    if ( (v10 & 0x400) != 0 )
    {
      dev_err(
        *(_QWORD *)(a1 + 1544) + 16LL,
        "GMU always on ticks: %llx gf_policy: 0x%x gf_trigger: 0x%lx\n",
        v9,
        v10,
        1024);
      __break(0x800u);
    }
LABEL_5:
    v3 = 0;
    goto LABEL_6;
  }
  v3 = 1;
LABEL_6:
  raw_write_lock_irq(a1 + 24548);
  v4 = v36;
  if ( *v36 == &v35 && (v5 = v35, *(unsigned __int64 **)(v35 + 8) == &v35) )
  {
    *(_QWORD *)(v35 + 8) = v36;
    *v4 = v5;
  }
  else
  {
    _list_del_entry_valid_or_report(&v35);
  }
  v35 = 0xDEAD000000000100LL;
  v36 = (unsigned __int64 **)0xDEAD000000000122LL;
  raw_write_unlock_irq(a1 + 24548);
  if ( v3 )
    result = HIDWORD(v22);
  else
    result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
