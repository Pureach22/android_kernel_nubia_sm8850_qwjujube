__int64 __fastcall destroy_user_object(__int64 a1)
{
  const char **v1; // x19
  int v2; // w0
  __int64 result; // x0
  const char *v4; // x1
  unsigned int v11; // w10
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v1 = (const char **)(a1 - 48);
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v2 = si_object_do_invoke(si_object_do_release_oic, a1 - 48, 0xFFFF, (__int64)&si_object_do_release_args, &v12);
  if ( v2 == -11 )
  {
    result = queue_work_on(32, si_core_wq);
  }
  else
  {
    if ( v2 | v12 )
    {
      ++release_failed;
      if ( v1 )
      {
        if ( v1 == &qword_1 )
        {
          v4 = "root";
        }
        else if ( *v1 )
        {
          v4 = *v1;
        }
        else
        {
          v4 = "noname";
        }
      }
      else
      {
        v4 = "null";
      }
      printk(&unk_B1FD, v4);
    }
    _X9 = &pending_releases;
    __asm { PRFM            #0x11, [X9] }
    do
      v11 = __ldxr((unsigned int *)&pending_releases);
    while ( __stxr(v11 - 1, (unsigned int *)&pending_releases) );
    kfree(*v1);
    result = free_si_object();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
