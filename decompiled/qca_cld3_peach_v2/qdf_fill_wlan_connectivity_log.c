__int64 __fastcall qdf_fill_wlan_connectivity_log(
        __int64 result,
        int a2,
        int a3,
        unsigned int a4,
        int a5,
        unsigned __int8 a6,
        __int64 a7,
        char a8)
{
  int v10; // w24
  _BYTE *v15; // x26
  __int64 v16; // x0
  unsigned int v17; // w8
  __int64 v18; // x8
  int v19; // w9
  __int16 v20; // w9
  unsigned int v21; // w8
  __int16 v22; // w8
  char v23; // w9
  char v24; // w9
  char v25; // w8
  char v26; // w9
  char v27; // w8
  _BYTE s[331]; // [xsp+5h] [xbp-14Bh] BYREF

  *(_QWORD *)&s[323] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a5 )
  {
    v10 = result;
    result = (__int64)memset(s, 0, 0x143u);
    if ( v10 || a3 != 1 || (unsigned int)(a2 - 5) >= 2 && (result = _qdf_nbuf_is_bcast_pkt(a7), (result & 1) == 0) )
    {
      v15 = &s[40];
      qdf_mem_set(s, 0x143u, 0);
      *(_QWORD *)&s[8] = 1000 * qdf_get_time_of_the_day_ms();
      v16 = ktime_get();
      *(_WORD *)&s[6] = a6;
      *(_QWORD *)&s[24] = v16 / 1000;
      result = wlan_get_qdf_to_diag_txrx_status(a4);
      s[56] = result;
      s[32] = 5;
      if ( v10 == 1 )
      {
        v18 = *(_QWORD *)(a7 + 224);
        v19 = *(unsigned __int8 *)(v18 + 15);
        if ( v19 == 3 )
        {
          v22 = *(_WORD *)(v18 + 19);
          if ( (v22 & 0x800) != 0 )
          {
            LOBYTE(v17) = 24;
            switch ( a2 )
            {
              case 1:
                LOWORD(v17) = 29;
                break;
              case 2:
                LOWORD(v17) = 30;
                break;
              case 3:
                LOWORD(v17) = 31;
                break;
              case 4:
                LOWORD(v17) = 32;
                break;
              case 5:
                goto LABEL_24;
              case 6:
                LOWORD(v17) = 26;
                break;
              case 7:
                LOWORD(v17) = 25;
                break;
              case 8:
                LOWORD(v17) = 27;
                break;
              case 9:
                LOWORD(v17) = 28;
                break;
              case 37:
                LOWORD(v17) = 35;
                break;
              case 38:
                LOWORD(v17) = 36;
                break;
              case 39:
                LOWORD(v17) = 37;
                break;
              case 40:
                LOWORD(v17) = 38;
                break;
              case 43:
                LOWORD(v17) = 40;
                break;
              default:
                LOWORD(v17) = 48;
                break;
            }
          }
          else
          {
            if ( (v22 & 0x10) != 0 )
              LOBYTE(v17) = 33;
            else
              LOBYTE(v17) = 34;
LABEL_24:
            LOWORD(v17) = (unsigned __int8)v17;
          }
        }
        else
        {
          v15 = &s[44];
          if ( v19 == 1 )
          {
            strcpy(&s[40], "(");
            v21 = *(unsigned __int16 *)(v18 + 16);
          }
          else
          {
            if ( *(_BYTE *)(v18 + 15) )
              goto LABEL_2;
            if ( ((*(_BYTE *)(v18 + 18) - 1) & 0xFC) != 0 )
              v20 = 48;
            else
              v20 = (unsigned __int8)(*(_BYTE *)(v18 + 18) - 1) + 35;
            *(_WORD *)&s[40] = v20;
            *(_WORD *)&s[46] = *(unsigned __int8 *)(v18 + 22);
            v21 = *(unsigned __int16 *)(v18 + 20);
          }
          v17 = bswap32(v21) >> 16;
        }
      }
      else
      {
        if ( v10 )
          goto LABEL_2;
        LOWORD(v17) = 24;
        switch ( a2 )
        {
          case 1:
            LOWORD(v17) = 29;
            break;
          case 2:
            LOWORD(v17) = 30;
            break;
          case 3:
            LOWORD(v17) = 31;
            break;
          case 4:
            LOWORD(v17) = 32;
            break;
          case 5:
            break;
          case 6:
            LOWORD(v17) = 26;
            break;
          case 7:
            LOWORD(v17) = 25;
            break;
          case 8:
            LOWORD(v17) = 27;
            break;
          case 9:
            LOWORD(v17) = 28;
            break;
          case 37:
            LOWORD(v17) = 35;
            break;
          case 38:
            LOWORD(v17) = 36;
            break;
          case 39:
            LOWORD(v17) = 37;
            break;
          case 40:
            LOWORD(v17) = 38;
            break;
          case 43:
            LOWORD(v17) = 40;
            break;
          default:
            LOWORD(v17) = 48;
            break;
        }
      }
      v23 = s[39];
      *(_WORD *)v15 = v17;
      v24 = v23 & 3 | (4 * a8);
      s[39] = v24;
      if ( !a3 )
      {
        v25 = v24 | 2;
        if ( a4 == 3 )
          v26 = 2;
        else
          v26 = 1;
        s[39] = v25;
        if ( a4 == 1 )
          v27 = 3;
        else
          v27 = v26;
        s[37] = v27;
      }
      result = host_diag_event_report_payload(3363, 323, s);
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
