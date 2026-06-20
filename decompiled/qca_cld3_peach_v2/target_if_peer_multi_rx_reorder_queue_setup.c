__int64 __fastcall target_if_peer_multi_rx_reorder_queue_setup(__int64 a1, char a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  char v8; // w8
  char v9; // w8
  __int64 v10; // x9
  __int64 v11; // x12
  __int64 result; // x0
  unsigned int v13; // w20
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  __int64 v15; // [xsp+10h] [xbp-30h]
  void *v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = nullptr;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v6 = _qdf_mem_malloc(0x128u, "target_if_peer_multi_rx_reorder_queue_setup", 267);
  if ( v6 )
  {
    *(_QWORD *)(v6 + 280) = a1;
    v7 = v6;
    v8 = *(_BYTE *)(a3 + 286);
    *(_BYTE *)(v6 + 289) = a2;
    *(_BYTE *)(v6 + 288) = v8;
    *(_DWORD *)(v6 + 292) = *(_DWORD *)(a3 + 280);
    *(_BYTE *)(v6 + 290) = *(_BYTE *)(a3 + 284);
    qdf_mem_copy((void *)(v6 + 272), *(const void **)(a3 + 272), 6u);
    v9 = 0;
    v10 = -272;
    do
    {
      if ( (((unsigned __int64)*(unsigned int *)(a3 + 280) >> v9) & 1) != 0 )
      {
        v11 = v7 + v10;
        *(_QWORD *)(v11 + 272) = *(_QWORD *)(a3 + v10 + 272);
        *(_WORD *)(v11 + 280) = *(_WORD *)(a3 + v10 + 280);
        *(_BYTE *)(v11 + 284) = *(_BYTE *)(a3 + v10 + 284);
        *(_WORD *)(v11 + 282) = *(_WORD *)(a3 + v10 + 282);
      }
      v10 += 16;
      ++v9;
    }
    while ( v10 );
    v15 = v7;
    v16 = &target_if_multi_rx_reorder_queue_setup;
    result = scheduler_post_message_debug(
               0x49u,
               0x49u,
               73,
               (unsigned __int16 *)&v14,
               0x128u,
               (__int64)"target_if_peer_multi_rx_reorder_queue_setup");
    if ( (_DWORD)result )
    {
      v13 = result;
      _qdf_mem_free(v7);
      result = v13;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
