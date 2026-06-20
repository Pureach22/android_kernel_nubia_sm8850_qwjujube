__int64 __fastcall reboot_mode_register(_QWORD *a1)
{
  _QWORD **v1; // x19
  __int64 v3; // x21
  const char **v4; // x25
  __int64 v5; // x0
  __int64 v6; // x24
  _BYTE *v7; // x0
  _QWORD *v8; // x0
  _QWORD *v9; // x1
  __int64 result; // x0
  _QWORD *v11; // x20
  unsigned int v12; // w21

  v1 = (_QWORD **)(a1 + 1);
  v3 = *(_QWORD *)(*a1 + 744LL);
  a1[1] = a1 + 1;
  a1[2] = a1 + 1;
  v4 = *(const char ***)(v3 + 96);
  if ( !v4 )
  {
LABEL_15:
    a1[4] = reboot_mode_notify;
    register_reboot_notifier(a1 + 4);
    return 0;
  }
  while ( 1 )
  {
    if ( strncmp(*v4, "mode-", 5u) )
      goto LABEL_4;
    v5 = devm_kmalloc(*a1, 32, 3520);
    if ( !v5 )
      goto LABEL_17;
    v6 = v5;
    if ( (of_property_read_variable_u32_array(v3, *v4, v5 + 8, 1, 0) & 0x80000000) == 0 )
      break;
    dev_err(*a1, "reboot mode %s without magic number\n", *(const char **)v6);
    devm_kfree(*a1, v6);
LABEL_4:
    v4 = (const char **)v4[3];
    if ( !v4 )
      goto LABEL_15;
  }
  v7 = (_BYTE *)kstrdup_const(*v4 + 5, 3264);
  *(_QWORD *)v6 = v7;
  if ( !v7 )
  {
LABEL_17:
    result = 4294967284LL;
    goto LABEL_18;
  }
  if ( *v7 )
  {
    v8 = (_QWORD *)(v6 + 16);
    v9 = (_QWORD *)a1[2];
    if ( (_QWORD **)(v6 + 16) == v1 || v9 == v8 || (_QWORD **)*v9 != v1 )
    {
      _list_add_valid_or_report();
    }
    else
    {
      a1[2] = v8;
      *(_QWORD *)(v6 + 16) = v1;
      *(_QWORD *)(v6 + 24) = v9;
      *v9 = v8;
    }
    goto LABEL_4;
  }
  ((void (*)(void))kfree_const)();
  dev_err(*a1, "invalid mode name(%s): too short!\n", *v4);
  result = 4294967274LL;
LABEL_18:
  v11 = *v1;
  if ( *v1 != v1 )
  {
    v12 = result;
    do
    {
      kfree_const(*(v11 - 2));
      v11 = (_QWORD *)*v11;
    }
    while ( v11 != v1 );
    return v12;
  }
  return result;
}
