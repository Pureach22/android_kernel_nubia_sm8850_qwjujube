__int64 __fastcall uaudio_get_iova(__int64 *a1, __int64 *a2, _QWORD *a3, unsigned __int64 a4)
{
  __int64 v5; // x5
  _QWORD *v8; // x28
  __int64 v11; // x0
  unsigned __int64 v12; // x9
  __int64 i; // x25
  __int64 *v14; // x1
  _QWORD *v15; // x24
  unsigned __int64 v16; // x19
  unsigned __int64 v17; // x4

  if ( (a4 & 0xFFF) != 0 )
  {
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: size %zu is not page size multiple\n",
      (const char *)&unk_B13E,
      "uaudio_get_iova",
      a4);
    printk("%s%s: size %zu is not page size multiple\n", &unk_B45D);
    goto LABEL_5;
  }
  v5 = *a2;
  if ( *a2 < a4 )
  {
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: size %zu > curr size %zu\n",
      (const char *)&unk_B13E,
      "uaudio_get_iova",
      a4,
      v5);
    printk("%s%s: size %zu > curr size %zu\n", &unk_B45D);
LABEL_5:
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: unable to find %zu size iova\n",
      (const char *)&unk_B13E,
      "uaudio_get_iova",
      a4);
    printk("%s%s: unable to find %zu size iova\n", &unk_B45D);
    return 0;
  }
  if ( !v5 )
  {
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: iova mapping is full\n",
      (const char *)&unk_B13E,
      "uaudio_get_iova");
    printk("%s%s: iova mapping is full\n", &unk_B45D);
    goto LABEL_5;
  }
  v8 = (_QWORD *)*a3;
  if ( (_QWORD *)*a3 == a3 )
  {
LABEL_10:
    v11 = _kmalloc_cache_noprof(iommu_domain_free, 3520, 40);
    if ( v11 )
    {
      v12 = *a1 + a4;
      i = *a1;
      *(_QWORD *)(v11 + 16) = *a1;
      *(_QWORD *)(v11 + 24) = a4;
      *a1 = v12;
      *a2 -= a4;
      v14 = (__int64 *)a3[1];
      *(_BYTE *)(v11 + 32) = 1;
      if ( (_QWORD *)v11 == a3 || v14 == (__int64 *)v11 || (_QWORD *)*v14 != a3 )
      {
        _list_add_valid_or_report();
      }
      else
      {
        a3[1] = v11;
        *(_QWORD *)v11 = a3;
        *(_QWORD *)(v11 + 8) = v14;
        *v14 = v11;
      }
      goto LABEL_28;
    }
    goto LABEL_5;
  }
  v15 = nullptr;
  v16 = a4;
  while ( 1 )
  {
    if ( (v8[4] & 1) == 0 )
    {
      v17 = v8[3];
      if ( v17 == a4 )
      {
        i = v8[2];
        *((_BYTE *)v8 + 32) = 1;
        *a2 -= a4;
        ipc_log_string(
          *(_QWORD *)(uaudio_svc + 24),
          "%s%s: exact size: %zu found\n",
          (const char *)&unk_B13E,
          "uaudio_get_iova",
          a4);
        printk("%s%s: exact size: %zu found\n", &unk_B8A7);
        goto LABEL_28;
      }
      if ( v16 >= v17 )
        break;
    }
    v15 = nullptr;
    v16 = a4;
LABEL_17:
    v8 = (_QWORD *)*v8;
    if ( v8 == a3 )
      goto LABEL_10;
  }
  if ( !v15 )
    v15 = v8;
  ipc_log_string(*(_QWORD *)(uaudio_svc + 24), "%s%s: partial size: %zu found\n", &unk_B13E, "uaudio_get_iova");
  printk("%s%s: partial size: %zu found\n", &unk_B8A7);
  v16 -= v8[3];
  if ( v16 )
    goto LABEL_17;
  for ( i = v15[2]; v15 != v8; v15 = (_QWORD *)*v15 )
    *((_BYTE *)v15 + 32) = 1;
  *((_BYTE *)v8 + 32) = 1;
  *a2 -= a4;
LABEL_28:
  ipc_log_string(
    *(_QWORD *)(uaudio_svc + 24),
    "%s%s: va:0x%08lx curr_iova:0x%08lx curr_iova_size:%zu\n",
    (const char *)&unk_B13E,
    "uaudio_get_iova",
    i,
    *a1,
    *a2);
  printk("%s%s: va:0x%08lx curr_iova:0x%08lx curr_iova_size:%zu\n", &unk_B8A7);
  return i;
}
