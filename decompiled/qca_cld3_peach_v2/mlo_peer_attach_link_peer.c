__int64 __fastcall mlo_peer_attach_link_peer(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v24; // x20
  unsigned int v25; // w21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w11
  __int64 v35; // x9
  char v36; // w10
  int v37; // w10
  unsigned int v44; // w10

  if ( a2 )
  {
    v3 = *(_QWORD *)(a2 + 96);
    if ( v3 )
    {
      qdf_mutex_acquire(a1 + 120);
      if ( *(_DWORD *)(a1 + 200) )
      {
        qdf_mutex_release(a1 + 120);
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML Peer %02x:%02x:%02x:**:**:%02x is not in created state (state %d)",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "mlo_peer_attach_link_peer",
          *(unsigned __int8 *)(a1 + 104),
          *(unsigned __int8 *)(a1 + 105),
          *(unsigned __int8 *)(a1 + 106),
          *(unsigned __int8 *)(a1 + 109),
          *(_DWORD *)(a1 + 200));
        return 1;
      }
      v24 = a1 + 16;
      if ( *(_QWORD *)(a1 + 16) )
      {
        v24 = a1 + 56;
        if ( *(_QWORD *)(a1 + 56) )
        {
          v25 = 1;
LABEL_19:
          qdf_mutex_release(a1 + 120);
          return v25;
        }
      }
      if ( (unsigned int)wlan_objmgr_peer_try_get_ref(a2, 0x5Au, v7, v8, v9, v10, v11, v12, v13, v14) )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML Peer %02x:%02x:%02x:**:**:%02x, link peer %02x:%02x:%02x:**:**:%02x is not in valid state",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "mlo_peer_attach_link_peer",
          *(unsigned __int8 *)(a1 + 104),
          *(unsigned __int8 *)(a1 + 105),
          *(unsigned __int8 *)(a1 + 106),
          *(unsigned __int8 *)(a1 + 109),
          *(unsigned __int8 *)(a2 + 48),
          *(unsigned __int8 *)(a2 + 49),
          *(unsigned __int8 *)(a2 + 50),
          *(unsigned __int8 *)(a2 + 53));
        v25 = 1;
        goto LABEL_19;
      }
      *(_QWORD *)v24 = a2;
      _X9 = (unsigned int *)(v3 + 228);
      __asm { PRFM            #0x11, [X9] }
      do
        v44 = __ldxr(_X9);
      while ( __stxr(v44 + 1, _X9) );
      v34 = *(_DWORD *)(a2 + 48);
      v35 = a3;
      *(_WORD *)(v24 + 12) = *(_WORD *)(a2 + 52);
      *(_DWORD *)(v24 + 8) = v34;
      v36 = *(_BYTE *)(v3 + 93);
      *(_BYTE *)(v24 + 16) = -1;
      *(_BYTE *)(v24 + 14) = v36;
      v37 = *(_DWORD *)(v3 + 16);
      if ( v37 == 1 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 1360) + 2232LL) + 200LL) )
          goto LABEL_18;
      }
      else if ( v37 || a1 && *(_QWORD *)(a1 + 16) == a2 )
      {
        goto LABEL_18;
      }
      mlo_peer_assign_primary_umac(a1, v24);
      v35 = a3;
LABEL_18:
      *(_QWORD *)(v24 + 24) = v35;
      v25 = 0;
      ++*(_BYTE *)(a1 + 96);
      goto LABEL_19;
    }
  }
  return 16;
}
