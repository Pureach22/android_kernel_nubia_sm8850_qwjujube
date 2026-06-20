__int64 __fastcall wlan_scan_update_low_latency_profile_chnlist(
        __int64 a1,
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
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  unsigned int v23; // w20
  unsigned __int64 v24; // x24
  unsigned __int64 v25; // x23
  _DWORD *v26; // x22
  unsigned int v27; // w8
  _DWORD *v28; // x27
  int v29; // w8
  unsigned __int64 v30; // x24
  unsigned __int64 v31; // x23
  _DWORD *v32; // x22
  unsigned int v33; // w8
  unsigned __int64 v34; // x26
  unsigned __int64 v35; // x23
  unsigned int v36; // w22
  unsigned int *v37; // x26
  __int64 v38; // x8
  __int64 v39; // x10
  unsigned __int64 v40; // x4
  __int64 v41; // [xsp+0h] [xbp-80h] BYREF
  __int64 v42; // [xsp+8h] [xbp-78h]
  __int64 v43; // [xsp+10h] [xbp-70h]
  __int64 v44; // [xsp+18h] [xbp-68h]
  __int64 v45; // [xsp+20h] [xbp-60h]
  __int64 v46; // [xsp+28h] [xbp-58h]
  __int64 v47; // [xsp+30h] [xbp-50h]
  __int64 v48; // [xsp+38h] [xbp-48h]
  __int64 v49; // [xsp+40h] [xbp-40h]
  __int64 v50; // [xsp+48h] [xbp-38h]
  __int64 v51; // [xsp+50h] [xbp-30h]
  __int64 v52; // [xsp+58h] [xbp-28h]
  __int64 v53; // [xsp+60h] [xbp-20h]
  __int64 v54; // [xsp+68h] [xbp-18h]
  __int64 v55; // [xsp+70h] [xbp-10h]
  __int64 v56; // [xsp+78h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    result = qdf_trace_msg(
               0x15u,
               2u,
               "%s: psoc is null",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wlan_scan_update_low_latency_profile_chnlist");
    goto LABEL_39;
  }
  result = policy_mgr_get_ll_ht_sap_freq(*(_QWORD *)(v10 + 80));
  if ( (_DWORD)result )
  {
    v22 = *(_DWORD *)(a2 + 2080);
    v23 = result;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v44 = 0;
    v45 = 0;
    v42 = 0;
    v43 = 0;
    v41 = 0;
    if ( v22 )
    {
      v24 = 0;
      v25 = 0;
      v26 = (_DWORD *)(a2 + 2168);
      while ( v24 != 10 )
      {
        v27 = *(v26 - 1);
        if ( v27 >= 0x10000 )
        {
          result = policy_mgr_2_freq_always_on_same_mac(v11, v23, HIWORD(v27));
          if ( (result & 1) == 0 )
          {
            if ( v25 > 9 )
              break;
            v28 = (_DWORD *)&v41 + 3 * v25;
            result = (__int64)qdf_mem_copy(v28 + 1, v26, 6u);
            ++v25;
            *v28 = *(v26 - 1);
          }
        }
        ++v24;
        v26 += 3;
        if ( v24 >= *(unsigned int *)(a2 + 2080) )
        {
          result = (__int64)qdf_mem_set((void *)(a2 + 2164), 0x78u, 0);
          if ( v25 )
            result = (__int64)qdf_mem_copy((void *)(a2 + 2164), &v41, 0x78u);
          *(_DWORD *)(a2 + 2080) = v25;
          goto LABEL_16;
        }
      }
    }
    else
    {
LABEL_16:
      v29 = *(_DWORD *)(a2 + 2076);
      v49 = 0;
      v50 = 0;
      v47 = 0;
      v48 = 0;
      v45 = 0;
      v46 = 0;
      v43 = 0;
      v44 = 0;
      v41 = 0;
      v42 = 0;
      if ( v29 )
      {
        v30 = 0;
        v31 = 0;
        v32 = (_DWORD *)(a2 + 2088);
        while ( v30 != 10 )
        {
          v33 = *(v32 - 1);
          if ( v33 >= 0x10000 )
          {
            result = policy_mgr_2_freq_always_on_same_mac(v11, v23, HIWORD(v33));
            if ( (result & 1) == 0 )
            {
              if ( v31 > 9 )
                break;
              v34 = (unsigned __int64)(&v41 + v31);
              result = (__int64)qdf_mem_copy((void *)(v34 | 4), v32, 4u);
              ++v31;
              *(_DWORD *)v34 = *(v32 - 1);
            }
          }
          ++v30;
          v32 += 2;
          if ( v30 >= *(unsigned int *)(a2 + 2076) )
          {
            result = (__int64)qdf_mem_set((void *)(a2 + 2084), 0x50u, 0);
            if ( v31 )
              result = (__int64)qdf_mem_copy((void *)(a2 + 2084), &v41, 0x50u);
            *(_DWORD *)(a2 + 2076) = v31;
            goto LABEL_27;
          }
        }
      }
      else
      {
LABEL_27:
        if ( !*(_BYTE *)(a2 + 120) )
          goto LABEL_35;
        v35 = 0;
        v36 = 0;
        v37 = (unsigned int *)(a2 + 124);
        while ( v35 != 102 )
        {
          result = policy_mgr_2_freq_always_on_same_mac(v11, v23, *v37);
          if ( (result & 1) == 0 )
          {
            if ( v36 > 0x66 )
              break;
            v38 = a2 + 124 + 12LL * v36;
            v39 = *(_QWORD *)v37;
            ++v36;
            *(_DWORD *)(v38 + 8) = v37[2];
            *(_QWORD *)v38 = v39;
          }
          v40 = *(unsigned __int8 *)(a2 + 120);
          ++v35;
          v37 += 3;
          if ( v35 >= v40 )
            goto LABEL_36;
        }
      }
    }
    __break(0x5512u);
LABEL_35:
    v36 = 0;
    LODWORD(v40) = 0;
LABEL_36:
    if ( v36 < (unsigned int)v40 )
      result = qdf_trace_msg(
                 0x15u,
                 8u,
                 "%s: For DBS: only 2.4Ghz chan and for SBS: mutually exclusive ll-sap 5GHz chan allowed, total-chan %d, "
                 "remaining-chan %d, ll-sap chan %d",
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "wlan_scan_update_low_latency_profile_chnlist",
                 v41,
                 v42,
                 v43,
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
                 v54,
                 v55,
                 v56);
    *(_BYTE *)(a2 + 120) = v36;
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
