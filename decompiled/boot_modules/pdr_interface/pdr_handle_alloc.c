__int64 __fastcall pdr_handle_alloc(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x19
  __int64 v6; // x0
  __int64 v7; // x0
  int v8; // w0
  int v9; // w0
  __int64 v10; // x20

  if ( !a1 )
    return -22;
  v4 = _kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 936);
  v5 = (_QWORD *)v4;
  if ( !v4 )
    return -12;
  *(_QWORD *)(v4 + 920) = a1;
  *(_QWORD *)(v4 + 928) = a2;
  _mutex_init(v4 + 704, "&pdr->status_lock", &pdr_handle_alloc___key);
  _mutex_init(v5 + 82, "&pdr->list_lock", &pdr_handle_alloc___key_8);
  _mutex_init(v5 + 94, "&pdr->lock", &pdr_handle_alloc___key_10);
  v5[78] = v5 + 78;
  v5[79] = v5 + 78;
  v5[80] = v5 + 80;
  v5[81] = v5 + 80;
  v5[101] = 0xFFFFFFFE00000LL;
  v5[102] = v5 + 102;
  v5[103] = v5 + 102;
  v5[104] = pdr_locator_work;
  v5[105] = 0xFFFFFFFE00000LL;
  v5[106] = v5 + 106;
  v5[107] = v5 + 106;
  v5[109] = 0xFFFFFFFE00000LL;
  v5[108] = pdr_notifier_work;
  v5[110] = v5 + 110;
  v5[111] = v5 + 110;
  v5[112] = pdr_indack_work;
  v6 = alloc_workqueue("%s", (const char *)0x6000A);
  v5[113] = v6;
  if ( !v6 )
  {
    v10 = -12;
    if ( (unsigned __int64)v5 > 0xFFFFFFFFFFFFF000LL )
      return v10;
    goto LABEL_17;
  }
  v7 = alloc_workqueue("pdr_indack_wq", 131090, 1);
  v5[114] = v7;
  if ( !v7 )
  {
    v10 = -12;
    goto LABEL_16;
  }
  v8 = qmi_handle_init(v5, 2389, pdr_locator_ops, 0);
  if ( v8 < 0 )
  {
    LODWORD(v10) = v8;
    goto LABEL_15;
  }
  v9 = qmi_add_lookup(v5, 64, 1, 1);
  if ( v9 < 0 || (v9 = qmi_handle_init(v5 + 38, 79, pdr_notifier_ops, &qmi_indication_handler), v9 < 0) )
  {
    LODWORD(v10) = v9;
    qmi_handle_release(v5);
LABEL_15:
    destroy_workqueue(v5[114]);
    v10 = (int)v10;
LABEL_16:
    destroy_workqueue(v5[113]);
    if ( (unsigned __int64)v5 > 0xFFFFFFFFFFFFF000LL )
      return v10;
LABEL_17:
    kfree(v5);
    return v10;
  }
  return (__int64)v5;
}
