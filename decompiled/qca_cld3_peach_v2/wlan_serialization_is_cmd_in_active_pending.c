__int64 __fastcall wlan_serialization_is_cmd_in_active_pending(char a1, char a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w9

  if ( (a2 & 1) != 0 )
    v2 = 0;
  else
    v2 = 4;
  if ( (a2 & 1) != 0 )
    v3 = 2;
  else
    v3 = 1;
  if ( (a1 & 1) != 0 )
    return v3;
  else
    return v2;
}
