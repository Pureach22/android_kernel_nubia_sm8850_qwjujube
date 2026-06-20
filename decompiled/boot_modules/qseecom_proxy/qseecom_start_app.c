__int64 qseecom_start_app()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0
  unsigned int v2; // w20

  v0 = (__int64 (*)(void))off_64F8;
  if ( off_64F8 )
  {
    if ( *((_DWORD *)off_64F8 - 1) != -596936371 )
      __break(0x8228u);
    result = v0();
    if ( (_DWORD)result )
    {
      v2 = result;
      printk(&unk_64A1);
      return v2;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&qseecom_start_app__rs, "qseecom_start_app") )
      printk(&unk_64CF);
    return 4294967285LL;
  }
  return result;
}
