__int64 __fastcall rmnet_mem_cb(__int64 result)
{
  __int64 v1; // x1

  if ( result > 5 )
  {
    if ( result == 6 )
    {
      ++qword_8E28;
    }
    else if ( result == 7 || result == 8 )
    {
      ++qword_8E30;
    }
  }
  else
  {
    if ( (unsigned __int64)(result - 3) >= 2 )
    {
      if ( result )
        return result;
      v1 = mem_wq;
    }
    else
    {
      v1 = mem_wq;
      ++qword_8E18;
    }
    return queue_delayed_work_on(32, v1, &pool_replenish_work, 0);
  }
  return result;
}
