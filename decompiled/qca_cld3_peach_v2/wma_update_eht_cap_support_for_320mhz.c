__int64 __fastcall wma_update_eht_cap_support_for_320mhz(
        _DWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  unsigned __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x11
  unsigned __int64 v15; // x9
  int v16; // w10
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x11
  __int64 v19; // x5
  unsigned int v20; // w10
  __int64 v21; // x11
  unsigned __int64 v22; // x11
  unsigned int v23; // w10
  __int64 v24; // x11
  unsigned __int64 v25; // x11
  unsigned int v26; // w10
  __int64 v27; // x11
  unsigned __int64 v28; // x11
  unsigned int v29; // w10
  __int64 v30; // x11
  unsigned __int64 v31; // x11
  unsigned int v32; // w10
  __int64 v33; // x11
  unsigned __int64 v34; // x11
  unsigned int v35; // w10
  __int64 v36; // x11
  unsigned __int64 v37; // x11
  bool v38; // zf
  __int64 v39; // x10
  unsigned __int64 v40; // x9

  v12 = *(_QWORD *)(a2 + 1);
  v13 = 0x20000;
  v14 = (v12 >> 17) & 1;
  v15 = v12 & 0xFFFFFFFFFFFDFFFFLL;
  v16 = v14 | ((a1[793] & 2u) >> 1);
  if ( !v16 )
    v13 = 0;
  *(_QWORD *)(a2 + 1) = v13 | v15;
  v17 = *(_QWORD *)(a2 + 9);
  v18 = (unsigned int)a1[794];
  v19 = ((unsigned int)v17 >> 2) & 0x1F;
  if ( ((a1[794] >> 14) & 0x1Fu) > (unsigned int)v19 )
  {
    v19 = ((unsigned int)v18 >> 14) & 0x1F;
    v17 = v17 & 0xFFFFFFFFFFFFFF83LL | (4 * ((v18 >> 14) & 0x1F));
    *(_QWORD *)(a2 + 9) = v17;
  }
  v20 = v16 | ((a1[839] & 2u) >> 1);
  v21 = 0x20000;
  if ( !v20 )
    v21 = 0;
  *(_QWORD *)(a2 + 1) = v21 | v15;
  v22 = (unsigned int)a1[840];
  if ( ((a1[840] >> 14) & 0x1Fu) > (unsigned int)v19 )
  {
    v19 = ((unsigned int)v22 >> 14) & 0x1F;
    v17 = v17 & 0xFFFFFFFFFFFFFF83LL | (4 * ((v22 >> 14) & 0x1F));
    *(_QWORD *)(a2 + 9) = v17;
  }
  v23 = v20 | ((a1[885] & 2u) >> 1);
  v24 = 0x20000;
  if ( !v23 )
    v24 = 0;
  *(_QWORD *)(a2 + 1) = v24 | v15;
  v25 = (unsigned int)a1[886];
  if ( ((a1[886] >> 14) & 0x1Fu) > (unsigned int)v19 )
  {
    v19 = ((unsigned int)v25 >> 14) & 0x1F;
    v17 = v17 & 0xFFFFFFFFFFFFFF83LL | (4 * ((v25 >> 14) & 0x1F));
    *(_QWORD *)(a2 + 9) = v17;
  }
  v26 = v23 | ((a1[931] & 2u) >> 1);
  v27 = 0x20000;
  if ( !v26 )
    v27 = 0;
  *(_QWORD *)(a2 + 1) = v27 | v15;
  v28 = (unsigned int)a1[932];
  if ( ((a1[932] >> 14) & 0x1Fu) > (unsigned int)v19 )
  {
    v19 = ((unsigned int)v28 >> 14) & 0x1F;
    v17 = v17 & 0xFFFFFFFFFFFFFF83LL | (4 * ((v28 >> 14) & 0x1F));
    *(_QWORD *)(a2 + 9) = v17;
  }
  v29 = v26 | ((a1[977] & 2u) >> 1);
  v30 = 0x20000;
  if ( !v29 )
    v30 = 0;
  *(_QWORD *)(a2 + 1) = v30 | v15;
  v31 = (unsigned int)a1[978];
  if ( ((a1[978] >> 14) & 0x1Fu) > (unsigned int)v19 )
  {
    v19 = ((unsigned int)v31 >> 14) & 0x1F;
    v17 = v17 & 0xFFFFFFFFFFFFFF83LL | (4 * ((v31 >> 14) & 0x1F));
    *(_QWORD *)(a2 + 9) = v17;
  }
  v32 = v29 | ((a1[1023] & 2u) >> 1);
  v33 = 0x20000;
  if ( !v32 )
    v33 = 0;
  *(_QWORD *)(a2 + 1) = v33 | v15;
  v34 = (unsigned int)a1[1024];
  if ( ((a1[1024] >> 14) & 0x1Fu) > (unsigned int)v19 )
  {
    v19 = ((unsigned int)v34 >> 14) & 0x1F;
    v17 = v17 & 0xFFFFFFFFFFFFFF83LL | (4 * ((v34 >> 14) & 0x1F));
    *(_QWORD *)(a2 + 9) = v17;
  }
  v35 = v32 | ((a1[1069] & 2u) >> 1);
  v36 = 0x20000;
  if ( !v35 )
    v36 = 0;
  *(_QWORD *)(a2 + 1) = v36 | v15;
  v37 = (unsigned int)a1[1070];
  if ( ((a1[1070] >> 14) & 0x1Fu) > (unsigned int)v19 )
  {
    v19 = ((unsigned int)v37 >> 14) & 0x1F;
    v17 = v17 & 0xFFFFFFFFFFFFFF83LL | (4 * ((v37 >> 14) & 0x1F));
    *(_QWORD *)(a2 + 9) = v17;
  }
  v38 = (v35 | ((a1[1115] & 2u) >> 1)) == 0;
  v39 = 0x20000;
  if ( v38 )
    v39 = 0;
  *(_QWORD *)(a2 + 1) = v39 | v15;
  v40 = (unsigned int)a1[1116];
  if ( ((a1[1116] >> 14) & 0x1Fu) > (unsigned int)v19 )
  {
    v19 = ((unsigned int)v40 >> 14) & 0x1F;
    *(_QWORD *)(a2 + 9) = v17 & 0xFFFFFFFFFFFFFF83LL | (4 * ((v40 >> 14) & 0x1F));
  }
  return qdf_trace_msg(
           0x36u,
           8u,
           "%s: Support for 320MHz 0x%01x, max_num_eht_ltf %d",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "wma_update_eht_cap_support_for_320mhz",
           (unsigned int)v39 >> 17,
           v19,
           v10,
           v11);
}
