__int64 __fastcall qmi_invoke_handler(__int64 result, __int64 a2, __int64 a3, unsigned __int8 *a4, __int64 a5)
{
  __int64 v5; // x9
  _QWORD *i; // x23
  __int64 v11; // x21
  __int64 v13; // x22
  __int64 v14; // x1
  __int64 v15; // x2
  void (__fastcall *v16)(__int64, __int64, __int64, __int64); // x8

  v5 = *(_QWORD *)(result + 296);
  if ( v5 && *(_QWORD *)(v5 + 24) )
  {
    for ( i = (_QWORD *)(v5 + 16); *((_DWORD *)i - 4) != *a4 || *((_DWORD *)i - 3) != *(unsigned __int16 *)(a4 + 3); i += 4 )
    {
      if ( !i[5] )
        return result;
    }
    v11 = result;
    result = _kmalloc_noprof(*i, 3520);
    v13 = result;
    if ( result )
    {
      if ( (qmi_decode_message((__int64)a4, a5, *(i - 1), result) & 0x80000000) != 0 )
      {
        printk(&unk_82AC, v14, v15);
      }
      else
      {
        v16 = (void (__fastcall *)(__int64, __int64, __int64, __int64))i[1];
        if ( *((_DWORD *)v16 - 1) != 1150878154 )
          __break(0x8228u);
        v16(v11, a2, a3, v13);
      }
      return kfree(v13);
    }
  }
  return result;
}
