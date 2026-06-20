__int64 __fastcall csr_update_owe_info(__int64 a1, __int64 a2)
{
  __int16 v4; // w9
  __int64 v5; // x0
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x2
  int v17; // [xsp+0h] [xbp-10h] BYREF
  __int16 v18; // [xsp+4h] [xbp-Ch]
  unsigned __int8 v19; // [xsp+6h] [xbp-Ah]
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_WORD *)(a2 + 18);
  v5 = *(_QWORD *)(a1 + 21632);
  v17 = *(_DWORD *)(a2 + 14);
  v18 = v4;
  v19 = 6;
  v6 = wlan_objmgr_pdev_iterate_obj_list(
         v5,
         2,
         (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
         (__int64)&v17,
         0,
         0xBu);
  if ( v19 >= 6u )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Couldn't find session_id for given BSSID",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "csr_update_owe_info");
    LODWORD(v15) = 16;
  }
  else
  {
    v15 = (unsigned int)csr_send_assoc_cnf_msg(
                          v7,
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v6,
                          a2,
                          4 * (unsigned int)(*(_WORD *)(a2 + 2924) != 0),
                          *(unsigned __int16 *)(a2 + 2924));
    if ( !*(_WORD *)(a2 + 2924) )
      LODWORD(v15) = csr_send_assoc_ind_to_upper_layer_cnf_msg(a1, a2, v15);
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v15;
}
