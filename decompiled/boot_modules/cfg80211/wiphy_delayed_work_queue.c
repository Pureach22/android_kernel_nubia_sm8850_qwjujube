__int64 __fastcall wiphy_delayed_work_queue(__int64 a1, _QWORD *a2, __int64 a3)
{
  if ( a3 )
  {
    a2[3] = a1;
    return mod_timer(a2 + 4, jiffies + a3);
  }
  else
  {
    timer_delete(a2 + 4);
    return wiphy_work_queue(a1, a2);
  }
}
