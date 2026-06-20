__int64 nubia_get_hw_id()
{
  __int64 result; // x0
  _UNKNOWN **v1; // x9
  unsigned int *v2; // x19

  result = 9;
  if ( (unsigned __int8)nubia_pcb_gpio1_v <= 1u )
  {
    if ( nubia_pcb_gpio1_v )
    {
      if ( nubia_pcb_gpio1_v != 1 || (unsigned int)_UNIQUE_ID_vermagic534[19] >= 3 )
        return result;
      v1 = &off_79D0;
    }
    else
    {
      if ( (unsigned int)_UNIQUE_ID_vermagic534[19] >= 3 )
        return result;
      v1 = &off_79A0;
    }
    goto LABEL_14;
  }
  if ( nubia_pcb_gpio1_v == 2 )
  {
    if ( (unsigned int)_UNIQUE_ID_vermagic534[19] >= 3 )
      return result;
    v1 = &off_79B8;
LABEL_14:
    v2 = (unsigned int *)v1[_UNIQUE_ID_vermagic534[19]];
    goto LABEL_15;
  }
  if ( nubia_pcb_gpio1_v != 3 || _UNIQUE_ID_vermagic534[19] != 3 )
    return result;
  v2 = (unsigned int *)&unk_7768;
LABEL_15:
  if ( debug_value == 1 )
    printk(&unk_7547);
  return v2[2];
}
