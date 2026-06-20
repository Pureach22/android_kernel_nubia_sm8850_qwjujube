__int64 __fastcall put_wifi_iface_stats(unsigned __int8 *a1, int a2, __int64 a3, __int64 a4)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  size_t v15; // x0
  size_t v16; // x2
  const char *v17; // x21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  __int64 v27; // x22
  __int64 v28; // x23
  __int64 v29; // x21
  __int64 v30; // x22
  int v31; // w8
  _WORD *v32; // x23
  __int64 v33; // x24
  unsigned __int8 *v34; // x22
  __int64 v35; // x25
  __int64 v36; // x26
  int v37; // w8
  _WORD *v38; // x25
  _QWORD v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_DWORD *)(*(_QWORD *)a4 + 40LL) | 2) == 2 )
  {
    LODWORD(v39[0]) = a1[7];
    if ( (unsigned int)nla_put(a3, 11, 4, v39) )
      goto LABEL_14;
  }
  LODWORD(v39[0]) = *a1;
  if ( (unsigned int)nla_put(a3, 9, 4, v39) )
    goto LABEL_14;
  if ( (unsigned int)nla_put(a3, 10, 6, a1 + 1) )
    goto LABEL_14;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 2);
  if ( (unsigned int)nla_put(a3, 12, 4, v39) )
    goto LABEL_14;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 3);
  if ( (unsigned int)nla_put(a3, 13, 4, v39) )
    goto LABEL_14;
  v15 = strnlen((const char *)a1 + 16, 0x21u);
  v16 = v15;
  if ( v15 >= 0x22 )
  {
    _fortify_panic(2, 33, v15 + 1);
    goto LABEL_37;
  }
  if ( v15 == 33 )
  {
LABEL_37:
    _fortify_panic(4, 33, v16 + 1);
    goto LABEL_38;
  }
  if ( (unsigned int)nla_put(a3, 14, v15, a1 + 16)
    || (unsigned int)nla_put(a3, 15, 6, a1 + 49)
    || (unsigned int)nla_put(a3, 16, 3, a1 + 55)
    || (unsigned int)nla_put(a3, 17, 3, a1 + 58)
    || (LOBYTE(v39[0]) = a1[61], (unsigned int)nla_put(a3, 87, 1, v39)) )
  {
LABEL_14:
    v17 = "%s: QCA_WLAN_VENDOR_ATTR put fail";
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: QCA_WLAN_VENDOR_ATTR put fail",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "put_wifi_interface_info");
LABEL_15:
    qdf_trace_msg(0x33u, 2u, v17, v18, v19, v20, v21, v22, v23, v24, v25, "put_wifi_iface_stats");
    result = 0;
    goto LABEL_16;
  }
  v27 = *((unsigned int *)a1 + 32);
  v28 = *((unsigned int *)a1 + 33);
  LODWORD(v39[0]) = 2;
  if ( (unsigned int)nla_put(a3, 76, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = a2;
  if ( (unsigned int)nla_put(a3, 33, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 21);
  if ( (unsigned int)nla_put(a3, 2, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 22);
  if ( (unsigned int)nla_put(a3, 3, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 23);
  if ( (unsigned int)nla_put(a3, 4, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 24);
  if ( (unsigned int)nla_put(a3, 5, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 25);
  if ( (unsigned int)nla_put(a3, 6, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 26);
  if ( (unsigned int)nla_put(a3, 7, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 27);
  if ( (unsigned int)nla_put(a3, 8, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 34);
  if ( (unsigned int)nla_put(a3, 73, 4, v39) )
    goto LABEL_35;
  LODWORD(v39[0]) = *((_DWORD *)a1 + 35);
  if ( (unsigned int)nla_put(a3, 74, 4, v39)
    || (LODWORD(v39[0]) = *((_DWORD *)a1 + 36), (unsigned int)nla_put(a3, 75, 4, v39))
    || (LODWORD(v39[0]) = *((_DWORD *)a1 + 48), (unsigned int)nla_put(a3, 90, 4, v39))
    || (v39[0] = v28 | (v27 << 32), (unsigned int)nla_put_64bit(a3, 72, 8, v39, 229))
    || (LODWORD(v39[0]) = *((_DWORD *)a1 + 16), (unsigned int)nla_put(a3, 79, 4, v39))
    || (LODWORD(v39[0]) = *((_DWORD *)a1 + 17), (unsigned int)nla_put(a3, 80, 4, v39))
    || (LODWORD(v39[0]) = *((_DWORD *)a1 + 18), (unsigned int)nla_put(a3, 81, 4, v39))
    || (LODWORD(v39[0]) = *((_DWORD *)a1 + 19), (unsigned int)nla_put(a3, 82, 4, v39)) )
  {
LABEL_35:
    v17 = "%s: QCA_WLAN_VENDOR_ATTR put fail";
    goto LABEL_15;
  }
LABEL_38:
  v29 = *(_QWORD *)(a3 + 216);
  v30 = *(unsigned int *)(a3 + 208);
  v31 = nla_put(a3, 32838, 0, 0);
  result = 0;
  if ( (v31 & 0x80000000) == 0 )
  {
    v32 = (_WORD *)(v29 + v30);
    if ( v29 + v30 )
    {
      v33 = 0;
      v34 = a1 + 196;
      v17 = "%s: put_wifi_wmm_ac_stat Fail";
      while ( 1 )
      {
        v35 = *(_QWORD *)(a3 + 216);
        v36 = *(unsigned int *)(a3 + 208);
        v37 = nla_put(a3, (unsigned int)v33 | 0x8000, 0, 0);
        result = 0;
        if ( v37 < 0 )
          break;
        v38 = (_WORD *)(v35 + v36);
        if ( !v38 )
          break;
        if ( (put_wifi_wmm_ac_stat(v34, a3) & 1) == 0 )
          goto LABEL_15;
        ++v33;
        v34 += 68;
        *v38 = *(_WORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v38;
        if ( v33 == 4 )
        {
          *v32 = *(_DWORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v32;
          LODWORD(v39[0]) = *((_DWORD *)a1 + 159);
          if ( (unsigned int)nla_put(a3, 88, 4, v39)
            || (LODWORD(v39[0]) = *((_DWORD *)a1 + 160), (unsigned int)nla_put(a3, 89, 4, v39)) )
          {
            v17 = "%s: QCA_WLAN_VENDOR_ATTR put powersave_stat fail";
            goto LABEL_15;
          }
          result = 1;
          break;
        }
      }
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
