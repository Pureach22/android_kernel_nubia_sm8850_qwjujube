__int64 rmnet_shs_dl_trl_handler_v2()
{
  __int64 result; // x0

  byte_19495 = 2;
  if ( qword_19468 >= 1 && !rmnet_shs_ht_splock )
  {
    ++qword_1A2E8;
    return rmnet_shs_flush_table(0, 0);
  }
  return result;
}
