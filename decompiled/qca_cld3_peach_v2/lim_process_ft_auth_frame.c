__int64 __fastcall lim_process_ft_auth_frame(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int16 *v11; // x19
  const void *v15; // x23
  unsigned int v16; // t1
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  int v21; // w8
  int v22; // w9
  unsigned __int16 *v23; // x26
  unsigned int v24; // w25
  __int64 result; // x0
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x24
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x24
  __int64 v54; // x5
  __int64 v55; // x6
  __int64 v56; // x7
  int v57; // w8
  __int64 v58; // x4
  __int64 v59; // x5
  __int64 v60; // x6
  __int64 v61; // x7
  int v62; // w26
  char v63; // w9
  __int64 v64; // [xsp+0h] [xbp-10h]

  v11 = *((unsigned __int16 **)a2 + 2);
  v16 = *v11;
  v15 = v11 + 5;
  v17 = (v16 >> 2) & 3;
  v18 = (unsigned __int8)v16 >> 4;
  if ( v11 == (unsigned __int16 *)-10LL )
  {
    v21 = 0;
    v19 = 0;
    v20 = 0;
    v22 = 0;
  }
  else
  {
    v19 = *((unsigned __int8 *)v11 + 10);
    v20 = *((unsigned __int8 *)v11 + 11);
    v21 = *((unsigned __int8 *)v11 + 12);
    v22 = *((unsigned __int8 *)v11 + 15);
  }
  v23 = *((unsigned __int16 **)a2 + 3);
  v24 = a2[10];
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: FT Auth RX type %d subtype %d from %02x:%02x:%02x:**:**:%02x",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_process_ft_auth_frame",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( *(_DWORD *)(a3 + 88) == 1 )
  {
    v26 = lim_search_pre_auth_list(a1, v15);
    if ( v26 )
    {
      v35 = v26;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: STA Auth ctx have ininted",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "lim_process_ft_auth_frame");
      if ( *(_DWORD *)(v35 + 20) == 30 )
        return qdf_trace_msg(
                 0x35u,
                 3u,
                 "%s: previous Auth not completed, don't process this auth frame",
                 v36,
                 v37,
                 v38,
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 "lim_process_ft_auth_frame");
      lim_delete_pre_auth_node(a1, v15);
    }
    v44 = lim_acquire_free_pre_auth_node(a1, (unsigned int *)(a1 + 11408));
    if ( v44 )
    {
      v53 = v44;
      if ( v11 == (unsigned __int16 *)-10LL )
      {
        v56 = 0;
        v54 = 0;
        v55 = 0;
        v57 = 0;
      }
      else
      {
        v54 = *((unsigned __int8 *)v11 + 10);
        v55 = *((unsigned __int8 *)v11 + 11);
        v56 = *((unsigned __int8 *)v11 + 12);
        v57 = *((unsigned __int8 *)v11 + 15);
      }
      LODWORD(v64) = v57;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Alloc new data: %pK peer %02x:%02x:%02x:**:**:%02x",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "lim_process_ft_auth_frame",
        v44,
        v54,
        v55,
        v56,
        v64);
      v62 = *v23;
      qdf_mem_copy((void *)(v53 + 8), v15, 6u);
      v63 = *(_BYTE *)(v53 + 278);
      *(_DWORD *)(v53 + 16) = v62;
      *(_DWORD *)(v53 + 20) = 30;
      *(_BYTE *)(v53 + 278) = v63 & 0xFC;
      *(_WORD *)(v53 + 544) = v11[11] >> 4;
      *(_QWORD *)(v53 + 552) = qdf_mc_timer_get_system_ticks();
      lim_add_pre_auth_node(a1, v53);
      return lim_send_sme_mgmt_frame_ind(
               a1,
               *(unsigned __int8 *)v11 >> 4,
               v11,
               v24 + 24,
               *(unsigned __int8 *)(a3 + 10),
               *a2,
               a2[2],
               2);
    }
    else
    {
      if ( v11 == (unsigned __int16 *)-10LL )
      {
        v60 = 0;
        v58 = 0;
        v59 = 0;
        v61 = 0;
      }
      else
      {
        v58 = *((unsigned __int8 *)v11 + 10);
        v59 = *((unsigned __int8 *)v11 + 11);
        v60 = *((unsigned __int8 *)v11 + 12);
        v61 = *((unsigned __int8 *)v11 + 15);
      }
      return qdf_trace_msg(
               0x35u,
               3u,
               "%s: Max pre-auth nodes reached %02x:%02x:%02x:**:**:%02x",
               v45,
               v46,
               v47,
               v48,
               v49,
               v50,
               v51,
               v52,
               "lim_process_ft_auth_frame",
               v58,
               v59,
               v60,
               v61);
    }
  }
  return result;
}
