__int64 __fastcall dlm_send_reject_ap_list_to_fw(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  _BYTE *psoc_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  __int64 v26; // [xsp+8h] [xbp-18h]
  _BYTE v27[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 80);
  v27[0] = 0;
  v25 = 0;
  ucfg_dlm_psoc_get_suspended(v6, v27);
  if ( v27[0] == 1 )
  {
    psoc_obj = (_BYTE *)dlm_get_psoc_obj(*(_QWORD *)(a1 + 80));
    if ( psoc_obj )
      *psoc_obj = *(_BYTE *)(a1 + 40);
    else
      qdf_trace_msg(
        0x6Du,
        2u,
        "%s: DLM psoc obj NULL",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "dlm_store_pdevid_in_dlm_psocpriv");
    result = qdf_trace_msg(
               0x6Du,
               8u,
               "%s: Failed to send reject AP list to FW as DLM is suspended",
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               "dlm_send_reject_ap_list_to_fw");
  }
  else
  {
    result = _qdf_mem_malloc(0x420u, "dlm_send_reject_ap_list_to_fw", 1423);
    v26 = result;
    if ( result )
    {
      dlm_fill_reject_list(a2, result, &v25, 1, 22, a3);
      dlm_fill_reject_list(a2, v26, &v25, 3, 22, a3);
      dlm_fill_reject_list(a2, v26, &v25, 4, 22, a3);
      dlm_fill_reject_list(a2, v26, &v25, 0, 22, a3);
      dlm_fill_reject_list(a2, v26, &v25, 2, 22, a3);
      if ( (unsigned int)tgt_dlm_send_reject_list_to_fw(a1, &v25) )
        qdf_trace_msg(
          0x6Du,
          2u,
          "%s: failed to send the reject Ap list to FW",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "dlm_send_reject_ap_list_to_fw");
      result = _qdf_mem_free(v26);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
