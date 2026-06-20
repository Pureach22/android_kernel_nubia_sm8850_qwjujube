__int64 __fastcall for_qptm_each_child(__int64 result, __int64 a2, _QWORD *a3, __int64 a4)
{
  __int64 v6; // x27
  __int64 v7; // x23
  unsigned __int64 v8; // x28
  __int64 v9; // x21
  size_t v10; // x0
  unsigned __int64 v11; // x2
  void *v12; // x2
  void *v13; // x0
  unsigned int v14; // w0
  unsigned int v15; // w26
  __int64 v16; // x0
  __int64 v17; // d30

  if ( *(int *)qh < 1 )
    return result;
  v6 = result;
  v7 = 0;
  v8 = 0;
  v9 = result;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(_QWORD *)(v9 + 40) != a2 )
      goto LABEL_5;
    if ( *(_DWORD *)v9 )
      goto LABEL_18;
    v8 = _kmalloc_cache_noprof(MEMORY[0x96B8], 3520, 1264);
    if ( v8 )
      break;
    v8 = -12;
LABEL_4:
    result = printk(&unk_82F4, "for_qptm_each_child", v9 + 4, a4);
LABEL_5:
    ++v7;
    v9 += 64;
    if ( v7 >= *(int *)qh )
      return result;
  }
  v10 = strnlen((const char *)(v9 + 4), 0x20u);
  if ( v10 < 0x21 )
  {
    if ( v10 == 32 )
      v11 = 32;
    else
      v11 = v10 + 1;
    if ( v11 >= 0x21 )
      goto LABEL_25;
    sized_strscpy(v8 + 1120, v9 + 4);
    *(_QWORD *)(v8 + 1152) = *(_QWORD *)(v9 + 56);
    _mutex_init(v8 + 1200, "&qptm->lock", &qptm_setup_virtual___key);
    *(_QWORD *)(v8 + 1168) = v8 + 1168;
    *(_QWORD *)(v8 + 1176) = v8 + 1168;
    mutex_lock(&qptm_list_lock);
    v12 = qptm_list;
    v13 = (void *)(v8 + 1184);
    if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)qptm_list) != &qptm_list || qptm_list == v13 )
    {
      _list_add_valid_or_report(v13, &qptm_list);
    }
    else
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)qptm_list) = v13;
      *(_QWORD *)(v8 + 1184) = v12;
      *(_QWORD *)(v8 + 1192) = &qptm_list;
      qptm_list = (_UNKNOWN *)(v8 + 1184);
    }
    mutex_unlock(&qptm_list_lock);
    *(_QWORD *)(v8 + 1096) = v8 + 1096;
    *(_QWORD *)(v8 + 1104) = v8 + 1096;
    *(_QWORD *)(v8 + 1080) = v8 + 1080;
    *(_QWORD *)(v8 + 1088) = v8 + 1080;
    *(_QWORD *)(v8 + 1112) = 0;
    *(_QWORD *)(v9 + 48) = v8;
    v14 = qptm_register(v9 + 4, (_QWORD *)v8, a3);
    if ( v14 )
    {
      v15 = v14;
      printk(&unk_82C1, "qptm_setup_virtual", v9 + 4, v14);
      kfree(v8);
      v8 = (int)v15;
      if ( (unsigned __int64)(int)v15 < 0xFFFFFFFFFFFFF001LL )
      {
LABEL_19:
        result = for_qptm_each_child(v6, v9, v8);
        goto LABEL_5;
      }
      goto LABEL_4;
    }
LABEL_18:
    if ( v8 < 0xFFFFFFFFFFFFF001LL )
      goto LABEL_19;
    goto LABEL_4;
  }
  _fortify_panic(2, 32, v10 + 1);
LABEL_25:
  v16 = _fortify_panic(7, 32, v11);
  *(_QWORD *)(v7 + 17960) = v17;
  return qptm_pct_set_enable(v16);
}
