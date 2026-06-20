__int64 __fastcall sched_boost_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int *v6; // x24
  unsigned int v11; // w19
  __int64 v12; // x0

  v6 = *(unsigned int **)(a1 + 8);
  mutex_lock(&boost_mutex);
  v11 = proc_dointvec_minmax(a1, a2, a3, a4, a5);
  if ( a2 && !v11 )
  {
    v12 = *v6;
    if ( (unsigned int)(v12 + 5) > 0xA )
    {
      v11 = -22;
    }
    else
    {
      sched_set_boost(v12);
      v11 = 0;
    }
  }
  mutex_unlock(&boost_mutex);
  return v11;
}
