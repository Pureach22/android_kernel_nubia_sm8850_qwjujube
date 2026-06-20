__int64 __fastcall target_if_ll_sap_continue_csa_after_tsf_rsp(__int64 a1, unsigned int *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD *v12; // x0
  __int64 v13; // x20
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  unsigned int v24; // w19
  __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v27)(); // [xsp+18h] [xbp-28h]
  __int64 v28; // [xsp+20h] [xbp-20h]
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = nullptr;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  if ( wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u) )
  {
    v12 = (_QWORD *)_qdf_mem_malloc(0x40u, "target_if_ll_sap_continue_csa_after_tsf_rsp", 294);
    if ( v12 )
    {
      v13 = (__int64)v12;
      *v12 = a1;
      qdf_mem_copy(v12 + 1, a2, 0x34u);
      v26 = v13;
      v27 = wlan_ll_lt_sap_continue_csa_after_tsf_rsp;
      v28 = 0;
      result = scheduler_post_message_debug(
                 0x49u,
                 0xA1u,
                 73,
                 (unsigned __int16 *)&v25,
                 0x133u,
                 (__int64)"target_if_ll_sap_continue_csa_after_tsf_rsp");
      if ( (_DWORD)result )
      {
        v23 = *a2;
        v24 = result;
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: vdev_id %d failed to post tsf stats rsp",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "target_if_ll_sap_continue_csa_after_tsf_rsp",
          v23);
        _qdf_mem_free(v13);
        result = v24;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc_ll_sap_obj is null",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "target_if_ll_sap_continue_csa_after_tsf_rsp");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
