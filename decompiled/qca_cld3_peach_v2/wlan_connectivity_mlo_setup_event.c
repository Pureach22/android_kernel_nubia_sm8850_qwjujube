__int64 __fastcall wlan_connectivity_mlo_setup_event(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  void *v21; // x0
  unsigned __int64 time_of_the_day_us; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x21
  __int64 v33; // x23
  unsigned __int64 v34; // x22
  __int64 v35; // x27
  __int64 v36; // x28
  __int64 v37; // x19
  int v38; // w4
  unsigned __int16 *v39; // x24
  __int64 v40; // x25
  char *v41; // x20
  unsigned int v42; // w0
  __int64 v43; // x8
  char v44; // w9
  char *v45; // x19
  unsigned __int64 v46; // x26
  unsigned int v47; // w0
  char v48; // w8
  __int64 v49; // x4
  const char *v50; // x2
  __int64 v51; // [xsp+18h] [xbp-88h] BYREF
  unsigned __int64 v52; // [xsp+20h] [xbp-80h]
  __int64 v53; // [xsp+28h] [xbp-78h]
  __int64 v54; // [xsp+30h] [xbp-70h]
  _QWORD v55[11]; // [xsp+38h] [xbp-68h] BYREF
  int v56; // [xsp+90h] [xbp-10h]
  __int64 v57; // [xsp+98h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v54 = 0;
  memset(v55, 0, sizeof(v55));
  v52 = 0;
  v53 = 0;
  v51 = 0;
  if ( wlan_cm_is_vdev_connecting(a1, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    result = mlo_is_mld_sta(a1);
    if ( (result & 1) == 0 )
      goto LABEL_29;
  }
  result = wlan_cm_is_vdev_active(a1, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( (result & 1) != 0 && (a2 & 1) == 0 )
    goto LABEL_29;
  v21 = qdf_mem_set(&v51, 0x7Cu, 0);
  v54 = ktime_get(v21) / 1000;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v31 = *(_QWORD *)(a1 + 1360);
  v52 = time_of_the_day_us;
  LOBYTE(v55[0]) = 3;
  if ( !v31 )
  {
    v49 = *(unsigned __int8 *)(a1 + 168);
    v50 = "%s: vdev: %d MLO dev ctx not found";
LABEL_28:
    result = qdf_trace_msg(
               0x38u,
               2u,
               v50,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               "wlan_connectivity_mlo_setup_event",
               v49);
    goto LABEL_29;
  }
  v32 = *(_QWORD *)(v31 + 3880);
  if ( !v32 )
  {
    v49 = *(unsigned __int8 *)(a1 + 168);
    v50 = "%s: vdev: %d mlo link ctx not found";
    goto LABEL_28;
  }
  v33 = 0;
  v34 = 0;
  v35 = 41;
  v36 = 81;
  do
  {
    v37 = v32 + v33;
    v38 = *(unsigned __int8 *)(v32 + v33 + 6);
    if ( v38 != 255 )
    {
      v39 = *(unsigned __int16 **)(v37 + 32);
      if ( v39 )
      {
        if ( v34 > 2 )
          goto LABEL_31;
        v40 = v32 + v33;
        v41 = (char *)v55 + 12 * v34 + 4;
        v41[1] = v38;
        v41[2] = *(_BYTE *)(v32 + v33 + 12);
        qdf_mem_copy(v41 + 6, (const void *)(v32 + v33 + 24), 6u);
        v42 = wlan_reg_freq_to_band(*v39);
        if ( v42 > 2 )
        {
          *v41 = 0;
          *((_BYTE *)&v51 + v35) = 1;
        }
        else
        {
          *v41 = v42 + 1;
        }
        v43 = 2 * v34;
        if ( ((16 * v34) | 0x4D) > 0x7C )
          goto LABEL_30;
        v44 = *(_BYTE *)(v37 + 6);
        v45 = (char *)&v55[v43 + 5] + 4;
        BYTE5(v55[v43 + 5]) = v44;
        if ( ((v43 * 8) | 0x4EuLL) > 0x7C
          || (v46 = (v43 * 8) | 0x4C,
              v45[2] = *(_BYTE *)(v40 + 12),
              qdf_mem_copy(v45 + 6, (const void *)(v40 + 24), 6u),
              *((_DWORD *)v45 + 3) = *v39,
              v47 = wlan_reg_freq_to_band(*v39),
              v46 > 0x7C) )
        {
LABEL_30:
          __break(1u);
LABEL_31:
          __break(0x5512u);
        }
        if ( v47 < 3 )
          v48 = v47 + 1;
        else
          v48 = 0;
        *v45 = v48;
        if ( !*v41 )
          *((_BYTE *)&v51 + v36) = 1;
        ++v34;
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          8u,
          "%s: link %d: chan_info not found",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "wlan_connectivity_mlo_setup_event");
      }
    }
    v33 += 48;
    v35 += 12;
    v36 += 16;
  }
  while ( v33 != 144 );
  BYTE3(v55[0]) = 3;
  BYTE1(v55[0]) = v34;
  BYTE2(v55[0]) = v34;
  LODWORD(v55[5]) = 16;
  result = host_diag_event_report_payload(3415, 124, &v51);
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
