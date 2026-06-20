__int64 __fastcall csr_send_channel_change_req(__int64 a1, const void *a2)
{
  void *v3; // x0
  __int64 v4; // x19
  unsigned int v5; // w20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v15; // [xsp+8h] [xbp-38h] BYREF
  __int64 v16; // [xsp+10h] [xbp-30h]
  __int64 v17; // [xsp+18h] [xbp-28h]
  __int64 v18; // [xsp+20h] [xbp-20h]
  __int64 v19; // [xsp+28h] [xbp-18h]
  __int64 v20; // [xsp+30h] [xbp-10h]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v3 = (void *)_qdf_mem_malloc(0x40u, "csr_send_channel_change_req", 7124);
  if ( v3 )
  {
    v4 = (__int64)v3;
    qdf_mem_copy(v3, a2, 0x40u);
    LODWORD(v15) = 5204;
    v16 = v4;
    v5 = scheduler_post_message_debug(
           0x34u,
           0x35u,
           53,
           (unsigned __int16 *)&v15,
           0x1BE0u,
           (__int64)"csr_send_channel_change_req");
    if ( v5 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed to send channel change request with status : %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "csr_send_channel_change_req",
        v5);
      _qdf_mem_free(v4);
    }
  }
  else
  {
    v5 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
