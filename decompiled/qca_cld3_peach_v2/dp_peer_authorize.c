__int64 __fastcall dp_peer_authorize(__int64 a1, int a2, unsigned __int8 *a3, int a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  __int64 v18; // x8
  unsigned int v19; // w9
  unsigned int v26; // w11
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  __int64 v32; // x24
  __int64 v33; // x10
  char v34; // w8
  __int64 v35; // x21
  __int64 v36; // x1
  unsigned int v37; // w8
  __int64 v38; // x0
  __int64 result; // x0
  unsigned int v41; // w9
  __int64 v42; // [xsp+10h] [xbp-30h] BYREF
  __int64 v43; // [xsp+18h] [xbp-28h]
  __int64 v44; // [xsp+20h] [xbp-20h]
  __int64 v45; // [xsp+28h] [xbp-18h]
  __int64 v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = dp_peer_find_hash_find(a1, (int)a3);
  if ( !v8 )
  {
    if ( a3 )
    {
      v27 = *a3;
      v28 = a3[1];
      v29 = a3[2];
      v30 = a3[5];
    }
    else
    {
      v29 = 0;
      v27 = 0;
      v28 = 0;
      v30 = 0;
    }
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: fail to find peer:%02x:%02x:%02x:**:**:%02x vdev_id: %u",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_peer_get_tgt_peer_hash_find",
      v27,
      v28,
      v29,
      v30,
      (unsigned __int8)a2);
    goto LABEL_39;
  }
  v17 = v8;
  if ( *(_DWORD *)(v8 + 408) == 1 )
  {
    v18 = *(_QWORD *)(v8 + 416);
    if ( v18 )
    {
      v19 = *(_DWORD *)(v18 + 40);
      while ( v19 )
      {
        _X13 = (unsigned int *)(v18 + 40);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v26 = __ldxr(_X13);
          if ( v26 != v19 )
            break;
          if ( !__stlxr(v19 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v26 == v19;
        v19 = v26;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v18 + 292);
          __asm { PRFM            #0x11, [X8] }
          do
            v41 = __ldxr(_X8);
          while ( __stxr(v41 + 1, _X8) );
          v32 = *(_QWORD *)(v8 + 416);
          dp_peer_unref_delete(v8, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
          v17 = v32;
          if ( !v32 )
            goto LABEL_39;
          goto LABEL_17;
        }
      }
      goto LABEL_63;
    }
  }
LABEL_17:
  v33 = *(_QWORD *)v17;
  v34 = *(_BYTE *)(v17 + 120) & 0xFD | (2 * (a4 != 0));
  *(_BYTE *)(v17 + 120) = v34;
  if ( v33 )
  {
    *(_BYTE *)(v33 + 10) = *(_BYTE *)(v33 + 10) & 0xFE | ((2 * (unsigned int)(a4 != 0)) >> 1);
    v34 = *(_BYTE *)(v17 + 120);
  }
  if ( (v34 & 2) == 0 )
    dp_peer_flush_frags(a1, a2, (int)a3);
  v35 = *(_QWORD *)(v17 + 416);
  if ( !v35 )
  {
LABEL_54:
    dp_peer_unref_delete(v17, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
    result = 0;
    goto LABEL_55;
  }
  v36 = *(_QWORD *)(v17 + 416);
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v42 = 0;
  dp_get_link_peers_ref_from_mld_peer(a1, v36, &v42);
  v37 = (unsigned __int8)v46;
  if ( !(_BYTE)v46 )
  {
    *(_BYTE *)(v35 + 120) |= 2u;
    goto LABEL_54;
  }
  v38 = v42;
  if ( (*((_BYTE *)&qword_74 + v42 + 4) & 2) == 0 )
    goto LABEL_24;
  if ( (unsigned __int8)v46 == 1 )
  {
LABEL_42:
    *(_BYTE *)(v35 + 120) |= 2u;
    if ( v38 )
    {
      dp_peer_unref_delete(v38, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
      v37 = (unsigned __int8)v46;
    }
    v42 = 0;
    if ( v37 < 2 )
      goto LABEL_54;
    if ( v43 )
    {
      dp_peer_unref_delete(v43, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
      v37 = (unsigned __int8)v46;
    }
    v43 = 0;
    if ( v37 < 3 )
      goto LABEL_54;
    if ( v44 )
    {
      dp_peer_unref_delete(v44, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
      v37 = (unsigned __int8)v46;
    }
    v44 = 0;
    if ( v37 < 4 )
      goto LABEL_54;
    if ( v45 )
    {
      dp_peer_unref_delete(v45, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
      v37 = (unsigned __int8)v46;
    }
    v45 = 0;
    if ( v37 <= 4 )
      goto LABEL_54;
    goto LABEL_62;
  }
  if ( (*(_BYTE *)(v43 + 120) & 2) != 0 )
  {
    if ( (unsigned __int8)v46 == 2 )
      goto LABEL_42;
    if ( (*(_BYTE *)(v44 + 120) & 2) != 0 )
    {
      if ( (unsigned __int8)v46 == 3 )
        goto LABEL_42;
      if ( (*(_BYTE *)(v45 + 120) & 2) != 0 )
      {
        if ( (unsigned __int8)v46 != 4 )
          goto LABEL_62;
        goto LABEL_42;
      }
    }
  }
LABEL_24:
  if ( v42 )
  {
    dp_peer_unref_delete(v42, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
    v37 = (unsigned __int8)v46;
  }
  v42 = 0;
  if ( v37 < 2 )
    goto LABEL_36;
  if ( v43 )
  {
    dp_peer_unref_delete(v43, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
    v37 = (unsigned __int8)v46;
  }
  v43 = 0;
  if ( v37 < 3 )
    goto LABEL_36;
  if ( v44 )
  {
    dp_peer_unref_delete(v44, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
    v37 = (unsigned __int8)v46;
  }
  v44 = 0;
  if ( v37 < 4 )
    goto LABEL_36;
  if ( v45 )
  {
    dp_peer_unref_delete(v45, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
    v37 = (unsigned __int8)v46;
  }
  v45 = 0;
  if ( v37 <= 4 )
  {
LABEL_36:
    *(_BYTE *)(v35 + 120) &= ~2u;
    goto LABEL_54;
  }
LABEL_62:
  __break(0x5512u);
LABEL_63:
  dp_peer_unref_delete(v17, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
LABEL_39:
  qdf_trace_msg(0x89u, 8u, "%s: %pK: Peer is NULL!", v9, v10, v11, v12, v13, v14, v15, v16, "dp_peer_authorize", a1);
  result = 16;
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
