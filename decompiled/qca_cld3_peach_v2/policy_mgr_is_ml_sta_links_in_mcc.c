__int64 __fastcall policy_mgr_is_ml_sta_links_in_mcc(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int8 a5,
        _DWORD *a6)
{
  unsigned __int64 v6; // x25
  __int64 v8; // x23
  __int64 v9; // x27
  int v10; // w24
  __int64 v11; // x20
  int v12; // w21
  unsigned int v13; // w26
  unsigned int v14; // w28
  unsigned __int64 v15; // x19
  int v16; // w24
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w25
  __int64 v26; // x23
  __int64 v27; // x5
  __int64 v29; // [xsp+0h] [xbp-40h]
  __int64 v30; // [xsp+8h] [xbp-38h]
  __int64 v31; // [xsp+10h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-18h]
  int v36; // [xsp+3Ch] [xbp-4h]

  v6 = a5;
  if ( a5 )
  {
    v8 = a1;
    v9 = 0;
    v10 = 0;
    v11 = 1;
    v34 = a4;
    while ( 1 )
    {
      v12 = a4 ? 1 << *(_BYTE *)(a4 + v9) : 0;
      v30 = v9 + 1;
      v31 = v11;
      if ( v9 + 1 < v6 )
        break;
LABEL_3:
      ++v9;
      a4 = v34;
      v11 = v31 + 1;
      if ( v30 == v6 )
        return v10 & 1;
    }
    while ( 1 )
    {
      v13 = *(_DWORD *)(a2 + 4 * v9);
      v14 = *(_DWORD *)(a2 + 4 * v11);
      if ( v13 != v14 )
      {
        v15 = v6;
        v36 = v10;
        v16 = policy_mgr_2_freq_same_mac_in_dbs(v8, v13, v14);
        if ( (v16 & 1) != 0 )
          v25 = policy_mgr_2_freq_same_mac_in_sbs(v8, v13, v14);
        else
          v25 = 1;
        v26 = jiffies;
        if ( policy_mgr_2_freq_always_on_same_mac___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: freq1 %d freq2 %d: Same mac:: DBS:%d SBS:%d",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "policy_mgr_2_freq_always_on_same_mac",
            v13,
            v14,
            v16 & 1,
            v25 & 1);
          policy_mgr_2_freq_always_on_same_mac___last_ticks = v26;
          if ( (v16 & v25 & 1) != 0 )
          {
LABEL_19:
            v8 = a1;
            v6 = v15;
            if ( a3 )
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: vdev %d and %d are in MCC with freq %d and freq %d",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "policy_mgr_is_ml_sta_links_in_mcc",
                *(unsigned __int8 *)(a3 + v9),
                *(unsigned __int8 *)(a3 + v11),
                *(unsigned int *)(a2 + 4 * v9),
                *(unsigned int *)(a2 + 4 * v11));
            v10 = 1;
            if ( v34 )
            {
              v27 = *(unsigned __int8 *)(v34 + v11);
              v12 |= 1 << v27;
              LODWORD(v29) = v12;
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: link %d and %d are in MCC with freq %d and freq %d bitmap 0x%x",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "policy_mgr_is_ml_sta_links_in_mcc",
                *(unsigned __int8 *)(v34 + v9),
                v27,
                *(unsigned int *)(a2 + 4 * v9),
                *(unsigned int *)(a2 + 4 * v11),
                v29);
              if ( a6 )
                *a6 |= v12;
            }
            goto LABEL_10;
          }
        }
        else if ( (v16 & v25 & 1) != 0 )
        {
          goto LABEL_19;
        }
        v8 = a1;
        v10 = v36;
        v6 = v15;
      }
LABEL_10:
      if ( (_DWORD)v6 == (unsigned __int8)++v11 )
        goto LABEL_3;
    }
  }
  LOBYTE(v10) = 0;
  return v10 & 1;
}
