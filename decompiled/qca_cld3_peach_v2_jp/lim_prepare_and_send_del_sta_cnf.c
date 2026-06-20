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
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int16 v30; // w2
  __int64 result; // x0
  _QWORD v32[8]; // [xsp+0h] [xbp-90h] BYREF
  __int64 v33; // [xsp+40h] [xbp-50h]
  __int64 v34; // [xsp+48h] [xbp-48h]
  __int64 v35; // [xsp+50h] [xbp-40h]
  __int64 v36; // [xsp+58h] [xbp-38h]
  __int64 v37; // [xsp+60h] [xbp-30h]
  __int64 v38; // [xsp+68h] [xbp-28h]
  __int64 v39; // [xsp+70h] [xbp-20h]
  __int64 v40; // [xsp+78h] [xbp-18h]
  unsigned int v41; // [xsp+80h] [xbp-10h] BYREF
  unsigned __int16 v42; // [xsp+84h] [xbp-Ch]
  __int64 v43; // [xsp+88h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v41 = 0;
  if ( a2 )
  {
    v15 = *(_WORD *)(a2 + 336);
    qdf_mem_copy(&v41, (const void *)(a2 + 338), 6u);
    v17 = *(_QWORD *)(a2 + 48);
    v18 = *(_DWORD *)(a4 + 88);
    v37 = *(_QWORD *)(a2 + 40);
    v38 = v17;
    v19 = *(_QWORD *)(a2 + 64);
    v39 = *(_QWORD *)(a2 + 56);
    v40 = v19;
    v20 = *(_QWORD *)(a2 + 16);
    v33 = *(_QWORD *)(a2 + 8);
    v34 = v20;
    v21 = *(_QWORD *)(a2 + 32);
    v35 = *(_QWORD *)(a2 + 24);
    v36 = v21;
    if ( v18 == 1 )
      lim_release_peer_idx(a1, *(unsigned __int16 *)(a2 + 336), a4);
    lim_delete_dph_hash_entry(a1, (unsigned __int8 *)(a2 + 338), *(unsigned __int16 *)(a2 + 336), a4);
    if ( *(_DWORD *)(a4 + 88) == 2 )
    {
      v30 = *(_WORD *)(a4 + 8);
      *(_DWORD *)(a4 + 72) = 1;
      qdf_trace(53, 0, v30, 1);
    }
    v32[4] = v37;
    v32[5] = v38;
    v32[6] = v39;
    v32[7] = v40;
    v32[0] = v33;
    v32[1] = v34;
    v32[2] = v35;
    v32[3] = v36;
    result = lim_send_del_sta_cnf(
               a1,
               v41 | ((unsigned __int64)v42 << 32),
               0,
               v15,
               (__int64)v32,
               a3,
               a4,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29);
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
