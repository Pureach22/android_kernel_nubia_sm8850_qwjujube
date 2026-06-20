__int64 init_module()
{
  __int64 result; // x0
  __int64 v1; // x19
  int qptm_count; // w0
  __int64 v3; // x3
  __int64 v4; // x9
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x8
  void *v9; // x2
  __int64 v10; // x9
  _UNKNOWN **v11; // x0
  _QWORD *v12; // x8
  unsigned int v13; // w0
  __int64 v14; // x3
  unsigned int v15; // w19
  __int64 v16; // x9
  _QWORD *v17; // x8
  __int64 *v18; // x0
  __int64 v19; // x10
  __int64 v20; // x19
  unsigned __int64 v21; // x0
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x8

  result = of_find_node_by_name(0, "power-zones");
  if ( result )
  {
    v1 = result;
    qh = _kmalloc_cache_noprof(powercap_unregister_control_type, 3520, 32);
    if ( !qh )
      return 4294967284LL;
    qptm_count = get_qptm_count(v1);
    if ( qptm_count <= 0 )
    {
      v15 = -19;
      printk(&unk_803E, "qptf_init", 4294967277LL, v3);
    }
    else
    {
      *(_DWORD *)qh = qptm_count;
      v4 = *(unsigned int *)qh;
      if ( (v4 & 0x80000000) != 0 )
      {
        *(_QWORD *)(qh + 16) = 0;
        v15 = -12;
      }
      else
      {
        v5 = _kmalloc_noprof(v4 << 6, 3520);
        *(_QWORD *)(qh + 16) = v5;
        if ( v5 )
        {
          v6 = _kmalloc_cache_noprof(MEMORY[0x96B8], 3520, 1264);
          v7 = qh;
          *(_QWORD *)(qh + 24) = v6;
          if ( v6 )
          {
            *(_QWORD *)(v6 + 1152) = 0;
            strcpy((char *)(v6 + 1120), "root");
            _mutex_init(v6 + 1200, "&qh->root->lock", &qptm_create_root_node___key);
            v8 = *(_QWORD *)(qh + 24);
            *(_QWORD *)(v8 + 1168) = v8 + 1168;
            *(_QWORD *)(v8 + 1176) = v8 + 1168;
            mutex_lock(&qptm_list_lock);
            v9 = qptm_list;
            v10 = *(_QWORD *)(qh + 24);
            v11 = (_UNKNOWN **)(v10 + 1184);
            if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)qptm_list) != &qptm_list
              || v11 == &qptm_list
              || qptm_list == (_UNKNOWN *)v11 )
            {
              _list_add_valid_or_report(v11, &qptm_list);
            }
            else
            {
              *(_QWORD *)((char *)&unk_8 + (_QWORD)qptm_list) = v11;
              *(_QWORD *)(v10 + 1184) = v9;
              *(_QWORD *)(v10 + 1192) = &qptm_list;
              qptm_list = (_UNKNOWN *)(v10 + 1184);
            }
            mutex_unlock(&qptm_list_lock);
            v12 = *(_QWORD **)(qh + 24);
            if ( v12 )
            {
              v12[137] = v12 + 137;
              v12[138] = v12 + 137;
              v12[135] = v12 + 135;
              v12[136] = v12 + 135;
              v12[139] = 0;
            }
            v13 = of_each_qptm_child(v1, 0);
            if ( v13 )
            {
              v15 = v13;
              printk(&unk_805D, "qptf_init", v13, v14);
            }
            else if ( *(_QWORD *)(qh + 8) )
            {
              v15 = -16;
            }
            else
            {
              v20 = *(_QWORD *)(qh + 16);
              v21 = powercap_register_control_type(0, "qpt", pc_ops);
              v24 = qh;
              *(_QWORD *)(qh + 8) = v21;
              if ( v21 > 0xFFFFFFFFFFFFF000LL )
              {
                printk(&unk_8281, "qptm_create_hierarchy", v22, v23);
                v15 = *(_DWORD *)(qh + 8);
                *(_QWORD *)(qh + 8) = 0;
                if ( (v15 & 0x80000000) == 0 )
                  return 0;
              }
              else
              {
                if ( v20 )
                {
                  for_qptm_each_child(v20, 0, *(_QWORD *)(v24 + 24));
                  return 0;
                }
                powercap_unregister_control_type();
                v15 = -14;
                *(_QWORD *)(qh + 8) = 0;
              }
            }
            mutex_lock(&qptm_list_lock);
            v16 = *(_QWORD *)(qh + 24);
            v17 = *(_QWORD **)(v16 + 1192);
            v18 = (__int64 *)(v16 + 1184);
            if ( *v17 == v16 + 1184 && (v19 = *v18, *(__int64 **)(*v18 + 8) == v18) )
            {
              *(_QWORD *)(v19 + 8) = v17;
              *v17 = v19;
            }
            else
            {
              _list_del_entry_valid_or_report(v18);
            }
            *(_QWORD *)(v16 + 1184) = 0xDEAD000000000100LL;
            *(_QWORD *)(v16 + 1192) = 0xDEAD000000000122LL;
            mutex_unlock(&qptm_list_lock);
            kfree(*(_QWORD *)(qh + 24));
            v7 = qh;
          }
          else
          {
            v15 = -12;
          }
          kfree(*(_QWORD *)(v7 + 16));
        }
        else
        {
          v15 = -12;
        }
      }
    }
    kfree(qh);
    return v15;
  }
  return result;
}
