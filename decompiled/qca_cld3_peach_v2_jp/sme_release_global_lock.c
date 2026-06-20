__int64 __fastcall sme_release_global_lock(__int64 a1)
{
  if ( a1 )
    return qdf_mutex_release(a1 + 8);
  else
    return 4;
}
