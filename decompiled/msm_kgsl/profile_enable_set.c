__int64 __fastcall profile_enable_set(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned int v5; // w21

  rt_mutex_lock(a1 + 11088);
  if ( a2 && !*(_QWORD *)(a1 + 19704) )
  {
    v4 = vmalloc_noprof(942080);
    *(_QWORD *)(a1 + 19704) = v4;
    if ( !v4 )
    {
      v5 = -12;
      goto LABEL_6;
    }
    *(_QWORD *)(a1 + 19720) = v4;
    *(_QWORD *)(a1 + 19712) = v4;
  }
  v5 = 0;
  *(_BYTE *)(a1 + 19728) = a2 != 0;
LABEL_6:
  rt_mutex_unlock(a1 + 11088);
  return v5;
}
