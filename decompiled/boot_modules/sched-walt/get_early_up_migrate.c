__int64 __fastcall get_early_up_migrate(unsigned int a1)
{
  __int64 v2; // x20

  if ( (int)a1 > 7 )
    return 0;
  if ( byte_6A5A8 == 1 )
  {
    if ( a1 < 8 )
    {
      v2 = a1;
      printk(&unk_60E21);
      return *((unsigned int *)&sched_early_up_migrate + v2);
    }
LABEL_10:
    __break(0x5512u);
    JUMPOUT(0x5D474);
  }
  if ( a1 > 7 )
    goto LABEL_10;
  v2 = a1;
  return *((unsigned int *)&sched_early_up_migrate + v2);
}
