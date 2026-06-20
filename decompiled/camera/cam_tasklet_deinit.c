_QWORD *__fastcall cam_tasklet_deinit(__int64 *a1)
{
  __int64 v1; // x20
  _QWORD *result; // x0
  unsigned int v10; // w9

  v1 = *a1;
  if ( *(_DWORD *)(*a1 + 24) )
  {
    *(_DWORD *)(v1 + 24) = 0;
    tasklet_kill(v1 + 32);
    _X8 = (unsigned int *)(v1 + 48);
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 + 1, _X8) );
    __dmb(0xBu);
    tasklet_unlock_wait(v1 + 32);
    __dmb(0xBu);
  }
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free((_QWORD *)v1, 0);
  else
    result = (_QWORD *)kvfree(v1);
  *a1 = 0;
  return result;
}
