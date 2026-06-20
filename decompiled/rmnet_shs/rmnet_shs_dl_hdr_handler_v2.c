unsigned int *__fastcall rmnet_shs_dl_hdr_handler_v2(unsigned int *result)
{
  unsigned int v1; // w2
  unsigned int *v2; // x20

  v1 = *result;
  if ( rmnet_shs_last_seq && rmnet_shs_last_seq >= v1 )
  {
    if ( rmnet_shs_debug )
    {
      v2 = result;
      result = (unsigned int *)printk(&unk_15566);
      v1 = *v2;
    }
    rmnet_shs_last_seq = v1;
    ++qword_1A4B0;
  }
  else
  {
    rmnet_shs_last_seq = *result;
  }
  if ( !rmnet_shs_ht_splock )
  {
    if ( qword_19468 >= 1 && byte_19495 != 2 )
    {
      ++qword_1A330;
      result = (unsigned int *)rmnet_shs_flush_table(0, 0);
    }
    byte_19495 = 1;
  }
  return result;
}
