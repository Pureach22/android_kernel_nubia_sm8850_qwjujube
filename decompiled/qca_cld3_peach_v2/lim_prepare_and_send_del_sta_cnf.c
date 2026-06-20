__int64 __fastcall lim_prepare_and_send_del_sta_cnf(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int16 v15; // w22
  __int64 v17; // x9
  int v18; // w11
  __int64 v19; // x10
  __int64 v20; // x8
  __int64 v21; // x8
  char is_mlo_conn; // w0
  __int64 v23; // x1
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int16 v33; // w2
  _QWORD v34[8]; // [xsp+8h] [xbp-98h] BYREF
  __int64 v35; // [xsp+48h] [xbp-58h]
  __int64 v36; // [xsp+50h] [xbp-50h]
  __int64 v37; // [xsp+58h] [xbp-48h]
  __int64 v38; // [xsp+60h] [xbp-40h]
  __int64 v39; // [xsp+68h] [xbp-38h]
  __int64 v40; // [xsp+70h] [xbp-30h]
  __int64 v41; // [xsp+78h] [xbp-28h]
  __int64 v42; // [xsp+80h] [xbp-20h]
  unsigned int v43; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int16 v44; // [xsp+8Ch] [xbp-14h]
  unsigned int v45; // [xsp+90h] [xbp-10h] BYREF
  unsigned __int16 v46; // [xsp+94h] [xbp-Ch]
  __int64 v47; // [xsp+98h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v45 = 0;
  v44 = 0;
  v43 = 0;
  if ( a2 )
  {
    v15 = *(_WORD *)(a2 + 348);
    qdf_mem_copy(&v45, (const void *)(a2 + 350), 6u);
    qdf_mem_copy(&v43, (const void *)(a2 + 1080), 6u);
    v17 = *(_QWORD *)(a2 + 48);
    v18 = *(_DWORD *)(a4 + 88);
    v39 = *(_QWORD *)(a2 + 40);
    v40 = v17;
    v19 = *(_QWORD *)(a2 + 64);
    v41 = *(_QWORD *)(a2 + 56);
    v42 = v19;
    v20 = *(_QWORD *)(a2 + 16);
    v35 = *(_QWORD *)(a2 + 8);
    v36 = v20;
    v21 = *(_QWORD *)(a2 + 32);
    v37 = *(_QWORD *)(a2 + 24);
    v38 = v21;
    if ( v18 == 1 )
    {
      is_mlo_conn = lim_is_mlo_conn(a4, a2);
      v23 = *(unsigned __int16 *)(a2 + 348);
      if ( (is_mlo_conn & 1) != 0 )
        lim_release_mlo_conn_idx(a1, v23, a4, 0);
      else
        lim_release_peer_idx(a1, v23, a4);
    }
    lim_delete_dph_hash_entry(a1, (unsigned __int8 *)(a2 + 350), *(unsigned __int16 *)(a2 + 348), a4);
    if ( *(_DWORD *)(a4 + 88) == 2 )
    {
      v33 = *(_WORD *)(a4 + 8);
      *(_DWORD *)(a4 + 72) = 1;
      qdf_trace(53, 0, v33, 1);
    }
    v34[4] = v39;
    v34[5] = v40;
    v34[6] = v41;
    v34[7] = v42;
    v34[0] = v35;
    v34[1] = v36;
    v34[2] = v37;
    v34[3] = v38;
    result = lim_send_del_sta_cnf(
               a1,
               v45 | ((unsigned __int64)v46 << 32),
               v43 | ((unsigned __int64)v44 << 32),
               v15,
               (__int64)v34,
               a3,
               a4,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: sta is NULL",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "lim_prepare_and_send_del_sta_cnf");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
