__int64 __fastcall cm_bss_mlo_type(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v6; // x22
  char sta_mlo_conn_max_num; // w0
  char v8; // w8
  __int64 result; // x0
  char v10; // w28
  unsigned __int64 v11; // x27
  unsigned __int8 *v12; // x22
  unsigned int v13; // w25
  unsigned int v14; // w26
  __int64 entry; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  __int64 v28; // [xsp+0h] [xbp-20h]
  unsigned __int8 v29; // [xsp+Ch] [xbp-14h]
  _WORD v30[2]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v31[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+18h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 1824);
  v31[0] = 0;
  v30[0] = 0;
  sta_mlo_conn_max_num = wlan_mlme_get_sta_mlo_conn_max_num();
  if ( !v6 )
  {
    result = 4;
    goto LABEL_12;
  }
  v8 = sta_mlo_conn_max_num;
  result = 0;
  if ( *(_BYTE *)(a2 + 1918) && v8 != 1 )
  {
    if ( (policy_mgr_is_hw_emlsr_capable(a1) & 1) != 0
      && (util_get_bvmlie_eml_cap(v6, *(unsigned __int8 *)(v6 + 1) + 2LL, v31, v30), v31[0] == 1) )
    {
      v29 = v30[0];
      if ( !*(_BYTE *)(a2 + 1918) )
        goto LABEL_7;
    }
    else
    {
      v29 = 0;
      if ( !*(_BYTE *)(a2 + 1918) )
      {
LABEL_7:
        v10 = 0;
LABEL_8:
        if ( (v10 & 1 & v29) != 0 )
          result = 2;
        else
          result = v10 & 1;
        goto LABEL_12;
      }
    }
    v11 = 0;
    v10 = 0;
    v12 = (unsigned __int8 *)(a2 + 1920);
    while ( 1 )
    {
      if ( v11 == 3 )
        __break(0x5512u);
      if ( v12[40] == 1 )
      {
        v13 = *(_DWORD *)(a2 + 1192);
        v14 = *((unsigned __int16 *)v12 + 3);
        entry = cm_get_entry(a3, (__int64)v12, a2 + 1912);
        if ( entry )
          v14 = *(_DWORD *)(entry + 1192);
        if ( (policy_mgr_2_freq_always_on_same_mac(a1, v14, v13) & 1) == 0 )
        {
          result = 3;
          break;
        }
        if ( v14 == v13 )
        {
          if ( v12 )
          {
            v24 = *v12;
            v25 = v12[1];
            v26 = v12[2];
            v27 = v12[5];
          }
          else
          {
            v26 = 0;
            v24 = 0;
            v25 = 0;
            v27 = 0;
          }
          LODWORD(v28) = v13;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: Partner %02x:%02x:%02x:**:**:%02x freq %d same as assoc freq, invalid it",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "cm_bss_mlo_type",
            v24,
            v25,
            v26,
            v27,
            v28);
          v12[40] = 0;
        }
        else
        {
          v10 = 1;
        }
      }
      ++v11;
      v12 += 48;
      if ( v11 >= *(unsigned __int8 *)(a2 + 1918) )
        goto LABEL_8;
    }
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
