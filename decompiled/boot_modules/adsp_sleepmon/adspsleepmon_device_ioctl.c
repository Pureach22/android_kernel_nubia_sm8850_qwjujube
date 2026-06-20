__int64 __fastcall adspsleepmon_device_ioctl(__int64 a1, int a2, int a3)
{
  __int64 v3; // x19
  __int16 *v4; // x8
  __int64 v5; // x22
  void *v6; // x0
  __int64 v8; // x8
  int v9; // w8
  int v10; // w8
  int v11; // w8
  __int64 v12; // x8
  int v13; // w20
  int v14; // w21
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x12
  unsigned __int64 StatusReg; // x10
  int v19; // w8
  __int64 v20; // x11
  __int64 v21; // x10
  __int64 v22; // x13
  _QWORD v23[2]; // [xsp+0h] [xbp-20h] BYREF
  int v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == -1073196542 )
  {
    v23[0] = 0;
    if ( !inline_copy_from_user((int)v23, a3, 8u) )
    {
      if ( LODWORD(v23[0]) )
      {
        if ( HIDWORD(v23[0]) < 5 )
        {
          v3 = 0;
          if ( SHIDWORD(v23[0]) > 2 )
          {
            v3 = 0;
            if ( HIDWORD(v23[0]) == 3 )
              v4 = &word_A62E;
            else
              v4 = (__int16 *)((char *)&word_A62E + 1);
            *(_BYTE *)v4 = *((_BYTE *)v4 + 2);
          }
          else if ( HIDWORD(v23[0]) == 1 )
          {
            v3 = 0;
            LOBYTE(word_A62E) = 0;
          }
          else if ( HIDWORD(v23[0]) == 2 )
          {
            v3 = 0;
            HIBYTE(word_A62E) = 0;
          }
          goto LABEL_23;
        }
        v6 = &unk_8F5F;
        v3 = 0xFFFFFFEA00000000LL;
      }
      else
      {
        v6 = &unk_9EE7;
        v3 = 0xFFFFFFE700000000LL;
      }
LABEL_22:
      printk(v6);
      goto LABEL_23;
    }
LABEL_18:
    v3 = 0xFFFFFFE700000000LL;
    printk(&unk_9FD8);
    goto LABEL_23;
  }
  if ( a2 != -1072410111 )
  {
    v3 = 0xFFFFFFE700000000LL;
    printk(&unk_984D);
    goto LABEL_23;
  }
  v5 = *(_QWORD *)(a1 + 32);
  v24 = 0;
  v23[0] = 0;
  v23[1] = 0;
  if ( inline_copy_from_user((int)v23, a3, 0x14u) )
    goto LABEL_18;
  if ( !v5 )
  {
    printk(&unk_946D);
    v3 = 0xFFFFFFF400000000LL;
    goto LABEL_23;
  }
  if ( *(_DWORD *)(v5 + 20) >= 2u )
  {
    printk(&unk_A2D1);
    v3 = 0xFFFFFFD600000000LL;
    goto LABEL_23;
  }
  if ( !LODWORD(v23[0]) )
  {
    v6 = &unk_9EE7;
    v3 = 0xFFFFFFE700000000LL;
    goto LABEL_22;
  }
  if ( HIDWORD(v23[0]) >= 6 )
  {
    v6 = &unk_8F5F;
    v3 = 0xFFFFFFEA00000000LL;
    goto LABEL_22;
  }
  mutex_lock(&unk_A688);
  if ( !*(_DWORD *)(v5 + 20) )
  {
    v8 = qword_A768;
    *(_QWORD *)v5 = qword_A768;
    if ( v8 )
      *(_QWORD *)(v8 + 8) = v5;
    qword_A768 = v5;
    *(_QWORD *)(v5 + 8) = &qword_A768;
    *(_DWORD *)(v5 + 20) = 1;
  }
  if ( SHIDWORD(v23[0]) <= 2 )
  {
    if ( HIDWORD(v23[0]) == 1 )
      goto LABEL_42;
    if ( HIDWORD(v23[0]) != 2 )
      goto LABEL_51;
    goto LABEL_47;
  }
  switch ( HIDWORD(v23[0]) )
  {
    case 5:
      *(_QWORD *)(v5 + 24) = 0;
      break;
    case 4:
      v10 = *(_DWORD *)(v5 + 28);
      if ( v10 )
        *(_DWORD *)(v5 + 28) = v10 - 1;
      else
        printk(&unk_9649);
LABEL_47:
      v11 = *(_DWORD *)(v5 + 24);
      if ( v11 )
      {
        v9 = v11 - 1;
        goto LABEL_50;
      }
      printk(&unk_954F);
      break;
    case 3:
      ++*(_DWORD *)(v5 + 28);
LABEL_42:
      v9 = *(_DWORD *)(v5 + 24) + 1;
LABEL_50:
      *(_DWORD *)(v5 + 24) = v9;
      break;
  }
LABEL_51:
  raw_spin_lock(v5 + 16);
  v12 = qword_A768;
  if ( qword_A768 )
  {
    v14 = 0;
    v13 = 0;
    do
    {
      if ( *(_DWORD *)(v12 + 20) )
      {
        v14 += *(_DWORD *)(v12 + 24);
        v13 += *(_DWORD *)(v12 + 28);
      }
      v12 = *(_QWORD *)v12;
    }
    while ( v12 );
  }
  else
  {
    v13 = 0;
    v14 = 0;
  }
  raw_spin_unlock(v5 + 16);
  if ( !v14 || v14 == v13 )
  {
    if ( v14 )
    {
      v20 = *(_QWORD *)(qword_A7C8 + 24);
      v21 = *(_QWORD *)qword_A7C8;
      v22 = *(_QWORD *)(qword_A7C8 + 8);
      qword_A7A8 = *(_QWORD *)(qword_A7C8 + 16);
      qword_A7B0 = v20;
      qword_A798 = v21;
      qword_A7A0 = v22;
      __isb(0xFu);
      qword_A7B8 = _ReadStatusReg(CNTVCT_EL0);
      v19 = HIDWORD(qword_A638);
      qword_A650 = 0;
      dword_A648 = 0;
    }
    else
    {
      v15 = *(_QWORD *)(qword_A7C0 + 24);
      v16 = *(_QWORD *)qword_A7C0;
      v17 = *(_QWORD *)(qword_A7C0 + 8);
      qword_A780 = *(_QWORD *)(qword_A7C0 + 16);
      qword_A788 = v15;
      qword_A770 = v16;
      qword_A778 = v17;
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      v19 = qword_A638;
      qword_A790 = StatusReg;
    }
    mod_timer(&adspsleep_timer, jiffies + (unsigned int)(250 * v19));
    HIBYTE(word_A629) = 1;
  }
  else if ( HIBYTE(word_A629) == 1 )
  {
    timer_delete(&adspsleep_timer);
    HIBYTE(word_A629) = 0;
    qword_A650 = 0;
    dword_A648 = 0;
  }
  LODWORD(qword_A760) = v14;
  HIDWORD(qword_A760) = v13;
  printk(&unk_94A4);
  mutex_unlock(&unk_A688);
  v3 = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v3 >> 32;
}
