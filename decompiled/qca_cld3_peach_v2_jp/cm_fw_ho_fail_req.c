__int64 __fastcall cm_fw_ho_fail_req(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // [xsp+8h] [xbp-38h] BYREF
  __int64 v17; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v18)(); // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = nullptr;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  result = _qdf_mem_malloc(0x18u, "cm_fw_ho_fail_req", 1889);
  if ( result )
  {
    v7 = result;
    *(_BYTE *)result = a2;
    *(_QWORD *)(result + 8) = a1;
    *(_WORD *)(result + 20) = WORD2(a3);
    *(_DWORD *)(result + 16) = a3;
    v17 = result;
    v18 = cm_handle_ho_fail;
    result = scheduler_post_message_debug(
               0x1Fu,
               0x48u,
               72,
               (unsigned __int16 *)&v16,
               0x76Du,
               (__int64)"cm_fw_ho_fail_req");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Failed to post HO fail indication on vdev_id %d",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "cm_fw_ho_fail_req",
        a2);
      result = _qdf_mem_free(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
