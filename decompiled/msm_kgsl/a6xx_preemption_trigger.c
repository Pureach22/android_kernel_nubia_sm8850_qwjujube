__int64 __fastcall a6xx_preemption_trigger(__int64 result, char a2)
{
  unsigned int *v2; // x19
  __int64 v3; // x23
  unsigned int v5; // w25
  __int64 v6; // x20
  __int64 v7; // x21
  int rptr; // w0
  int v9; // w26
  int v10; // w22
  __int64 v11; // x21
  int *v12; // x8
  int v13; // w21
  const char *v14; // x0
  int v15; // w8
  int v16; // w8
  unsigned int v17; // w20
  int *v18; // x8
  int v19; // w20
  const char *v20; // x0
  unsigned int v27; // w8
  unsigned int v30; // w9
  unsigned int v33; // w9
  unsigned int v34; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v36[2]; // [xsp+10h] [xbp-10h] BYREF

  v2 = (unsigned int *)result;
  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = result + 19632;
  v35 = 0;
  v36[0] = 0;
  v34 = 0;
  _X10 = (unsigned int *)(result + 20488);
  __asm { PRFM            #0x11, [X10] }
  while ( 1 )
  {
    v27 = __ldxr(_X10);
    if ( v27 )
      break;
    if ( !__stlxr(1u, _X10) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( !v27 )
  {
    if ( *(_DWORD *)v3 )
    {
      v5 = 0;
      v6 = result + 14352;
      while ( 1 )
      {
        v7 = raw_spin_lock_irqsave(v6 + 1292);
        rptr = adreno_get_rptr(v6);
        v9 = *(_DWORD *)(v6 + 20);
        v10 = rptr;
        result = raw_spin_unlock_irqrestore(v6 + 1292, v7);
        if ( v10 != v9 )
          break;
        ++v5;
        v6 += 1320;
        if ( v5 >= *(_DWORD *)v3 )
          goto LABEL_37;
      }
      if ( v6 )
      {
        if ( v6 != *((_QWORD *)v2 + 2455) )
        {
          timer_delete(v2 + 4954);
          v11 = raw_spin_lock_irqsave(v6 + 1292);
          kgsl_sharedmem_readq(*((_QWORD *)v2 + 6), v36, (32LL * *(int *)(v6 + 28)) | 0x10);
          kgsl_sharedmem_readl(*((_QWORD *)v2 + 6), &v34, (32LL * *(int *)(v6 + 28)) | 0x18);
          kgsl_sharedmem_writel(*(_QWORD *)(v6 + 184), 24, *(unsigned int *)(v6 + 20));
          raw_spin_unlock_irqrestore(v6 + 1292, v11);
          if ( (*((_QWORD *)v2 + 13) & 0x40) != 0 )
          {
            kgsl_sharedmem_writeq(*((_QWORD *)v2 + 125), 8, v36[0]);
            kgsl_sharedmem_writel(*((_QWORD *)v2 + 125), 20, v34);
          }
          kgsl_sharedmem_readq(*((_QWORD *)v2 + 2562), &v35, 8LL * *(int *)(v6 + 28));
          if ( (gmu_core_isenabled(v2) & 1) != 0 )
          {
            v12 = *((int **)v2 + 1783);
            v13 = *v12;
            if ( *v12 == 660
              || (v14 = *((const char **)v12 + 3)) != nullptr && !strcmp(v14, "qcom,adreno-gpu-a642l")
              || (unsigned int)(v13 - 643) <= 0x14 && ((1 << (v13 + 125)) & 0x180001) != 0 )
            {
              gmu_core_regwrite(v2, 129220, 1);
            }
            else
            {
              gmu_core_regrmw(v2, 146198, 0, 2);
            }
          }
          if ( !(unsigned int)a6xx_fenced_write(v2, 2211, *(_DWORD *)(*(_QWORD *)(v6 + 184) + 24LL), 2) )
          {
            if ( (a2 & 1) == 0 && (unsigned int)gmu_core_dev_wait_for_active_transition(v2) )
              goto LABEL_39;
            if ( !(unsigned int)a6xx_fenced_write(v2, 2212, *(_DWORD *)(*(_QWORD *)(v6 + 184) + 28LL), 2)
              && !(unsigned int)a6xx_fenced_write(v2, 2213, *(_DWORD *)(*(_QWORD *)(v6 + 192) + 24LL), 2)
              && !(unsigned int)a6xx_fenced_write(v2, 2214, *(_DWORD *)(*(_QWORD *)(v6 + 192) + 28LL), 2)
              && !(unsigned int)a6xx_fenced_write(v2, 2215, v35, 2)
              && !(unsigned int)a6xx_fenced_write(v2, 2216, HIDWORD(v35), 2) )
            {
              *((_QWORD *)v2 + 2456) = v6;
              mod_timer(v2 + 5126);
              if ( *(_BYTE *)(v3 + 948) )
                v15 = 513;
              else
                v15 = 1;
              v16 = v15 | (*(_DWORD *)(v3 + 944) << 6);
              if ( *(_BYTE *)(v3 + 949) )
                v17 = v16 | 0x100;
              else
                v17 = v16;
              trace_adreno_preempt_trigger(
                *(unsigned int *)(*((_QWORD *)v2 + 2455) + 28LL),
                *(unsigned int *)(*((_QWORD *)v2 + 2456) + 28LL),
                v17);
              __dmb(0xAu);
              *(_DWORD *)(v3 + 856) = 2;
              __dmb(0xAu);
              result = a6xx_fenced_write(v2, 2208, v17, 2);
              if ( !(_DWORD)result )
                goto LABEL_38;
              *((_QWORD *)v2 + 2456) = 0;
              timer_delete(v2 + 5126);
            }
          }
          if ( (a2 & 1) != 0 )
          {
            _X8 = v2 + 6112;
            __asm { PRFM            #0x11, [X8] }
            do
              v33 = __ldxr(_X8);
            while ( __stxr(v33 | 0x20, _X8) );
            goto LABEL_57;
          }
LABEL_39:
          gmu_core_fault_snapshot(v2, 0);
          _X8 = v2 + 6112;
          __asm { PRFM            #0x11, [X8] }
          do
            v30 = __ldxr(_X8);
          while ( __stxr(v30 | 0x80, _X8) );
LABEL_57:
          __dmb(0xAu);
          kthread_queue_work(*((_QWORD *)v2 + 3050), v2 + 6102);
          __dmb(0xAu);
          *(_DWORD *)(v3 + 856) = 0;
          __dmb(0xAu);
          result = gmu_core_isenabled(v2);
          if ( (result & 1) != 0 )
          {
            v18 = *((int **)v2 + 1783);
            v19 = *v18;
            if ( *v18 == 660
              || (v20 = *((const char **)v18 + 3)) != nullptr && !strcmp(v20, "qcom,adreno-gpu-a642l")
              || (unsigned int)(v19 - 643) <= 0x14 && ((1 << (v19 + 125)) & 0x180001) != 0 )
            {
              result = gmu_core_regwrite(v2, 129220, 0);
            }
            else
            {
              result = gmu_core_regrmw(v2, 146198, 2, 0);
            }
          }
          goto LABEL_38;
        }
        update_wptr(v2, 0, a2 & 1);
        result = mod_timer(v2 + 4954);
      }
    }
LABEL_37:
    __dmb(0xAu);
    *(_DWORD *)(v3 + 856) = 0;
    __dmb(0xAu);
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
