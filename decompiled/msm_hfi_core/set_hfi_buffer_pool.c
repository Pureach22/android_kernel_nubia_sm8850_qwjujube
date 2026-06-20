__int64 __fastcall set_hfi_buffer_pool(_QWORD *a1, __int64 *a2, int a3)
{
  __int64 v3; // x30
  __int64 v4; // x8
  _QWORD *v5; // x10
  _QWORD *v6; // x9
  __int64 v7; // x11
  _QWORD *v9; // x10
  _QWORD *v10; // x8
  __int64 v11; // x11
  __int64 v12; // x11
  __int64 v13; // x13
  _QWORD *v14; // x1
  __int64 *v15; // x4
  _QWORD *v16; // x11
  __int64 *v17; // x12

  if ( !a2 || a3 != 24 )
  {
    if ( !a2 )
    {
      v15 = nullptr;
      goto LABEL_22;
    }
LABEL_21:
    v15 = a2;
LABEL_22:
    printk(&unk_1AD82, "set_hfi_buffer_pool", 298, v3, v15);
    return 4294967274LL;
  }
  if ( !*a2 )
    goto LABEL_21;
  v4 = a2[1];
  if ( !v4 || !*((_DWORD *)a2 + 4) )
    goto LABEL_21;
  v5 = (_QWORD *)a1[123];
  v6 = a1 + 123;
  while ( v5 != v6 )
  {
    if ( *(v5 - 3) != *a2 )
    {
      v7 = *(v5 - 2);
      v5 = (_QWORD *)*v5;
      if ( v7 != v4 )
        continue;
    }
    return 4294967182LL;
  }
  v9 = (_QWORD *)a1[125];
  if ( v9 != a1 + 125 )
  {
    v10 = (_QWORD *)v9[1];
    if ( (_QWORD *)*v10 == v9 && (v11 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
    {
      *(_QWORD *)(v11 + 8) = v10;
      *v10 = v11;
    }
    else
    {
      _list_del_entry_valid_or_report(a1[125]);
      a1 = v16;
      a2 = v17;
    }
    *v9 = v9;
    v9[1] = v9;
  }
  if ( v9 == &_ksymtab_hfi_core_cmds_rx_buf_get )
    return 4294967284LL;
  v12 = a2[2];
  v13 = *a2;
  *(v9 - 2) = a2[1];
  *(v9 - 1) = v12;
  *(v9 - 3) = v13;
  v14 = (_QWORD *)a1[124];
  if ( v9 == v6 || v14 == v9 || (_QWORD *)*v14 != v6 )
  {
    _list_add_valid_or_report(v9, v14, v6);
    return 0;
  }
  else
  {
    a1[124] = v9;
    *v9 = v6;
    v9[1] = v14;
    *v14 = v9;
    return 0;
  }
}
