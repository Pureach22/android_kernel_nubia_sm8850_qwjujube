__int64 __fastcall sme_update_he_mcs(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x9
  int v14; // w8
  int v15; // w11
  unsigned __int8 v16; // w12
  const char *v17; // x2
  __int64 result; // x0
  int v19; // w10
  __int64 v20; // x4
  _WORD *v21; // x1
  void *v22; // x0
  unsigned __int16 v23; // w8
  unsigned __int16 v24; // w8
  int v25; // w9
  int v26; // w11
  __int16 v27; // w8
  int v28; // w13
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int16 v37; // w8
  int v38; // w9
  int v39; // w11
  __int16 v40; // w8
  int v41; // w13
  _WORD v42[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42[0] = -1;
  if ( (unsigned __int8)a2 > 5u || !(*(_QWORD *)(a1 + 17224) + 96LL * (unsigned __int8)a2) )
  {
    v17 = "%s: No session for id %d";
LABEL_6:
    qdf_trace_msg(0x34u, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_he_mcs");
    result = 4294967274LL;
    goto LABEL_7;
  }
  v13 = *(_QWORD *)(a1 + 8);
  v14 = *(unsigned __int16 *)(v13 + 1308);
  v15 = v14 & 3;
  if ( v15 == 3 )
  {
    v16 = 0;
  }
  else if ( (~v14 & 0xC) != 0 )
  {
    if ( (~v14 & 0x30) != 0 )
    {
      if ( (~v14 & 0xC0) != 0 )
      {
        if ( (~v14 & 0x300) != 0 )
        {
          if ( (~v14 & 0xC00) != 0 )
          {
            if ( (~v14 & 0x3000) != 0 )
            {
              if ( (~v14 & 0xC000) != 0 )
                v16 = 8;
              else
                v16 = 7;
            }
            else
            {
              v16 = 6;
            }
          }
          else
          {
            v16 = 5;
          }
        }
        else
        {
          v16 = 4;
        }
      }
      else
      {
        v16 = 3;
      }
    }
    else
    {
      v16 = 2;
    }
  }
  else
  {
    v16 = 1;
  }
  v19 = a3 & 3;
  if ( (v16 & 0xFE) != 0 )
    v20 = 2;
  else
    v20 = v16;
  if ( v19 == 3 )
  {
    v17 = "%s: Invalid HE MCS 0x%0x, can't disable 0-7 for 1ss";
    goto LABEL_6;
  }
  if ( a3 > 0xAu )
    goto LABEL_53;
  if ( ((1 << a3) & 7) != 0 )
  {
    if ( v15 == 3 )
    {
      v23 = -1;
    }
    else
    {
      v25 = 0;
      if ( (v16 & 0xFE) != 0 )
        v26 = 2;
      else
        v26 = v16;
      v23 = -1;
      do
      {
        --v26;
        v27 = v23 & ~(unsigned __int16)(3 << v25);
        v28 = v19 << v25;
        v25 += 2;
        v23 = v27 | v28;
      }
      while ( v26 );
    }
    v42[0] = v23;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: HE 80 nss: %d, mcs: 0x%0X",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_update_he_mcs",
      v20,
      v23);
    v37 = v42[0];
    *(_WORD *)(*(_QWORD *)(a1 + 8) + 1310LL) = v42[0];
    *(_WORD *)(*(_QWORD *)(a1 + 8) + 1308LL) = v37;
    *(_WORD *)(a1 + 21738) = v37;
    *(_WORD *)(a1 + 21736) = v37;
    *(_WORD *)(a1 + 21798) = v37;
    *(_WORD *)(a1 + 21796) = v37;
    goto LABEL_50;
  }
  if ( ((1 << a3) & 0x70) != 0 )
  {
    if ( v15 == 3 )
    {
      v24 = -1;
    }
    else
    {
      v38 = 0;
      if ( (v16 & 0xFE) != 0 )
        v39 = 2;
      else
        v39 = v16;
      v24 = -1;
      do
      {
        --v39;
        v40 = v24 & ~(unsigned __int16)(3 << v38);
        v41 = v19 << v38;
        v38 += 2;
        v24 = v40 | v41;
      }
      while ( v39 );
    }
    v42[0] = v24;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: HE 160 nss: %d, mcs: 0x%0X",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_update_he_mcs",
      v20,
      v24);
    qdf_mem_copy((void *)(*(_QWORD *)(a1 + 8) + 1314LL), v42, 2u);
    qdf_mem_copy((void *)(*(_QWORD *)(a1 + 8) + 1312LL), v42, 2u);
    qdf_mem_copy((void *)(a1 + 21802), (const void *)(*(_QWORD *)(a1 + 8) + 1314LL), 2u);
    v22 = (void *)(a1 + 21800);
    v21 = (_WORD *)(*(_QWORD *)(a1 + 8) + 1312LL);
    goto LABEL_49;
  }
  if ( ((1 << a3) & 0x700) == 0 )
  {
LABEL_53:
    v17 = "%s: Invalid HE MCS 0x%0x";
    goto LABEL_6;
  }
  v42[0] = a3 | 0xFFFC;
  qdf_mem_copy((void *)(v13 + 1318), v42, 2u);
  v21 = v42;
  v22 = (void *)(*(_QWORD *)(a1 + 8) + 1316LL);
LABEL_49:
  qdf_mem_copy(v22, v21, 2u);
LABEL_50:
  qdf_trace_msg(0x34u, 8u, "%s: new HE MCS 0x%0x", v29, v30, v31, v32, v33, v34, v35, v36, "sme_update_he_mcs", v42[0]);
  if ( !(unsigned int)qdf_mutex_acquire(a1 + 12776) )
  {
    csr_set_vdev_ies_per_band(a1, a2, 0);
    qdf_mutex_release(a1 + 12776);
  }
  csr_update_session_he_cap(a1);
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
