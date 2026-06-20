__int64 __fastcall cm_send_bss_peer_create_req(__int64 a1, int *a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  unsigned __int8 *v6; // x19
  int v7; // w9
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w20
  __int64 v17; // [xsp+8h] [xbp-38h] BYREF
  __int64 v18; // [xsp+10h] [xbp-30h]
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  result = 16;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v21 = 0;
    v22 = 0;
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    qdf_mem_set(&v17, 0x30u, 0);
    v5 = _qdf_mem_malloc(7u, "cm_send_bss_peer_create_req", 1491);
    if ( v5 )
    {
      v6 = (unsigned __int8 *)v5;
      *(_BYTE *)v5 = *(_BYTE *)(a1 + 104);
      v7 = *a2;
      *(_WORD *)(v5 + 5) = *((_WORD *)a2 + 2);
      *(_DWORD *)(v5 + 1) = v7;
      v18 = v5;
      LOWORD(v17) = 5291;
      result = scheduler_post_message_debug(
                 0x1Fu,
                 0x35u,
                 53,
                 (unsigned __int16 *)&v17,
                 0x5E1u,
                 (__int64)"cm_send_bss_peer_create_req");
      if ( (_DWORD)result )
      {
        v16 = result;
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d: post fail",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "cm_send_bss_peer_create_req",
          *v6);
        _qdf_mem_free((__int64)v6);
        result = v16;
      }
    }
    else
    {
      result = 2;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
