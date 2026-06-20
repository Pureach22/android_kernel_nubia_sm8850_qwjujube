__int64 __fastcall wlan_mlo_peer_set_aid(__int64 a1, char a2, unsigned __int8 a3, unsigned __int16 a4)
{
  unsigned __int8 v8; // w24
  __int64 mlo_ctx; // x20
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x6
  __int64 v13; // x14
  unsigned __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  __int64 v24; // x11
  unsigned __int64 v25; // x10
  __int64 v26; // x9
  unsigned int v27; // w21
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x12
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned __int64 v45; // x14
  __int64 v46; // x8
  unsigned __int64 v47; // x13
  _QWORD *v48; // x8

  v8 = a2 ^ 1;
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  result = 16;
  if ( ((a3 == 0xFF) & v8) == 0 && mlo_ctx )
  {
    v11 = qdf_mutex_acquire(mlo_ctx + 64);
    v14 = (a4 & 0x3FFFu) - 1;
    if ( ((*(_QWORD *)(a1 + ((v14 >> 3) & 0x1FFFFFF8)) >> ((unsigned __int8)a4 - 1)) & 1) != 0 )
    {
      qdf_mutex_release(mlo_ctx + 64);
      v23 = "%s: Assoc id %d is not available on ml aid mgr";
LABEL_5:
      qdf_trace_msg(0x8Fu, 2u, v23, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_mlo_peer_set_aid", a4);
      return 16;
    }
    if ( (a2 & 1) != 0 )
    {
      if ( *(unsigned __int16 *)(a1 + 256) <= (unsigned int)a4 && *(unsigned __int16 *)(a1 + 258) > (unsigned int)a4 )
      {
        v24 = *(_QWORD *)(a1 + 264);
        v25 = v14 >> 6;
        v26 = 1LL << ((unsigned __int8)a4 - 1);
        if ( v24 && (*(_QWORD *)(v24 + 8 * v25) & v26) != 0 )
        {
          v27 = 0;
LABEL_23:
          qdf_mutex_release(mlo_ctx + 64);
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Assoc id %d is not available on link vdev %d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "wlan_mlo_peer_set_aid",
            a4,
            v27);
          return 16;
        }
        v36 = *(_QWORD *)(a1 + 272);
        if ( v36 && (*(_QWORD *)(v36 + 8 * v25) & v26) != 0 )
        {
          v27 = 1;
          goto LABEL_23;
        }
        v45 = (unsigned __int16)v14;
        v46 = 1LL << v14;
        v47 = v45 >> 6;
        if ( v24 )
        {
          *(_QWORD *)(v24 + 8 * v47) |= v46;
          v36 = *(_QWORD *)(a1 + 272);
        }
        if ( v36 )
          *(_QWORD *)(v36 + 8 * v47) |= v46;
        v48 = (_QWORD *)(a1 + 8 * v25);
        goto LABEL_30;
      }
    }
    else
    {
      if ( a3 > 1u )
      {
        __break(0x5512u);
        return mlme_free_aid(v11, v13 | __ROR8__(v12, 63));
      }
      a1 = *(_QWORD *)(a1 + 8LL * a3 + 264);
      if ( !a1 )
      {
        qdf_mutex_release(mlo_ctx + 64);
        return 16;
      }
      if ( *(unsigned __int16 *)(a1 + 256) <= (unsigned int)a4 && *(unsigned __int16 *)(a1 + 258) > (unsigned int)a4 )
      {
        if ( ((*(_QWORD *)(a1 + (((unsigned __int64)((a4 & 0x3FFFu) - 1) >> 3) & 0x1FFFFFF8)) >> ((unsigned __int8)a4 - 1))
            & 1) != 0 )
        {
          qdf_mutex_release(mlo_ctx + 64);
          v23 = "%s: Assoc id %d is not available on vdev aid mgr";
          goto LABEL_5;
        }
        v26 = 1LL << ((unsigned __int8)a4 - 1);
        v48 = (_QWORD *)(a1 + ((v14 >> 3) & 0x1FFFFFF8));
LABEL_30:
        *v48 |= v26;
        qdf_mutex_release(mlo_ctx + 64);
        return 0;
      }
    }
    qdf_mutex_release(mlo_ctx + 64);
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Assoc id %d is not in bounds, start aid %d, max aid %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_mlo_peer_set_aid",
      a4,
      *(unsigned __int16 *)(a1 + 256),
      *(unsigned __int16 *)(a1 + 258));
    return 16;
  }
  return result;
}
