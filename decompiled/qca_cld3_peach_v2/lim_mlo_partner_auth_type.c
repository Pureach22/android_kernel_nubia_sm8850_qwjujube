bool __fastcall lim_mlo_partner_auth_type(__int64 a1, __int64 a2, _DWORD *a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v15[8]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  lim_mlo_get_assoc_link_session_sta_ds(a1, a2, v15, &v14);
  v12 = v14;
  if ( v14 )
    *a3 = *(_DWORD *)((char *)&qword_8 + v14 + 4);
  else
    qdf_trace_msg(0x35u, 2u, "%s: sta ds is null", v4, v5, v6, v7, v8, v9, v10, v11, "lim_mlo_partner_auth_type");
  _ReadStatusReg(SP_EL0);
  return v12 != 0;
}
