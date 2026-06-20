__int64 is_sbt_or_oscillate()
{
  return now_is_sbt & 1 | (unsigned int)(oscillate_cpu != -1);
}
