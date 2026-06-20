__int64 __fastcall hdd_populate_wifi_wmm_ac_info(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _WORD *v14; // x25
  int *v15; // x26
  __int64 v16; // x24
  __int64 v17; // x23
  __int64 v18; // x22
  __int64 v19; // x21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x3
  const char *v29; // x2
  int *v30; // x22
  __int64 v31; // x21
  __int64 v32; // x20
  __int64 result; // x0
  int v34; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 216);
  v5 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, *(_DWORD *)a1 | 0x8000u, 0, 0) & 0x80000000) != 0 || (v14 = (_WORD *)(v4 + v5)) == nullptr )
  {
    v29 = "%s: nla_nest_start failed";
  }
  else
  {
    v15 = *(int **)(a1 + 8);
    if ( !v15 )
      goto LABEL_26;
    v16 = *((_QWORD *)v15 + 5);
    v17 = *((_QWORD *)v15 + 7);
    v18 = *((_QWORD *)v15 + 9);
    v19 = *((_QWORD *)v15 + 11);
    v34 = *v15;
    if ( (unsigned int)nla_put(a2, 21, 4, &v34) )
      goto LABEL_16;
    v34 = v15[1];
    if ( (unsigned int)nla_put(a2, 22, 4, &v34) )
      goto LABEL_16;
    v34 = v15[2];
    if ( (unsigned int)nla_put(a2, 23, 4, &v34) )
      goto LABEL_16;
    v34 = v15[3];
    if ( (unsigned int)nla_put(a2, 24, 4, &v34) )
      goto LABEL_16;
    v34 = v15[4];
    if ( (unsigned int)nla_put(a2, 25, 4, &v34) )
      goto LABEL_16;
    v34 = v15[5];
    if ( (unsigned int)nla_put(a2, 26, 4, &v34) )
      goto LABEL_16;
    v34 = v15[6];
    if ( (unsigned int)nla_put(a2, 27, 4, &v34) )
      goto LABEL_16;
    v34 = v15[7];
    if ( (unsigned int)nla_put(a2, 28, 4, &v34) )
      goto LABEL_16;
    v34 = v15[8];
    if ( (unsigned int)nla_put(a2, 30, 4, &v34) )
      goto LABEL_16;
    v34 = v15[12];
    if ( (unsigned int)nla_put(a2, 31, 4, &v34) )
      goto LABEL_16;
    v34 = v15[16];
    if ( (unsigned int)nla_put(a2, 32, 4, &v34) )
      goto LABEL_16;
    v34 = v15[20];
    if ( (unsigned int)nla_put(a2, 36, 4, &v34) || v16 && (unsigned int)nla_put(a2, 33, (unsigned int)v15[8], v16) )
      goto LABEL_16;
    if ( v17 && (unsigned int)nla_put(a2, 34, (unsigned int)v15[12], v17)
      || v18 && (unsigned int)nla_put(a2, 35, (unsigned int)v15[16], v18)
      || v19 && (unsigned int)nla_put(a2, 37, (unsigned int)v15[20], v19) )
    {
LABEL_16:
      v28 = "hdd_populate_wifi_wmm_ac_tx_info";
    }
    else
    {
LABEL_26:
      v30 = *(int **)(a1 + 16);
      if ( !v30 )
        goto LABEL_45;
      v31 = *((_QWORD *)v30 + 5);
      v32 = *((_QWORD *)v30 + 7);
      v34 = *v30;
      if ( !(unsigned int)nla_put(a2, 38, 4, &v34) )
      {
        v34 = v30[1];
        if ( !(unsigned int)nla_put(a2, 39, 4, &v34) )
        {
          v34 = v30[2];
          if ( !(unsigned int)nla_put(a2, 40, 4, &v34) )
          {
            v34 = v30[3];
            if ( !(unsigned int)nla_put(a2, 41, 4, &v34) )
            {
              v34 = v30[4];
              if ( !(unsigned int)nla_put(a2, 42, 4, &v34) )
              {
                v34 = v30[5];
                if ( !(unsigned int)nla_put(a2, 43, 4, &v34) )
                {
                  v34 = v30[6];
                  if ( !(unsigned int)nla_put(a2, 44, 4, &v34) )
                  {
                    v34 = v30[7];
                    if ( !(unsigned int)nla_put(a2, 45, 4, &v34) )
                    {
                      v34 = v30[8];
                      if ( !(unsigned int)nla_put(a2, 46, 4, &v34) )
                      {
                        v34 = v30[12];
                        if ( !(unsigned int)nla_put(a2, 47, 4, &v34)
                          && (!v31 || !(unsigned int)nla_put(a2, 49, (unsigned int)v30[8], v31))
                          && (!v32 || !(unsigned int)nla_put(a2, 48, (unsigned int)v30[12], v32)) )
                        {
LABEL_45:
                          result = 0;
                          *v14 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v14;
                          goto LABEL_40;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      v28 = "hdd_populate_wifi_wmm_ac_rx_info";
    }
    qdf_trace_msg(0x33u, 2u, "%s: QCA_WLAN_VENDOR_ATTR put fail", v20, v21, v22, v23, v24, v25, v26, v27, v28);
    v29 = "%s: QCA_WLAN_VENDOR_ATTR put fail";
  }
  qdf_trace_msg(0x33u, 2u, v29, v6, v7, v8, v9, v10, v11, v12, v13, "hdd_populate_wifi_wmm_ac_info");
  result = 4294967274LL;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
