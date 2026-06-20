__int64 __fastcall cm_update_phymode_on_roam(
        unsigned __int8 a1,
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
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x26
  __int64 v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 v32; // x25
  unsigned int v33; // w22
  unsigned int *v34; // x23
  void *v35; // x24
  unsigned int v36; // w8
  unsigned int v37; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w9
  unsigned int v47; // w8
  unsigned __int16 v48; // w2
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w4
  unsigned int v58; // w6
  unsigned int v59; // w8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // [xsp+0h] [xbp-30h]
  unsigned int v69; // [xsp+18h] [xbp-18h] BYREF
  _DWORD v70[5]; // [xsp+1Ch] [xbp-14h]

  *(_QWORD *)&v70[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(54, (__int64)"cm_update_phymode_on_roam", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v21 = *(_QWORD *)(result + 520) + 488LL * a1;
    v70[2] = 0;
    v22 = result;
    *(_QWORD *)v70 = 0;
    result = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)v21, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( result )
    {
      v31 = result;
      v32 = *(_QWORD *)(*(_QWORD *)(result + 504) + 152LL);
      wlan_reg_freq_to_chan(v32, *(_DWORD *)(v21 + 436), v23, v24, v25, v26, v27, v28, v29, v30);
      v33 = wma_fw_to_host_phymode(*(_DWORD *)(a2 + 2480) & 0x3F);
      v35 = *(void **)(*(_QWORD *)v21 + 32LL);
      v34 = *(unsigned int **)(*(_QWORD *)v21 + 40LL);
      v34[7] = v33;
      v36 = *(_DWORD *)(v21 + 180);
      v34[6] = v36;
      v37 = (unsigned __int16)*(_DWORD *)(a2 + 2468);
      *(_WORD *)v34 = *(_DWORD *)(a2 + 2468);
      v69 = v36;
      if ( wlan_reg_is_24ghz_ch_freq(v37) && v34[6] == 1 && (v46 = *(_DWORD *)(a2 + 2472)) != 0 )
      {
        v47 = *(unsigned __int16 *)v34;
        if ( v46 <= v47 )
          v48 = v47 - 20;
        else
          v48 = v47 + 20;
      }
      else
      {
        v48 = 0;
      }
      wlan_reg_set_channel_params_for_pwrmode(
        v32,
        *(unsigned __int16 *)v34,
        v48,
        (__int64)&v69,
        0,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45);
      v57 = v69;
      v58 = v70[1];
      v59 = v70[2];
      if ( v69 != v34[6] || *(_QWORD *)&v70[1] != *(_QWORD *)(a2 + 2472) )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: ch mismatch host & fw bw (%d %d) seg0 (%d, %d) seg1 (%d, %d)",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "wma_update_phymode_on_roam",
          v70[2],
          *(_DWORD *)(a2 + 2476));
        v58 = v70[1];
        v59 = v70[2];
        v57 = v69;
      }
      v34[4] = v58;
      v34[5] = v59;
      v34[6] = v57;
      qdf_mem_copy(v35, v34, 0x20u);
      *(_DWORD *)(v31 + 176) = wmi_host_to_fw_phymode(v33);
      wma_objmgr_set_peer_mlme_phymode(v22, (_BYTE *)(a2 + 14), v33);
      LODWORD(v68) = v34[5];
      result = qdf_trace_msg(
                 0x36u,
                 8u,
                 "%s: LFR3: new phymode %d freq %d (bw %d, %d %d)",
                 v60,
                 v61,
                 v62,
                 v63,
                 v64,
                 v65,
                 v66,
                 v67,
                 "wma_update_phymode_on_roam",
                 v33,
                 *(unsigned __int16 *)v34,
                 v34[6],
                 v34[4],
                 v68);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
