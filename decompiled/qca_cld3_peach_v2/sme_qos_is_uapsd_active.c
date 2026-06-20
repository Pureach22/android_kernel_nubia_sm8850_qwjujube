bool sme_qos_is_uapsd_active()
{
  if ( *(_BYTE *)(qword_91F2D8 + 1) == 1 && *(_BYTE *)(qword_91F2D8 + 2916) )
    return 1;
  if ( *(_BYTE *)(qword_91F2D8 + 3041) == 1 && *(_BYTE *)(qword_91F2D8 + 5956) )
    return 1;
  if ( *(_BYTE *)(qword_91F2D8 + 6081) == 1 && *(_BYTE *)(qword_91F2D8 + 8996) )
    return 1;
  if ( *(_BYTE *)(qword_91F2D8 + 9121) == 1 && *(_BYTE *)(qword_91F2D8 + 12036) )
    return 1;
  if ( *(_BYTE *)(qword_91F2D8 + 12161) == 1 && *(_BYTE *)(qword_91F2D8 + 15076) )
    return 1;
  return *(_BYTE *)(qword_91F2D8 + 15201) == 1 && *(_BYTE *)(qword_91F2D8 + 18116);
}
