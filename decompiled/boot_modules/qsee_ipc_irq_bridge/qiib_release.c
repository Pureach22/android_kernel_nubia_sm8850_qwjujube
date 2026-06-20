__int64 __fastcall qiib_release(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0

  v3 = *(_QWORD *)(a2 + 32);
  if ( v3 )
  {
    result = *(_QWORD *)(qiib_info + 88);
    if ( result )
    {
      ipc_log_string(result, "%s on [%s]\n", "qiib_release", *(const char **)(v3 + 24));
      return 0;
    }
  }
  else
  {
    printk(&unk_7670, "qiib_release", a3);
    ipc_log_string(*(_QWORD *)(qiib_info + 88), "%s on NULL device\n", "qiib_release");
    return 4294967274LL;
  }
  return result;
}
