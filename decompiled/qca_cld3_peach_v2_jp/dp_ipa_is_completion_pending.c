__int64 __fastcall dp_ipa_is_completion_pending(__int64 a1)
{
  __int64 obj_context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x20
  __int64 v14; // x0
  unsigned __int16 v15; // w0
  unsigned int v16; // w8
  unsigned __int16 v17; // w20
  unsigned int outstanding_buffers; // w0
  __int64 v19; // x4
  const char *v20; // x2
  __int64 result; // x0
  unsigned int v22; // w8
  _QWORD v23[2]; // [xsp+0h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  obj_context = wlan_ipa_get_obj_context();
  v11 = *(_QWORD *)(a1 + 7640);
  if ( v11 )
  {
    v12 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1920LL);
    if ( !v12 )
    {
      v20 = "%s: Unable to get num avail, err: %d";
      v19 = 11;
      goto LABEL_9;
    }
    v13 = obj_context;
    v14 = *(_QWORD *)(a1 + 7640);
    if ( *((_DWORD *)v12 - 1) != 1161982592 )
      __break(0x8228u);
    v15 = v12(v14);
    v16 = *(_DWORD *)(v13 + 7460);
    v17 = v15;
    outstanding_buffers = ipa_wdi_get_outstanding_buffers(v16, v23);
    if ( outstanding_buffers )
    {
      v19 = outstanding_buffers;
      v20 = "%s: Unable to get IPA outstanding buffers, err: %d";
LABEL_9:
      qdf_trace_msg(0x45u, 2u, v20, v3, v4, v5, v6, v7, v8, v9, v10, "dp_ipa_is_completion_pending", v19);
      goto LABEL_10;
    }
    v22 = *(_DWORD *)(v11 + 44);
    if ( (LODWORD(v23[0]) + 16) * v22 != v17 )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: num_avail: %d num_tx_outstanding: %d No buf entries: %d",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "dp_ipa_is_completion_pending",
        v17 / v22);
      result = 1;
      goto LABEL_11;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: wbm_srng NULL", v3, v4, v5, v6, v7, v8, v9, v10, "dp_ipa_is_completion_pending");
  }
LABEL_10:
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
