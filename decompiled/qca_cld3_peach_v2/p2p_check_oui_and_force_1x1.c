unsigned __int8 *__fastcall p2p_check_oui_and_force_1x1(unsigned __int8 *a1, unsigned __int16 a2)
{
  unsigned __int8 *result; // x0

  result = p2p_parse_assoc_ie_for_device_info(a1, a2);
  if ( result )
    return (unsigned __int8 *)((unsigned int)qdf_mem_cmp(result + 9, &unk_AEFAE0, 4u) == 0);
  return result;
}
