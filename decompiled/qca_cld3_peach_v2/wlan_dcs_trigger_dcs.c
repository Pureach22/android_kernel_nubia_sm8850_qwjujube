__int64 __fastcall wlan_dcs_trigger_dcs(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, char a4)
{
  __int64 comp_private_obj; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  __int64 (__fastcall *v18)(__int64, __int64 *, __int64); // x8
  __int64 v19; // x2
  __int64 result; // x0
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( comp_private_obj )
  {
    v17 = comp_private_obj;
    BYTE4(v21) = a3;
    LODWORD(v21) = a2;
    BYTE5(v21) = a4;
    qdf_trace_msg(
      0x74u,
      4u,
      "%s: vdev: %d start dcs callback handler",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_dcs_trigger_dcs",
      a3,
      v21,
      v22);
    v18 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v17 + 1152);
    v19 = *(_QWORD *)(v17 + 1160);
    if ( *((_DWORD *)v18 - 1) != 1380631204 )
      __break(0x8228u);
    result = v18(a1, &v21, v19);
  }
  else
  {
    result = qdf_trace_msg(
               0x74u,
               2u,
               "%s: dcs private psoc object is null",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "wlan_dcs_trigger_dcs",
               v21,
               v22);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
