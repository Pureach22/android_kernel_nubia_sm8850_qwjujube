__int64 __fastcall msm_lastclose(__int64 result)
{
  __int64 v1; // x22
  _QWORD *v2; // x19
  __int64 v3; // x20
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  int v8; // w8
  __int64 v9; // x24
  __int64 v10; // x0
  __int64 v11; // x21
  int v12; // w8
  bool v13; // zf
  int v14; // w21
  __int64 v15; // x1
  __int64 (__fastcall *v16)(_QWORD); // x8
  unsigned int v17; // w21
  __int64 v18; // x25
  void (__fastcall *v19)(_QWORD); // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x21
  int v23; // w20
  __int64 v24; // x0
  __int64 v25; // x20
  int v26; // w8
  bool v27; // zf
  __int64 v28; // x0
  __int64 v29; // x1
  unsigned __int64 v30; // x21
  __int64 v31; // x20
  __int64 v32; // x0
  __int64 v33; // x0
  int v34; // w20
  __int64 v35; // x0
  __int64 v36; // x20
  int v37; // w8
  bool v38; // zf
  __int64 v39; // x1
  __int64 v40; // x8
  __int64 (__fastcall *v41)(_QWORD); // x8
  __int64 v42; // [xsp+0h] [xbp-30h] BYREF
  __int64 v43; // [xsp+8h] [xbp-28h]
  __int64 v44; // [xsp+10h] [xbp-20h]
  __int64 v45; // [xsp+18h] [xbp-18h]
  __int64 v46; // [xsp+20h] [xbp-10h]
  __int64 v47; // [xsp+28h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 56);
  if ( v1 )
  {
    v2 = *(_QWORD **)(v1 + 8);
    if ( v2 )
    {
      v3 = result;
      if ( !*v2 )
        goto LABEL_100;
      v4 = *(__int64 (__fastcall **)(_QWORD))(*v2 + 272LL);
      if ( !v4 )
        goto LABEL_100;
      v5 = *(_QWORD *)(v1 + 8);
      if ( *((_DWORD *)v4 - 1) != -2057246533 )
        __break(0x8228u);
      v6 = v4(v5);
      if ( (v6 & 1) == 0 )
        goto LABEL_100;
      v7 = ktime_get(v6);
      v8 = *(_DWORD *)(v1 + 696);
      v9 = v7 + 500000000;
      while ( 1 )
      {
        if ( v8 )
        {
          v45 = 0;
          v46 = 0;
          v43 = 0;
          v44 = 0;
          v42 = 0;
          init_wait_entry(&v42, 0);
          prepare_to_wait_event(v1 + 704, &v42, 2);
          if ( *(_DWORD *)(v1 + 696) )
          {
            v10 = 125;
            do
            {
              v11 = schedule_timeout(v10);
              prepare_to_wait_event(v1 + 704, &v42, 2);
              v12 = *(_DWORD *)(v1 + 696);
              if ( v11 )
                v13 = 0;
              else
                v13 = v12 == 0;
              if ( v13 )
                v10 = 1;
              else
                v10 = v11;
            }
            while ( v12 && v10 );
          }
          else
          {
            LODWORD(v10) = 125;
          }
          v14 = v10;
          v7 = finish_wait(v1 + 704, &v42);
        }
        else
        {
          v14 = 125;
        }
        v7 = ktime_get(v7);
        v15 = *(unsigned int *)(v1 + 696);
        if ( !(_DWORD)v15 || v14 )
          break;
        v8 = 1;
        if ( v9 - v7 <= 0 )
          goto LABEL_41;
      }
      if ( v14 )
        goto LABEL_29;
LABEL_41:
      printk(&unk_222C71, v15);
LABEL_29:
      v16 = *(__int64 (__fastcall **)(_QWORD))(*v2 + 280LL);
      if ( *((_DWORD *)v16 - 1) != -543790661 )
        __break(0x8228u);
      result = v16(v2);
      if ( !(_DWORD)result )
      {
LABEL_100:
        if ( *(_DWORD *)(v3 + 428) )
        {
          v17 = 0;
          do
          {
            v18 = *(_QWORD *)(v3 + 384) + 312LL * (int)v17;
            if ( (unsigned int)timer_delete_sync(v18 + 32) )
            {
              v19 = *(void (__fastcall **)(_QWORD))(v18 + 56);
              if ( *((_DWORD *)v19 - 1) != 1184366065 )
                __break(0x8228u);
              v19(v18 + 32);
            }
            ++v17;
          }
          while ( v17 < *(_DWORD *)(v3 + 428) );
        }
        v20 = _flush_workqueue(*(_QWORD *)(v1 + 688));
        v21 = ktime_get(v20);
        v22 = v21 + 500000000;
        if ( *(_DWORD *)(v1 + 696) )
          goto LABEL_42;
        v23 = 125;
        while ( 1 )
        {
          v28 = ktime_get(v21);
          v29 = *(unsigned int *)(v1 + 696);
          if ( !(_DWORD)v29 || v23 )
            break;
          if ( v22 - v28 <= 0 )
            goto LABEL_66;
LABEL_42:
          v45 = 0;
          v46 = 0;
          v43 = 0;
          v44 = 0;
          v42 = 0;
          init_wait_entry(&v42, 0);
          prepare_to_wait_event(v1 + 704, &v42, 2);
          LODWORD(v24) = 125;
          if ( *(_DWORD *)(v1 + 696) )
          {
            v24 = 125;
            do
            {
              v25 = schedule_timeout(v24);
              prepare_to_wait_event(v1 + 704, &v42, 2);
              v26 = *(_DWORD *)(v1 + 696);
              if ( v25 )
                v27 = 0;
              else
                v27 = v26 == 0;
              if ( v27 )
                v24 = 1;
              else
                v24 = v25;
            }
            while ( v26 && v24 );
          }
          v23 = v24;
          v21 = finish_wait(v1 + 704, &v42);
        }
        if ( v23 )
        {
          if ( !*(_DWORD *)(v1 + 992) )
            goto LABEL_67;
          goto LABEL_59;
        }
LABEL_66:
        printk(&unk_222C71, v29);
        if ( !*(_DWORD *)(v1 + 992) )
          goto LABEL_67;
LABEL_59:
        v30 = 0;
        v31 = v1 + 2432;
        do
        {
          if ( v30 == 16 )
          {
            __break(0x5512u);
            goto LABEL_74;
          }
          if ( *(_QWORD *)(v31 - 1296) )
            kthread_flush_worker(v31 - 1280);
          if ( *(_QWORD *)(v31 - 16) )
            kthread_flush_worker(v31);
          ++v30;
          v31 += 80;
        }
        while ( v30 < *(unsigned int *)(v1 + 992) );
LABEL_67:
        v32 = kthread_flush_worker(v1 + 3696);
        if ( !*(_QWORD *)(v1 + 592) )
        {
          v32 = (__int64)(v2 + 3);
          if ( v2[3] )
          {
            v32 = drm_client_modeset_commit_locked(v32);
            if ( (_DWORD)v32 )
              v32 = _drm_err("client modeset commit failed: %d\n", v32);
          }
        }
        v33 = ktime_get(v32);
        v30 = v33 + 500000000;
        if ( *(_DWORD *)(v1 + 696) )
          goto LABEL_74;
        v34 = 125;
        while ( 1 )
        {
          result = ktime_get(v33);
          v39 = *(unsigned int *)(v1 + 696);
          if ( !(_DWORD)v39 || v34 )
            break;
          if ( (__int64)(v30 - result) <= 0 )
            goto LABEL_96;
LABEL_74:
          v45 = 0;
          v46 = 0;
          v43 = 0;
          v44 = 0;
          v42 = 0;
          init_wait_entry(&v42, 0);
          prepare_to_wait_event(v1 + 704, &v42, 2);
          LODWORD(v35) = 125;
          if ( *(_DWORD *)(v1 + 696) )
          {
            v35 = 125;
            do
            {
              v36 = schedule_timeout(v35);
              prepare_to_wait_event(v1 + 704, &v42, 2);
              v37 = *(_DWORD *)(v1 + 696);
              if ( v36 )
                v38 = 0;
              else
                v38 = v37 == 0;
              if ( v38 )
                v35 = 1;
              else
                v35 = v36;
            }
            while ( v37 && v35 );
          }
          v34 = v35;
          v33 = finish_wait(v1 + 704, &v42);
        }
        if ( v34 )
        {
          v40 = *v2;
          if ( !*v2 )
            goto LABEL_95;
          goto LABEL_91;
        }
LABEL_96:
        result = printk(&unk_222C71, v39);
        v40 = *v2;
        if ( !*v2 )
          goto LABEL_95;
LABEL_91:
        v41 = *(__int64 (__fastcall **)(_QWORD))(v40 + 168);
        if ( v41 )
        {
          if ( *((_DWORD *)v41 - 1) != -2100390869 )
            __break(0x8228u);
          result = v41(v2);
        }
      }
    }
  }
LABEL_95:
  _ReadStatusReg(SP_EL0);
  return result;
}
