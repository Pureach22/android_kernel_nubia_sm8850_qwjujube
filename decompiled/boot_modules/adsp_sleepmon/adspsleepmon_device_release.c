__int64 __fastcall adspsleepmon_device_release(__int64 a1, __int64 a2)
{
  __int64 *v2; // x19
  __int64 *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x8
  int v7; // w20
  int v8; // w21
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x12
  unsigned __int64 StatusReg; // x10
  int v13; // w8
  __int64 v14; // x11
  __int64 v15; // x10
  __int64 v16; // x13

  v2 = *(__int64 **)(a2 + 32);
  if ( !v2 )
    return 4294967235LL;
  mutex_lock(&unk_A688);
  raw_spin_lock(v2 + 2);
  v4 = (__int64 *)v2[1];
  if ( v4 )
  {
    v5 = *v2;
    *v4 = *v2;
    if ( v5 )
      *(_QWORD *)(v5 + 8) = v4;
    *v2 = 0;
    v2[1] = 0;
  }
  v6 = qword_A768;
  if ( qword_A768 )
  {
    v8 = 0;
    v7 = 0;
    do
    {
      if ( *(_DWORD *)(v6 + 20) )
      {
        v8 += *(_DWORD *)(v6 + 24);
        v7 += *(_DWORD *)(v6 + 28);
      }
      v6 = *(_QWORD *)v6;
    }
    while ( v6 );
  }
  else
  {
    v7 = 0;
    v8 = 0;
  }
  raw_spin_unlock(v2 + 2);
  kfree(v2);
  if ( v8 != (_DWORD)qword_A760 )
  {
    if ( !v8 || v8 == v7 )
    {
      if ( v8 )
      {
        v14 = *(_QWORD *)(qword_A7C8 + 24);
        v15 = *(_QWORD *)qword_A7C8;
        v16 = *(_QWORD *)(qword_A7C8 + 8);
        qword_A7A8 = *(_QWORD *)(qword_A7C8 + 16);
        qword_A7B0 = v14;
        qword_A798 = v15;
        qword_A7A0 = v16;
        __isb(0xFu);
        qword_A7B8 = _ReadStatusReg(CNTVCT_EL0);
        v13 = HIDWORD(qword_A638);
        qword_A650 = 0;
        dword_A648 = 0;
      }
      else
      {
        v9 = *(_QWORD *)(qword_A7C0 + 24);
        v10 = *(_QWORD *)qword_A7C0;
        v11 = *(_QWORD *)(qword_A7C0 + 8);
        qword_A780 = *(_QWORD *)(qword_A7C0 + 16);
        qword_A788 = v9;
        qword_A770 = v10;
        qword_A778 = v11;
        __isb(0xFu);
        StatusReg = _ReadStatusReg(CNTVCT_EL0);
        v13 = qword_A638;
        qword_A790 = StatusReg;
      }
      mod_timer(&adspsleep_timer, jiffies + (unsigned int)(250 * v13));
      HIBYTE(word_A629) = 1;
    }
    else if ( HIBYTE(word_A629) == 1 )
    {
      timer_delete(&adspsleep_timer);
      HIBYTE(word_A629) = 0;
      qword_A650 = 0;
      dword_A648 = 0;
    }
    LODWORD(qword_A760) = v8;
    HIDWORD(qword_A760) = v7;
  }
  mutex_unlock(&unk_A688);
  printk(&unk_9876);
  return 0;
}
