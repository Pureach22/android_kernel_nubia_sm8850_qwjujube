__int64 __fastcall target_if_peer_rx_reorder_queue_setup(
        __int64 a1,
        char a2,
        char a3,
        const void *a4,
        __int64 a5,
        char a6,
        __int16 a7,
        char a8,
        __int16 a9)
{
  __int64 v17; // x0
  __int64 v18; // x19
  __int64 result; // x0
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
  v17 = _qdf_mem_malloc(0x20u, "target_if_peer_rx_reorder_queue_setup", 231);
  if ( v17 )
  {
    v18 = v17;
    *(_QWORD *)v17 = a1;
    *(_BYTE *)(v17 + 8) = a3;
    *(_BYTE *)(v17 + 9) = a2;
    *(_QWORD *)(v17 + 16) = a5;
    *(_BYTE *)(v17 + 24) = a6;
    *(_WORD *)(v17 + 26) = a7;
    *(_BYTE *)(v17 + 28) = a8;
    *(_WORD *)(v17 + 30) = a9;
    qdf_mem_copy((void *)(v17 + 10), a4, 6u);
    v22 = v18;
    v23 = target_if_rx_reorder_queue_setup;
    result = scheduler_post_message_debug(
               0x49u,
               0x49u,
               73,
               (unsigned __int16 *)&v21,
               0xF9u,
               (__int64)"target_if_peer_rx_reorder_queue_setup");
    if ( (_DWORD)result )
    {
      v20 = result;
      _qdf_mem_free(v18);
      result = v20;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
