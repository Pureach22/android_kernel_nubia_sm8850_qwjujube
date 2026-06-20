__int64 adspsleepmon_worker()
{
  __int64 v0; // x0
  __int64 *v2; // x27
  __int64 should_stop; // x0
  __int64 v4; // x21
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x9
  int v8; // w11
  int v9; // w19
  unsigned __int64 v10; // x26
  unsigned __int64 v11; // x27
  __int64 v12; // x28
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  unsigned __int64 v16; // x21
  __int64 *v17; // x24
  int v18; // w11
  int v19; // w26
  unsigned __int64 v20; // x19
  unsigned __int64 v21; // x27
  __int64 v22; // x28
  __int64 *v23; // x8
  bool v24; // zf
  unsigned __int64 v25; // x8
  __int64 v26; // x0
  unsigned __int8 is_audio_active; // w0
  __int64 v28; // x0
  __int64 v29; // x0
  void *v30; // x0
  __int64 v31; // x0
  unsigned __int8 v32; // w9
  unsigned __int64 v33; // x8
  __int64 v34; // x0
  unsigned __int8 v35; // [xsp+8h] [xbp-58h]
  int v36; // [xsp+Ch] [xbp-54h]
  int v37; // [xsp+Ch] [xbp-54h]
  __int64 v38; // [xsp+10h] [xbp-50h] BYREF
  __int64 v39; // [xsp+18h] [xbp-48h]
  __int64 v40; // [xsp+20h] [xbp-40h] BYREF
  __int64 v41; // [xsp+28h] [xbp-38h]
  __int64 v42; // [xsp+30h] [xbp-30h]
  __int64 v43; // [xsp+38h] [xbp-28h]
  __int64 v44; // [xsp+40h] [xbp-20h]
  __int64 v45; // [xsp+48h] [xbp-18h]
  int v46; // [xsp+50h] [xbp-10h]
  __int64 v47; // [xsp+58h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ((__int64 (*)(void))kthread_should_stop)();
  if ( (v0 & 1) == 0 )
  {
    v2 = &qword_A788;
    do
    {
      while ( 1 )
      {
        should_stop = kthread_should_stop(v0);
        if ( (should_stop & 1) != 0 || (word_A629 & 1) != 0 || (byte_A62B & 1) != 0 )
        {
          LODWORD(v4) = 0;
        }
        else
        {
          v43 = 0;
          v44 = 0;
          v41 = 0;
          v42 = 0;
          v40 = 0;
          init_wait_entry(&v40, 0);
          while ( 1 )
          {
            v4 = prepare_to_wait_event(&adspsleepmon_wq, &v40, 1);
            should_stop = kthread_should_stop(v4);
            if ( (should_stop & 1) != 0 || (word_A629 & 1) != 0 || (byte_A62B & 1) != 0 )
              break;
            if ( v4 )
              goto LABEL_8;
            schedule();
          }
          should_stop = finish_wait(&adspsleepmon_wq, &v40);
          LODWORD(v4) = 0;
        }
LABEL_8:
        v5 = kthread_should_stop(should_stop);
        if ( (v5 & 1) != 0 )
          goto LABEL_2;
        if ( !(_DWORD)v4 )
          break;
        v0 = kthread_should_stop(v5);
        if ( (v0 & 1) != 0 )
          goto LABEL_2;
      }
      printk(&unk_8EFC);
      mutex_lock(&unk_A688);
      if ( (_DWORD)qword_A760 )
      {
        if ( (_DWORD)qword_A760 == HIDWORD(qword_A760) )
        {
          __isb(0xFu);
          StatusReg = _ReadStatusReg(CNTVCT_EL0);
          v7 = StatusReg < qword_A7B8 ? ~qword_A7B8 : -qword_A7B8;
          if ( v7 + StatusReg >= (unsigned int)(19200000 * HIDWORD(qword_A638)) )
          {
            v8 = *(_DWORD *)qword_A7C8;
            v9 = *(_DWORD *)(qword_A7C8 + 4);
            v10 = *(_QWORD *)(qword_A7C8 + 8);
            v11 = *(_QWORD *)(qword_A7C8 + 16);
            v12 = *(_QWORD *)(qword_A7C8 + 24);
            if ( v9 && v11 <= v10 && (v10 < StatusReg || v11 >= v10) )
              goto LABEL_30;
            v43 = *(_QWORD *)(qword_A7D0 + 24);
            v44 = *(_QWORD *)(qword_A7D0 + 32);
            v45 = *(_QWORD *)(qword_A7D0 + 40);
            v46 = *(_DWORD *)(qword_A7D0 + 48);
            v40 = *(_QWORD *)qword_A7D0;
            v41 = *(_QWORD *)(qword_A7D0 + 8);
            v42 = *(_QWORD *)(qword_A7D0 + 16);
            if ( v12 != qword_A7B0 )
              goto LABEL_30;
            v37 = v8;
            printk(&unk_9442);
            printk(&unk_95AA);
            printk(&unk_9AFB);
            sleepmon_is_audio_active(&v40);
            if ( dword_A678 )
            {
              v38 = 0;
              v39 = 0;
              mutex_lock(&unk_B140);
              if ( qword_A680 && dword_A678 )
              {
                v29 = *(_QWORD *)(qword_A680 + 968);
                v39 = 0x100000002LL;
                v38 = 0x200000010LL;
                if ( !(unsigned int)rpmsg_send(v29, &v38, 16) )
                {
                  mutex_unlock(&unk_B140);
                  if ( !wait_for_completion_timeout(&dword_A658, 25) )
                    printk(&unk_91EC);
                  ((void (*)(void))print_complete_dsppm_info)();
                  goto LABEL_65;
                }
                printk(&unk_9902);
              }
              mutex_unlock(&unk_B140);
              printk(&unk_9B74);
            }
LABEL_65:
            v38 = 0;
            v39 = 0;
            mutex_lock(&unk_B140);
            if ( qword_A680 )
            {
              v30 = &unk_A520;
              if ( (unsigned int)dword_A678 >= 2 )
              {
                v31 = *(_QWORD *)(qword_A680 + 968);
                LODWORD(v39) = 3;
                if ( HIBYTE(word_A62E) )
                  v32 = 1;
                else
                  v32 = byte_A633;
                BYTE4(v39) = 1;
                *(_WORD *)((char *)&v39 + 5) = v32;
                v38 = 0x200000010LL;
                if ( !(unsigned int)rpmsg_send(v31, &v38, 16) )
                  goto LABEL_71;
                v30 = &unk_9A1E;
              }
            }
            else
            {
              v30 = &unk_A520;
            }
            printk(v30);
LABEL_71:
            mutex_unlock(&unk_B140);
            v8 = v37;
LABEL_30:
            LODWORD(qword_A798) = v8;
            HIDWORD(qword_A798) = v9;
            qword_A7A0 = v10;
            qword_A7A8 = v11;
            v2 = &qword_A788;
            __isb(0xFu);
            v13 = _ReadStatusReg(CNTVCT_EL0);
            qword_A7B0 = v12;
            qword_A7B8 = v13;
          }
        }
      }
      else
      {
        __isb(0xFu);
        v14 = _ReadStatusReg(CNTVCT_EL0);
        if ( v14 < qword_A790 )
          v15 = ~qword_A790;
        else
          v15 = -qword_A790;
        v16 = v15 + v14;
        if ( v15 + v14 >= (unsigned int)(19200000 * qword_A638) )
        {
          v17 = v2;
          v18 = *(_DWORD *)qword_A7C0;
          v19 = *(_DWORD *)(qword_A7C0 + 4);
          v20 = *(_QWORD *)(qword_A7C0 + 8);
          v21 = *(_QWORD *)(qword_A7C0 + 16);
          v22 = *(_QWORD *)(qword_A7C0 + 24);
          if ( v19 && v21 <= v20 && (v20 < v14 || v21 >= v20) )
            goto LABEL_41;
          v23 = *(__int64 **)((char *)&unk_48 + (_QWORD)v17);
          v43 = v23[3];
          v44 = v23[4];
          v45 = v23[5];
          v46 = *((_DWORD *)v23 + 12);
          v40 = *v23;
          v41 = v23[1];
          v24 = v22 == *v17;
          v42 = v23[2];
          if ( !v24 )
            goto LABEL_40;
          v36 = v18;
          printk(&unk_8F32);
          printk(&unk_95AA);
          printk(&unk_A3E4);
          is_audio_active = sleepmon_is_audio_active(&v40);
          if ( !dword_A678 )
            goto LABEL_54;
          v35 = is_audio_active;
          v38 = 0;
          v39 = 0;
          mutex_lock(&unk_B140);
          if ( qword_A680 && dword_A678 )
          {
            v28 = *(_QWORD *)(qword_A680 + 968);
            v39 = 0x100000002LL;
            v38 = 0x200000010LL;
            if ( !(unsigned int)rpmsg_send(v28, &v38, 16) )
            {
              mutex_unlock(&unk_B140);
              if ( !wait_for_completion_timeout(&dword_A658, 25) )
                printk(&unk_91EC);
              ((void (*)(void))print_complete_dsppm_info)();
LABEL_53:
              is_audio_active = v35;
LABEL_54:
              if ( (word_A62E & 1) != 0 )
              {
                if ( (is_audio_active & 1) != 0 )
                {
                  if ( byte_A632 != 1 )
                    panic("ADSP sleep issue detected");
LABEL_78:
                  v34 = printk(&unk_93C1);
                  sleepmon_send_ssr_command(v34);
                  v18 = v36;
LABEL_41:
                  LODWORD(qword_A770) = v18;
                  HIDWORD(qword_A770) = v19;
                  qword_A778 = v20;
                  qword_A780 = v21;
                  __isb(0xFu);
                  v25 = _ReadStatusReg(CNTVCT_EL0);
                  qword_A788 = v22;
                  qword_A790 = v25;
                  v2 = v17;
                  goto LABEL_42;
                }
              }
              else if ( ((unsigned __int8)byte_A632 & is_audio_active & 1) != 0 )
              {
                goto LABEL_78;
              }
              v33 = qword_A650 + v16;
              qword_A650 += v16;
              if ( byte_A62B == 1 )
                ++dword_A648;
              v18 = v36;
              if ( v33 >= 19200000 * (unsigned __int64)(unsigned int)qword_A640
                && (unsigned int)dword_A648 >= HIDWORD(qword_A640) )
              {
                adspsleepmon_lpm_adsp_panic_overall();
                v18 = v36;
LABEL_40:
                qword_A650 = 0;
                dword_A648 = 0;
              }
              goto LABEL_41;
            }
            printk(&unk_9902);
          }
          mutex_unlock(&unk_B140);
          printk(&unk_9B74);
          goto LABEL_53;
        }
      }
LABEL_42:
      if ( (unsigned __int8)word_A629 == 1 )
        word_A629 = 0;
      byte_A62B = 0;
      v26 = mutex_unlock(&unk_A688);
      v0 = kthread_should_stop(v26);
    }
    while ( (v0 & 1) == 0 );
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return 0;
}
