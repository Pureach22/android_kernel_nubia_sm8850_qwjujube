__int64 kgsl_reclaim_close()
{
  if ( qword_3A918 )
    shrinker_free();
  qword_3A918 = 0;
  return cancel_work_sync(&reclaim_work);
}
