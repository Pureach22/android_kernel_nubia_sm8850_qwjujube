__int64 process_cdsp_request_thread()
{
  _DWORD *v1; // x28
  __int64 *v2; // x19
  void *v3; // x24
  int *v4; // x26
  int *v5; // x22
  __int64 v6; // x9
  __int64 should_stop; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x25
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  int v14; // w8
  int v15; // w8
  __int64 v16; // x0
  unsigned int v17; // w8
  __int64 v18; // x0
  int *v19; // x23
  __int64 *v20; // x22
  int v21; // w25
  int *v22; // x19
  __int64 v23; // x0
  void *v24; // x26
  unsigned int v25; // w25
  __int64 v26; // x0
  void (__fastcall *v27)(_QWORD); // x8
  __int64 (*v28)(void); // x8
  int v29; // w0
  int v30; // w25
  int v31; // w8
  int v32; // w25
  __int64 v33; // x0
  __int64 v34; // x0
  void **v35; // x8
  _QWORD *v36; // x10
  int v37; // w25
  __int64 v38; // x0
  void *v39; // x0
  __int64 v40; // [xsp+8h] [xbp-148h] BYREF
  int v41; // [xsp+10h] [xbp-140h]
  __int64 v42; // [xsp+18h] [xbp-138h] BYREF
  int v43; // [xsp+20h] [xbp-130h]
  __int64 v44; // [xsp+28h] [xbp-128h] BYREF
  __int64 v45; // [xsp+30h] [xbp-120h]
  _QWORD v46[35]; // [xsp+38h] [xbp-118h] BYREF

  v46[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v40 = 0;
  if ( (((__int64 (*)(void))kthread_should_stop)() & 1) == 0 )
  {
    v1 = nullptr;
    v2 = &qword_A318;
    v3 = &unk_A2E8;
    v4 = &dword_A398;
    v5 = &dword_A358;
    while ( 1 )
    {
      v8 = ((__int64 (*)(void))kthread_should_stop)();
      if ( (v8 & 1) != 0
        || (v9 = raw_spin_lock_irqsave((char *)&qword_A318 + 4),
            v1 = cdsprm_list,
            v8 = raw_spin_unlock_irqrestore((char *)&qword_A318 + 4, v9),
            v1 != (_DWORD *)&cdsprm_list)
        && v1 )
      {
        LODWORD(v10) = 0;
        should_stop = kthread_should_stop(v8);
        if ( (should_stop & 1) != 0 )
          goto LABEL_2;
      }
      else
      {
        v45 = 0;
        memset(v46, 0, 24);
        v44 = 0;
        init_wait_entry(&v44, 0);
        v10 = prepare_to_wait_event(&cdsprm_wq, &v44, 1);
        v1 = nullptr;
        if ( (((__int64 (*)(void))kthread_should_stop)() & 1) == 0 )
        {
          while ( 1 )
          {
            v11 = raw_spin_lock_irqsave((char *)&qword_A318 + 4);
            v1 = cdsprm_list;
            v12 = raw_spin_unlock_irqrestore((char *)&qword_A318 + 4, v11);
            if ( v1 != (_DWORD *)&cdsprm_list )
            {
              if ( v1 )
                break;
            }
            if ( v10 )
            {
              v1 = nullptr;
              should_stop = kthread_should_stop(v12);
              if ( (should_stop & 1) == 0 )
                goto LABEL_19;
              goto LABEL_2;
            }
            schedule(v12);
            v10 = prepare_to_wait_event(&cdsprm_wq, &v44, 1);
            if ( (kthread_should_stop(v10) & 1) != 0 )
            {
              v1 = nullptr;
              break;
            }
          }
        }
        v13 = finish_wait(&cdsprm_wq, &v44);
        LODWORD(v10) = 0;
        should_stop = kthread_should_stop(v13);
        if ( (should_stop & 1) != 0 )
          goto LABEL_2;
      }
LABEL_19:
      if ( !(_DWORD)v10 )
        break;
LABEL_6:
      if ( (kthread_should_stop(should_stop) & 1) != 0 )
        goto LABEL_2;
    }
    if ( !v1 )
      goto LABEL_2;
    v14 = v1[4];
    if ( v14 <= 4 )
    {
      if ( v14 == 1 )
      {
        v25 = v1[5];
        v26 = raw_spin_lock_irqsave(v2);
        *(_QWORD *)((char *)&unk_1C0 + (_QWORD)v2) = *(_QWORD *)((char *)&unk_1B8 + (_QWORD)v2);
        raw_spin_unlock_irqrestore(v2, v26);
        v27 = *(void (__fastcall **)(_QWORD))((char *)&unk_1C0 + (_QWORD)v2);
        if ( v27 )
        {
          if ( *((_DWORD *)v27 - 1) != -133327859 )
            __break(0x8228u);
          v27(v25);
        }
        goto LABEL_82;
      }
      if ( v14 == 2 && byte_A48A == 1 )
      {
        mutex_lock(v3);
        v15 = v1[5];
        if ( v15 != 1 )
        {
          if ( v15 == 2 && dword_A490 != 0x7FFFFFFF )
          {
            set_qos_latency(0x7FFFFFFF);
            dword_A490 = 0x7FFFFFFF;
          }
          goto LABEL_81;
        }
        v16 = (unsigned int)*v4;
        if ( *(_DWORD *)((char *)&off_F8 + (_QWORD)v4) != (_DWORD)v16 )
        {
          set_qos_latency(v16);
          *(_DWORD *)((char *)&off_F8 + (_QWORD)v4) = *v4;
        }
        v17 = *v5;
        *(_QWORD *)((char *)&unk_8 + (_QWORD)v5) = *((_QWORD *)v1 + 3);
        if ( v17 < 3 )
        {
          if ( v17 )
          {
LABEL_81:
            mutex_unlock(v3);
            goto LABEL_82;
          }
        }
        else
        {
          _flush_workqueue(qword_A2C0);
          if ( dword_A358 != 4 )
            goto LABEL_81;
        }
        dword_A358 = 1;
        queue_work_on(32, qword_A2C0, &qword_A2C8);
        goto LABEL_81;
      }
LABEL_82:
      v34 = raw_spin_lock_irqsave((char *)&qword_A318 + 4);
      v35 = *((void ***)v1 + 1);
      v6 = v34;
      if ( *v35 == v1 && (v36 = *(_QWORD **)v1, *(_DWORD **)(*(_QWORD *)v1 + 8LL) == v1) )
      {
        v36[1] = v35;
        *v35 = v36;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *(_QWORD *)v1 = 0xDEAD000000000100LL;
      *((_QWORD *)v1 + 1) = 0xDEAD000000000122LL;
      *((_BYTE *)v1 + 36) = 0;
      should_stop = raw_spin_unlock_irqrestore((char *)&qword_A318 + 4, v6);
      goto LABEL_6;
    }
    if ( v14 == 5 )
    {
      mutex_lock(&unk_A3A8);
      v28 = (__int64 (*)(void))off_A4E0;
      qword_A4E8 = (__int64)off_A4E0;
      if ( off_A4E0 )
      {
        v29 = v1[5];
        byte_A48B = 1;
        dword_A43C = v29;
        if ( *((_DWORD *)off_A4E0 - 1) != 1995188558 )
          __break(0x8228u);
        v30 = v28();
        byte_A48B = 0;
        mutex_unlock(&unk_A3A8);
        v31 = 0;
        LODWORD(v40) = 4;
        if ( !v30 )
          v31 = v1[5];
      }
      else
      {
        mutex_unlock(&unk_A3A8);
        v31 = 0;
        LODWORD(v40) = 4;
      }
      HIDWORD(v40) = v31;
      v41 = 12;
      if ( (unsigned int)rpmsg_send(*(_QWORD *)(qword_A350 + 968), &v40, 12) )
        printk(&unk_B873);
      goto LABEL_82;
    }
    if ( v14 != 12 || !gcdsprm[0] )
      goto LABEL_82;
    v43 = 0;
    v42 = 0;
    if ( gcdsprm[0] != 1 && dword_99A4 )
      cdsprm_compute_vtcm_set_partition_map(1);
    if ( byte_A3D8 == 1 )
    {
      dword_A3F0 = 0;
      dword_A410 = 0;
      if ( dword_A434 )
      {
        LODWORD(v42) = 8;
        HIDWORD(v42) = dword_A434;
        v43 = 12;
        rpmsg_send(*(_QWORD *)(qword_A350 + 968), &v42, 12);
      }
      if ( dword_A3DC )
      {
        LODWORD(v42) = 6;
        HIDWORD(v42) = dword_A3DC;
        v43 = 12;
        rpmsg_send(*(_QWORD *)(qword_A350 + 968), &v42, 12);
      }
      if ( qword_A350 && gcdsprm[0] )
      {
        v18 = *(_QWORD *)(qword_A350 + 968);
        LODWORD(v44) = 3;
        HIDWORD(v44) = dword_A3A0;
        LODWORD(v45) = 12;
        rpmsg_send(v18, &v44, 12);
      }
      if ( dword_A3E0 )
      {
        LODWORD(v42) = 11;
        HIDWORD(v42) = dword_A3E0;
        v43 = 12;
        rpmsg_send(*(_QWORD *)(qword_A350 + 968), &v42, 12);
      }
    }
    v19 = v5;
    v20 = v2;
    v21 = dword_A470;
    if ( dword_A470 )
    {
      v22 = v4;
      LODWORD(v45) = 0;
      v44 = 0;
      mutex_lock(&unk_A440);
      if ( qword_A350 )
      {
        if ( gcdsprm[0] )
        {
          v23 = *(_QWORD *)(qword_A350 + 968);
          LODWORD(v44) = 10;
          HIWORD(v44) = v21;
          LODWORD(v45) = 12;
          WORD2(v44) = dword_A474;
          if ( !(unsigned int)rpmsg_send(v23, &v44, 12) )
            dword_A470 = v21;
        }
      }
      v24 = v3;
    }
    else
    {
      v22 = v4;
      v24 = v3;
      v32 = dword_A474;
      if ( !dword_A474 )
      {
LABEL_54:
        if ( qword_A350 && gcdsprm[0] >= 3u )
        {
          v37 = dword_99AC;
          memset(v46, 0, 0x104u);
          v38 = *(_QWORD *)(qword_A350 + 968);
          LODWORD(v45) = 16;
          HIDWORD(v45) = dword_99AC;
          v44 = 0x200000114LL;
          if ( (unsigned int)rpmsg_send(v38, &v44, 276) )
          {
            v39 = &unk_BEE4;
          }
          else
          {
            v39 = &unk_B368;
            dword_99AC = v37;
          }
          printk(v39);
        }
        v3 = v24;
        v4 = v22;
        v2 = v20;
        v5 = v19;
        goto LABEL_82;
      }
      LODWORD(v45) = 0;
      v44 = 0;
      mutex_lock(&unk_A440);
      if ( qword_A350 )
      {
        if ( gcdsprm[0] )
        {
          v33 = *(_QWORD *)(qword_A350 + 968);
          LODWORD(v44) = 10;
          WORD2(v44) = v32;
          LODWORD(v45) = 12;
          HIWORD(v44) = dword_A470;
          if ( !(unsigned int)rpmsg_send(v33, &v44, 12) )
            dword_A474 = v32;
        }
      }
    }
    mutex_unlock(&unk_A440);
    goto LABEL_54;
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return 0;
}
