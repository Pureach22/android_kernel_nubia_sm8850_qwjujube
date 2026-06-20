__int64 __fastcall sched_set_boost(unsigned int a1)
{
  unsigned int v2; // w19

  if ( (walt_disabled & 1) != 0 )
  {
    return (unsigned int)-11;
  }
  else
  {
    mutex_lock(&boost_mutex);
    if ( a1 + 5 > 0xA )
    {
      v2 = -22;
    }
    else
    {
      sched_set_boost(a1);
      v2 = 0;
    }
    mutex_unlock(&boost_mutex);
  }
  return v2;
}
