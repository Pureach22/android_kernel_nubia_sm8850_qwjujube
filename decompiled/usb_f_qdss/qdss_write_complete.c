__int64 __fastcall qdss_write_complete(const char **a1, __int64 a2)
{
  const char *v2; // x22
  _QWORD *v3; // x23
  __int64 v5; // x19
  __int64 v6; // x0
  _QWORD *v7; // x8
  const char *v8; // x9
  __int64 v9; // x21
  const char *v10; // x10
  __int64 v11; // x11
  const char **v12; // x1
  __int64 result; // x0
  _DWORD *v14; // x8
  __int64 v15; // x0

  v2 = *a1;
  v3 = *(_QWORD **)(a2 + 56);
  v5 = v3[1];
  ipc_log_string(
    qdss_ipc_log,
    "%s: channel:%s ep:%s req:%pK req->status:%d req->length:%d\n",
    "qdss_write_complete",
    *((const char **)*a1 + 37),
    a1[1],
    (const void *)a2,
    *(_DWORD *)(a2 + 84),
    *(_DWORD *)(a2 + 8));
  v6 = raw_spin_lock_irqsave(v2 + 456);
  v7 = (_QWORD *)v3[3];
  v8 = (const char *)(v3 + 2);
  v9 = v6;
  v10 = v2 + 344;
  if ( (_QWORD *)*v7 == v3 + 2 && (v11 = *(_QWORD *)v8, *(const char **)(*(_QWORD *)v8 + 8LL) == v8) )
  {
    *(_QWORD *)(v11 + 8) = v7;
    *v7 = v11;
  }
  else
  {
    _list_del_entry_valid_or_report(v3 + 2);
  }
  v12 = *((const char ***)v2 + 44);
  if ( v8 == v10 || v12 == (const char **)v8 || *v12 != v10 )
  {
    _list_add_valid_or_report(v8, v12, v10);
    if ( (v2[520] & 1) != 0 )
      goto LABEL_11;
  }
  else
  {
    *((_QWORD *)v2 + 44) = v8;
    v3[2] = v10;
    v3[3] = v12;
    *v12 = v8;
    if ( (v2[520] & 1) != 0 )
      goto LABEL_11;
  }
  if ( *((const char **)v2 + 47) == v2 + 376 && *((const char **)v2 + 45) == v2 + 360 )
    complete(v2 + 528);
LABEL_11:
  if ( *(_DWORD *)(a2 + 8) )
  {
    *(_DWORD *)(v5 + 12) = *(_DWORD *)(a2 + 88);
    *(_DWORD *)(v5 + 16) = *(_DWORD *)(a2 + 84);
  }
  result = raw_spin_unlock_irqrestore(v2 + 456, v9);
  v14 = *((_DWORD **)v2 + 40);
  if ( v14 )
  {
    v15 = *((_QWORD *)v2 + 41);
    if ( *(v14 - 1) != 840361381 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v14)(v15, 3, v5, 0);
  }
  return result;
}
