__int64 __fastcall qcedev_parse_context_bank(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 *v6; // x19
  __int64 v7; // x23
  __int64 v8; // x22
  _QWORD *v9; // x0
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x2
  _QWORD *v13; // x20
  _QWORD *v14; // x1
  __int64 property; // x8
  _DWORD *v16; // x0
  __int64 v17; // x3
  __int64 v18; // x8
  __int64 result; // x0
  __int64 v20; // x2
  _QWORD *v21; // x8
  __int64 v22; // x9

  if ( !a1 )
  {
    printk(&unk_11F28, "qcedev_parse_context_bank", a3, a4);
    return 4294967274LL;
  }
  v4 = a1[14];
  v6 = a1 + 2;
  if ( v4 )
  {
    v7 = *(_QWORD *)(v4 + 152);
    v8 = a1[95];
    v9 = (_QWORD *)devm_kmalloc(a1 + 2, 56, 3520);
    if ( v9 )
    {
      *v9 = v9;
      v12 = v7 + 320;
      v13 = v9;
      v9[1] = v9;
      v14 = *(_QWORD **)(v7 + 328);
      if ( v9 == (_QWORD *)(v7 + 320) || v14 == v9 || *v14 != v12 )
      {
        _list_add_valid_or_report(v9, v14, v12);
      }
      else
      {
        *(_QWORD *)(v7 + 328) = v9;
        *v9 = v12;
        v9[1] = v14;
        *v14 = v9;
      }
      of_property_read_string(v8, "label", v13 + 2);
      property = of_find_property(v8, "qcom,secure-context-bank", 0);
      v16 = (_DWORD *)a1[86];
      v13[5] = v6;
      *((_BYTE *)v13 + 36) = property != 0;
      if ( v16 || (v16 = (_DWORD *)devm_kmalloc(v6, 16, 3520), (a1[86] = v16) != 0) )
      {
        *v16 = -1;
        v18 = a1[86];
        if ( v18 )
        {
          result = 0;
          *(_QWORD *)(v18 + 8) = -1;
        }
        else
        {
          __break(0x800u);
          return 0;
        }
        return result;
      }
      printk(&unk_11A03, "qcedev_parse_context_bank", 4294967284LL, v17);
      v21 = (_QWORD *)v13[1];
      if ( (_QWORD *)*v21 == v13 && (v22 = *v13, *(_QWORD **)(*v13 + 8LL) == v13) )
      {
        *(_QWORD *)(v22 + 8) = v21;
        *v21 = v22;
      }
      else
      {
        _list_del_entry_valid_or_report(v13);
      }
      *v13 = 0xDEAD000000000100LL;
      v13[1] = 0xDEAD000000000122LL;
      devm_kfree(v6, v13);
    }
    else
    {
      printk(&unk_12319, "qcedev_parse_context_bank", v10, v11);
    }
    return 4294967284LL;
  }
  v20 = a1[16];
  if ( !v20 )
    v20 = *v6;
  printk(&unk_11B24, "qcedev_parse_context_bank", v20, a4);
  return 4294967274LL;
}
