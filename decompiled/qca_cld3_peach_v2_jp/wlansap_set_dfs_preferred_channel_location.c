__int64 __fastcall wlansap_set_dfs_preferred_channel_location(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  const char *v19; // x2
  unsigned int v20; // w1
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  HIDWORD(v21) = 0;
  LOBYTE(v21) = 0;
  if ( !a1 )
  {
    v19 = "%s: Invalid mac_handle pointer";
    v20 = 2;
LABEL_7:
    qdf_trace_msg(
      0x39u,
      v20,
      v19,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlansap_set_dfs_preferred_channel_location",
      v21,
      v22);
    result = 5;
    goto LABEL_8;
  }
  wlan_reg_get_dfs_region(*(_QWORD *)(a1 + 21560), (_DWORD *)&v21 + 1, a2, a3, a4, a5, a6, a7, a8, a9);
  wlan_mlme_get_sap_chan_pref_location(*(_QWORD *)(a1 + 21552), &v21);
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: dfs_preferred_channels_location %d dfs region %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlansap_set_dfs_preferred_channel_location",
    (unsigned __int8)v21,
    HIDWORD(v21));
  if ( HIDWORD(v21) != 3 && HIDWORD(v21) != 6 )
  {
    v19 = "%s: sapdfs:NOT JAPAN REG, Invalid Set preferred chans location";
    v20 = 8;
    goto LABEL_7;
  }
  *(_BYTE *)(a1 + 14810) = v21;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sapdfs:Set Preferred Operating Channel location=%d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlansap_set_dfs_preferred_channel_location",
    v21,
    v22);
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
