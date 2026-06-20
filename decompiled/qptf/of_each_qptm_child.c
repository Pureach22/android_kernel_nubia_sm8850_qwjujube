__int64 __fastcall of_each_qptm_child(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x2
  __int64 v6; // x3
  const char **v7; // x21
  __int64 v8; // x8
  __int64 v9; // x9
  const char *v10; // x23
  __int64 v11; // x25
  __int64 v12; // x26
  size_t v13; // x0
  unsigned __int64 v14; // x2
  __int64 property; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x1
  __int64 v19; // x0
  __int64 v20; // x1
  __int64 v21; // x2

  result = of_get_next_child(a1, 0);
  if ( result )
  {
    v7 = (const char **)result;
    while ( 1 )
    {
      v8 = qh;
      v9 = *(int *)(qh + 4);
      if ( (int)v9 >= *(_DWORD *)qh )
      {
        printk(&unk_825D, "of_each_qptm_child", v5, v6);
        return 4294967274LL;
      }
      *(_QWORD *)(*(_QWORD *)(qh + 16) + (v9 << 6) + 56) = v7;
      v10 = *v7;
      v11 = *(_QWORD *)(v8 + 16);
      v12 = *(int *)(v8 + 4);
      v13 = strnlen(*v7, 0x20u);
      if ( v13 == -1 )
        break;
      if ( v13 == 32 )
        v14 = 32;
      else
        v14 = v13 + 1;
      if ( v14 >= 0x21 )
        goto LABEL_14;
      sized_strscpy(v11 + (v12 << 6) + 4, v10);
      property = of_find_property(v7, "power-channels", 0);
      v16 = qh;
      *(_DWORD *)(*(_QWORD *)(qh + 16) + ((__int64)*(int *)(qh + 4) << 6)) = property != 0;
      *(_QWORD *)(*(_QWORD *)(v16 + 16) + ((__int64)*(int *)(v16 + 4) << 6) + 40) = a2;
      v17 = *(int *)(v16 + 4);
      v18 = *(_QWORD *)(v16 + 16) + (v17 << 6);
      *(_DWORD *)(v16 + 4) = v17 + 1;
      result = of_each_qptm_child(v7, v18);
      if ( !(_DWORD)result )
      {
        result = of_get_next_child(a1, v7);
        v7 = (const char **)result;
        if ( result )
          continue;
      }
      return result;
    }
    _fortify_panic(2, -1, 0);
LABEL_14:
    v19 = _fortify_panic(7, 32, v14);
    return for_qptm_each_child(v19, v20, v21);
  }
  return result;
}
