__int64 __fastcall extract_additional_reg_rules(
        __int64 result,
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
  __int64 v11; // x20
  unsigned int i; // w27
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x25
  int v17; // w8
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x11
  __int16 v30; // w10
  unsigned int v31; // w26
  unsigned __int16 *v32; // x8
  __int64 v33; // [xsp+0h] [xbp-20h]
  __int64 v34; // [xsp+8h] [xbp-18h]
  __int64 v35; // [xsp+10h] [xbp-10h]
  __int64 v36; // [xsp+18h] [xbp-8h]

  if ( *(_QWORD *)(a2 + 360) && *(_DWORD *)(a2 + 368) )
  {
    v11 = result;
    for ( i = 0; i < *(_DWORD *)(a2 + 368); ++i )
    {
      v17 = *(_DWORD *)(*(_QWORD *)(a2 + 360) + 4LL * (int)i);
      if ( v17 == 12 )
      {
        v13 = v11;
        v14 = a2;
        v15 = 1;
      }
      else
      {
        if ( v17 != 11 )
        {
          if ( v17 == 10 )
          {
            v16 = *(unsigned int *)(a2 + 212);
            if ( (_DWORD)v16 )
            {
              v18 = _qdf_mem_malloc(14 * v16, "create_ext_reg_rules_from_wmi", 17267);
              if ( v18 )
              {
                v27 = 0;
                v28 = v11 + 8;
                do
                {
                  v29 = v18 + v27;
                  v27 += 14;
                  *(_WORD *)v29 = *(_DWORD *)(v28 - 4);
                  *(_WORD *)(v29 + 2) = *(_WORD *)(v28 - 2);
                  *(_WORD *)(v29 + 4) = *(_DWORD *)v28;
                  *(_BYTE *)(v29 + 6) = *(_WORD *)(v28 + 2);
                  *(_BYTE *)(v29 + 7) = *(_BYTE *)(v28 + 3);
                  *(_WORD *)(v29 + 8) = *(_DWORD *)(v28 + 4);
                  *(_BYTE *)(v29 + 10) = *(_BYTE *)(v28 + 8) & 1;
                  v30 = *(_WORD *)(v28 + 10);
                  v28 += 20;
                  *(_WORD *)(v29 + 12) = v30;
                }
                while ( 14 * v16 != v27 );
              }
              *(_QWORD *)(a2 + 272) = v18;
              qdf_trace_msg(0x31u, 8u, "AP Power type %s", v19, v20, v21, v22, v23, v24, v25, v26, "INDOOR_ENABLED_AP");
              v31 = 0;
              do
              {
                v32 = (unsigned __int16 *)(*(_QWORD *)(a2 + 272) + 14LL * (int)v31);
                LODWORD(v34) = v32[4];
                LODWORD(v36) = v32[6];
                LODWORD(v35) = *((unsigned __int8 *)v32 + 10);
                LODWORD(v33) = *((unsigned __int8 *)v32 + 7);
                result = qdf_trace_msg(
                           0x31u,
                           8u,
                           "AP 6GHz rule %u start freq %u end freq %u max_bw %u reg_power %u ant_gain %u flags %u psd_fla"
                           "g %u psd_eirp %u",
                           a3,
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           a10,
                           v31++,
                           *v32,
                           v32[1],
                           v32[2],
                           *((unsigned __int8 *)v32 + 6),
                           v33,
                           v34,
                           v35,
                           v36);
              }
              while ( (_DWORD)v16 != v31 );
            }
            else
            {
              *(_QWORD *)(a2 + 272) = 0;
              result = qdf_trace_msg(
                         0x31u,
                         8u,
                         "AP Power type %s",
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         "INDOOR_ENABLED_AP");
            }
          }
          else
          {
            LODWORD(v16) = 0;
          }
          goto LABEL_6;
        }
        v13 = v11;
        v14 = a2;
        v15 = 0;
      }
      result = extract_additional_cli_reg_rules(v13, v14, v15);
      LODWORD(v16) = result;
LABEL_6:
      v11 += 20LL * (unsigned int)v16;
    }
  }
  return result;
}
