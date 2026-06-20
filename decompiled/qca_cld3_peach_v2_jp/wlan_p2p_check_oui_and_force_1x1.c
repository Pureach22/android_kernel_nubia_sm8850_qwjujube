__int64 __fastcall wlan_p2p_check_oui_and_force_1x1(unsigned __int8 *a1, int a2)
{
  unsigned __int8 v3; // w0

  v3 = 0;
  if ( a1 && a2 )
    v3 = (unsigned __int8)p2p_check_oui_and_force_1x1(a1, a2);
  return v3 & 1;
}
