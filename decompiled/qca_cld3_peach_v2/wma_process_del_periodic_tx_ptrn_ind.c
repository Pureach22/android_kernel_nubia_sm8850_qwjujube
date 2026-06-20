__int64 __fastcall wma_process_del_periodic_tx_ptrn_ind(__int64 *a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  __int64 result; // x0
  unsigned __int8 v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  if ( (unsigned int)_wma_validate_handle(a1, "wma_process_del_periodic_tx_ptrn_ind")
    || (v12 = *a1,
        (unsigned int)_wmi_validate_handle(
                        *a1,
                        (__int64)"wma_process_del_periodic_tx_ptrn_ind",
                        v4,
                        v5,
                        v6,
                        v7,
                        v8,
                        v9,
                        v10,
                        v11)) )
  {
LABEL_9:
    result = 4;
    goto LABEL_10;
  }
  if ( (unsigned int)wma_find_vdev_id_by_addr((__int64)a1, (__int64)a2, v26) )
  {
    if ( a2 )
    {
      v21 = *a2;
      v22 = a2[1];
      v23 = a2[2];
      v24 = a2[5];
    }
    else
    {
      v23 = 0;
      v21 = 0;
      v22 = 0;
      v24 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to find vdev id for %02x:%02x:%02x:**:**:%02x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_process_del_periodic_tx_ptrn_ind",
      v21,
      v22,
      v23,
      v24);
    goto LABEL_9;
  }
  result = wmi_unified_process_del_periodic_tx_ptrn_cmd(v12, v26[0], a2[6]);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
