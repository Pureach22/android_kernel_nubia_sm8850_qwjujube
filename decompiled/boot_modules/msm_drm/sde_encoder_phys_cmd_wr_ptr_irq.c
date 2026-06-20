__int64 __fastcall sde_encoder_phys_cmd_wr_ptr_irq(__int64 result)
{
  _QWORD *v1; // x20
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x8
  __int64 v4; // x24
  int v5; // w21
  unsigned int v6; // w8
  unsigned int v13; // w10
  _DWORD *v14; // x8
  __int64 v15; // x0
  int v16; // w22
  int v17; // w4
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x5
  int v22; // w6
  int v23; // w7
  __int64 v24; // x8
  unsigned int disp_op; // w8
  __int64 v26; // x0
  int v27; // w21
  void (*v28)(void); // x8
  __int64 v29; // x0
  __int64 v30; // x8
  _QWORD v31[14]; // [xsp+68h] [xbp-E8h] BYREF
  _QWORD v32[2]; // [xsp+D8h] [xbp-78h] BYREF
  __int64 v33; // [xsp+E8h] [xbp-68h]
  __int64 v34; // [xsp+F0h] [xbp-60h]
  __int64 v35; // [xsp+F8h] [xbp-58h]
  __int64 v36; // [xsp+100h] [xbp-50h]
  __int64 v37; // [xsp+108h] [xbp-48h]
  __int64 v38; // [xsp+110h] [xbp-40h]
  __int64 v39; // [xsp+118h] [xbp-38h]
  __int64 v40; // [xsp+120h] [xbp-30h]
  __int64 v41; // [xsp+128h] [xbp-28h]
  __int64 v42; // [xsp+130h] [xbp-20h]
  __int64 v43; // [xsp+138h] [xbp-18h]
  __int64 v44; // [xsp+140h] [xbp-10h]
  __int64 v45; // [xsp+148h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v31, 0, sizeof(v31));
  if ( result )
  {
    v1 = (_QWORD *)result;
    if ( *(_QWORD *)(result + 416) )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v3 = v1[1];
        v4 = v1[52];
        v5 = v3 ? *(_DWORD *)(v3 + 4676) : 0;
        v6 = *((_DWORD *)v1 + 220);
        do
        {
          if ( !v6 )
          {
            v16 = 0;
            goto LABEL_21;
          }
          _X12 = (unsigned int *)(v1 + 110);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v13 = __ldxr(_X12);
            if ( v13 != v6 )
              break;
            if ( !__stlxr(v6 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v13 == v6;
          v6 = v13;
        }
        while ( !_ZF );
        if ( v1[49] )
        {
          raw_spin_lock(v1[103]);
          v14 = (_DWORD *)v1[49];
          v15 = *v1;
          v16 = 16;
          if ( *(v14 - 1) != -570463643 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD *, __int64))v14)(v15, v1, 16);
          raw_spin_unlock(v1[103]);
        }
        else
        {
          v16 = 16;
        }
LABEL_21:
        ((void (__fastcall *)(_QWORD, _QWORD *))sde_encoder_helper_get_pp_line_count)(*v1, v31);
        v17 = *v1 ? *(_DWORD *)(*v1 + 24LL) : -1;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_phys_cmd_wr_ptr_irq",
          626,
          2,
          v17,
          *(_DWORD *)(v4 + 64) - 1,
          v16,
          v5,
          v31[0]);
        if ( !v5 )
          break;
        v24 = v1[53];
        if ( (*(_QWORD *)(*(_QWORD *)(v24 + 40) + 32LL) & 0x20) != 0 )
          break;
        v43 = 0;
        v44 = 0;
        v41 = 0;
        v42 = 0;
        v39 = 0;
        v40 = 0;
        v37 = 0;
        v38 = 0;
        v35 = 0;
        v36 = 0;
        v33 = 0;
        v34 = 0;
        v32[0] = 0;
        v32[1] = 0;
        if ( !v24 )
          break;
        disp_op = sde_encoder_get_disp_op(*v1);
        v26 = v1[53];
        v27 = *((unsigned __int16 *)v1 + 267) + *((_DWORD *)v1 + 726);
        if ( !v26 )
          goto LABEL_33;
        if ( disp_op < 3 )
        {
          v28 = *(void (**)(void))(v26 + 8LL * disp_op + 1208);
          if ( v28 )
          {
            if ( *((_DWORD *)v28 - 1) != -1913620264 )
              __break(0x8228u);
            v28();
          }
LABEL_33:
          ((void (__fastcall *)(_QWORD, _QWORD *))sde_encoder_helper_get_pp_line_count)(*v1, v32);
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_encoder_override_tearcheck_rd_ptr",
            221,
            4,
            *(_DWORD *)(v1[53] + 32LL) - 1,
            *((unsigned __int16 *)v1 + 267),
            *((_DWORD *)v1 + 726),
            v27 + 1,
            v33);
          break;
        }
        __break(0x5512u);
        if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                         + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
            & 1) != 0 )
        {
          ++*(_DWORD *)(StatusReg + 16);
          v29 = _traceiter_tracing_mark_write(0, 66, StatusReg, "wr_ptr_irq", 0);
          v30 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v30;
          if ( !v30 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule_notrace(v29);
        }
      }
      sde_encoder_handle_frequency_stepping(v1, 1, v18, v19, v20, v21, v22, v23);
      result = _wake_up(v1 + 112, 3, 0, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
