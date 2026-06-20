__int64 __fastcall get_hfi_buffer_pool(_QWORD *a1, _QWORD *a2, int a3)
{
  __int64 v3; // x30
  _QWORD *v4; // x9
  __int64 v5; // x8
  _QWORD *v6; // x10
  __int64 v7; // x12
  _QWORD *v8; // x8
  __int64 v9; // x11
  _QWORD *v10; // x2
  _QWORD *v11; // x1
  unsigned int v12; // w8
  _QWORD *v14; // x11

  if ( a2 && a3 == 24 )
  {
    v4 = (_QWORD *)a1[123];
    if ( v4 == a1 + 123 )
    {
      return (unsigned int)-105;
    }
    else
    {
      v5 = *(v4 - 1);
      v6 = v4 - 3;
      v7 = *(v4 - 3);
      a2[1] = *(v4 - 2);
      a2[2] = v5;
      *a2 = v7;
      v8 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v8 == v4 && (v9 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
      {
        *(_QWORD *)(v9 + 8) = v8;
        *v8 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
        a1 = v14;
      }
      *v4 = v4;
      v10 = a1 + 125;
      v4[1] = v4;
      *v6 = 0;
      v6[1] = 0;
      v6[2] = 0;
      v11 = (_QWORD *)a1[126];
      if ( v4 == a1 + 125 || v11 == v4 || (_QWORD *)*v11 != v10 )
      {
        _list_add_valid_or_report(v4, v11, v10);
        return 0;
      }
      else
      {
        v12 = 0;
        a1[126] = v4;
        *v4 = v10;
        v4[1] = v11;
        *v11 = v4;
      }
    }
  }
  else
  {
    printk(&unk_1D0A2, "get_hfi_buffer_pool", 320, v3, a2);
    return (unsigned int)-22;
  }
  return v12;
}
