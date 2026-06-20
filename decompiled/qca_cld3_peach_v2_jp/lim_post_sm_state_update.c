__int64 __fastcall lim_post_sm_state_update(__int64 a1, int a2, const void *a3, char a4)
{
  __int64 v8; // x0
  __int64 v9; // x20
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v28; // [xsp+8h] [xbp-38h] BYREF
  __int64 v29; // [xsp+10h] [xbp-30h]
  __int64 v30; // [xsp+18h] [xbp-28h]
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  v28 = 4195;
  v8 = _qdf_mem_malloc(0x10u, "lim_post_sm_state_update", 4221);
  if ( v8 )
  {
    v9 = v8;
    *(_DWORD *)v8 = a2;
    *(_BYTE *)(v8 + 8) = 1;
    *(_BYTE *)(v8 + 15) = a4;
    qdf_mem_copy((void *)(v8 + 9), a3, 6u);
    v29 = v9;
    HIDWORD(v28) = 0;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sending WMA_SET_MIMOPS_REQ",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "lim_post_sm_state_update");
    mac_trace_msg_tx(a1, 0xFFu, 4195);
    v18 = wma_post_ctrl_msg(a1, &v28);
    if ( v18 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Posting WMA_SET_MIMOPS_REQ to HAL failed! Reason: %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "lim_post_sm_state_update",
        v18);
      _qdf_mem_free(v9);
    }
  }
  else
  {
    v18 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v18;
}
