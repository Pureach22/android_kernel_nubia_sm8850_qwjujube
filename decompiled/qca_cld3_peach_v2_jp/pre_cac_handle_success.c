__int64 __fastcall pre_cac_handle_success(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 result; // x0
  _DWORD *v13; // x8
  __int64 v14; // x1
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Du);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    result = qdf_trace_msg(
               0x98u,
               8u,
               "%s: vdev id %d",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "pre_cac_handle_success",
               *(unsigned __int8 *)(comp_private_obj + 48));
    if ( glbl_pre_cac_ops )
    {
      v13 = *(_DWORD **)(glbl_pre_cac_ops + 8);
      if ( v13 )
      {
        v14 = *(unsigned __int8 *)(v11 + 48);
        if ( *(v13 - 1) != -345040066 )
          __break(0x8228u);
        return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v13)(a1, v14, 0);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x98u, 2u, "%s:%u: psoc_priv is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "pre_cac_handle_success", 165);
    return qdf_trace_msg(
             0x98u,
             2u,
             "%s: Invalid psoc priv",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "pre_cac_handle_success");
  }
  return result;
}
