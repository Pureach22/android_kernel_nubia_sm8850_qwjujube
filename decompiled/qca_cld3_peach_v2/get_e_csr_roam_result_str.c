const char *__fastcall get_e_csr_roam_result_str(unsigned int a1)
{
  if ( a1 > 0x17 )
    return "unknown";
  else
    return off_B09858[a1];
}
