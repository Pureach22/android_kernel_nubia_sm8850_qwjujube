__int64 __fastcall wlan_qmi_wfds_send_req_mem_msg(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 (__fastcall *v12)(_QWORD); // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x31u);
  if ( comp_private_obj )
  {
    v12 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 32);
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != -595128173 )
        __break(0x8228u);
      return v12(a2);
    }
    else
    {
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x9Du,
      2u,
      "%s: QMI context is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_qmi_wfds_send_req_mem_msg");
    return 4;
  }
}
