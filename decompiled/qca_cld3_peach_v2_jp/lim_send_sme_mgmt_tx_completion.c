__int64 __fastcall lim_send_sme_mgmt_tx_completion(__int64 a1, char a2, int a3)
{
  __int64 result; // x0
  __int64 v7; // x19
  __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // [xsp+8h] [xbp-38h] BYREF
  __int64 v18; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v19)(); // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = nullptr;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  result = _qdf_mem_malloc(0x10u, "lim_send_sme_mgmt_tx_completion", 1266);
  if ( result )
  {
    *(_BYTE *)result = a2;
    v7 = result;
    *(_DWORD *)(result + 4) = a3;
    v8 = *(_QWORD *)(a1 + 21552);
    v18 = result;
    HIDWORD(v17) = 0;
    *(_QWORD *)(result + 8) = v8;
    v19 = tgt_tdls_send_mgmt_tx_completion;
    result = scheduler_post_message_debug(
               0x35u,
               0,
               73,
               (unsigned __int16 *)&v17,
               0x502u,
               (__int64)"lim_send_sme_mgmt_tx_completion");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: post msg fail, %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "lim_send_sme_mgmt_tx_completion",
        (unsigned int)result);
      result = _qdf_mem_free(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
