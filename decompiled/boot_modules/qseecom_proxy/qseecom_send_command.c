__int64 qseecom_send_command()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0
  unsigned int v2; // w19

  v0 = (__int64 (*)(void))qseecom_fun_ops;
  if ( qseecom_fun_ops )
  {
    if ( *((_DWORD *)qseecom_fun_ops - 1) != -1092058380 )
      __break(0x8228u);
    result = v0();
    if ( (_DWORD)result )
    {
      v2 = result;
      printk(&unk_6401);
      return v2;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&qseecom_send_command__rs, "qseecom_send_command") )
      printk(&unk_64CF);
    return 4294967285LL;
  }
  return result;
}
