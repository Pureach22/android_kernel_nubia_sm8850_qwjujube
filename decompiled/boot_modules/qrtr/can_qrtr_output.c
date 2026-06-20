__int64 can_qrtr_output()
{
  if ( msm_pm_debug_mask == 1 )
    return 1;
  if ( qrtr_count >= 1 )
  {
    --qrtr_count;
    return 1;
  }
  return 0;
}
