__int64 __fastcall crm_send_cmd(__int64 a1, __int64 a2, unsigned int a3, int *a4, char a5)
{
  __int64 v8; // x25
  __int64 v9; // x19
  int v11; // w22
  unsigned int v12; // w23
  unsigned int v13; // w24
  unsigned int v14; // w12
  __int64 v15; // x24
  __int64 v16; // x8
  __int64 v17; // x27
  __int64 v18; // x27
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x24
  __int64 v22; // x27
  __int64 v23; // x27
  __int64 v24; // x8
  _DWORD *v25; // x8
  _DWORD *v26; // x8
  int v27; // w9
  int v28; // w10
  int v29; // w28
  __int64 result; // x0
  __int64 v31; // x1
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x0
  int v40; // [xsp+8h] [xbp-58h]
  int v42; // [xsp+1Ch] [xbp-44h]
  __int64 v43; // [xsp+20h] [xbp-40h]
  unsigned int v45; // [xsp+2Ch] [xbp-34h]
  _QWORD v46[6]; // [xsp+30h] [xbp-30h] BYREF

  v8 = a2 + 48;
  v9 = a2 + 48 + 40LL * a3;
  v46[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *a4;
  v12 = a4[1];
  v13 = a4[2];
  v42 = *((unsigned __int8 *)a4 + 12);
  v43 = raw_spin_lock_irqsave(a2 + 168);
  if ( ((a3 == 1) & (unsigned __int8)v42) != 0 )
    v14 = v13 | 0x80000000;
  else
    v14 = v13;
  if ( a3 == 2 )
    v15 = 0;
  else
    v15 = v12;
  v45 = v14;
  switch ( v11 )
  {
    case 2:
      if ( a3 >= 4 )
        goto LABEL_31;
      v26 = *(_DWORD **)(v8 + 40LL * a3 + 16);
      v27 = *v26 + v26[1] * *(_DWORD *)(a2 + 32);
      v28 = v26[5];
      goto LABEL_21;
    case 1:
      if ( a3 >= 4 )
        goto LABEL_31;
      v26 = *(_DWORD **)(v8 + 40LL * a3 + 16);
      v27 = *v26 + v26[1] * *(_DWORD *)(a2 + 32);
      v28 = v26[4];
LABEL_21:
      writel_relaxed(v14, *(_QWORD *)(a2 + 24) + v27 + v28 + v26[2] * v12);
      v23 = 0;
      if ( (a5 & 1) == 0 )
        goto LABEL_26;
      goto LABEL_24;
    case 0:
      v16 = *(_QWORD *)(v9 + 32);
      v17 = 5 * v15;
      if ( *(_BYTE *)(v16 + 80LL * (unsigned int)v15 + 48) == 1 )
      {
        memset(v46, 0, 40);
        init_wait_entry(v46, 0);
        v18 = 80 * v15;
        prepare_to_wait_event(*(_QWORD *)(v9 + 32) + 80 * v15 + 56, v46, 2);
        v19 = *(_QWORD *)(v9 + 32);
        if ( *(_BYTE *)(v19 + 80 * v15 + 48) == 1 )
        {
          do
          {
            v20 = raw_spin_unlock_irq(a2 + 168);
            schedule(v20);
            raw_spin_lock_irq(a2 + 168);
            prepare_to_wait_event(*(_QWORD *)(v9 + 32) + v18 + 56, v46, 2);
            v19 = *(_QWORD *)(v9 + 32);
          }
          while ( (*(_BYTE *)(v19 + v18 + 48) & 1) != 0 );
        }
        finish_wait(v19 + 80LL * (unsigned int)v15 + 56, v46);
        v16 = *(_QWORD *)(v9 + 32);
        v17 = 5 * v15;
      }
      v40 = v15;
      v21 = 16 * v17;
      v22 = v16 + 16 * v17;
      *(_DWORD *)(v22 + 16) = 0;
      v23 = v22 + 16;
      _init_swait_queue_head(v23 + 8, "&x->wait", &init_completion___key);
      v24 = *(_QWORD *)(v9 + 32) + v21;
      *(_DWORD *)(v24 + 4) = a4[1];
      *(_DWORD *)v24 = *a4;
      *(_DWORD *)(v24 + 8) = a4[2];
      *(_BYTE *)(v24 + 12) = *((_BYTE *)a4 + 12);
      *(_BYTE *)(*(_QWORD *)(v9 + 32) + v21 + 48) = 1;
      if ( a3 >= 4 )
        goto LABEL_31;
      v25 = *(_DWORD **)(v8 + 40LL * a3 + 16);
      writel_relaxed(v45, *(_QWORD *)(a2 + 24) + *v25 + v25[1] * *(_DWORD *)(a2 + 32) + v25[3] + v25[2] * v12);
      LODWORD(v15) = v40;
      if ( (a5 & 1) == 0 )
        goto LABEL_26;
LABEL_24:
      if ( a3 < 4 )
      {
        v29 = v15;
        v15 = v8 + 40LL * a3;
        writel_relaxed(
          1,
          *(_QWORD *)(a2 + 24)
        + (unsigned int)(**(_DWORD **)(v15 + 16)
                       + *(_DWORD *)(*(_QWORD *)(v15 + 16) + 4LL) * *(_DWORD *)(a2 + 32)
                       + *(_DWORD *)(*(_QWORD *)(v15 + 16) + 52LL)));
        _const_udelay(4295);
        writel_relaxed(
          0,
          *(_QWORD *)(a2 + 24)
        + (unsigned int)(**(_DWORD **)(v15 + 16)
                       + *(_DWORD *)(*(_QWORD *)(v15 + 16) + 4LL) * *(_DWORD *)(a2 + 32)
                       + *(_DWORD *)(*(_QWORD *)(v15 + 16) + 52LL)));
        LODWORD(v15) = v29;
        goto LABEL_26;
      }
LABEL_31:
      __break(0x5512u);
      break;
  }
  v23 = 0;
  __break(0x800u);
  if ( (a5 & 1) != 0 )
    goto LABEL_24;
LABEL_26:
  raw_spin_unlock_irqrestore(a2 + 168, v43);
  result = ipc_log_string(
             *(_QWORD *)(a2 + 184),
             "Write: type: %u resource_idx:%u pwr_state: %u data: %#x",
             a3,
             v12,
             v11,
             v45);
  if ( !v23 || !v42 )
    goto LABEL_30;
  if ( (unsigned int)wait_for_completion_timeout(v23, 1250) )
  {
    result = _wake_up(*(_QWORD *)(v9 + 32) + 80LL * (unsigned int)v15 + 56, 3, 1, 0);
LABEL_30:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  crm_dump_drv_regs(a2, a1);
  v34 = crm_dump_regs(a1, v31, v32, v33);
  __break(0x800u);
  __asm { STR             P16, [X16,#-0x68,MUL VL] }
  return crm_write_bw_vote(v34);
}
