__int64 __fastcall hdcp1_ops_notify_smcinvoke(__int64 a1)
{
  _DWORD *v1; // x9
  __int64 v2; // x0
  unsigned int v3; // w19
  __int64 result; // x0
  void *v5; // x0

  if ( !a1 || !*(_QWORD *)(a1 + 40) )
  {
    v5 = &unk_D0E9;
LABEL_12:
    printk(v5);
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(a1 + 64) & 1) == 0 )
  {
    v5 = &unk_C905;
    goto LABEL_12;
  }
  if ( (*(_BYTE *)(a1 + 72) & 1) != 0 )
  {
    v1 = *(_DWORD **)(a1 + 32);
    v2 = *(_QWORD *)(a1 + 40);
    if ( *(v1 - 1) != 816020464 )
      __break(0x8229u);
    v3 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v1)(v2, 0, 0, 0);
    result = 0;
    if ( v3 )
    {
      printk(&unk_BF45);
      return v3;
    }
  }
  else
  {
    printk(&unk_C830);
    return 4294967274LL;
  }
  return result;
}
