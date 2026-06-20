__int64 qseecom_process_listener_from_smcinvoke()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0
  unsigned int v2; // w19

  v0 = (__int64 (*)(void))off_6508;
  if ( off_6508 )
  {
    if ( *((_DWORD *)off_6508 - 1) != -989477991 )
      __break(0x8228u);
    result = v0();
    if ( (_DWORD)result )
    {
      v2 = result;
      printk(&unk_63A4);
      return v2;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(
                         &qseecom_process_listener_from_smcinvoke__rs,
                         "qseecom_process_listener_from_smcinvoke") )
      printk(&unk_645A);
    return 4294967285LL;
  }
  return result;
}
