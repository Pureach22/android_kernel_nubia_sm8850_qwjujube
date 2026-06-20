__int64 __fastcall ufs_qcom_hook_send_command(__int64 result, __int64 a2, __int64 a3)
{
  unsigned int v3; // w19
  __int64 v4; // x21
  unsigned int v5; // w22
  unsigned int v6; // w23
  __int64 v7; // x25
  __int64 v9; // x21
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x19
  __int64 v13; // x22
  int v14; // w19
  __int64 v15; // x24
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x26
  __int64 *v19; // x27
  unsigned int v20; // w21
  __int64 v21; // x28
  int v22; // w9
  int v23; // w8
  __int64 *v24; // x11
  __int64 v25; // t1
  __int64 v26; // x8
  __int64 v27; // x21
  int v28; // w22
  int v29; // w24
  int v30; // w23
  int v31; // w0
  unsigned __int64 StatusReg; // x24
  __int64 v33; // x25
  unsigned int v34; // w20
  __int64 (__fastcall *v35)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x8
  __int64 v36; // x0
  __int64 v37; // t1
  __int64 v38; // x8
  unsigned int v45; // w10

  if ( a2 )
  {
    v7 = *(_QWORD *)(a2 + 184);
    if ( (*(_BYTE *)(v7 + 360) & 1) == 0 && *(_BYTE *)(v7 + 3176) == 1 )
    {
      v9 = a3;
      v10 = raw_spin_lock_irqsave(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 56LL));
      v11 = *(_QWORD *)(v7 + 3184);
      v12 = v10;
      *(_QWORD *)(v7 + 3184) = v11 + 1;
      if ( !v11 )
        writel(0, (unsigned int *)(*(_QWORD *)a2 + 24LL));
      result = raw_spin_unlock_irqrestore(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 56LL), v12);
      a3 = v9;
    }
    if ( a3 )
    {
      v13 = *(_QWORD *)(a3 + 64);
      if ( v13 )
      {
        if ( *(_BYTE *)(v13 + 180) )
        {
          if ( v13 == 288 )
            v14 = 0;
          else
            v14 = *(_DWORD *)(v13 - 244) >> 9;
          v15 = *(_QWORD *)(a2 + 184);
          if ( !*(_QWORD *)(v15 + 472) )
            goto LABEL_29;
          v16 = *(_QWORD *)(a2 + 104) + 152LL * *(unsigned int *)(a3 + 80);
          if ( !v16 )
            goto LABEL_29;
          v17 = *(_QWORD *)(v16 + 64);
          if ( !v17 )
            goto LABEL_29;
          result = v17 - 288;
          if ( v17 == 288 )
            goto LABEL_29;
          v18 = a3;
          result = blk_mq_rq_cpu(result);
          a3 = v18;
          if ( (result & 0x80000000) != 0 )
            goto LABEL_29;
          v19 = *(__int64 **)(v15 + 472);
          v20 = result;
          v21 = *v19;
          result = _sw_hweight64(_cpu_possible_mask);
          a3 = v18;
          if ( v20 > (unsigned int)result )
            goto LABEL_29;
          v22 = *((_DWORD *)v19 + 2);
          if ( !v22 )
            goto LABEL_29;
          v23 = 0;
          v24 = (__int64 *)(v21 + (((unsigned __int64)v20 >> 3) & 0x1FFFFFF8));
          while ( 1 )
          {
            v25 = *v24;
            v24 += 10;
            if ( (v25 & (1LL << v20)) != 0 )
              break;
            if ( v22 == ++v23 )
              goto LABEL_29;
          }
          v26 = *v19 + 80LL * v23;
          if ( !v26 )
            goto LABEL_29;
          if ( *(_BYTE *)(v26 + 76) == 1 && (*(_BYTE *)(v15 + 632) & 1) == 0 )
          {
            _X9 = (unsigned int *)(v15 + 520);
            __asm { PRFM            #0x11, [X9] }
            do
              v45 = __ldxr(_X9);
            while ( __stxr(v45 + 1, _X9) );
            if ( (*(_BYTE *)(v26 + 24) & 1) != 0 )
            {
LABEL_29:
              if ( (*(_BYTE *)(a2 + 4893) & 1) != 0 )
              {
                if ( v13 != 288 )
                {
                  result = *(_QWORD *)(v7 + 656);
                  if ( result )
                  {
                    if ( *(_BYTE *)(v7 + 664) == 1 )
                      return ipc_log_string(
                               result,
                               ",%d,<,%x,%d,%d,%d\n",
                               *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                               *(unsigned __int8 *)(*(_QWORD *)(a3 + 64) + 180LL),
                               *(_DWORD *)(a3 + 80),
                               *(_DWORD *)(*(_QWORD *)(a2 + 5072)
                                         + 144LL * *(unsigned __int16 *)(*(_QWORD *)(v13 - 272) + 356LL)
                                         + 68),
                               v14);
                  }
                }
              }
              else
              {
                v27 = *(_QWORD *)(v7 + 656);
                if ( v27 && *(_BYTE *)(v7 + 664) == 1 )
                {
                  v28 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
                  v29 = *(_DWORD *)(a3 + 80);
                  v30 = *(unsigned __int8 *)(*(_QWORD *)(a3 + 64) + 180LL);
                  v31 = readl((unsigned int *)(*(_QWORD *)a2 + 88LL));
                  result = ipc_log_string(v27, ",%d,<,%x,%d,%x,%d\n", v28, v30, v29, v31, v14);
                }
                if ( *(_BYTE *)(v7 + 664) == 1 )
                  return readl((unsigned int *)(*(_QWORD *)a2 + 88LL));
              }
              return result;
            }
          }
          else if ( (*(_BYTE *)(v26 + 24) & 1) != 0 )
          {
            goto LABEL_29;
          }
          result = queue_work_on(32, *(_QWORD *)(*(_QWORD *)(v15 + 472) + 16LL), v26 + 32);
          a3 = v18;
          goto LABEL_29;
        }
      }
    }
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v33 = qword_174C8;
      if ( qword_174C8 )
      {
        v34 = result;
        do
        {
          v35 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v33;
          v36 = *(_QWORD *)(v33 + 8);
          if ( *(_DWORD *)(*(_QWORD *)v33 - 4LL) != -384891958 )
            __break(0x8228u);
          result = v35(v36, v4, 0, v5, v6, v34, v3);
          v37 = *(_QWORD *)(v33 + 24);
          v33 += 24;
        }
        while ( v37 );
      }
      v38 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v38;
      if ( !v38 || !*(_QWORD *)(StatusReg + 16) )
        return preempt_schedule_notrace(result);
    }
  }
  return result;
}
