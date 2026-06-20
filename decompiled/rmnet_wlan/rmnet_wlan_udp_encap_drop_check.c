bool __fastcall rmnet_wlan_udp_encap_drop_check(unsigned __int16 *a1)
{
  int v1; // w8
  _QWORD *v2; // x9

  v1 = *a1;
  v2 = &rmnet_wlan_act_encap_drop_hash[(unsigned int)(1640531527 * v1) >> 28];
  do
    v2 = (_QWORD *)*v2;
  while ( v2 && *((unsigned __int16 *)v2 + 16) != v1 );
  return v2 != nullptr;
}
