__int64 __fastcall wlan_dp_spm_get_flow_id_origin(
        __int64 *a1,
        _WORD *a2,
        const void *a3,
        __int64 a4,
        __int16 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x25
  __int64 v14; // x24
  __int64 v20; // x9
  __int64 v21; // x8
  unsigned __int64 *v22; // x11
  unsigned __int64 v23; // x10
  unsigned __int64 v24; // x9
  __int64 v25; // x9
  int v26; // w10
  __int64 v27; // x0
  __int64 v28; // x1
  __int64 v29; // x0
  __int64 v30; // x8
  int v31; // w10
  __int64 v32; // x11
  void *v33; // x0
  __int64 v34; // x8
  __int64 v35; // x1
  __int64 v36; // x0
  __int64 v37; // x8
  int v38; // w9
  __int64 v39; // x10
  unsigned __int64 v40; // x14
  unsigned int v41; // w15
  unsigned __int64 v42; // x11
  __int64 v43; // x13
  unsigned __int64 v44; // x16
  unsigned __int64 v45; // x12
  unsigned int v46; // w9
  __int64 result; // x0
  int v48; // w17
  __int64 v49; // x2
  unsigned __int64 v50; // x9
  unsigned __int64 v51; // x10
  __int64 v52; // x14
  unsigned __int64 v53; // x9
  __int64 v54; // x21
  unsigned int v55; // w20
  char v56; // w9
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // [xsp+0h] [xbp-210h] BYREF
  _QWORD v66[32]; // [xsp+8h] [xbp-208h] BYREF
  _QWORD v67[33]; // [xsp+108h] [xbp-108h] BYREF

  v67[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = a1[467];
  v65 = 0;
  if ( v13 )
  {
    v14 = *a1;
    qdf_spinlock_acquire(*a1 + 2984);
    qdf_list_remove_front((_DWORD *)(v14 + 2960), &v65);
    v20 = v65;
    if ( v65 )
    {
      v21 = *(_WORD *)(v65 + 48) & 0x3F;
      v22 = (unsigned __int64 *)(v13 + 8 * v21);
      v23 = *v22;
      *(_QWORD *)(v65 + 16) = *v22;
      v24 = v20 + 16;
      *(_QWORD *)(v24 + 8) = v22;
      atomic_store(v24, v22);
      if ( v23 )
        *(_QWORD *)(v23 + 8) = v24;
      v25 = v65;
      v26 = *(_DWORD *)(v65 + 128);
      *(_QWORD *)(v65 + 120) = a4;
      *(_DWORD *)(v25 + 128) = v26 | 1;
      *a2 = v21;
      v27 = qdf_spinlock_release(v14 + 2984);
      v29 = sched_clock(v27, v28);
      v30 = v65;
      v31 = flow_guid_gen;
      *(_QWORD *)(v65 + 136) = v29;
      *(_DWORD *)(v30 + 104) = v31;
      *(_WORD *)(v30 + 108) = a5;
      v32 = a1[458];
      flow_guid_gen = v31 + 1;
      *(_BYTE *)(v30 + 110) = *(_BYTE *)(v32 + 24);
      v33 = qdf_mem_copy((void *)(v30 + 52), a3, 0x30u);
      v34 = v65;
      *(_WORD *)(v65 + 112) = 255;
      *(_BYTE *)(v34 + 114) = -1;
      *(_BYTE *)(v34 + 50) = 1;
      v36 = sched_clock(v33, v35);
      v37 = v65;
      v38 = *(_DWORD *)(v65 + 92);
      *(_QWORD *)(v65 + 144) = v36;
      if ( (v38 & 8) != 0 )
      {
        v46 = *(_DWORD *)(v37 + 68);
        v41 = *(_DWORD *)(v37 + 52);
        v39 = 0;
        v40 = 0;
        v42 = 0;
        v43 = 0;
        v44 = 0;
        v45 = 0;
        *(_BYTE *)(v37 + 100) = 1;
      }
      else if ( (v38 & 0x20) != 0 )
      {
        v46 = *(_DWORD *)(v37 + 68);
        v39 = *(unsigned int *)(v37 + 76);
        v41 = *(_DWORD *)(v37 + 52);
        v43 = *(unsigned int *)(v37 + 60);
        v45 = (unsigned __int64)*(unsigned int *)(v37 + 72) << 32;
        v40 = (unsigned __int64)*(unsigned int *)(v37 + 80) << 32;
        v42 = (unsigned __int64)*(unsigned int *)(v37 + 56) << 32;
        v44 = (unsigned __int64)*(unsigned int *)(v37 + 64) << 32;
      }
      else
      {
        v39 = 0;
        v40 = 0;
        v41 = 0;
        v42 = 0;
        v43 = 0;
        v44 = 0;
        v45 = 0;
        v46 = 0;
      }
      v48 = *(unsigned __int8 *)(v37 + 88);
      v49 = 0xEA00000000LL;
      v50 = v45 | v46;
      v51 = (v40 | v39) ^ (v44 | v43) ^ (v42 | v41);
      v52 = 0x100000000LL;
      if ( v48 == 17 )
        v49 = 0;
      v53 = v51 ^ v50;
      if ( v48 != 6 )
        v52 = v49;
      *(_QWORD *)(v37 + 168) = v53
                             ^ 0x574C414E5F44505FLL
                             ^ (v52
                              | ((unsigned __int64)*(unsigned __int16 *)(v37 + 84) << 16)
                              | *(unsigned __int16 *)(v37 + 86));
      ++*(_DWORD *)(v13 + 516);
      v54 = *(_QWORD *)(v14 + 2936);
      if ( v54 )
      {
        v55 = *(unsigned __int16 *)(v37 + 48);
        v56 = *(_BYTE *)(v54 + 148);
        memset(v67, 0, 256);
        memset(v66, 0, sizeof(v66));
        if ( (v56 & 8) != 0 )
        {
          dp_print_tuple_to_str_1(v37 + 52, (__int64)v67);
          dp_print_tx_flow_info_to_str(v55, v66);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: STC: Add TX flow [%u] %s [%s]",
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            "wlan_dp_indicate_flow_add",
            v55,
            v67,
            v66);
        }
        if ( *(_DWORD *)(v54 + 152) <= 1u )
        {
          qdf_periodic_work_start(v54 + 16, *(_DWORD *)(v54 + 144));
          *(_DWORD *)(v54 + 152) = 2;
        }
      }
      if ( *(_DWORD *)(v14 + 2976) <= 4u )
        wlan_dp_spm_flow_retire(a1[467], 0);
      result = 0;
    }
    else
    {
      qdf_spinlock_release(v14 + 2984);
      *a2 = -1;
      wlan_dp_spm_flow_retire(a1[467], 0);
      result = 13;
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Feature not supported",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_dp_spm_get_flow_id_origin");
    result = 11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
