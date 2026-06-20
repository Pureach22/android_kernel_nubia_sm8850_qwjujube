__int64 __fastcall hdd_set_grat_arp_keepalive(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x21
  __int64 v10; // x23
  __int64 v11; // x26
  __int64 v12; // x25
  const char *v14; // x20
  __int16 v15; // w9
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w19
  const char *v34; // x2
  __int64 v35; // [xsp+8h] [xbp-28h] BYREF
  __int64 v36; // [xsp+10h] [xbp-20h] BYREF
  __int128 v37; // [xsp+18h] [xbp-18h]
  __int64 v38; // [xsp+28h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0xFFFFFFFFFFFFuLL;
  v35 = 2;
  v36 = 0;
  if ( a1 )
  {
    v9 = (__int64 *)a1[3];
    if ( v9 )
    {
      v10 = a1[6603];
      if ( v10 == -80 )
      {
        v34 = "%s: sta_ctx is null";
      }
      else
      {
        if ( &v36 )
        {
          v11 = a1[4];
          v12 = *(_QWORD *)(v11 + 968);
          if ( v12 )
          {
            v14 = "%s: ipv4 address not found";
            while ( 1 )
            {
              v12 = *(_QWORD *)(v12 + 16);
              if ( !v12 )
                break;
              if ( !strcmp((const char *)(v11 + 296), (const char *)(v12 + 76)) )
              {
                if ( !*(_DWORD *)(v12 + 48) )
                  goto LABEL_17;
                LODWORD(v36) = *(_DWORD *)(v12 + 48);
                qdf_mem_copy((char *)&v36 + 4, &v36, 4u);
                v15 = *(_WORD *)(v10 + 304);
                *(_DWORD *)((char *)&v37 + 6) = *(_DWORD *)(v10 + 300);
                WORD5(v37) = v15;
                ucfg_mlme_get_sta_keep_alive_period(*v9, (int *)&v35 + 1);
                BYTE12(v37) = *(_BYTE *)(a1[6603] + 8LL);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Setting gratuitous ARP keepalive; ipv4_addr:%u.%u.%u.%u",
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  v23,
                  "hdd_set_grat_arp_keepalive",
                  (unsigned __int8)v36,
                  BYTE1(v36),
                  BYTE2(v36),
                  BYTE3(v36));
                result = sme_set_keep_alive(v9[2], BYTE12(v37), &v35);
                if ( (_DWORD)result )
                {
                  v33 = result;
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Failed to set keepalive",
                    v25,
                    v26,
                    v27,
                    v28,
                    v29,
                    v30,
                    v31,
                    v32,
                    "hdd_set_grat_arp_keepalive");
                  result = qdf_status_to_os_return(v33);
                }
                goto LABEL_20;
              }
            }
          }
          else
          {
            qdf_trace_msg(0x33u, 2u, "%s: Failed to get in_device", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_lookup_ifaddr");
LABEL_17:
            v14 = "%s: ipv4 address not found";
          }
        }
        else
        {
          v14 = "%s: ipv4_addr is null";
        }
        qdf_trace_msg(0x33u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_populate_ipv4_addr");
        v34 = "%s: Failed to populate ipv4 address";
      }
    }
    else
    {
      v34 = "%s: hdd_ctx is null";
    }
  }
  else
  {
    v34 = "%s: adapter is null";
  }
  qdf_trace_msg(0x33u, 2u, v34, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_set_grat_arp_keepalive");
  result = 4294967274LL;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
