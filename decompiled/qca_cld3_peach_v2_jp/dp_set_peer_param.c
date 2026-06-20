__int64 __fastcall dp_set_peer_param(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3, int a4, unsigned __int8 *a5)
{
  _QWORD *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  unsigned int v20; // w22
  _QWORD *v21; // x19
  char v22; // w8
  _QWORD *v23; // x21
  int v24; // w22
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  _QWORD *v47; // x24
  __int64 v48; // x4
  __int64 v49; // x5
  __int64 v50; // x6
  __int64 v51; // x7
  __int64 v52; // x4
  __int64 v53; // x5
  __int64 v54; // x6
  __int64 v55; // x7
  char v56; // w8

  v10 = (_QWORD *)dp_peer_find_hash_find(a1, (int)a3);
  if ( v10 )
  {
    v19 = *v10;
    if ( *v10 )
    {
      v20 = 0;
      if ( a4 > 4 )
      {
        if ( a4 == 5 )
        {
          v23 = v10;
          v24 = *(_DWORD *)a5;
          v25 = dp_peer_find_hash_find(a1, (int)a3);
          if ( v25 )
          {
            v34 = v25;
            *(_DWORD *)(v25 + 404) = v24;
            dp_peer_unref_delete(v25, 7u, v26, v27, v28, v29, v30, v31, v32, v33);
            if ( a3 )
            {
              v43 = *a3;
              v44 = a3[1];
              v45 = a3[2];
              v46 = a3[5];
            }
            else
            {
              v45 = 0;
              v43 = 0;
              v44 = 0;
              v46 = 0;
            }
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: Peer %02x:%02x:%02x:**:**:%02x vdev_id %u, frequency %u",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "dp_set_peer_freq",
              v43,
              v44,
              v45,
              v46,
              a2,
              *(_DWORD *)(v34 + 404));
            v20 = 0;
          }
          else
          {
            if ( a3 )
            {
              v52 = *a3;
              v53 = a3[1];
              v54 = a3[2];
              v55 = a3[5];
            }
            else
            {
              v54 = 0;
              v52 = 0;
              v53 = 0;
              v55 = 0;
            }
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: peer NULL,MAC %02x:%02x:%02x:**:**:%02x, vdev_id %u",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "dp_set_peer_freq",
              v52,
              v53,
              v54,
              v55,
              a2);
            v20 = 16;
          }
          v10 = v23;
          goto LABEL_36;
        }
        if ( a4 != 6 )
        {
          if ( a4 == 9 )
          {
            v21 = v10;
            dp_peer_set_bw(a1, v19, *(unsigned int *)a5);
            v10 = v21;
            v20 = 0;
          }
          goto LABEL_36;
        }
        v20 = 0;
        v22 = *(_BYTE *)(v19 + 88) & 0xEF | (16 * *a5);
      }
      else
      {
        if ( a4 )
        {
          if ( a4 == 2 )
          {
            v47 = v10;
            if ( a3 )
            {
              v48 = *a3;
              v49 = a3[1];
              v50 = a3[2];
              v51 = a3[5];
            }
            else
            {
              v50 = 0;
              v48 = 0;
              v49 = 0;
              v51 = 0;
            }
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: Peer %02x:%02x:%02x:**:**:%02x vdev_id %d, isolation %d",
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              "dp_set_peer_param",
              v48,
              v49,
              v50,
              v51,
              a2,
              *a5);
            if ( *(_WORD *)(v19 + 168) )
            {
              v20 = 0;
              v10 = v47;
              if ( *a5 )
                v56 = 4;
              else
                v56 = 0;
              *(_BYTE *)(v19 + 88) = *(_BYTE *)(v19 + 88) & 0xFB | v56;
            }
            else
            {
              v20 = 0;
              v10 = v47;
            }
          }
          else if ( a4 == 3 )
          {
            v20 = 0;
            *(_BYTE *)(v19 + 10) = *(_BYTE *)(v19 + 10) & 0xFD | (2 * *a5);
          }
          goto LABEL_36;
        }
        v20 = 0;
        v22 = *(_BYTE *)(v19 + 88) & 0xFE | *a5;
      }
      *(_BYTE *)(v19 + 88) = v22;
    }
    else
    {
      v20 = 16;
    }
LABEL_36:
    dp_peer_unref_delete((__int64)v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
    return v20;
  }
  return 16;
}
