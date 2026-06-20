__int64 __fastcall sde_encoder_phys_cmd_wait_for_wr_ptr(__int64 a1)
{
  __int64 v1; // x8
  unsigned int disp_op; // w0
  __int64 v4; // x8
  int v5; // w10
  unsigned int v6; // w20
  __int64 v7; // x21
  char v9; // w9
  __int64 v10; // x8
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x21
  unsigned int (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  int v16; // w7
  __int64 v17; // x8
  int v18; // w4
  unsigned int v19; // w8
  unsigned int v25; // w10
  __int64 v26; // x0
  void (__fastcall *v27)(__int64, __int64, __int64); // x9
  __int64 v28; // x20
  __int64 v29; // x0
  char v30; // [xsp+0h] [xbp-30h]
  _QWORD v31[5]; // [xsp+8h] [xbp-28h] BYREF

  v31[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 416);
  v31[2] = 0;
  if ( !v1 || !*(_QWORD *)(a1 + 8) )
  {
    printk(&unk_253460, "_sde_encoder_phys_cmd_wait_for_wr_ptr");
    result = 4294967274LL;
    goto LABEL_24;
  }
  disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
  v4 = *(_QWORD *)(a1 + 8);
  v5 = *(_DWORD *)(a1 + 992);
  v6 = disp_op;
  v7 = *(_QWORD *)(a1 + 416);
  _X22 = (unsigned int *)(a1 + 880);
  v9 = (unsigned int)(*(_DWORD *)(v4 + 3292) - 1) < 2;
  v31[0] = a1 + 896;
  v31[1] = a1 + 880;
  v31[3] = v5 << v9;
  if ( v4 )
  {
    v10 = *(_QWORD *)(v4 + 2512);
    if ( v10 )
    {
      if ( *(_DWORD *)(v10 + 1376) == 10 && *(_DWORD *)(a1 + 664) == 3 )
      {
        result = 0;
LABEL_24:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
  }
  result = sde_encoder_helper_wait_for_irq((__int64 **)a1, 0x12u, v31);
  if ( (_DWORD)result != -110
    || ((v12 = *(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL), *(_DWORD *)(v12 + 52)) || *(_BYTE *)(v12 + 22140) == 1)
    && (result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))sde_encoder_helper_hw_fence_extended_wait)(
                   a1,
                   v7,
                   v31,
                   18),
        (_DWORD)result != -110) )
  {
LABEL_23:
    *(_BYTE *)(a1 + 2760) = (_DWORD)result == 0;
    goto LABEL_24;
  }
  v13 = *(_QWORD *)(a1 + 416);
  if ( !v13 )
  {
LABEL_19:
    v17 = *(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL);
    if ( *(_DWORD *)(v17 + 52) || *(_BYTE *)(v17 + 22140) == 1 )
      sde_encoder_helper_hw_fence_sw_override((__int64 **)a1, v13);
    result = 4294967186LL;
    goto LABEL_23;
  }
  if ( v6 < 3 )
  {
    v14 = *(unsigned int (__fastcall **)(_QWORD))(v13 + 8LL * v6 + 1456);
    if ( v14 )
    {
      v15 = *(_QWORD *)(a1 + 416);
      if ( *((_DWORD *)v14 - 1) != 1800103338 )
        __break(0x8228u);
      if ( !v14(v15) && !(unsigned int)sde_connector_esd_status(*(_QWORD *)(a1 + 8)) )
      {
        if ( *(_QWORD *)a1 )
          v18 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
        else
          v18 = -1;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_encoder_phys_cmd_wait_for_wr_ptr",
          2113,
          -1,
          v18,
          13107,
          -1059143953,
          v16,
          v30);
        if ( *(_DWORD *)(a1 + 664) != 3 )
        {
          v19 = *_X22;
          while ( v19 )
          {
            __asm { PRFM            #0x11, [X22] }
            while ( 1 )
            {
              v25 = __ldxr(_X22);
              if ( v25 != v19 )
                break;
              if ( !__stlxr(v19 - 1, _X22) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v25 == v19;
            v19 = v25;
            if ( _ZF )
            {
              v26 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
              v27 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 392);
              v28 = v26;
              v29 = *(_QWORD *)a1;
              if ( *((_DWORD *)v27 - 1) != -570463643 )
                __break(0x8229u);
              v27(v29, a1, 16);
              raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v28);
              break;
            }
          }
        }
        result = 0;
        goto LABEL_23;
      }
    }
    goto LABEL_19;
  }
  __break(0x5512u);
  return sde_encoder_phys_cmd_wait_for_idle();
}
