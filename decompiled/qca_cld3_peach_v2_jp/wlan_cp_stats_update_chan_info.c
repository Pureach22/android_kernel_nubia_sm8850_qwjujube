__int64 __fastcall wlan_cp_stats_update_chan_info(__int64 a1, unsigned int *a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int *v5; // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 comp_private_obj; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x28
  unsigned int v27; // w8
  unsigned int v28; // w21
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  unsigned int v38; // w9
  _DWORD *v39; // x8
  __int64 v40; // x11
  char v41; // w21
  unsigned int *v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w11
  unsigned int v52; // w11
  unsigned int v53; // w10
  unsigned int v54; // w26
  unsigned __int16 v55; // w25
  unsigned int v56; // w24
  unsigned __int16 *bonded_chan_entry; // x0
  unsigned int *v58; // x23
  __int64 v59; // x8
  unsigned int v60; // w27
  unsigned int v61; // w22
  unsigned int v62; // w26
  _DWORD *v63; // x21
  __int64 v64; // x6
  unsigned int v65; // w24
  __int64 v66; // [xsp+20h] [xbp-10h]
  unsigned int *v67; // [xsp+28h] [xbp-8h]

  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 38);
  if ( result )
  {
    v14 = result;
    v15 = *(_QWORD *)(result + 152);
    if ( v15 )
    {
      comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(v15, 0x1Bu);
      if ( comp_private_obj )
      {
        v26 = *(_QWORD *)(comp_private_obj + 8);
        v66 = v26 + 24;
        if ( (*((_BYTE *)a2 + 57) & 1) == 0 )
        {
          v38 = *(unsigned __int8 *)(v26 + 20);
          if ( *(_BYTE *)(v26 + 20) )
          {
            v39 = (_DWORD *)(v26 + 72);
            v40 = *(unsigned __int8 *)(v26 + 20);
            do
            {
              if ( *(v39 - 1) == a2[11] )
              {
                if ( a2[12] == 1 && !*v39 )
                {
                  v51 = a2[3];
                  a2[2] -= *(v39 - 10);
                  a2[3] = v51 - *(v39 - 9);
                  v52 = a2[7];
                  v53 = a2[9];
                  a2[6] -= *(v39 - 6);
                  a2[9] = v53 - *(v39 - 3);
                  a2[7] = v52 - *(v39 - 5);
                }
                qdf_mem_copy(v39 - 12, a2, 0x7Cu);
                return wlan_objmgr_vdev_release_ref(v14, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49, v50);
              }
              --v40;
              v39 += 31;
            }
            while ( v40 );
            if ( v38 <= 0x65 )
              goto LABEL_17;
            qdf_trace_msg(
              0x62u,
              2u,
              "%s: Chan cnt exceed, channel_id=%d",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "wlan_cp_stats_update_chan_info",
              a2[11]);
          }
          else
          {
LABEL_17:
            v41 = v38 + 1;
            qdf_mem_copy((void *)(v66 + 124LL * *(unsigned __int8 *)(v26 + 20)), a2, 0x7Cu);
            *(_BYTE *)(v26 + 20) = v41;
          }
          return wlan_objmgr_vdev_release_ref(v14, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49, v50);
        }
        v27 = *((unsigned __int8 *)a2 + 56);
        if ( v27 > 3 )
        {
          if ( v27 == 8 )
          {
            v28 = 3;
            goto LABEL_28;
          }
          if ( v27 == 4 )
          {
            v28 = 2;
            goto LABEL_28;
          }
        }
        else
        {
          if ( v27 == 1 )
          {
            v54 = 1;
            v55 = *a2;
            v56 = *a2;
            goto LABEL_30;
          }
          if ( v27 == 2 )
          {
            v28 = 1;
LABEL_28:
            bonded_chan_entry = wlan_reg_get_bonded_chan_entry(*a2, v28, 0, v18, v19, v20, v21, v22, v23, v24, v25);
            if ( bonded_chan_entry )
            {
              v55 = *bonded_chan_entry;
              v56 = bonded_chan_entry[1];
              v54 = *((unsigned __int8 *)a2 + 56);
LABEL_30:
              qdf_trace_msg(
                0x62u,
                8u,
                "%s: freq :%d bw %d, range [%d-%d], num_freq:%d",
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                "wlan_cp_stats_update_channel_stats",
                v54);
              if ( v55 <= (unsigned int)(unsigned __int16)v56 )
              {
                v58 = nullptr;
                if ( v54 >= 0x10 )
                  v59 = 16;
                else
                  v59 = v54;
                v67 = (unsigned int *)v59;
                while ( 1 )
                {
                  v42 = v67;
                  if ( v58 == v67 )
                    return wlan_objmgr_vdev_release_ref(v14, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49, v50);
                  v60 = *(unsigned __int8 *)(v26 + 20);
                  v61 = v56;
                  v62 = a2[(_QWORD)v58 + 15];
                  if ( !*(_BYTE *)(v26 + 20) )
                    break;
                  v63 = (_DWORD *)(v26 + 36);
                  v64 = 0;
                  v65 = *(unsigned __int8 *)(v26 + 20);
                  do
                  {
                    if ( *(v63 - 3) == v55 )
                    {
                      qdf_trace_msg(
                        0x62u,
                        8u,
                        "%s: update rcc: %d, cc:%d at index: %d, freq: %d",
                        v43,
                        v44,
                        v45,
                        v46,
                        v47,
                        v48,
                        v49,
                        v50,
                        "wlan_cp_stats_update_per_channel_stats",
                        a2[2],
                        a2[3]);
                      *(v63 - 1) = v62;
                      *v63 = a2[3];
                      goto LABEL_36;
                    }
                    ++v64;
                    v63 += 31;
                  }
                  while ( *(unsigned __int8 *)(v26 + 20) != v64 );
                  if ( v60 <= 0x65 )
                    goto LABEL_45;
                  qdf_trace_msg(
                    0x62u,
                    8u,
                    "%s: Chan cnt exceed, channel_id: %d",
                    v43,
                    v44,
                    v45,
                    v46,
                    v47,
                    v48,
                    v49,
                    v50,
                    "wlan_cp_stats_update_per_channel_stats",
                    a2[11]);
LABEL_36:
                  v55 += 20;
                  v56 = v61;
                  v58 = (unsigned int *)((char *)v58 + 1);
                  v42 = (unsigned int *)v55;
                  if ( v55 > (unsigned int)(unsigned __int16)v61 )
                    return wlan_objmgr_vdev_release_ref(v14, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49, v50);
                }
                v65 = 0;
LABEL_45:
                a2[2] = v62;
                *a2 = v55;
                qdf_trace_msg(
                  0x62u,
                  8u,
                  "%s: Add rcc: %d cc: %d, at index: %d, freq: %d",
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  "wlan_cp_stats_update_per_channel_stats",
                  v62,
                  v62,
                  v60,
                  v55);
                qdf_mem_copy((void *)(v66 + 124LL * v65), a2, 0x7Cu);
                *(_BYTE *)(v26 + 20) = v60 + 1;
                goto LABEL_36;
              }
              return wlan_objmgr_vdev_release_ref(v14, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49, v50);
            }
            qdf_trace_msg(
              0x62u,
              8u,
              "%s: range is NULL for freq %d, ch_width %d",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "wlan_cp_stats_update_channel_stats",
              *a2,
              v28);
            return wlan_objmgr_vdev_release_ref(v14, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49, v50);
          }
        }
        qdf_trace_msg(
          0x62u,
          8u,
          "%s: Invalid scanned_ch_width",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "wlan_cp_stats_update_channel_stats");
        return wlan_objmgr_vdev_release_ref(v14, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49, v50);
      }
      wlan_objmgr_vdev_release_ref(v14, 0x26u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
      v37 = "%s: pdev cp stats object is null";
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v14, 0x26u, v5, v6, v7, v8, v9, v10, v11, v12, v13);
      v37 = "%s: pdev object is null";
    }
    return qdf_trace_msg(0x62u, 2u, v37, v29, v30, v31, v32, v33, v34, v35, v36, "wlan_cp_stats_update_chan_info");
  }
  return result;
}
