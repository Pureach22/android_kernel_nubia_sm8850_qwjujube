_QWORD *__fastcall hfi_kms_get_cmd_buf(__int64 a1, unsigned __int16 a2, int a3)
{
  _QWORD *v3; // x0
  _QWORD *v4; // x8
  _QWORD *v5; // t1

  if ( !a1 )
  {
    printk(&unk_226F51, "hfi_kms_get_cmd_buf");
    return nullptr;
  }
  v5 = *(_QWORD **)(a1 + 72);
  v3 = (_QWORD *)(a1 + 72);
  v4 = v5;
  if ( v5 == v3 )
    return nullptr;
  while ( *((_DWORD *)v4 - 14) != a3 || *((_DWORD *)v4 - 12) != a2 )
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == v3 )
      return nullptr;
  }
  return v4 - 13;
}
