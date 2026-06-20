__int64 __fastcall qmi_encode_message(char a1, __int16 a2, _QWORD *a3, __int16 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x24
  unsigned int v12; // w0
  unsigned __int64 v13; // x23
  __int64 result; // x0
  __int64 v15; // x26
  int v16; // w0
  unsigned __int64 StatusReg; // x26
  __int64 v18; // x27

  v6 = a6;
  if ( !a6 && (v12 = qmi_calc_min_msg_len(a5, 1)) != 0 )
  {
    printk(&unk_83AF, "qmi_encode_message", v12);
    return -22;
  }
  else
  {
    v13 = *a3 + 7LL;
    for ( result = _kmalloc_noprof(v13, 3520); result; *(_QWORD *)(StatusReg + 80) = v18 )
    {
      if ( v6 )
      {
        v15 = result;
        v16 = qmi_encode(a5, result + 7, v6, *(unsigned int *)a3, 1);
        v6 = v16;
        if ( v16 < 0 )
        {
          kfree(v15);
          return v6;
        }
        result = v15;
      }
      if ( v13 )
      {
        *(_BYTE *)result = a1;
        if ( v13 >= 3 )
        {
          *(_WORD *)(result + 1) = a4;
          if ( v13 - 3 >= 2 )
          {
            *(_WORD *)(result + 3) = a2;
            if ( v13 >= 7 )
            {
              *(_WORD *)(result + 5) = v6;
              *a3 = v6 + 7;
              return result;
            }
          }
        }
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v18 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v13 = *a3 + 7LL;
      result = _kmalloc_noprof(v13, 3520);
    }
    return -12;
  }
}
