__int64 __fastcall cam_tasklet_stop(__int64 result)
{
  __int64 v1; // x19
  unsigned int v8; // w9

  if ( *(_DWORD *)(result + 24) )
  {
    v1 = result;
    *(_DWORD *)(result + 24) = 0;
    tasklet_kill(result + 32);
    _X8 = (unsigned int *)(v1 + 48);
    __asm { PRFM            #0x11, [X8] }
    do
      v8 = __ldxr(_X8);
    while ( __stxr(v8 + 1, _X8) );
    __dmb(0xBu);
    tasklet_unlock_wait(v1 + 32);
    __dmb(0xBu);
    return cam_tasklet_action(v1);
  }
  return result;
}
