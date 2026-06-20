__int64 sub_140E8()
{
  const double *v0; // x18

  vld2q_f64(v0);
  return sps_get_free_count();
}
