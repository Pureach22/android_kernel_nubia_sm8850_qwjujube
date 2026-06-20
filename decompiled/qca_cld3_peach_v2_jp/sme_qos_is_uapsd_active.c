bool sme_qos_is_uapsd_active()
{
  if ( *(_BYTE *)(qword_856120 + 1) == 1 && *(_BYTE *)(qword_856120 + 2916) )
    return 1;
  if ( *(_BYTE *)(qword_856120 + 3041) == 1 && *(_BYTE *)(qword_856120 + 5956) )
    return 1;
  if ( *(_BYTE *)(qword_856120 + 6081) == 1 && *(_BYTE *)(qword_856120 + 8996) )
    return 1;
  if ( *(_BYTE *)(qword_856120 + 9121) == 1 && *(_BYTE *)(qword_856120 + 12036) )
    return 1;
  if ( *(_BYTE *)(qword_856120 + 12161) == 1 && *(_BYTE *)(qword_856120 + 15076) )
    return 1;
  return *(_BYTE *)(qword_856120 + 15201) == 1 && *(_BYTE *)(qword_856120 + 18116);
}
