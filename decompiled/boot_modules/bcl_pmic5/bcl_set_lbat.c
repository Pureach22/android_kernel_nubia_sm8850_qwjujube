__int64 __fastcall bcl_set_lbat(__int64 a1, __int64 a2, int a3)
{
  unsigned int *v3; // x20
  __int64 v5; // x0

  v3 = *(unsigned int **)(a1 + 1048);
  mutex_lock(v3 + 6);
  v5 = *v3;
  if ( a3 == 0x7FFFFFFF )
  {
    if ( (_DWORD)v5 && *((_BYTE *)v3 + 72) == 1 )
    {
      disable_irq_nosync(v5);
      irq_set_irq_wake(*v3, 0);
      *((_BYTE *)v3 + 72) = 0;
    }
  }
  else if ( (_DWORD)v5 && (v3[18] & 1) == 0 )
  {
    enable_irq();
    irq_set_irq_wake(*v3, 1);
    *((_BYTE *)v3 + 72) = 1;
  }
  mutex_unlock(v3 + 6);
  return 0;
}
