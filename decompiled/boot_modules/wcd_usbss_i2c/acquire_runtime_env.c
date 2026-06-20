__int64 __fastcall acquire_runtime_env(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x23
  unsigned int v4; // w0
  unsigned int v5; // w20
  int v7; // w24
  unsigned int v8; // w8
  unsigned int v15; // w10

  mutex_lock(a1 + 456);
  v2 = *(_DWORD *)(a1 + 512);
  *(_DWORD *)(a1 + 512) = v2 + 1;
  if ( v2
    || (pm_stay_awake(*(_QWORD *)(a1 + 8)),
        v3 = *(_QWORD *)(a1 + 8),
        v4 = _pm_runtime_resume(v3, 4),
        (v4 & 0x80000000) == 0) )
  {
LABEL_3:
    v5 = 0;
    goto LABEL_4;
  }
  v5 = v4;
  v7 = 0;
  while ( 1 )
  {
    v8 = *(_DWORD *)(v3 + 480);
    do
    {
      if ( !v8 )
        break;
      _X12 = (unsigned int *)(v3 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v15 = __ldxr(_X12);
        if ( v15 != v8 )
          break;
        if ( !__stlxr(v8 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v15 == v8;
      v8 = v15;
    }
    while ( !_ZF );
    if ( v5 == -13 )
      break;
    dev_err(*(_QWORD *)(a1 + 8), "%s: pm_runtime_resume_and_get failed: %i\n", "acquire_runtime_env", v5);
    if ( ++v7 == 8 )
      goto LABEL_22;
LABEL_17:
    v3 = *(_QWORD *)(a1 + 8);
    v5 = _pm_runtime_resume(v3, 4);
    if ( (v5 & 0x80000000) == 0 )
      goto LABEL_3;
  }
  usleep_range_state(5000, 5500, 2);
  if ( ++v7 != 8 )
    goto LABEL_17;
  dev_err(*(_QWORD *)(a1 + 8), "%s: pm runtime in disabled state\n", "acquire_runtime_env");
LABEL_22:
  pm_relax(*(_QWORD *)(a1 + 8));
  --*(_DWORD *)(a1 + 512);
LABEL_4:
  mutex_unlock(a1 + 456);
  return v5;
}
