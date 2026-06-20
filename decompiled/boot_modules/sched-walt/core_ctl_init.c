unsigned __int64 core_ctl_init()
{
  unsigned __int64 result; // x0
  __int64 v1; // x19
  __int64 v2; // x23
  unsigned int v3; // w10
  unsigned int v4; // w27
  __int64 cpu_device; // x0
  __int64 v6; // x26
  unsigned int v7; // w21
  char *v8; // x25
  __int64 v9; // x0
  unsigned int v10; // w0
  __int64 v11; // x8
  char v12; // w8
  char *v13; // x27
  char v14; // w9
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x28
  char *v18; // x21
  char v19; // w8
  char *v20; // x0
  char **v21; // x1
  bool v22; // zf
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 99;
  core_ctl_pending_lock = 0;
  nr_stats = ((__int64 (*)(void))sched_get_nr_running_avg)();
  result = kthread_create_on_node(try_core_ctl, 0, 0xFFFFFFFFLL, "core_ctl");
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v1 = result;
    wake_up_process(result);
    core_ctl_thread = v1;
    sched_setscheduler_nocheck(v1, 1, &v24);
    v2 = cluster_head;
    if ( (__int64 *)cluster_head == &cluster_head )
    {
LABEL_46:
      result = 0;
      initialized = 1;
      goto LABEL_47;
    }
    while ( 1 )
    {
      v3 = __clz(__rbit64(*(unsigned int *)(v2 + 16)));
      if ( *(_DWORD *)(v2 + 16) )
        v4 = v3;
      else
        v4 = 32;
      if ( num_clusters )
      {
        if ( dword_67F78 == v4 )
          goto LABEL_6;
        if ( num_clusters != 1 )
        {
          if ( dword_680A8 == v4 )
            goto LABEL_6;
          if ( num_clusters != 2 )
          {
            if ( dword_681D8 == v4 )
              goto LABEL_6;
            if ( num_clusters != 3 )
            {
              if ( dword_68308 == v4 )
                goto LABEL_6;
              if ( num_clusters != 4 )
                goto LABEL_48;
            }
          }
        }
      }
      cpu_device = get_cpu_device(v4);
      if ( !cpu_device )
        goto LABEL_20;
      v6 = cpu_device;
      printk(&unk_64179);
      v7 = num_clusters;
      if ( num_clusters == 4 )
      {
        printk(&unk_66AEC);
LABEL_20:
        printk(&unk_677AE);
        goto LABEL_6;
      }
      ++num_clusters;
      if ( v7 > 3 )
        goto LABEL_48;
      v8 = (char *)&cluster_state + 304 * v7;
      v9 = (unsigned int)*(_QWORD *)(v2 + 16);
      *((_QWORD *)v8 + 10) = *(_QWORD *)(v2 + 16);
      v10 = _sw_hweight64(v9);
      *((_DWORD *)v8 + 18) = v10;
      if ( v10 >= 7 )
      {
        printk(&unk_66B2B);
        goto LABEL_20;
      }
      v11 = 304LL * v7;
      *((_DWORD *)v8 + 36) = v4;
      if ( (v11 | 4uLL) > 0x4C0
        || (*((_DWORD *)v8 + 1) = 1, (v11 | 8uLL) > 0x4C0)
        || (*((_DWORD *)v8 + 2) = 0, (v11 | 0xCuLL) > 0x4C0) )
      {
LABEL_48:
        __break(1u);
      }
      v12 = 0;
      *((_DWORD *)v8 + 3) = v10;
      *((_DWORD *)v8 + 4) = 100;
      v13 = v8 + 120;
      *((_DWORD *)v8 + 22) = v10;
      *((_DWORD *)v8 + 23) = -1;
      v14 = nr_cpu_ids;
      *((_DWORD *)v8 + 35) = v10;
      v8[136] = 0;
      *((_DWORD *)v8 + 19) = 0;
      v15 = 0xFFFFFFFFFFFFFFFFLL >> -v14;
      *((_DWORD *)v8 + 62) = 0;
      *((_DWORD *)v8 + 27) = 0;
      *((_DWORD *)v8 + 74) = 0;
      *((_DWORD *)v8 + 68) = 0;
      *((_QWORD *)v8 + 32) = v15;
      *((_QWORD *)v8 + 33) = v15;
      *((_QWORD *)v8 + 35) = v15;
      *((_QWORD *)v8 + 36) = v15;
      *((_QWORD *)v8 + 15) = v8 + 120;
      *((_QWORD *)v8 + 16) = v8 + 120;
      do
      {
        v16 = (unsigned int)(-1LL << v12) & *(_DWORD *)(v2 + 16);
        if ( !(_DWORD)v16 )
          break;
        v17 = __clz(__rbit64(v16));
        printk(&unk_66EDB);
        v18 = (char *)&cpu_state + *((_QWORD *)&_per_cpu_offset + v17);
        *((_QWORD *)v18 + 2) = v8;
        *((_DWORD *)v18 + 2) = v17;
        v19 = get_cpu_device((unsigned int)v17) ? *(_BYTE *)(get_cpu_device((unsigned int)v17) + 844) : 0;
        v20 = v18 + 24;
        v18[40] = v19 & 1;
        v21 = *((char ***)v8 + 16);
        v22 = v18 + 24 == v13 || v21 == (char **)v20;
        if ( !v22 && *v21 == v13 )
        {
          *((_QWORD *)v8 + 16) = v20;
          *((_QWORD *)v18 + 3) = v13;
          *((_QWORD *)v18 + 4) = v21;
          *v21 = v20;
        }
        else
        {
          _list_add_valid_or_report(v20, v21, v8 + 120);
        }
        v12 = v17 + 1;
      }
      while ( v17 < 0x1F );
      *((_DWORD *)v8 + 17) = _sw_hweight64(
                               *((_DWORD *)v8 + 20)
                             & ~((unsigned int)_cpu_partial_halt_mask | (unsigned int)_cpu_halt_mask));
      *v8 = 1;
      kobject_init(v8 + 152, &ktype_core_ctl);
      if ( (unsigned int)kobject_add(v8 + 152, v6, "core_ctl") )
        goto LABEL_20;
LABEL_6:
      v2 = *(_QWORD *)v2;
      if ( (__int64 *)v2 == &cluster_head )
        goto LABEL_46;
    }
  }
  core_ctl_thread = result;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
