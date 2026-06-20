__int64 __fastcall wlan_cm_handle_hw_mode_change_resp(__int64 a1, unsigned __int8 a2, unsigned int a3, int a4)
{
  __int64 v8; // x0
  __int64 v9; // x21
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x4
  unsigned int v20; // w20
  __int64 v21; // [xsp+8h] [xbp-38h] BYREF
  __int64 v22; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v23)(); // [xsp+18h] [xbp-28h]
  __int64 v24; // [xsp+20h] [xbp-20h]
  __int64 v25; // [xsp+28h] [xbp-18h]
  __int64 v26; // [xsp+30h] [xbp-10h]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26 = 0;
  v23 = nullptr;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v8 = _qdf_mem_malloc(0x18u, "wlan_cm_handle_hw_mode_change_resp", 1962);
  if ( v8 )
  {
    *(_QWORD *)v8 = a1;
    *(_BYTE *)(v8 + 8) = a2;
    *(_DWORD *)(v8 + 12) = a3;
    *(_DWORD *)(v8 + 16) = a4;
    v9 = v8;
    v22 = v8;
    v23 = cm_handle_hw_mode_change_resp_cb;
    result = scheduler_post_message_debug(
               0x1Fu,
               0x49u,
               73,
               (unsigned __int16 *)&v21,
               0x7B8u,
               (__int64)"wlan_cm_handle_hw_mode_change_resp");
    if ( (_DWORD)result )
    {
      v19 = a2;
      v20 = result;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: Failed to post HW mode change rsp",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_cm_handle_hw_mode_change_resp",
        v19,
        a3);
      _qdf_mem_free(v9);
      result = v20;
    }
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
