bool can_qrtr_output()
{
  int v0; // w8

  v0 = qrtr_count;
  if ( qrtr_count >= 1 )
    --qrtr_count;
  return v0 > 0;
}
