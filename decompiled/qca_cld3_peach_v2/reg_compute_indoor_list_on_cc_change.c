__int64 __fastcall reg_compute_indoor_list_on_cc_change(
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
  __int64 pdev_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  unsigned int v22; // w8
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  unsigned __int16 *v33; // x9
  unsigned int v34; // w4
  __int16 v35; // w11
  __int16 v36; // w12
  unsigned int v37; // w13
  __int16 v38; // w14
  __int16 v39; // w8
  __int64 v40; // x23
  __int64 v41; // x22
  __int64 v42; // x23
  __int64 v43; // x22
  __int64 v44; // x22
  __int64 v46; // [xsp+8h] [xbp-8h]

  pdev_obj = reg_get_pdev_obj(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( pdev_obj )
  {
    if ( (*(_BYTE *)(pdev_obj + 56760) & 1) == 0 && *(_BYTE *)(pdev_obj + 58944) == 1 )
    {
      v21 = 0;
      v46 = pdev_obj + 7344;
      do
      {
        v23 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v21, 21);
        if ( v23 )
        {
          v32 = *(_DWORD *)(v23 + 16) | 2u;
          if ( (_DWORD)v32 == 2 )
          {
            v33 = *(unsigned __int16 **)(v23 + 40);
            if ( v33 )
            {
              v34 = *v33;
              v32 = *(unsigned int *)(channel_map + 168);
              if ( (unsigned int)v32 <= v34 )
              {
                v32 = *(unsigned int *)(channel_map + 492);
                if ( (unsigned int)v32 >= v34 )
                {
                  v35 = 0;
                  v36 = 101;
                  while ( 1 )
                  {
                    v32 = (unsigned int)((v35 + v36) / 2);
                    v37 = *(_DWORD *)(channel_map + 12LL * (int)v32);
                    if ( v37 == v34 )
                      break;
                    v38 = v32 - 1;
                    if ( v37 < v34 )
                      v39 = v32 + 1;
                    else
                      v39 = v35;
                    if ( v37 >= v34 )
                      v36 = v38;
                    v35 = v39;
                    if ( v39 > v36 )
                    {
                      v40 = jiffies;
                      if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
                      {
                        v41 = v23;
                        qdf_trace_msg(
                          0x51u,
                          8u,
                          "%s: invalid channel center frequency %d",
                          v24,
                          v25,
                          v26,
                          v27,
                          v28,
                          v29,
                          v30,
                          v31,
                          "reg_get_chan_enum_for_freq");
                        v23 = v41;
                        reg_get_chan_enum_for_freq___last_ticks = v40;
                      }
                      v32 = 102;
                      goto LABEL_24;
                    }
                  }
                  if ( (unsigned int)v32 >= 0x66 )
                  {
LABEL_24:
                    v42 = jiffies;
                    if ( reg_compute_indoor_list_on_cc_change___last_ticks - jiffies + 125 < 0 )
                    {
                      v43 = v23;
                      qdf_trace_msg(
                        0x51u,
                        2u,
                        "%s: Invalid chan enum %d",
                        v24,
                        v25,
                        v26,
                        v27,
                        v28,
                        v29,
                        v30,
                        v31,
                        "reg_compute_indoor_list_on_cc_change",
                        (unsigned int)v32);
                      v23 = v43;
                      reg_compute_indoor_list_on_cc_change___last_ticks = v42;
                    }
                    goto LABEL_5;
                  }
                  v32 = v46 + 36LL * (unsigned int)v32;
                  if ( *(_DWORD *)(v32 + 8) )
                  {
                    v32 = *(unsigned __int8 *)(v32 + 13);
                    if ( (v32 & 2) != 0 )
                    {
                      v44 = v23;
                      reg_add_indoor_concurrency(
                        a2,
                        v21,
                        *v33,
                        *((_DWORD *)v33 + 6),
                        v24,
                        v25,
                        v26,
                        v27,
                        v28,
                        v29,
                        v30,
                        v31);
                      v23 = v44;
                    }
                  }
                }
              }
            }
          }
LABEL_5:
          wlan_objmgr_vdev_release_ref(v23, 0x15u, (unsigned int *)v32, v24, v25, v26, v27, v28, v29, v30, v31);
        }
        v22 = (unsigned __int8)v21++;
      }
      while ( v22 < 5 );
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev priv obj is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "reg_compute_indoor_list_on_cc_change");
    return 16;
  }
}
