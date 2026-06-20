__int64 __fastcall cm_send_bss_peer_create_req(__int64 a1, int *a2, int *a3, char a4)
{
  __int64 result; // x0
  __int64 v9; // x0
  unsigned __int8 *v10; // x19
  int v11; // w9
  int v12; // w9
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  __int64 v22; // [xsp+8h] [xbp-38h] BYREF
  __int64 v23; // [xsp+10h] [xbp-30h]
  __int64 v24; // [xsp+18h] [xbp-28h]
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  result = 16;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
    qdf_mem_set(&v22, 0x30u, 0);
    v9 = _qdf_mem_malloc(0xEu, "cm_send_bss_peer_create_req", 1491);
    if ( v9 )
    {
      v10 = (unsigned __int8 *)v9;
      if ( a3 )
      {
        v11 = *a3;
        *(_WORD *)(v9 + 11) = *((_WORD *)a3 + 2);
        *(_DWORD *)(v9 + 7) = v11;
        *(_BYTE *)(v9 + 13) = a4 & 1;
      }
      *(_BYTE *)v9 = *(_BYTE *)(a1 + 168);
      v12 = *a2;
      *(_WORD *)(v9 + 5) = *((_WORD *)a2 + 2);
      *(_DWORD *)(v9 + 1) = v12;
      v23 = v9;
      LOWORD(v22) = 5291;
      result = scheduler_post_message_debug(
                 0x1Fu,
                 0x35u,
                 53,
                 (unsigned __int16 *)&v22,
                 0x5E1u,
                 (__int64)"cm_send_bss_peer_create_req");
      if ( (_DWORD)result )
      {
        v21 = result;
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d: post fail",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "cm_send_bss_peer_create_req",
          *v10);
        _qdf_mem_free((__int64)v10);
        result = v21;
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
