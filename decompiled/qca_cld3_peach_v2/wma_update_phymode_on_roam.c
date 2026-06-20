__int64 __fastcall wma_update_phymode_on_roam(
        __int64 a1,
        _BYTE *a2,
        _DWORD *a3,
        unsigned int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x0
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x21
  __int64 v27; // x25
  __int64 v28; // x1
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w0
  __int64 v38; // x8
  unsigned int *v39; // x22
  void *v40; // x23
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w9
  unsigned int v51; // w8
  unsigned int v52; // w2
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w4
  unsigned int v62; // w6
  unsigned int v63; // w8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  int v72; // w0
  int v73; // w2
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // [xsp+0h] [xbp-40h]
  __int64 v83; // [xsp+18h] [xbp-28h] BYREF
  __int64 v84; // [xsp+20h] [xbp-20h]
  __int64 v85; // [xsp+28h] [xbp-18h]
  unsigned int v86; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v87; // [xsp+38h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)a4;
  v86 = 0;
  v84 = 0;
  v85 = 0;
  v83 = 0;
  result = wlan_vdev_mlme_get_cmpt_obj(v16, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    v26 = result;
    v27 = *(_QWORD *)(*(_QWORD *)(result + 520) + 216LL);
    wlan_reg_freq_to_chan(v27, a4[109], v18, v19, v20, v21, v22, v23, v24, v25);
    if ( a3 )
    {
      v37 = wma_fw_to_host_phymode(a3[4] & 0x3F, v28);
      v38 = *(_QWORD *)a4;
      v86 = v37;
      v40 = *(void **)(v38 + 32);
      v39 = *(unsigned int **)(v38 + 40);
      v39[7] = v37;
      LODWORD(v38) = a4[45];
      v39[6] = v38;
      v41 = (unsigned __int16)a3[1];
      *(_WORD *)v39 = a3[1];
      LODWORD(v83) = v38;
      if ( wlan_reg_is_24ghz_ch_freq(v41) && v39[6] == 1 && (v50 = a3[2]) != 0 )
      {
        v51 = *(unsigned __int16 *)v39;
        if ( v50 <= v51 )
          v52 = v51 - 20;
        else
          v52 = v51 + 20;
      }
      else
      {
        v52 = 0;
      }
      wlan_reg_set_channel_params_for_pwrmode(
        v27,
        *(unsigned __int16 *)v39,
        v52,
        (__int64)&v83,
        0,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49);
      v61 = v83;
      v62 = v84;
      if ( (_DWORD)v83 != v39[6] || (_DWORD)v84 != a3[2] || (v63 = HIDWORD(v84), HIDWORD(v84) != a3[3]) )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: ch mismatch host & fw bw (%d %d) seg0 (%d, %d) seg1 (%d, %d)",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "wma_update_phymode_on_roam",
          HIDWORD(v84),
          a3[3]);
        v62 = v84;
        v63 = HIDWORD(v84);
        v61 = v83;
      }
      v39[4] = v62;
      v39[5] = v63;
      v39[6] = v61;
    }
    else
    {
      wma_get_phy_mode_cb(a4[109], a4[45], &v86, v29, v30, v31, v32, v33, v34, v35, v36);
      v40 = *(void **)(*(_QWORD *)a4 + 32LL);
      v39 = *(unsigned int **)(*(_QWORD *)a4 + 40LL);
      v39[7] = v86;
      v39[6] = a4[45];
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: LFR3: invalid chan",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "wma_update_phymode_on_roam");
    }
    qdf_mem_copy(v40, v39, 0x28u);
    v72 = wmi_host_to_fw_phymode(v86);
    v73 = v86;
    *(_DWORD *)(v26 + 192) = v72;
    wma_objmgr_set_peer_mlme_phymode(a1, a2, v73);
    LODWORD(v82) = v39[5];
    result = qdf_trace_msg(
               0x36u,
               8u,
               "%s: LFR3: new phymode %d freq %d (bw %d, %d %d)",
               v74,
               v75,
               v76,
               v77,
               v78,
               v79,
               v80,
               v81,
               "wma_update_phymode_on_roam",
               v86,
               *(unsigned __int16 *)v39,
               v39[6],
               v39[4],
               v82);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
