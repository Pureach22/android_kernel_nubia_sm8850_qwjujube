__int64 qseecom_shutdown_app()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0
  unsigned int v2; // w19

  v0 = (__int64 (*)(void))off_6500;
  if ( off_6500 )
  {
    if ( *((_DWORD *)off_6500 - 1) != -63234598 )
      __break(0x8228u);
    result = v0();
    if ( (_DWORD)result )
    {
      v2 = result;
      printk(&unk_63D0);
      return v2;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&qseecom_shutdown_app__rs, "qseecom_shutdown_app") )
      printk(&unk_64CF);
    return 4294967285LL;
  }
  return result;
}
