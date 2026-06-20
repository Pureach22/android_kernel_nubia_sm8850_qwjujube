__int64 __fastcall kgsl_reclaim_proc_private_init(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 v9; // x9
  unsigned __int64 v12; // x9

  result = _mutex_init(a1 + 440, "&process->reclaim_lock", &kgsl_reclaim_proc_private_init___key);
  *(_QWORD *)(a1 + 408) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 416) = a1 + 416;
  *(_QWORD *)(a1 + 424) = a1 + 416;
  *(_QWORD *)(a1 + 432) = kgsl_reclaim_foreground_work;
  _X8 = (unsigned __int64 *)(a1 + 392);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 | 1, _X8) );
  _X8 = (unsigned __int64 *)(a1 + 392);
  __asm { PRFM            #0x11, [X8] }
  do
    v12 = __ldxr(_X8);
  while ( __stxr(v12 | 2, _X8) );
  *(_DWORD *)(a1 + 400) = 0;
  return result;
}
