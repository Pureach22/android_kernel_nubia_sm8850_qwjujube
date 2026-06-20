__int64 __fastcall dp_reo_remap_config(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        unsigned int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v14; // w4
  _DWORD *v15; // x8
  __int64 v16; // x1
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char is_vlan_enabled; // w0
  int v28; // w9
  int v29; // w10
  _DWORD *v30; // x8
  void (__fastcall *v31)(_QWORD); // x8
  _QWORD v33[5]; // [xsp+8h] [xbp-28h] BYREF

  v33[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(unsigned __int16 *)(a1 + 20008);
  v33[2] = 0x900000008LL;
  v33[3] = 0;
  v33[0] = 0x200000001LL;
  v33[1] = 0x700000003LL;
  if ( v14 )
  {
    if ( v14 == 1 )
    {
      v15 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1064LL);
      v16 = (unsigned int)*(unsigned __int8 *)(a1 + 12848) - 2;
      if ( *(v15 - 1) != 1624039104 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, __int64))v15)(v33, v16);
    }
    else
    {
      qdf_trace_msg(0x45u, 2u, "%s: unknown arch_id 0x%x", a5, a6, a7, a8, a9, a10, a11, a12, "dp_reo_remap_config");
    }
  }
  else
  {
    is_vlan_enabled = wlan_ipa_is_vlan_enabled();
    v28 = *(unsigned __int8 *)(a1 + 12848);
    if ( (is_vlan_enabled & 1) != 0 )
      v29 = -2;
    else
      v29 = -1;
    v30 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1064LL);
    if ( *(v30 - 1) != 1624039104 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, unsigned int *, unsigned int *))v30)(v33, (unsigned int)(v29 + v28), a3, a4);
    v31 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1072LL);
    if ( v31 )
    {
      if ( *((_DWORD *)v31 - 1) != 2116863787 )
        __break(0x8228u);
      v31(a2);
    }
  }
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: remap1 %x remap2 %x",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "dp_reo_remap_config",
    *a3,
    *a4);
  _ReadStatusReg(SP_EL0);
  return 1;
}
