__int64 __fastcall rtc6226_vidioc_s_ctrl(__int64 a1, __int64 a2, int *a3)
{
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 v8; // x20
  unsigned int v9; // w0
  __int16 v10; // w8
  int v11; // w9
  __int16 v12; // w8
  __int16 v13; // w9
  __int16 v14; // w8
  unsigned int v15; // w9
  __int64 v16; // x1
  __int16 v17; // w8
  unsigned int v18; // w8
  __int64 v19; // x19
  int v20; // w8
  __int64 v21; // x20
  unsigned int v22; // w8
  __int16 v23; // w8
  unsigned int v24; // w8
  int v25; // w21
  __int64 v26; // x20
  __int64 v27; // x0
  __int16 v28; // w8
  __int64 v29; // x19
  __int16 v30; // w8
  __int16 v31; // w8
  __int64 v33; // x20
  void *v34; // x0

  v4 = video_devdata();
  v5 = *a3;
  v6 = *(_QWORD *)(v4 + 336);
  v7 = 0;
  if ( *a3 > 10025228 )
  {
    switch ( v5 )
    {
      case 134217729:
        v24 = a3[1];
        if ( v24 <= 2 )
        {
          v7 = 0;
          *(_BYTE *)(v6 + 1929) = v24;
          return v7;
        }
        v34 = &unk_D74D;
        goto LABEL_71;
      case 134217730:
        v22 = a3[1];
        if ( v22 <= 0xF )
        {
          v7 = 0;
          *(_DWORD *)(v6 + 1864) = v22;
          return v7;
        }
        v34 = &unk_DB8D;
        goto LABEL_71;
      case 134217731:
        goto LABEL_33;
      case 134217732:
        v20 = a3[1];
        if ( v20 )
        {
          if ( v20 != 1 )
            return 0;
          if ( *(_DWORD *)(v6 + 1756) >= 2u )
          {
            v34 = &unk_D697;
LABEL_71:
            printk(v34, "rtc6226_vidioc_s_ctrl");
            return (unsigned int)-22;
          }
          else
          {
            v21 = v6;
            *(_DWORD *)(v6 + 1756) = 5;
            v7 = rtc6226_enable();
            if ( (v7 & 0x80000000) != 0 )
            {
              printk(&unk_D806, "rtc6226_vidioc_s_ctrl");
              *(_DWORD *)(v21 + 1756) = 0;
            }
          }
        }
        else
        {
          v33 = v6;
          *(_DWORD *)(v6 + 1756) = 4;
          v7 = rtc6226_disable();
          if ( (v7 & 0x80000000) != 0 )
          {
            printk(&unk_D1E5, v7);
            *(_DWORD *)(v33 + 1756) = 1;
          }
        }
        return v7;
      case 134217733:
      case 134217737:
      case 134217738:
      case 134217749:
      case 134217750:
      case 134217751:
      case 134217752:
      case 134217753:
      case 134217754:
      case 134217756:
      case 134217757:
      case 134217759:
      case 134217760:
      case 134217761:
      case 134217762:
      case 134217763:
      case 134217764:
      case 134217765:
      case 134217766:
      case 134217767:
      case 134217768:
      case 134217770:
      case 134217772:
      case 134217773:
      case 134217774:
      case 134217776:
      case 134217777:
      case 134217779:
      case 134217780:
      case 134217781:
      case 134217782:
      case 134217783:
      case 134217784:
      case 134217785:
      case 134217786:
      case 134217787:
      case 134217788:
        return (unsigned int)-22;
      case 134217734:
      case 134217744:
      case 134217747:
        if ( (*(_WORD *)(v6 + 1770) & 0x1000) != 0 )
          return 0;
        v8 = v6;
        *(_WORD *)(v6 + 1770) |= 0x1000u;
        v7 = 0;
        if ( (rtc6226_set_register(v6, 4) & 0x80000000) != 0 )
          *(_WORD *)(v8 + 1770) &= ~0x1000u;
        return v7;
      case 134217735:
      case 134217739:
      case 134217746:
      case 134217748:
      case 134217755:
      case 134217769:
      case 134217771:
      case 134217775:
      case 134217778:
      case 134217789:
        return v7;
      case 134217736:
        v25 = a3[1];
        v26 = v6;
        *(_WORD *)(v6 + 1772) = ((_WORD)v25 << 6) & 0xFF00 | *(_WORD *)(v6 + 1772) & 0xF0FF;
        v7 = rtc6226_set_register(v6, 5);
        v27 = v26;
        *(_BYTE *)(v26 + 1761) = v25 & 0xFC;
        if ( (v7 & 0x80000000) != 0 )
        {
          printk(&unk_D9F1, "rtc6226_vidioc_s_ctrl");
          v27 = v26;
        }
        ((void (__fastcall *)(__int64, __int64))rtc6226_get_register)(v27, 5);
        return v7;
      case 134217740:
        goto LABEL_29;
      case 134217741:
        v23 = *(_WORD *)(v6 + 1770) | 0xC000;
        goto LABEL_62;
      case 134217742:
        goto LABEL_26;
      case 134217743:
        v29 = v6;
        rtc6226_reset_rds_data(v6);
        v6 = v29;
        v30 = *(_WORD *)(v29 + 1770) & 0x6FFF;
        *(_WORD *)(v29 + 1770) = v30;
        v31 = v30 | (*((_WORD *)a3 + 2) << 15);
        *(_WORD *)(v29 + 1770) = v31;
        *(_WORD *)(v29 + 1770) = v31 | (*((_WORD *)a3 + 2) << 12);
        goto LABEL_63;
      case 134217745:
        v28 = *(_WORD *)(v6 + 1770);
        if ( a3[1] )
          v23 = v28 & 0x7FFF;
        else
          v23 = v28 | 0x8000;
LABEL_62:
        *(_WORD *)(v6 + 1770) = v23;
LABEL_63:
        v16 = 4;
        return (unsigned int)rtc6226_set_register(v6, v16);
      case 134217758:
        v12 = *(_WORD *)(v6 + 1766) & 0x7FFF | ((a3[1] != 1) << 15);
        goto LABEL_52;
      default:
        if ( v5 == 10025229 )
        {
LABEL_33:
          if ( a3[1] )
            queue_delayed_work_on(32, *(_QWORD *)(v6 + 2040), v6 + 2416, 3);
          else
            rtc6226_cancel_seek(v6);
          return 0;
        }
        if ( v5 != 10025230 )
          return (unsigned int)-22;
        v16 = 5;
        v17 = *(_WORD *)(v6 + 1772) & 0xF0FF;
        *(_WORD *)(v6 + 1772) = v17;
        *(_WORD *)(v6 + 1772) = v17 | *((_WORD *)a3 + 2);
        break;
    }
    return (unsigned int)rtc6226_set_register(v6, v16);
  }
  if ( v5 > 10025221 )
  {
    if ( v5 > 10025224 )
    {
      if ( v5 == 10025225 )
      {
        v18 = a3[1];
        if ( v18 <= 3 )
        {
          *(_WORD *)(v6 + 1802) = 0x1DB0238C2A302A30uLL >> (16 * (unsigned __int8)v18);
          *(_WORD *)(v6 + 1804) = 0x19001DB01DB0222EuLL >> (16 * (unsigned __int8)v18);
        }
        v19 = v6;
        *(_DWORD *)(v6 + 1744) = a3[1];
        rtc6226_set_register(v6, 20);
        v6 = v19;
        v16 = 21;
        return (unsigned int)rtc6226_set_register(v6, v16);
      }
      if ( v5 == 10025226 )
      {
LABEL_26:
        v13 = *(_WORD *)(v6 + 1800);
        *(_DWORD *)(v6 + 1748) = a3[1];
        v14 = v13 & 0xE0FF;
        *(_WORD *)(v6 + 1800) = v13 & 0xE0FF;
        v15 = a3[1];
        if ( v15 <= 2 )
          *(_WORD *)(v6 + 1800) = v14 | (0x5000A001400uLL >> (16 * (unsigned __int8)v15));
        v16 = 19;
        *(_DWORD *)(v6 + 1748) = a3[1];
        return (unsigned int)rtc6226_set_register(v6, v16);
      }
      if ( v5 != 10025227 )
        return (unsigned int)-22;
    }
    else
    {
      if ( v5 == 10025222 )
      {
LABEL_29:
        v12 = *(_WORD *)(v6 + 1766) & 0xEFFF | ((a3[1] == 1) << 12);
        goto LABEL_52;
      }
      if ( v5 != 10025223 )
        goto LABEL_15;
    }
  }
  else
  {
    if ( v5 <= 10025217 )
    {
      if ( v5 != 9963781 )
      {
        if ( v5 != 9963785 )
        {
          if ( v5 == 10025217 )
          {
            v9 = rtc6226_power_up(v6);
LABEL_36:
            v7 = v9;
            a3[1] = 0;
            return v7;
          }
          return (unsigned int)-22;
        }
        goto LABEL_21;
      }
LABEL_15:
      v10 = *(_WORD *)(v6 + 1766) & 0xFFF0;
      *(_WORD *)(v6 + 1766) = v10;
      v11 = a3[1];
      if ( v11 > 15 )
        LOWORD(v11) = 8;
      v12 = v11 | v10;
      goto LABEL_52;
    }
    if ( v5 == 10025218 )
    {
      v9 = rtc6226_power_down((_WORD *)v6);
      goto LABEL_36;
    }
    if ( v5 != 10025219 )
    {
      if ( v5 != 10025221 )
        return (unsigned int)-22;
LABEL_21:
      v12 = *(_WORD *)(v6 + 1766) & 0xBFFF | ((a3[1] != 1) << 14);
LABEL_52:
      *(_WORD *)(v6 + 1766) = v12;
      v16 = 2;
      return (unsigned int)rtc6226_set_register(v6, v16);
    }
  }
  return v7;
}
