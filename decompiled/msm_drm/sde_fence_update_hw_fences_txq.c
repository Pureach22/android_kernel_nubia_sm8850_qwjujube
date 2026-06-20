__int64 __fastcall sde_fence_update_hw_fences_txq(unsigned int *a1, char a2, int a3, char a4)
{
  unsigned int *v8; // x27
  unsigned int *v9; // x28
  unsigned int *v10; // x24
  __int64 v11; // x6
  _QWORD *v12; // x25
  int v13; // w24
  unsigned int v14; // w22
  unsigned int *v15; // x25
  __int64 v16; // x24
  unsigned int *v17; // x8
  size_t v19; // x0
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  unsigned int v24; // w8
  __int64 v25; // x27
  char v26; // w11
  unsigned int v27; // w23
  int v28; // w25
  int v29; // w8
  const char *v30; // x6
  unsigned __int64 v31; // x9
  int v32; // w24
  __int64 v33; // x8
  _DWORD *v34; // x8
  __int64 v35; // x1
  _DWORD *v36; // x9
  __int64 v37; // x1
  _DWORD *v38; // x8
  int v39; // w7
  __int64 v40; // x8
  void (__fastcall *v41)(__int64, __int64); // x8
  __int64 v42; // x0
  __int64 v43; // x1
  __int64 v44; // x8
  __int64 v45; // x8
  char v46; // [xsp+0h] [xbp-30h]

  raw_spin_lock(a1 + 5);
  v8 = a1 + 12;
  v9 = *((unsigned int **)a1 + 6);
  if ( v9 != a1 + 12 )
  {
    while ( 1 )
    {
      v10 = *(unsigned int **)v9;
      v11 = *((_QWORD *)v9 - 6);
      if ( (v11 & 0x80000000) != 0 && (v9[10] & 1) == 0 && *((_QWORD *)v9 - 7) <= (unsigned __int64)*a1 )
        break;
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "skip fence ctx:%llu seq:%llu f:0x%lx commit_cnt:%d txq:%d\n",
          *((_QWORD *)v9 - 8),
          *((_QWORD *)v9 - 7),
          v11,
          *a1,
          *((unsigned __int8 *)v9 + 40));
      v9 = v10;
      if ( v10 == v8 )
      {
        LODWORD(v12) = 0;
        v13 = 0;
        v14 = 0;
        goto LABEL_10;
      }
    }
    v12 = *((_QWORD **)v9 + 3);
    if ( v12 )
    {
      v31 = v12[21];
      v32 = *((_DWORD *)v12 + 16) - 1;
      if ( v31 && v31 < 0xFFFFFFFFFFFFF001LL )
      {
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_fence_update_hw_fences_txq",
          682,
          -1,
          v32,
          HIDWORD(*((_QWORD *)v9 + 4)),
          *((_QWORD *)v9 + 4),
          *(_DWORD *)v12[28],
          BYTE4(*((_QWORD *)v9 - 8)));
        v19 = synx_signal(v12[21], v9[8], 2);
        if ( (_DWORD)v19 )
        {
          v14 = v19;
          printk(&unk_21AADC, "sde_fence_update_hw_fences_txq");
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_fence_update_hw_fences_txq",
            690,
            -1,
            21845,
            *((_QWORD *)v9 - 6),
            *((_QWORD *)v9 - 8),
            *((_QWORD *)v9 - 7),
            v32);
          LODWORD(v12) = 0;
        }
        else
        {
          v33 = *((unsigned int *)v12 + 7);
          if ( (unsigned int)v33 >= 3 )
            goto LABEL_84;
          v34 = (_DWORD *)v12[v33 + 65];
          if ( v34 )
          {
            v35 = *(unsigned int *)v12[28];
            if ( *(v34 - 1) != -1646250321 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, __int64))v34)(v12, v35);
          }
          LODWORD(v12) = 1;
          *((_BYTE *)v9 + 40) = 1;
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "update txq fence:0x%pK ctx:%llu seqno:%llu f:0x%lx ctl:%d vid:%d\n",
              v9 - 24,
              *((_QWORD *)v9 - 8),
              *((_QWORD *)v9 - 7),
              *((_QWORD *)v9 - 6),
              v32,
              a2 & 1);
          v14 = 0;
        }
      }
      else
      {
        printk(&unk_22F50D, "sde_fence_update_hw_fences_txq");
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_fence_update_hw_fences_txq",
          673,
          -1,
          17476,
          *((_QWORD *)v9 - 6),
          *((_QWORD *)v9 - 8),
          *((_QWORD *)v9 - 7),
          v32);
        LODWORD(v12) = 0;
        v14 = -22;
      }
      v13 = 1;
    }
    else
    {
      printk(&unk_24A3BF, "sde_fence_update_hw_fences_txq");
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_fence_update_hw_fences_txq",
        662,
        -1,
        13107,
        *((_QWORD *)v9 - 6),
        *((_QWORD *)v9 - 8),
        *((_QWORD *)v9 - 7),
        173);
      v13 = 0;
      v14 = -22;
    }
