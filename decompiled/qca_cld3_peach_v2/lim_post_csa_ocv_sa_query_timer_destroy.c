__int64 __fastcall lim_post_csa_ocv_sa_query_timer_destroy(__int64 result)
{
  __int64 v1; // x20

  if ( result )
  {
    v1 = result;
    qdf_mc_timer_stop(result + 9800);
    return qdf_mc_timer_destroy(v1 + 9800);
  }
  return result;
}
