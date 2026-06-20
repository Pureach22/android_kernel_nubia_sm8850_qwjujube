__int64 __fastcall target_if_dp_send_dhcp_ind(
        unsigned __int16 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_by_id; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x8
  int v23; // w11
  int v24; // w9
  int v25; // w10
  __int64 v26; // x19
  double v27; // d0
  unsigned int v28; // w0
  unsigned int v29; // w20
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  __int64 v38; // [xsp+0h] [xbp-20h] BYREF
  int v39; // [xsp+8h] [xbp-18h]
  int v40; // [xsp+Ch] [xbp-14h]
  int v41; // [xsp+10h] [xbp-10h]
  int v42; // [xsp+14h] [xbp-Ch]
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v38) = 0;
  psoc_by_id = wlan_objmgr_get_psoc_by_id(0, 0x48u, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( psoc_by_id )
  {
    v21 = *(_QWORD *)(psoc_by_id + 2800);
    if ( v21 && (v22 = *(_QWORD *)(v21 + 16)) != 0 )
    {
      v23 = *((_DWORD *)a2 + 2);
      v24 = *a2;
      HIDWORD(v38) = a1;
      v39 = v23;
      v25 = *((unsigned __int16 *)a2 + 6);
      v26 = psoc_by_id;
      v42 = v24;
      v40 = v25;
      v41 = 9;
      v27 = wmi_unified_process_dhcp_ind(v22, &v38);
      v29 = v28;
      wlan_objmgr_psoc_release_ref(v26, 0x48u, v27, v30, v31, v32, v33, v34, v35, v36);
      result = v29;
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Unable to get wmi handle",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "target_if_dp_send_dhcp_ind",
        v38);
      result = 29;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: psoc null", v13, v14, v15, v16, v17, v18, v19, v20, "target_if_dp_send_dhcp_ind", v38);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
