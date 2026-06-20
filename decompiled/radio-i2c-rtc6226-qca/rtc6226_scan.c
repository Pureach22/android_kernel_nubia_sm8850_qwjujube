__int64 __fastcall rtc6226_scan(__int64 a1)
{
  __int64 v1; // x20
  void *v3; // x0
  unsigned __int16 *v4; // x23
  int v5; // w8
  unsigned int v6; // w22
  __int64 v7; // x24
  __int64 v8; // x22
  int v9; // w23
  void *v10; // x0
  __int64 v11; // x21
  int v12; // w22
  __int64 result; // x0
  __int64 v14; // x22
  int v15; // w23
  __int64 v16; // x22
  int v17; // w23
  _BYTE *v18; // x13
  _DWORD *v19; // x12
  __int16 *v20; // x22
  unsigned __int8 *v21; // x24
  _BYTE *v22; // x25
  _BYTE *v23; // x27
  __int16 v24; // w21
  _BYTE *v25; // x26
  _DWORD *v26; // x28
  __int64 v27; // x0
  __int64 v28; // x1
  unsigned int v29; // w21
  __int64 v30; // x24
  int v31; // w25
  int v32; // w8
  __int64 v33; // x24
  int v34; // w25
  unsigned int v35; // w8
  unsigned __int64 v36; // x9
  __int64 v37; // x1
  __int64 v38; // x1
  _DWORD *v39; // [xsp+10h] [xbp-50h]
  __int64 v40; // [xsp+18h] [xbp-48h]
  unsigned __int8 *v41; // [xsp+40h] [xbp-20h]
  __int64 v42; // [xsp+4Ch] [xbp-14h] BYREF
  _BYTE v43[4]; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+58h] [xbp-8h]

  v1 = a1 - 2416;
  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  if ( (rtc6226_get_freq(a1 - 2416, (char *)&v42 + 4) & 0x80000000) != 0 )
  {
LABEL_2:
    v3 = &unk_D17A;
LABEL_3:
    printk(v3, "rtc6226_scan");
  }
  else
  {
    v4 = (unsigned __int16 *)(a1 - 388);
    v5 = *(unsigned __int16 *)(a1 - 388);
    *(_BYTE *)(a1 - 656) = 3;
    if ( (rtc6226_set_freq(v1, 10 * v5) & 0x80000000) == 0 )
    {
      if ( !wait_for_completion_timeout(a1 + 1032, 750) )
      {
        printk(&unk_CE33, "rtc6226_scan");
        v43[0] = 7;
        v11 = raw_spin_lock_irqsave(a1 - 440);
        v12 = _kfifo_in(a1 + 744, v43, 1);
        result = raw_spin_unlock_irqrestore(a1 - 440, v11);
        if ( v12 )
          result = _wake_up(a1 + 104, 1, 1, 0);
        goto LABEL_24;
      }
      v18 = (_BYTE *)(a1 - 488);
      v41 = (unsigned __int8 *)(a1 - 655);
      v19 = (_DWORD *)(a1 - 660);
      v20 = (__int16 *)(a1 - 644);
      v39 = (_DWORD *)(a1 - 552);
      v40 = a1 - 440;
      v21 = (unsigned __int8 *)(a1 - 632);
      v22 = (_BYTE *)(a1 - 487);
      v23 = (_BYTE *)(a1 - 486);
      do
      {
        if ( *v18 == 1 )
        {
LABEL_56:
          printk(&unk_CD9E, "rtc6226_scan");
          if ( *v22 == 2 )
            goto LABEL_5;
          goto LABEL_8;
        }
        if ( *v19 != 1 )
          goto LABEL_58;
        v24 = *v20;
        v25 = v18;
        v26 = v19;
        *v20 = *v20 & 0x1FFF | 0x6000;
        if ( (rtc6226_set_register(v1, 5) & 0x80000000) != 0 )
          goto LABEL_55;
        *v20 |= 0x8000u;
        if ( (rtc6226_set_register(v1, 5) & 0x80000000) != 0 )
          goto LABEL_55;
        if ( !wait_for_completion_timeout(a1 + 1032, 3750) )
        {
          printk(&unk_CE62, "rtc6226_scan");
          rtc6226_get_all_registers(v1);
          goto LABEL_60;
        }
        printk(&unk_D975, "rtc6226_scan");
        if ( (rtc6226_get_freq(v1, &v42) & 0x80000000) != 0 )
          goto LABEL_2;
        v27 = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(v1, 11);
        if ( (v27 & 0x80000000) != 0 )
          goto LABEL_64;
        v29 = *v21;
        if ( *v22 == 1 && v29 >= *v41 )
        {
          v43[0] = 1;
          v30 = raw_spin_lock_irqsave(v40);
          v31 = _kfifo_in(a1 + 744, v43, 1);
          v27 = raw_spin_unlock_irqrestore(v40, v30);
          if ( v31 )
            v27 = _wake_up(a1 + 104, 1, 1, 0);
          v21 = (unsigned __int8 *)(a1 - 632);
          v22 = (_BYTE *)(a1 - 487);
        }
        if ( *v25 == 1 )
          goto LABEL_56;
        if ( *v26 != 1 )
        {
LABEL_58:
          printk(&unk_CBB0, "rtc6226_scan");
          goto LABEL_60;
        }
        v32 = (unsigned __int8)*v22;
        v18 = v25;
        v19 = v26;
        if ( v32 == 2 )
        {
          if ( v29 >= *v41 )
          {
            v35 = (unsigned __int8)*v23;
            if ( v35 >= 0x14 )
            {
              __break(0x5512u);
              return rtc6226_get_freq(v27, v28);
            }
            v36 = 1374389535LL * (int)(v42 - 10 * *v4);
            *v23 = v35 + 1;
            *(_WORD *)(a1 - 485 + 2LL * v35) = bswap32((v36 >> 36) + (v36 >> 63)) >> 16;
          }
        }
        else if ( v32 == 1 && v29 >= *v41 )
        {
          msleep((unsigned int)(1000 * *v39));
          v43[0] = 3;
          v33 = raw_spin_lock_irqsave(v40);
          v34 = _kfifo_in(a1 + 744, v43, 1);
          raw_spin_unlock_irqrestore(v40, v33);
          if ( v34 )
            _wake_up(a1 + 104, 1, 1, 0);
          v21 = (unsigned __int8 *)(a1 - 632);
          v22 = (_BYTE *)(a1 - 487);
          v19 = v26;
          v18 = v25;
        }
      }
      while ( (*(_WORD *)(a1 - 634) & 0x2000) == 0 && 10 * *(unsigned __int16 *)(a1 - 386) != (_DWORD)v42 );
      printk(&unk_D99B, "rtc6226_scan");
      v24 = *v20;
      *v20 = *v20 & 0x1FFF | 0x4000;
      if ( (rtc6226_set_register(v1, 5) & 0x80000000) != 0
        || (*v20 |= 0x8000u, (rtc6226_set_register(v1, 5) & 0x80000000) != 0) )
      {
LABEL_55:
        *v20 = v24;
        printk(&unk_CC34, "rtc6226_scan");
        goto LABEL_5;
      }
      if ( !wait_for_completion_timeout(a1 + 1032, 3750) )
      {
        printk(&unk_DBF0, v37);
LABEL_60:
        result = rtc6226_q_event(v1, 7);
        goto LABEL_24;
      }
      printk(&unk_D975, "rtc6226_scan");
      if ( (rtc6226_get_freq(v1, &v42) & 0x80000000) != 0 )
      {
        v3 = &unk_DAF4;
        goto LABEL_3;
      }
      if ( (((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(v1, 11) & 0x80000000) != 0 )
      {
LABEL_64:
        v3 = &unk_CC50;
        goto LABEL_3;
      }
      if ( 10 * *v4 == (_DWORD)v42 && *v21 >= (unsigned int)*v41 )
      {
        printk(&unk_CDBD, v38);
        rtc6226_q_event(v1, 1);
        msleep((unsigned int)(1000 * *v39));
        rtc6226_q_event(v1, 3);
      }
    }
  }
LABEL_5:
  if ( *(_BYTE *)(a1 - 487) == 2 )
  {
    v6 = (2 * *(unsigned __int8 *)(a1 - 486)) | 1;
    v7 = raw_spin_lock_irqsave(a1 - 444);
    _kfifo_in(a1 + 720, a1 - 486, v6);
    raw_spin_unlock_irqrestore(a1 - 444, v7);
    v43[0] = 14;
    v8 = raw_spin_lock_irqsave(a1 - 440);
    v9 = _kfifo_in(a1 + 744, v43, 1);
    raw_spin_unlock_irqrestore(a1 - 440, v8);
    if ( v9 )
      _wake_up(a1 + 104, 1, 1, 0);
  }
LABEL_8:
  if ( (rtc6226_set_freq(v1, HIDWORD(v42)) & 0x80000000) != 0 )
  {
    printk(&unk_DA64, "rtc6226_scan");
  }
  else
  {
    if ( wait_for_completion_timeout(a1 + 1032, 750) )
      v10 = &unk_CFEE;
    else
      v10 = &unk_DB12;
    printk(v10, "rtc6226_scan");
  }
  *(_WORD *)(a1 - 646) |= 0x1000u;
  if ( (rtc6226_set_register(v1, 4) & 0x80000000) != 0 )
    *(_WORD *)(a1 - 646) &= ~0x1000u;
  v43[0] = 2;
  v14 = raw_spin_lock_irqsave(a1 - 440);
  v15 = _kfifo_in(a1 + 744, v43, 1);
  raw_spin_unlock_irqrestore(a1 - 440, v14);
  if ( v15 )
    _wake_up(a1 + 104, 1, 1, 0);
  v43[0] = 1;
  v16 = raw_spin_lock_irqsave(a1 - 440);
  v17 = _kfifo_in(a1 + 744, v43, 1);
  raw_spin_unlock_irqrestore(a1 - 440, v16);
  if ( v17 )
    _wake_up(a1 + 104, 1, 1, 0);
  *(_BYTE *)(a1 - 656) = 0;
  result = printk(&unk_D676, "rtc6226_scan");
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
