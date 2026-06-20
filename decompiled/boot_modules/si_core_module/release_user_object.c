__int64 __fastcall release_user_object(_QWORD *a1)
{
  unsigned int v8; // w9

  a1[6] = 0xFFFFFFFE00000LL;
  a1[7] = a1 + 7;
  a1[8] = a1 + 7;
  a1[9] = destroy_user_object;
  _X8 = &pending_releases;
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr((unsigned int *)&pending_releases);
  while ( __stxr(v8 + 1, (unsigned int *)&pending_releases) );
  return queue_work_on(32, si_core_wq);
}
