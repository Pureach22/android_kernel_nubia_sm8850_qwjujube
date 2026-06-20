__int64 __fastcall a6xx_hfi_send_cmd_async(__int64 a1, int *a2, unsigned int a3)
{
  unsigned int v6; // w20
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x0
  _QWORD *v9; // x8
  unsigned __int64 v10; // x9
  __int64 v12; // x20
  int v13; // w3
  unsigned int v20; // w9
  unsigned int v21; // w9
  __int64 v22; // x0
  __int64 v23; // [xsp+8h] [xbp-88h] BYREF
  __int64 v24; // [xsp+10h] [xbp-80h]
  __int64 v25; // [xsp+18h] [xbp-78h]
  __int64 v26; // [xsp+20h] [xbp-70h]
  __int64 v27; // [xsp+28h] [xbp-68h]
  __int64 v28; // [xsp+30h] [xbp-60h]
  __int64 v29; // [xsp+38h] [xbp-58h]
  __int64 v30; // [xsp+40h] [xbp-50h]
  __int64 v31; // [xsp+48h] [xbp-48h]
  __int64 v32; // [xsp+50h] [xbp-40h]
  __int64 v33; // [xsp+58h] [xbp-38h]
  __int64 v34; // [xsp+60h] [xbp-30h]
  __int64 v35; // [xsp+68h] [xbp-28h]
  __int64 v36; // [xsp+70h] [xbp-20h]
  unsigned __int64 v37; // [xsp+78h] [xbp-18h] BYREF
  unsigned __int64 **v38; // [xsp+80h] [xbp-10h]
  __int64 v39; // [xsp+88h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38 = nullptr;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  _X10 = (unsigned int *)(to_a6xx_gmu(a1) + 36);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v20 = __ldxr(_X10);
    v21 = v20 + 1;
  }
  while ( __stlxr(v21, _X10) );
  __dmb(0xBu);
  *a2 |= (a3 << 6) & 0xFF00 | (v21 << 20);
  add_waiter(a1 + 24544);
  v6 = a6xx_hfi_cmdq_write(a1, a2, a3);
  if ( !v6 )
  {
    v6 = adreno_hwsched_wait_ack_completion(a1, *(_QWORD *)(a1 + 1544) + 16LL, &v23, a6xx_hwsched_process_msgq);
    if ( !v6 )
    {
      v7 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 152LL);
      if ( *((_DWORD *)v7 - 1) != -944375624 )
        __break(0x8228u);
      v8 = v7(a1);
      if ( HIDWORD(v24) == -1 )
      {
        v12 = v8;
        dev_err(
          *(_QWORD *)(a1 + 1544) + 16LL,
          "ACK error: sender id %d seqnum %d\n",
          (unsigned __int8)v23,
          (unsigned int)v23 >> 20);
        v13 = *(_DWORD *)(a1 + 1536);
        if ( (v13 & 0x400) != 0 )
        {
          v22 = dev_err(
                  *(_QWORD *)(a1 + 1544) + 16LL,
                  "GMU always on ticks: %llx gf_policy: 0x%x gf_trigger: 0x%lx\n",
                  v12,
                  v13,
                  1024);
          __break(0x800u);
          return add_waiter(v22);
        }
        v6 = -22;
      }
      else
      {
        v6 = 0;
      }
    }
  }
  raw_write_lock_irq(a1 + 24548);
  v9 = v38;
  if ( *v38 == &v37 && (v10 = v37, *(unsigned __int64 **)(v37 + 8) == &v37) )
  {
    *(_QWORD *)(v37 + 8) = v38;
    *v9 = v10;
  }
  else
  {
    _list_del_entry_valid_or_report(&v37);
  }
  v37 = 0xDEAD000000000100LL;
  v38 = (unsigned __int64 **)0xDEAD000000000122LL;
  raw_write_unlock_irq(a1 + 24548);
  _ReadStatusReg(SP_EL0);
  return v6;
}
