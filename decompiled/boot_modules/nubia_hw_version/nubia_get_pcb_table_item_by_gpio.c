_DWORD *__fastcall nubia_get_pcb_table_item_by_gpio(_DWORD *result, unsigned int a2)
{
  __int64 v2; // x10

  if ( !result || !a2 )
    return nullptr;
  v2 = a2;
  while ( *result != (unsigned __int8)nubia_pcb_gpio1_v || result[1] != (unsigned __int8)nubia_pcb_gpio2_v )
  {
    --v2;
    result += 6;
    if ( !v2 )
      return nullptr;
  }
  return result;
}
