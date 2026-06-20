__int64 __fastcall hdd_cfg80211_update_pcl(__int64 a1, __int64 a2, unsigned __int8 a3, __int64 a4, __int64 a5)
{
  __int64 v10; // x24
  __int64 v11; // x25
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _WORD *v20; // x24
  __int64 v21; // x25
  __int64 v22; // x26
  __int64 v23; // x27
  _WORD *v24; // x26
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  _BYTE v34[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v35; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v36[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+18h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 216);
  v11 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 32779, 0, 0) & 0x80000000) != 0 || (v20 = (_WORD *)(v10 + v11)) == nullptr )
  {
LABEL_13:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: updating pcl list failed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_cfg80211_update_pcl");
    result = 4294967274LL;
    goto LABEL_14;
  }
  if ( a3 )
  {
    v21 = 0;
    do
    {
      v22 = *(_QWORD *)(a2 + 216);
      v23 = *(unsigned int *)(a2 + 208);
      if ( (nla_put(a2, (unsigned int)v21 | 0x8000, 0, 0) & 0x80000000) != 0 )
        goto LABEL_13;
      v24 = (_WORD *)(v22 + v23);
      if ( !v24 )
        goto LABEL_13;
      v34[0] = wlan_reg_freq_to_chan(
                 *(_QWORD *)(a1 + 8),
                 *(_DWORD *)(a4 + 4 * v21),
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19);
      if ( (unsigned int)nla_put(a2, 1, 1, v34)
        || (v35 = *(_DWORD *)(a4 + 4 * v21), (unsigned int)nla_put(a2, 3, 4, &v35))
        || (v36[0] = *(_BYTE *)(a5 + v21), (unsigned int)nla_put(a2, 2, 1, v36)) )
      {
        qdf_trace_msg(0x33u, 2u, "%s: put fail", v25, v26, v27, v28, v29, v30, v31, v32, "hdd_cfg80211_update_pcl");
        goto LABEL_13;
      }
      ++v21;
      *v24 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v24;
    }
    while ( a3 != v21 );
  }
  result = 0;
  *v20 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v20;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
