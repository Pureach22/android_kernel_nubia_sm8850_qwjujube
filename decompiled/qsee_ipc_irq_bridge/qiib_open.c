__int64 __fastcall qiib_open(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 656);
  if ( v3 == 32 )
  {
    printk(&unk_7670, "qiib_open", a3);
    ipc_log_string(*(_QWORD *)(qiib_info + 88), "%s on NULL device\n", "qiib_open");
    return 4294967274LL;
  }
  else
  {
    *(_QWORD *)(a2 + 32) = v3 - 32;
    result = *(_QWORD *)(qiib_info + 88);
    if ( result )
    {
      ipc_log_string(result, "%s on [%s]\n", "qiib_open", *(const char **)(v3 - 8));
      return 0;
    }
  }
  return result;
}
