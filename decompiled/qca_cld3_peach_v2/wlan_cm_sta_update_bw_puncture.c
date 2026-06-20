__int64 __fastcall wlan_cm_sta_update_bw_puncture(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        int a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  unsigned __int16 *v15; // x25
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w6
  unsigned __int8 v41; // w8
  __int64 v42; // x5
  int v43; // w8
  int v44; // w9
  const char *v45; // x2
  __int64 v46; // [xsp+10h] [xbp-20h] BYREF
  __int64 v47; // [xsp+18h] [xbp-18h]
  __int64 v48; // [xsp+20h] [xbp-10h]
  __int64 v49; // [xsp+28h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v46 = 0;
  if ( !a1 || !a2 )
  {
    v45 = "%s: invalid input parameters";
LABEL_10:
    qdf_trace_msg(0x68u, 2u, v45, a8, a9, a10, a11, a12, a13, a14, a15, "wlan_cm_sta_update_bw_puncture");
    goto LABEL_11;
  }
  v15 = *(unsigned __int16 **)(a1 + 40);
  if ( !v15 )
  {
    v45 = "%s: invalid des chan";
    goto LABEL_10;
  }
  qdf_mem_set(&v46, 0x18u, 0);
  LODWORD(v46) = a7;
  result = wlan_cm_sta_set_chan_param(
             a1,
             *v15,
             a4,
             a3,
             a5,
             a6,
             (unsigned int *)&v46,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30);
  if ( !(_DWORD)result )
  {
    v40 = v46;
    if ( v15[16] != WORD1(v48) || *((_DWORD *)v15 + 6) != (_DWORD)v46 )
    {
      v41 = BYTE5(v46);
      v15[16] = WORD1(v48);
      *((_DWORD *)v15 + 6) = v40;
      v42 = *v15;
      *(unsigned __int16 *)((char *)v15 + 3) = __PAIR16__(BYTE6(v46), v41);
      v43 = v47;
      v44 = HIDWORD(v47);
      *((_DWORD *)v15 + 4) = v47;
      *((_DWORD *)v15 + 5) = v44;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: sta vdev %d freq %d bw %d puncture 0x%x ch_cfreq1 %d ch_cfreq2 %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "wlan_cm_sta_update_bw_puncture",
        *(unsigned __int8 *)(a1 + 168),
        v42,
        v43,
        v44);
      result = wlan_util_vdev_peer_set_param_send(a1, a2, 0, *((unsigned __int8 *)v15 + 24) | (v15[16] << 8));
      goto LABEL_12;
    }
LABEL_11:
    result = 4;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
