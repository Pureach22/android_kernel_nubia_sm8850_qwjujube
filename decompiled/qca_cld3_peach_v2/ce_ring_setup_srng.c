__int64 __fastcall ce_ring_setup_srng(
        __int64 a1,
        char a2,
        unsigned int a3,
        int *a4,
        char *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x9
  char v27; // w11
  __int64 v28; // x0
  unsigned int v29; // w1
  __int64 v30; // x8
  __int64 v31; // x9
  unsigned int v32; // w8
  __int64 v33; // x8
  __int64 v34; // x9
  char v35; // w11
  int v36; // w9
  __int64 v38; // [xsp+0h] [xbp-60h] BYREF
  __int64 v39; // [xsp+8h] [xbp-58h]
  __int64 v40; // [xsp+10h] [xbp-50h]
  __int64 v41; // [xsp+18h] [xbp-48h]
  __int128 v42; // [xsp+20h] [xbp-40h]
  __int64 v43; // [xsp+30h] [xbp-30h]
  __int64 v44; // [xsp+38h] [xbp-28h]
  __int64 v45; // [xsp+40h] [xbp-20h]
  __int64 v46; // [xsp+48h] [xbp-18h]
  __int64 v47; // [xsp+50h] [xbp-10h]
  __int64 v48; // [xsp+58h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  switch ( a2 )
  {
    case 2:
      v46 = 0;
      v47 = 0;
      v44 = 0;
      v45 = 0;
      v43 = 0;
      v41 = 0;
      v42 = 0u;
      v40 = 0;
      qdf_trace_msg(0x3Du, 8u, "%s: ce_id: %d", a6, a7, a8, a9, a10, a11, a12, a13, "ce_srng_status_ring_setup", a3);
      v34 = *((_QWORD *)a4 + 5);
      v33 = *((_QWORD *)a4 + 6);
      v35 = *a5;
      LODWORD(v40) = *a4;
      v38 = v33;
      v39 = v34;
      if ( (v35 & 8) == 0 )
      {
        ce_srng_msi_ring_params_setup(a1, a3, &v38);
        v36 = *(unsigned __int8 *)(a1 + 3950);
        DWORD1(v42) = *(unsigned __int16 *)(a1 + 3948);
        DWORD2(v42) = v36;
      }
      v28 = *(_QWORD *)(a1 + 2560);
      v29 = 10;
      goto LABEL_13;
    case 1:
      v46 = 0;
      v47 = 0;
      v44 = 0;
      v45 = 0;
      v43 = 0;
      v41 = 0;
      v42 = 0u;
      v40 = 0;
      qdf_trace_msg(0x3Du, 8u, "%s: ce_id: %d", a6, a7, a8, a9, a10, a11, a12, a13, "ce_srng_dest_ring_setup", a3);
      v31 = *((_QWORD *)a4 + 5);
      v30 = *((_QWORD *)a4 + 6);
      LODWORD(v40) = *a4;
      v38 = v30;
      v39 = v31;
      LOBYTE(v31) = *a5;
      WORD2(v40) = *((_DWORD *)a5 + 3);
      if ( (v31 & 8) == 0 )
      {
        ce_srng_msi_ring_params_setup(a1, a3, &v38);
        v32 = *a4;
        *(_QWORD *)((char *)&v42 + 4) = 0x100000000LL;
        HIDWORD(v42) = v32 >> 3;
        LODWORD(v43) = v43 | 0x10000;
        LODWORD(v47) = 1;
      }
      v28 = *(_QWORD *)(a1 + 2560);
      v29 = 9;
      goto LABEL_13;
    case 0:
      v46 = 0;
      v47 = 0;
      v44 = 0;
      v45 = 0;
      v43 = 0;
      v41 = 0;
      v42 = 0u;
      v40 = 0;
      qdf_trace_msg(
        0x3Du,
        8u,
        "%s: %s: ce_id %d",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "ce_srng_src_ring_setup",
        "ce_srng_src_ring_setup",
        a3);
      v26 = *((_QWORD *)a4 + 5);
      v25 = *((_QWORD *)a4 + 6);
      v27 = *a5;
      LODWORD(v40) = *a4;
      v38 = v25;
      v39 = v26;
      if ( (v27 & 8) == 0 )
      {
        ce_srng_msi_ring_params_setup(a1, a3, &v38);
        *(_QWORD *)((char *)&v42 + 4) = 0x100000000LL;
        LODWORD(v47) = 1;
      }
      v28 = *(_QWORD *)(a1 + 2560);
      v29 = 8;
LABEL_13:
      *((_QWORD *)a4 + 10) = hal_srng_setup(v28, v29, a3, 0, (__int64)&v38, 0, v17, v18, v19, v20, v21, v22, v23, v24);
      break;
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
