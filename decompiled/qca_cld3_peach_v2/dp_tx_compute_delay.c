__int64 __fastcall dp_tx_compute_delay(__int64 result, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 v6; // x21
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x9
  __int64 v27; // x26
  __int64 v28; // x23
  __int64 v29; // x24
  __int64 v30; // x22
  unsigned int v31; // w21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  if ( (*(_BYTE *)(*(_QWORD *)(result + 24) + 95938LL) & 1) == 0 )
  {
    if ( !*(_BYTE *)(result + 46141) )
      return result;
    goto LABEL_5;
  }
  if ( *(_BYTE *)(result + 46141) )
  {
LABEL_5:
    v6 = result;
    result = ktime_get_with_offset(0);
    if ( (unsigned __int8)a3 <= 9u && (unsigned __int8)a4 < 5u )
      return dp_update_delay_stats(
               v6 + 6768LL * (unsigned __int8)a4 + 752LL * (unsigned __int8)a3 + 9408,
               nullptr,
               (int)*(_QWORD *)(a2 + 80) / -1000 + (int)result / 1000,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               a3,
               2u,
               a4,
               1);
LABEL_12:
    __break(0x5512u);
    return dp_tx_get_link_id_from_ppdu_id_wrapper(result);
  }
  v16 = result;
  result = ktime_get_with_offset(0);
  v26 = *(_QWORD *)(a2 + 80);
  if ( (unsigned __int64)(v26 + 999999) >= 0x1E847F )
  {
    if ( (unsigned __int8)a3 <= 9u && (unsigned __int8)a4 < 5u )
    {
      v27 = v16;
      v28 = v16 + 6768LL * (unsigned __int8)a4 + 752LL * (unsigned __int8)a3;
      v29 = v26 / 1000000;
      dp_update_delay_stats(
        v28 + 9408,
        nullptr,
        (int)result / 1000000 - v26 / 1000000,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        a3,
        2u,
        a4,
        0);
      v30 = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 32LL) / 1000000LL;
      v31 = v30 - *(_DWORD *)(v27 + 384);
      dp_update_delay_stats(v28 + 9408, nullptr, v29 - v30, v32, v33, v34, v35, v36, v37, v38, v39, a3, 0, a4, 0);
      result = dp_update_delay_stats(v28 + 9408, nullptr, v31, v40, v41, v42, v43, v44, v45, v46, v47, a3, 1u, a4, 0);
      *(_QWORD *)(v27 + 384) = v30;
      return result;
    }
    goto LABEL_12;
  }
  return result;
}
