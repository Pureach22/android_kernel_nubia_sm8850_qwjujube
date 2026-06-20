__int64 __fastcall ucfg_dp_set_high_bus_bw_request(__int64 a1, char a2, char a3)
{
  __int64 result; // x0
  int v6; // w9
  int v7; // w8

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  v6 = *(unsigned __int8 *)(result + 880);
  v7 = v6 | (1 << a2);
  if ( (a3 & 1) == 0 )
    LOBYTE(v7) = v6 & ~(1 << a2);
  *(_BYTE *)(result + 880) = v7;
  return result;
}
