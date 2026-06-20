__int64 __fastcall sme_modify_nss_chains_tgt_cfg(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x25
  __int64 v13; // x21
  int v15; // w8
  unsigned __int8 v16; // w10
  _DWORD *v17; // x9
  unsigned int v18; // w22
  unsigned __int8 v19; // w11
  unsigned int v20; // w23
  unsigned int v21; // w9
  unsigned int v22; // w24
  unsigned int v23; // w8
  unsigned int v24; // w25
  int v25; // w8
  __int64 v26; // x10
  int v27; // w13
  __int64 v28; // x9
  int v29; // w10

  v11 = *(_QWORD *)(result + 8);
  v13 = result;
  if ( a2 < 0x11 && ((0x189AFu >> a2) & 1) != 0 )
  {
    v15 = dword_B09170[a2];
  }
  else
  {
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: Device mode %d invalid",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "sme_get_nss_chain_shift",
               a2);
    LOBYTE(v15) = 0;
  }
  if ( a3 >= 2 )
  {
    __break(0x5512u);
    return ((__int64 (*)(void))sme_modify_nss_in_mlme_cfg)();
  }
  else
  {
    v16 = *(_BYTE *)(v13 + 7);
    v17 = (_DWORD *)(v11 + 4LL * a3);
    if ( a3 != 1 )
      v16 = 2;
    if ( !a3 )
      v16 = *(_BYTE *)(v13 + 5);
    if ( ((v17[867] >> v15) & 7u) >= v16 )
      v18 = v16;
    else
      v18 = (v17[867] >> v15) & 7;
    if ( v18 )
    {
      if ( a3 == 1 )
        v19 = *(_BYTE *)(v13 + 6);
      else
        v19 = 2;
      if ( !a3 )
        v19 = *(_BYTE *)(v13 + 4);
      if ( ((v17[865] >> v15) & 7u) >= v19 )
        v20 = v19;
      else
        v20 = (v17[865] >> v15) & 7;
      if ( v20 )
      {
        v21 = (v17[863] >> v15) & 7;
        v22 = v21 >= v16 ? v16 : v21;
        if ( v22 )
        {
          v23 = (*(_DWORD *)(v11 + 3444 + 4LL * a3) >> v15) & 7;
          v24 = v23 >= v19 ? v19 : v23;
          if ( v24 )
          {
            if ( a2 < 0x11 && ((0x189AFu >> a2) & 1) != 0 )
            {
              v25 = dword_B09170[a2];
            }
            else
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: Device mode %d invalid",
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                "sme_get_nss_chain_shift",
                a2);
              LOBYTE(v25) = 0;
            }
            v26 = 4LL * a3;
            *(_DWORD *)(*(_QWORD *)(v13 + 8) + v26 + 3452) &= ~(7 << v25);
            if ( v22 >= 2 )
              v27 = 2;
            else
              v27 = v22;
            *(_DWORD *)(*(_QWORD *)(v13 + 8) + v26 + 3452) |= v27 << v25;
            *(_DWORD *)(*(_QWORD *)(v13 + 8) + v26 + 3444) &= ~(7 << v25);
            v28 = *(_QWORD *)(v13 + 8) + v26;
            if ( v24 >= 2 )
              v29 = 2;
            else
              v29 = v24;
            *(_DWORD *)(v28 + 3444) |= v29 << v25;
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: rx chains %d tx chains %d changed for vdev mode %d for band %d",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "sme_modify_chains_in_mlme_cfg",
              v22,
              v24,
              a2,
              a3);
            return sme_modify_nss_in_mlme_cfg(v13, v18, v20, a2, a3);
          }
        }
      }
    }
  }
  return result;
}
