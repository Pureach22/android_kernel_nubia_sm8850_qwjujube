__int64 __fastcall ping_selected_receivers(__int64 a1)
{
  unsigned int v2; // w8
  int v3; // w22
  int v4; // w21
  unsigned __int8 v5; // w20
  unsigned int v6; // w9
  __int64 should_stop; // x0
  int v9; // w8
  int v10; // w27
  __int64 v11; // x22
  __int64 v12; // x23
  int v13; // w25
  __int64 v14; // x0
  int v15; // w8
  int v16; // w24
  __int64 v17; // x26
  __int64 v18; // x0
  int v19; // w0
  int v20; // w8
  int v21; // w9
  bool v22; // zf
  __int64 v23; // x27
  int v24; // w8
  int v25; // w9
  bool v26; // zf
  int v27; // w8
  int v28; // w9
  bool v29; // zf
  unsigned int v30; // [xsp+Ch] [xbp-34h]
  __int64 v31; // [xsp+10h] [xbp-30h] BYREF
  __int64 v32; // [xsp+18h] [xbp-28h]
  __int64 v33; // [xsp+20h] [xbp-20h]
  __int64 v34; // [xsp+28h] [xbp-18h]
  __int64 v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = test_params;
  v2 = HIDWORD(test_params);
  v4 = *(_DWORD *)(a1 + 8);
  v5 = BYTE4(qword_B688);
  v6 = HIDWORD(test_params) / (unsigned int)qword_B694;
  *(_DWORD *)(a1 + 12) = HIDWORD(test_params) / (unsigned int)qword_B694;
  if ( v4 )
  {
    should_stop = ((__int64 (*)(void))kthread_should_stop)();
    if ( (should_stop & 1) != 0 )
      goto LABEL_5;
  }
  else
  {
    *(_DWORD *)(a1 + 12) = v2 % (unsigned int)qword_B694 + v6;
    should_stop = ((__int64 (*)(void))kthread_should_stop)();
    if ( (should_stop & 1) != 0 )
      goto LABEL_5;
  }
  v9 = 2000 * v3 + 3000;
  v10 = 0;
  v11 = a1 + 16;
  v12 = a1 + 52;
  v30 = v9;
  do
  {
    if ( (*(_BYTE *)(a1 + 112) & 1) == 0 )
    {
      v34 = 0;
      v35 = 0;
      v32 = 0;
      v33 = 0;
      v31 = 0;
      init_wait_entry(&v31, 0);
      should_stop = prepare_to_wait_event(a1 + 88, &v31, 1);
      if ( (*(_BYTE *)(a1 + 112) & 1) != 0 )
      {
LABEL_14:
        should_stop = finish_wait(a1 + 88, &v31);
      }
      else
      {
        while ( !should_stop )
        {
          schedule();
          should_stop = prepare_to_wait_event(a1 + 88, &v31, 1);
          if ( *(_BYTE *)(a1 + 112) == 1 )
            goto LABEL_14;
        }
      }
    }
    if ( (kthread_should_stop(should_stop) & 1) != 0 )
      break;
    v15 = *(_DWORD *)(a1 + 12);
    *(_BYTE *)(a1 + 112) = 0;
    if ( v15 < 1 )
    {
      v13 = v10;
    }
    else
    {
      v16 = 0;
      do
      {
        v17 = 0;
        v13 = v10;
        ++v16;
        do
        {
          if ( v17 != HIDWORD(qword_B69C) && (((unsigned __int64)(unsigned int)qword_B688 >> v17) & 1) != 0 )
          {
            while ( 1 )
            {
              v19 = ipclite_test_msg_send(
                      (unsigned int)v17,
                      ((unsigned __int64)(v4 & 0xF) << 36) & 0xFFFF00FFFFFFFFFFLL
                    | ((unsigned __int64)v5 << 40)
                    | 0xAA010000000A0000LL);
              if ( v19 != -11 )
                break;
              msleep_interruptible(50);
            }
            if ( v19 )
              goto LABEL_8;
            ++*(_DWORD *)(v11 + 4 * v17);
            if ( (_DWORD)test_params && (!(v16 % (unsigned int)test_params) || v16 == *(_DWORD *)(a1 + 12)) )
            {
              v18 = _msecs_to_jiffies(v30);
              v20 = *(_DWORD *)(v11 + 4 * v17);
              v21 = *(_DWORD *)(v12 + 4 * v17);
              if ( v18 )
                v22 = 0;
              else
                v22 = v20 == v21;
              if ( v22 )
                v18 = 1;
              if ( v20 != v21 && v18 )
              {
                v34 = 0;
                v35 = 0;
                v32 = 0;
                v33 = 0;
                v31 = 0;
                v23 = _msecs_to_jiffies(v30);
                init_wait_entry(&v31, 0);
                v18 = prepare_to_wait_event(a1 + 88, &v31, 1);
                v24 = *(_DWORD *)(v11 + 4 * v17);
                v25 = *(_DWORD *)(v12 + 4 * v17);
                if ( v23 )
                  v26 = 0;
                else
                  v26 = v24 == v25;
                if ( v26 )
                  v23 = 1;
                if ( v24 == v25 || !v23 )
                {
LABEL_19:
                  finish_wait(a1 + 88, &v31);
                  LODWORD(v18) = v23;
                }
                else
                {
                  while ( !v18 )
                  {
                    v23 = schedule_timeout(v23);
                    v18 = prepare_to_wait_event(a1 + 88, &v31, 1);
                    v27 = *(_DWORD *)(v11 + 4 * v17);
                    v28 = *(_DWORD *)(v12 + 4 * v17);
                    if ( v23 )
                      v29 = 0;
                    else
                      v29 = v27 == v28;
                    if ( v29 )
                      v23 = 1;
                    if ( v27 == v28 || !v23 )
                      goto LABEL_19;
                  }
                }
              }
              if ( (int)v18 <= 0 )
              {
                printk(&unk_AD75, "ipclite_test", "ping_selected_receivers");
LABEL_8:
                v13 = 1;
                goto LABEL_9;
              }
            }
          }
          ++v17;
        }
        while ( v17 != 9 );
        if ( (v13 & 1) != 0 )
          break;
        v10 = 0;
      }
      while ( v16 < *(_DWORD *)(a1 + 12) );
    }
LABEL_9:
    ipclite_global_atomic_inc(&threads_completed);
    v14 = _wake_up(&thread_wq, 1, 1, 0);
    should_stop = kthread_should_stop(v14);
    v10 = v13;
  }
  while ( (should_stop & 1) == 0 );
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return 0;
}
