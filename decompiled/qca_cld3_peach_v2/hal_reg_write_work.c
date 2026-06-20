__int64 __fastcall hal_reg_write_work(__int64 result)
{
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x22
  _QWORD *v3; // x19
  unsigned __int8 **v4; // x24
  int v5; // w21
  __int64 v6; // x8
  _BYTE *v7; // x25
  unsigned int v8; // w8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w23
  unsigned int v18; // w21
  __int64 v19; // x4
  unsigned __int64 v20; // x10
  unsigned __int8 *v21; // x27
  unsigned __int64 v22; // x8
  unsigned int v23; // w26
  unsigned __int64 v24; // x25
  __int64 v25; // x8
  __int64 v26; // x21
  int v27; // w8
  unsigned int v28; // w2
  unsigned int *v29; // x1
  unsigned int v30; // w28
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x26
  __int64 v34; // x0
  unsigned int v41; // w8
  unsigned int v44; // w9
  unsigned int *v45; // [xsp+8h] [xbp-8h]

  v1 = result + 73728;
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = (_QWORD *)result;
  v4 = (unsigned __int8 **)(*(_QWORD *)(result + 74464) + ((unsigned __int64)*(unsigned int *)(result + 74532) << 6));
  __isb(0xFu);
  v4[5] = (unsigned __int8 *)_ReadStatusReg(CNTVCT_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  v5 = *(_DWORD *)(StatusReg + 40);
  v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v6;
  if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
    result = preempt_schedule(result);
  *((_DWORD *)v4 + 14) = v5;
  __dsb(0xDu);
  v7 = v4 + 3;
  if ( *((_BYTE *)v4 + 24) )
  {
    v8 = *(_DWORD *)(v1 + 700);
    if ( v8 > *(_DWORD *)(v1 + 704) )
      *(_DWORD *)(v1 + 704) = v8;
    result = hif_prevent_link_low_power_states(*v3);
    if ( (_DWORD)result )
    {
      ++*(_DWORD *)(v1 + 696);
      return result;
    }
    __dsb(0xDu);
    if ( *v7 )
    {
      v17 = 0;
      v18 = 0;
      v45 = (unsigned int *)(v1 + 700);
      while ( 1 )
      {
        __dsb(0xDu);
        if ( *v4 )
        {
          v19 = **v4;
          if ( *((_DWORD *)v4 + 15) == (_DWORD)v19 )
            goto LABEL_12;
          v33 = jiffies;
          if ( hal_reg_write_work___last_ticks - jiffies + 125 < 0 )
            goto LABEL_38;
        }
        else
        {
          v33 = jiffies;
          if ( hal_reg_write_work___last_ticks - jiffies + 125 < 0 )
          {
            v19 = 57005;
LABEL_38:
            qdf_trace_msg(
              0x46u,
              2u,
              "%s: q_elem fields not up to date 0x%x 0x%x",
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              "hal_reg_write_work",
              v19,
              *((unsigned int *)v4 + 15));
            hal_reg_write_work___last_ticks = v33;
          }
        }
        if ( v18 > 4 )
        {
          v34 = printk(
                  &unk_AAA255,
                  "0",
                  "hal_reg_write_work",
                  "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/hal/wifi3.0/hal_srng.c");
          dump_stack(v34);
LABEL_12:
          __isb(0xFu);
          v20 = _ReadStatusReg(CNTVCT_EL0);
          v4[6] = (unsigned __int8 *)v20;
          v21 = v4[1];
          v22 = v20 - (_QWORD)v4[4];
          v23 = **v4;
          if ( 10 * v22 >= v22 )
            v24 = 10 * v22 / 0xC0;
          else
            v24 = 10 * ((v20 - (unsigned __int64)v4[4]) / 0xC0);
          v25 = 74436;
          if ( v24 >= 0x64 )
          {
            if ( v24 >= 0x3E8 )
            {
              if ( v24 >> 3 >= 0x271 )
                v25 = 74448;
              else
                v25 = 74444;
            }
            else
            {
              v25 = 74440;
            }
          }
          ++*(_DWORD *)((char *)v3 + v25);
          ++*(_DWORD *)(v1 + 684);
          _X10 = v1 + 700;
          __asm { PRFM            #0x11, [X10] }
          do
            v41 = __ldxr(v45);
          while ( __stxr(v41 - 1, v45) );
          v26 = (__int64)*v4;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v26 + 80);
          }
          else
          {
            raw_spin_lock_bh(v26 + 80);
            *(_QWORD *)(v26 + 88) |= 1uLL;
          }
          v27 = *(_DWORD *)(v26 + 212);
          *(_BYTE *)(v26 + 192) = 0;
          v28 = *(_DWORD *)(v26 + 120);
          *(_DWORD *)(v26 + 212) = v27 + 1;
          *((_DWORD *)v4 + 5) = v28;
          v29 = *(unsigned int **)(v26 + 144);
          if ( (*(_BYTE *)(v1 + 496) & 1) != 0 )
            hal_write32_mb_0(v3, (_DWORD)v29 - *((_DWORD *)v3 + 4), v28);
          else
            writel_6(v28, v29);
          v30 = *(_DWORD *)(v26 + 120);
          *((_BYTE *)v4 + 24) = 0;
          v31 = *(_QWORD *)(v26 + 88);
          *(_QWORD *)(v26 + 200) = v4[6];
          if ( (v31 & 1) != 0 )
          {
            *(_QWORD *)(v26 + 88) = v31 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v26 + 80);
          }
          else
          {
            raw_spin_unlock(v26 + 80);
          }
          if ( is_hal_verbose_debug_enabled == 1 )
            qdf_trace_msg(
              0x46u,
              8u,
              "%s: read_idx %u srng 0x%x, addr 0x%pK dequeue_val %u sched delay %llu us",
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              "hal_reg_write_work",
              *(unsigned int *)(v1 + 804),
              v23,
              v21,
              v30,
              v24);
          ++v17;
          v32 = ((unsigned __int8)*(_DWORD *)(v1 + 804) + 1) & 0x1F;
          v4 = (unsigned __int8 **)(*(_QWORD *)(v1 + 736) + (v32 << 6));
          *(_DWORD *)(v1 + 804) = v32;
          __dsb(0xDu);
          v7 = v4 + 3;
          if ( !*((_BYTE *)v4 + 24) )
            goto LABEL_48;
          v18 = 0;
        }
        else
        {
          ++v18;
          qdf_sleep();
          __dsb(0xDu);
          if ( !*v7 )
            goto LABEL_48;
        }
      }
    }
    v17 = 0;
LABEL_48:
    result = hif_allow_link_low_power_states(*v3);
    _X8 = (unsigned int *)(v1 + 808);
    __asm { PRFM            #0x11, [X8] }
    do
      v44 = __ldxr(_X8);
    while ( __stxr(v44 - v17, _X8) );
  }
  return result;
}
