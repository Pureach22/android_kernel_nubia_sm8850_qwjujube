__int64 __fastcall get_hfi_buffer_queue(_QWORD *a1, _QWORD *a2, int a3)
{
  __int64 v3; // x30
  __int64 *buf; // x0
  __int64 v7; // x8
  _QWORD *v8; // x2
  __int64 v9; // x10
  _QWORD *v10; // x9
  _QWORD *v11; // x1
  unsigned int v12; // w8
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  if ( a2 && a3 == 24 )
  {
    buf = (__int64 *)virtqueue_get_buf(a1[135], &v14);
    if ( buf )
    {
      v7 = buf[2];
      v8 = a1 + 125;
      v9 = *buf;
      a2[1] = buf[1];
      a2[2] = v7;
      v10 = buf + 3;
      *a2 = v9;
      buf[1] = 0;
      buf[2] = 0;
      *buf = 0;
      v11 = (_QWORD *)a1[126];
      if ( buf + 3 == a1 + 125 || v11 == v10 || (_QWORD *)*v11 != v8 )
      {
        _list_add_valid_or_report(buf + 3, v11, v8);
        v12 = 0;
      }
      else
      {
        v12 = 0;
        a1[126] = v10;
        buf[3] = (__int64)v8;
        buf[4] = (__int64)v11;
        *v11 = v10;
      }
    }
    else
    {
      v12 = -105;
    }
  }
  else
  {
    printk(&unk_1D0A2, "get_hfi_buffer_queue", 391, v3, a2);
    v12 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
