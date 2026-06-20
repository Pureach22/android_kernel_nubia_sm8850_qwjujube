const char *__fastcall syna_tcm_get_partition_id_string(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x16 )
    return " ";
  else
    return off_42090[a1 - 1];
}
