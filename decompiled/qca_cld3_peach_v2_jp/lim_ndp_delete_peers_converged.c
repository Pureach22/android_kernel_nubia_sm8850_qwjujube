__int64 __fastcall lim_ndp_delete_peers_converged(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v13; // x25
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  unsigned int *v24; // x21
  _WORD *v25; // x28
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  int v29; // w8
  __int64 session_by_vdev_id; // x0
  __int64 v31; // x27
  char *v32; // x21
  __int64 v33; // x26
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  __int16 v44; // w10
  const char *v45; // x2
  __int64 v46; // [xsp+0h] [xbp-30h]
  __int64 v47; // [xsp+8h] [xbp-28h]
  __int64 v48; // [xsp+10h] [xbp-20h]
  unsigned __int16 v49; // [xsp+18h] [xbp-18h]
  __int16 v50; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+28h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(53, (__int64)"lim_ndp_delete_peers_converged", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v13 = a2;
    v14 = result;
    v50 = 0;
    result = _qdf_mem_malloc(6LL * a2, "lim_ndp_delete_peers", 204);
    v48 = result;
    if ( result )
    {
      if ( a2 )
      {
        v23 = 0;
        v49 = 0;
        do
        {
          v24 = (unsigned int *)(a1 + 28 * v23);
          v25 = v24 + 1;
          if ( v24 == (unsigned int *)-4LL )
          {
            v28 = 0;
            v26 = 0;
            v27 = 0;
            v29 = 0;
          }
          else
          {
            v26 = *((unsigned __int8 *)v24 + 4);
            v27 = *((unsigned __int8 *)v24 + 5);
            v28 = *((unsigned __int8 *)v24 + 6);
            v29 = *((unsigned __int8 *)v24 + 9);
          }
          LODWORD(v47) = v24[3];
          LODWORD(v46) = v29;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: ndp_map[%d]: MAC: %02x:%02x:%02x:**:**:%02x num_active %d",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "lim_ndp_delete_peers",
            (unsigned int)v23,
            v26,
            v27,
            v28,
            v46,
            v47);
          if ( v24[3] )
            goto LABEL_6;
          session_by_vdev_id = pe_find_session_by_vdev_id(v14, *v24, v15, v16, v17, v18, v19, v20, v21, v22);
          if ( session_by_vdev_id && (v31 = session_by_vdev_id, *(_DWORD *)(session_by_vdev_id + 92) == 4) )
          {
            if ( v49 )
            {
              v32 = (char *)v48;
              v33 = v49;
              while ( (unsigned int)qdf_mem_cmp(v32, v25, 6u) )
              {
                --v33;
                v32 += 6;
                if ( !v33 )
                  goto LABEL_17;
              }
              goto LABEL_6;
            }
LABEL_17:
            v34 = dph_lookup_hash_entry(
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    v21,
                    v22,
                    v14,
                    (unsigned __int8 *)v25,
                    &v50,
                    v31 + 360);
            if ( !v34 )
            {
              v45 = "%s: Unknown NDI Peer";
LABEL_23:
              qdf_trace_msg(0x35u, 2u, v45, v35, v36, v37, v38, v39, v40, v41, v42, "lim_ndp_delete_peers");
              goto LABEL_6;
            }
            if ( *(_BYTE *)(v34 + 344) != 5 )
            {
              v45 = "%s: Non-NDI Peer ignored";
              goto LABEL_23;
            }
            lim_del_sta(v14, v34, 1, v31);
            v43 = v48 + 6LL * v49;
            v44 = v25[2];
            *(_DWORD *)v43 = *(_DWORD *)v25;
            *(_WORD *)(v43 + 4) = v44;
            ++v49;
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: PE session is NULL or non-NDI for sme session %d",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              "lim_ndp_delete_peers",
              *v24);
          }
LABEL_6:
          ++v23;
        }
        while ( v23 != v13 );
      }
      result = _qdf_mem_free(v48);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
