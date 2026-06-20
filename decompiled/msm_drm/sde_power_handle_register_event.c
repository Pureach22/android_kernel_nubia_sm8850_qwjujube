__int64 __fastcall sde_power_handle_register_event(__int64 a1, int a2, __int64 a3, __int64 a4, const char *a5)
{
  __int64 v10; // x20
  size_t v11; // x0
  unsigned __int64 v12; // x2
  _QWORD *v13; // x2
  _QWORD *v14; // x1
  _QWORD *v15; // x0
  void *v16; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v18; // x26
  __int64 (__fastcall *v19)(_QWORD, _QWORD, _QWORD); // x0

  if ( !a1 )
  {
    v16 = &unk_246EF7;
LABEL_17:
    printk(v16, "sde_power_handle_register_event");
    return -22;
  }
  if ( !a2 || !a3 )
  {
    v16 = &unk_2135AF;
    goto LABEL_17;
  }
  v10 = _kmalloc_cache_noprof(_init_waitqueue_head, 3520, 176);
  if ( !v10 )
    return -12;
  while ( 1 )
  {
    *(_DWORD *)(v10 + 144) = a2;
    *(_QWORD *)(v10 + 128) = a3;
    *(_QWORD *)(v10 + 136) = a4;
    v11 = strnlen(a5, 0x80u);
    if ( v11 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_20:
    _fortify_panic(7, 128, v12);
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = *(_QWORD *)(StatusReg + 80);
    v19 = _init_waitqueue_head;
    *(_QWORD *)(StatusReg + 80) = &sde_power_handle_register_event__alloc_tag;
    v10 = _kmalloc_cache_noprof(v19, 3520, 176);
    *(_QWORD *)(StatusReg + 80) = v18;
    if ( !v10 )
      return -12;
  }
  if ( v11 == 128 )
    v12 = 128;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x81 )
    goto LABEL_20;
  sized_strscpy(v10, a5);
  *(_BYTE *)(v10 + 168) = 1;
  mutex_lock(a1 + 48);
  v13 = *(_QWORD **)(a1 + 344);
  v14 = (_QWORD *)(a1 + 344);
  v15 = (_QWORD *)(v10 + 152);
  if ( v13[1] != a1 + 344 || v15 == v14 || v13 == v15 )
  {
    _list_add_valid_or_report(v15, v14);
  }
  else
  {
    v13[1] = v15;
    *(_QWORD *)(v10 + 152) = v13;
    *(_QWORD *)(v10 + 160) = v14;
    *v14 = v15;
  }
  mutex_unlock(a1 + 48);
  return v10;
}
