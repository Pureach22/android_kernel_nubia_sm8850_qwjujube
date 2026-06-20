__int64 __fastcall tmc_etr_byte_cntr_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x22
  __int64 v4; // x23
  __int64 v7; // x0
  unsigned __int64 v8; // x24
  __int64 v9; // x21
  unsigned __int64 v10; // x0
  __int64 data; // x20
  __int64 v12; // x8
  unsigned __int64 v13; // x1
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x8
  unsigned __int64 v18; // x1
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  __int64 v21; // x9
  unsigned __int64 v22; // x8
  __int64 v23; // x2
  __int64 v24; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x0
  unsigned __int64 v28; // x9
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  __int64 v36; // x2
  unsigned int v44; // w10
  _QWORD v45[5]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v46 = 0;
  v4 = *(_QWORD *)(v3 + 368);
  if ( a2 )
  {
    mutex_lock(v3 + 312);
    if ( (*(_BYTE *)(v3 + 145) & 1) != 0 )
    {
      if ( *(_BYTE *)(v3 + 144) != 1 )
      {
        if ( v4 )
        {
          v17 = *(_QWORD *)(v4 + 304);
          if ( v17 )
          {
            v18 = *(_QWORD *)(v3 + 400);
            v19 = *(_QWORD *)(v17 + 408);
            _CF = v19 >= v18;
            v20 = v19 - v18;
            v21 = _CF ? 0LL : *(unsigned int *)(v4 + 132);
            v35 = v20 + v21;
            v36 = v35 >= a3 ? a3 : v35;
            if ( v36 >= 1 )
            {
              data = tmc_etr_buf_get_data(*(_QWORD *)(v4 + 288));
              if ( data >= 1 )
                goto LABEL_28;
            }
          }
        }
LABEL_49:
        data = -22;
LABEL_50:
        mutex_unlock(v3 + 312);
        goto LABEL_51;
      }
      if ( *(_DWORD *)(v3 + 160) )
        goto LABEL_10;
      mutex_unlock(v3 + 312);
      if ( *(int *)(v3 + 160) <= 0 && *(_BYTE *)(v3 + 144) == 1 )
      {
        memset(v45, 0, sizeof(v45));
        init_wait_entry(v45, 0);
        v7 = prepare_to_wait_event(v3 + 168, v45, 1);
        if ( *(int *)(v3 + 160) <= 0 )
        {
          while ( *(_BYTE *)(v3 + 144) == 1 )
          {
            if ( v7 )
            {
              if ( !(_DWORD)v7 )
                goto LABEL_9;
              data = -512;
              goto LABEL_51;
            }
            schedule();
            v7 = prepare_to_wait_event(v3 + 168, v45, 1);
            if ( *(int *)(v3 + 160) >= 1 )
              break;
          }
        }
        finish_wait(v3 + 168, v45);
      }
LABEL_9:
      mutex_lock(v3 + 312);
      if ( (*(_BYTE *)(v3 + 145) & 1) != 0 )
      {
LABEL_10:
        v8 = *(unsigned int *)(v3 + 152);
        v9 = *(_QWORD *)(v3 + 400);
        v10 = tmc_etr_buf_get_data(*(_QWORD *)(*(_QWORD *)(v3 + 368) + 288LL));
        data = v10;
        if ( v10 == v8 || !((v10 + (unsigned int)v9) % v8) )
        {
          _X8 = (unsigned int *)(v3 + 160);
          __asm { PRFM            #0x11, [X8] }
          do
            v44 = __ldxr(_X8);
          while ( __stxr(v44 - 1, _X8) );
          if ( v10 >> 31 )
            goto LABEL_56;
          goto LABEL_29;
        }
LABEL_28:
        if ( (unsigned __int64)data >> 31 )
        {
LABEL_56:
          __break(0x800u);
          data = -14;
          goto LABEL_50;
        }
LABEL_29:
        v24 = v46;
        _check_object_size(v46, data, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v26 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v26 = a2 & ((__int64)(a2 << 8) >> 8);
        v27 = data;
        if ( 0x8000000000LL - data >= v26 )
        {
          v28 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v30 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v30 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v30);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v28);
          v27 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v24, data);
          v31 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v33 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v33 - 4096);
          _WriteStatusReg(TTBR1_EL1, v33);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v31);
        }
        if ( v27 )
        {
          data = -14;
        }
        else
        {
          *(_QWORD *)(v3 + 416) += data;
          v34 = *(_QWORD *)(v3 + 400) + data;
          if ( v34 >= *(unsigned int *)(v4 + 132) )
            v34 = 0;
          *(_QWORD *)(v3 + 400) = v34;
        }
        goto LABEL_50;
      }
    }
    if ( v4 )
    {
      v12 = *(_QWORD *)(v4 + 304);
      if ( v12 )
      {
        v13 = *(_QWORD *)(v3 + 400);
        v14 = *(_QWORD *)(v12 + 408);
        _CF = v14 >= v13;
        v15 = v14 - v13;
        v16 = _CF ? 0LL : *(unsigned int *)(v4 + 132);
        v22 = v15 + v16;
        v23 = v22 >= a3 ? a3 : v22;
        if ( v23 >= 1 )
        {
          data = tmc_etr_buf_get_data(*(_QWORD *)(v4 + 288));
          if ( data > 0 )
            goto LABEL_28;
        }
      }
    }
    goto LABEL_49;
  }
  data = -22;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return data;
}
