__int64 __fastcall bcl_set_soc(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x21
  __int64 v5; // x8
  __int64 v6; // x1

  v4 = a3;
  if ( *(_QWORD *)(bcl_perph + 64) != a3 )
  {
    mutex_lock(bcl_perph + 80);
    v5 = bcl_perph;
    *(_QWORD *)(bcl_perph + 64) = v4;
    if ( a3 == 0x7FFFFFFF )
    {
      *(_BYTE *)(v5 + 128) = 0;
    }
    else
    {
      v6 = system_wq;
      *(_BYTE *)(v5 + 128) = 1;
      queue_work_on(32, v6, v5 + 32);
      v5 = bcl_perph;
    }
    mutex_unlock(v5 + 80);
  }
  return 0;
}