LABEL_10:
    raw_spin_unlock(a1 + 5);
    if ( !a3 && ((unsigned int)v12 & v13) == 0 )
      return v14;
    raw_spin_lock(a1 + 5);
    v15 = *(unsigned int **)v8;
    if ( *(unsigned int **)v8 == v8 )
    {
LABEL_18:
      raw_spin_unlock(a1 + 5);
      return v14;
    }
    v16 = 0;
    do
    {
      v17 = *(unsigned int **)v15;
      if ( (*((_QWORD *)v15 - 6) & 0x80000000) != 0 )
      {
        v16 = *((_QWORD *)v15 + 3);
        if ( !v16 )
        {
          printk(&unk_24A3BF, "_sde_fence_arm_output_hw_fence");
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_fence_arm_output_hw_fence",
            602,
            -1,
            60333,
            13107,
            *((_QWORD *)v15 - 6),
            *((_QWORD *)v15 - 8),
            *((_QWORD *)v15 - 7));
          goto LABEL_18;
        }
      }
      v15 = *(unsigned int **)v15;
    }
    while ( v17 != v8 );
    v19 = raw_spin_unlock(a1 + 5);
    if ( !v16 )
      return v14;
    v24 = *(_DWORD *)(v16 + 28);
    if ( v24 >= 3 )
    {
LABEL_84:
      __break(0x5512u);
      return sde_fence_update_input_hw_fence_signal(v19, v20, v21, v22, v23);
    }
    v25 = v16 + 424;
    if ( !*(_QWORD *)(v16 + 424 + 8LL * v24) || !*(_QWORD *)(v16 + 472 + 8LL * v24) )
    {
      if ( !v24 )
        printk(&unk_269F1E, "_arm_output_hw_fence");
      return v14;
    }
    v22 = *(unsigned int *)(v16 + 256);
    if ( (unsigned int)v22 >= 2 )
    {
      printk(&unk_243ECB, "_arm_output_hw_fence");
      return v14;
    }
    v26 = _drm_debug;
    v27 = *(_DWORD *)(v16 + 4 * v22 + 248);
    v28 = *(_DWORD *)(v16 + 64) - 1;
    *(_DWORD *)(v16 + 256) = v22 ^ 1;
    if ( (v26 & 4) == 0 )
    {
LABEL_62:
      if ( (a4 & 2) != 0 )
      {
        if ( v24 > 2 )
          goto LABEL_84;
        v36 = *(_DWORD **)(v16 + 8LL * v24 + 376);
        if ( !v36 )
          goto LABEL_69;
        if ( *(v36 - 1) != 128872864 )
          __break(0x8229u);
        v19 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v36)(v16, 1, 0);
        v24 = *(_DWORD *)(v16 + 28);
      }
      if ( v24 > 2 )
        goto LABEL_84;
LABEL_69:
      v37 = *(unsigned int *)(v16 + 260);
      v38 = *(_DWORD **)(v16 + 472 + 8LL * v24);
      if ( *(v38 - 1) != -1400796485 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v38)(v16, v37, v27);
      v19 = sde_evtlog_log(sde_dbg_base_evtlog, "_arm_output_hw_fence", 558, 4, v28, v27, -1059143953, v39, v46);
      if ( a3 )
      {
        v40 = *(unsigned int *)(v16 + 28);
        if ( (unsigned int)v40 <= 2 )
        {
          v41 = *(void (__fastcall **)(__int64, __int64))(v25 + 8 * v40);
          v42 = v16;
          v43 = 1;
LABEL_80:
          if ( *((_DWORD *)v41 - 1) != -1646250321 )
            __break(0x8228u);
          v41(v42, v43);
          return v14;
        }
      }
      else if ( (a2 & 1) != 0 && (*(_BYTE *)(*(_QWORD *)(v16 + 72) + 33LL) & 1) != 0 )
      {
        v45 = *(unsigned int *)(v16 + 28);
        if ( (unsigned int)v45 <= 2 )
        {
          v41 = *(void (__fastcall **)(__int64, __int64))(v25 + 8 * v45);
          v42 = v16;
          v43 = 2;
          goto LABEL_80;
        }
      }
      else
      {
        v44 = *(unsigned int *)(v16 + 28);
        if ( (unsigned int)v44 <= 2 )
        {
          v41 = *(void (__fastcall **)(__int64, __int64))(v25 + 8 * v44);
          v42 = v16;
          v43 = 0;
          goto LABEL_80;
        }
      }
      goto LABEL_84;
    }
    v29 = *(_DWORD *)(v16 + 164);
    if ( v29 <= 1217 )
    {
      switch ( v29 )
      {
        case 1024:
          v30 = "SYNX_CLIENT_HW_FENCE_GFX_CTX0";
          goto LABEL_61;
        case 1216:
          v30 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL0";
          goto LABEL_61;
        case 1217:
          v30 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL1";
LABEL_61:
          _drm_dev_dbg(0, 0, 0, "out-fence ctl_id:%d out_signal:%d hw_fence_client:%s\n", v28, v27, v30);
          v24 = *(_DWORD *)(v16 + 28);
          goto LABEL_62;
      }
    }
    else
    {
      if ( v29 <= 1219 )
      {
        if ( v29 == 1218 )
          v30 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL2";
        else
          v30 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL3";
        goto LABEL_61;
      }
      if ( v29 == 1220 )
      {
        v30 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL4";
        goto LABEL_61;
      }
      if ( v29 == 1221 )
      {
        v30 = "SYNX_CLIENT_HW_FENCE_DPU0_CTL5";
        goto LABEL_61;
      }
    }
    v30 = "Unknown";
    goto LABEL_61;
  }
  raw_spin_unlock(a1 + 5);
  return 0;
}
