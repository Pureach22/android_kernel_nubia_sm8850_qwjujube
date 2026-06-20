__int64 __fastcall dp_rx_tm_dump_stats(unsigned __int8 *a1)
{
  unsigned int v1; // w8
  __int64 v3; // x27
  unsigned __int8 *v4; // x21
  unsigned int v5; // w25
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w4
  unsigned int v16; // w26
  int v17; // w0
  int v18; // w4
  int v19; // w4
  int v20; // w0
  int v21; // w0
  int v22; // w4
  int v23; // w0
  int v24; // w4
  int v25; // w0
  int v26; // w4
  int v27; // w0
  int v28; // w4
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x26
  unsigned int v38; // w25
  unsigned int v39; // w22
  unsigned __int8 *v40; // x21
  int v41; // w4
  int v42; // w0
  __int64 v44; // [xsp+0h] [xbp-D0h]
  __int64 v45; // [xsp+8h] [xbp-C8h]
  __int64 v46; // [xsp+10h] [xbp-C0h]
  __int64 v47; // [xsp+18h] [xbp-B8h]
  __int64 v48; // [xsp+20h] [xbp-B0h]
  __int64 v49; // [xsp+28h] [xbp-A8h]
  __int64 v50; // [xsp+30h] [xbp-A0h]
  __int64 v51; // [xsp+38h] [xbp-98h]
  __int64 v52; // [xsp+40h] [xbp-90h]
  __int64 v53; // [xsp+48h] [xbp-88h]
  __int64 v54; // [xsp+50h] [xbp-80h]
  _QWORD v55[12]; // [xsp+58h] [xbp-78h] BYREF
  int v56; // [xsp+B8h] [xbp-18h]
  __int64 v57; // [xsp+C0h] [xbp-10h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  if ( *a1 )
  {
    v3 = 0;
    while ( 1 )
    {
      v4 = *(unsigned __int8 **)(*((_QWORD *)a1 + 3) + 8 * v3);
      if ( !v4 )
        goto LABEL_4;
      v56 = 0;
      memset(v55, 0, sizeof(v55));
      qdf_mem_set(v55, 0x64u, 0);
      v5 = *((_DWORD *)v4 + 118);
      if ( v5 )
        break;
      v5 = *((_DWORD *)v4 + 119);
      if ( v5 )
      {
        v16 = 0;
        v15 = *((_DWORD *)v4 + 119);
        goto LABEL_12;
      }
      v5 = *((_DWORD *)v4 + 120);
      if ( v5 )
      {
        v16 = 0;
        v18 = *((_DWORD *)v4 + 120);
LABEL_19:
        v7 = scnprintf((char *)v55 + v16, 100LL - v16, "reo[%u]:%u ", 2, v18);
        v16 += v20;
        v19 = *((_DWORD *)v4 + 121);
        if ( !v19 )
          goto LABEL_22;
LABEL_20:
        v5 += v19;
        if ( v16 <= 0x63 )
          goto LABEL_21;
        goto LABEL_22;
      }
      v5 = *((_DWORD *)v4 + 121);
      if ( v5 )
      {
        v16 = 0;
        v19 = *((_DWORD *)v4 + 121);
LABEL_21:
        v7 = scnprintf((char *)v55 + v16, 100LL - v16, "reo[%u]:%u ", 3, v19);
        v16 += v21;
LABEL_22:
        v22 = *((_DWORD *)v4 + 122);
        if ( v22 )
        {
          v5 += v22;
          if ( v16 <= 0x63 )
          {
LABEL_24:
            v7 = scnprintf((char *)v55 + v16, 100LL - v16, "reo[%u]:%u ", 4, v22);
            v16 += v23;
          }
        }
        v24 = *((_DWORD *)v4 + 123);
        if ( v24 )
        {
          v5 += v24;
          if ( v16 <= 0x63 )
          {
LABEL_27:
            v7 = scnprintf((char *)v55 + v16, 100LL - v16, "reo[%u]:%u ", 5, v24);
            v16 += v25;
          }
        }
        v26 = *((_DWORD *)v4 + 124);
        if ( v26 )
        {
          v5 += v26;
          if ( v16 <= 0x63 )
          {
LABEL_30:
            v7 = scnprintf((char *)v55 + v16, 100LL - v16, "reo[%u]:%u ", 6, v26);
            v16 += v27;
          }
        }
        v28 = *((_DWORD *)v4 + 125);
        if ( v28 )
        {
          v5 += v28;
          if ( v16 <= 0x63 )
LABEL_33:
            v7 = scnprintf((char *)v55 + v16, 100LL - v16, "reo[%u]:%u ", 7, v28);
        }
        if ( v5 )
        {
          LODWORD(v54) = *((_DWORD *)v4 + 137);
          LODWORD(v52) = *((_DWORD *)v4 + 135);
          LODWORD(v53) = *((_DWORD *)v4 + 136);
          LODWORD(v51) = *((_DWORD *)v4 + 132);
          LODWORD(v50) = *((_DWORD *)v4 + 134);
          LODWORD(v49) = *((_DWORD *)v4 + 131);
          LODWORD(v48) = *((_DWORD *)v4 + 133);
          LODWORD(v47) = *((_DWORD *)v4 + 130);
          LODWORD(v46) = *((_DWORD *)v4 + 129);
          LODWORD(v45) = *((_DWORD *)v4 + 128);
          LODWORD(v44) = *((_DWORD *)v4 + 127);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: thread:%u - qlen:%u queued:(total:%u %s) dequeued:%u stack:%u gro_flushes: %u gro_flushes_by_vdev_del: %"
            "u rx_flushes: %u max_len:%u invalid(peer:%u vdev:%u rx-handle:%u others:%u enq fail:%u)",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "dp_rx_tm_thread_dump_stats",
            *v4,
            *((unsigned int *)v4 + 114),
            v5,
            v55,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54);
          qdf_mem_set(v55, 0x64u, 0);
          v37 = 0;
          v38 = 0;
          v39 = 0;
          v40 = v4 + 564;
          do
          {
            v41 = *(_DWORD *)&v40[4 * v37];
            if ( v41 )
            {
              v38 += v41;
              if ( v39 <= 0x63 )
              {
                v29 = scnprintf((char *)v55 + v39, 100LL - v39, "cpu[%u]:%u ", v37, v41);
                v39 += v42;
              }
            }
            ++v37;
          }
          while ( v37 != 32 );
          if ( v38 )
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: total:%u %s",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "dp_rx_tm_thread_dump_stats",
              v38,
              v55);
        }
        goto LABEL_3;
      }
      v5 = *((_DWORD *)v4 + 122);
      if ( v5 )
      {
        v16 = 0;
        v22 = *((_DWORD *)v4 + 122);
        goto LABEL_24;
      }
      v5 = *((_DWORD *)v4 + 123);
      if ( v5 )
      {
        v16 = 0;
        v24 = *((_DWORD *)v4 + 123);
        goto LABEL_27;
      }
      v5 = *((_DWORD *)v4 + 124);
      if ( v5 )
      {
        v16 = 0;
        v26 = *((_DWORD *)v4 + 124);
        goto LABEL_30;
      }
      v5 = *((_DWORD *)v4 + 125);
      if ( v5 )
      {
        v16 = 0;
        v28 = *((_DWORD *)v4 + 125);
        goto LABEL_33;
      }
LABEL_3:
      v1 = *a1;
LABEL_4:
      if ( ++v3 >= (unsigned __int64)v1 )
        goto LABEL_52;
    }
    v7 = scnprintf(v55, 100, "reo[%u]:%u ", 0, v5);
    v15 = *((_DWORD *)v4 + 119);
    v16 = v6;
    if ( v15 )
    {
      v5 += v15;
      if ( v6 <= 0x63 )
      {
LABEL_12:
        v7 = scnprintf((char *)v55 + v16, 100LL - v16, "reo[%u]:%u ", 1, v15);
        v16 += v17;
      }
    }
    v18 = *((_DWORD *)v4 + 120);
    if ( v18 )
    {
      v5 += v18;
      if ( v16 <= 0x63 )
        goto LABEL_19;
    }
    v19 = *((_DWORD *)v4 + 121);
    if ( !v19 )
      goto LABEL_22;
    goto LABEL_20;
  }
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return 0;
}
