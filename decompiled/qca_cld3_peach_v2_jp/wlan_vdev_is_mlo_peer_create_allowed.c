__int64 __fastcall wlan_vdev_is_mlo_peer_create_allowed(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w20
  int v10; // w21
  const char *v12; // x2
  __int64 result; // x0
  unsigned int v14; // w9
  bool v15; // zf
  int v16; // w9

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    v12 = "%s: vdev is null";
    goto LABEL_5;
  }
  v9 = *(_DWORD *)(a1 + 20);
  v10 = *(_DWORD *)(a1 + 24);
  if ( (unsigned int)mlme_ext_hdl_get_acs_in_progress() )
  {
    v12 = "%s: Unable to get ACS in progress status";
LABEL_5:
    qdf_trace_msg(0x68u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_is_mlo_peer_create_allowed");
    result = 16;
    goto LABEL_20;
  }
  if ( v9 == 3 || (v9 == 4 ? (v15 = v10 == 14) : (v15 = 0), !v15 ? (v16 = 0) : (v16 = 1), v9 == 2 || v16) )
    v14 = 0;
  else
    v14 = 16;
  if ( (*(_BYTE *)(a1 + 66) & 0xA0) != 0 )
    result = 16;
  else
    result = v14;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
