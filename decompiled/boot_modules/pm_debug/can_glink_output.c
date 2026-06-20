bool can_glink_output()
{
  int v0; // w8

  v0 = glink_count;
  if ( glink_count >= 1 )
    --glink_count;
  return v0 > 0;
}
