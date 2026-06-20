__int64 __fastcall sde_hw_fence_init(__int64 a1, __int64 a2, char a3, char a4, __int64 a5)
{
  __int64 v5; // x8
  unsigned int v7; // w19
  _DWORD *v8; // x8
  int v9; // w9
  _DWORD *v10; // x9
  long double v13; // q0
  int v14; // w8
  __int64 v15; // x0
  unsigned __int64 v16; // x8
  int v17; // w9
  int v18; // w0
  int v19; // w7
  long double v20; // q0
  int v21; // w21
  int v22; // w8
  _DWORD *v23; // x9
  __int64 v24; // x2
  __int64 v25; // x21
  unsigned int v26; // w0
  __int64 v27; // x8
  char v28; // w10
  __int64 v29; // x9
  _DWORD *v30; // x8
  _DWORD *v31; // x9
  __int64 result; // x0
  char v33; // w8
  unsigned int v34; // w20
  char v35; // [xsp+0h] [xbp-30h]
  __int64 v36; // [xsp+10h] [xbp-20h] BYREF
  __int64 v37; // [xsp+18h] [xbp-18h]
  __int64 v38; // [xsp+20h] [xbp-10h]
  __int64 v39; // [xsp+28h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_29;
  v5 = *(unsigned int *)(a1 + 28);
  v37 = 0;
  v38 = 0;
  v36 = 0;
  if ( (unsigned int)v5 < 3 )
  {
    if ( !*(_QWORD *)(a1 + 8 * v5 + 496) )
    {
      if ( (_DWORD)v5 == 1 )
        result = 0;
      else
        result = 4294967274LL;
      goto LABEL_30;
    }
    v7 = *(_DWORD *)(a1 + 64) - 1;
    if ( v7 >= 6 )
    {
      printk(&unk_254A3D, "sde_hw_fence_init");
      result = 4294967274LL;
      goto LABEL_30;
    }
    v8 = &hw_fence_data_dpu_client;
    v9 = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22128LL);
    if ( (a4 & 1) != 0 )
      v8 = &hw_fence_data_dpu_client_with_soccp;
    if ( (a3 & 1) == 0 )
      v8 = &hw_fence_data_no_dpu;
    if ( v9 )
    {
      v8[25] = v9;
      v8[26] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22124LL);
      v8[61] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22128LL);
      v8[62] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22124LL);
      v8[97] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22128LL);
      v8[98] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22124LL);
      v8[133] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22128LL);
      v8[134] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22124LL);
      v8[169] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22128LL);
      v8[170] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22124LL);
      v8[205] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22128LL);
      v8[206] = *(_DWORD *)(*(_QWORD *)(a2 + 152) + 22124LL);
    }
    v10 = &v8[36 * v7];
    if ( *v10 != v7 )
    {
      printk(&unk_2580C9, "sde_hw_fence_init");
      result = 4294967274LL;
      goto LABEL_30;
    }
    memcpy((void *)(a1 + 160), v10, 0x90u);
    if ( (_drm_debug & 4) != 0 )
      *(double *)&v13 = _drm_dev_dbg(0, 0, 0, "hwfence register ctl:%d client:%d\n", v7, *(_DWORD *)(a1 + 164));
    v14 = *(_DWORD *)(a1 + 164);
    v37 = a1 + 176;
    LODWORD(v38) = v14;
    *(_QWORD *)(a1 + 168) = synx_initialize(&v36, v13);
    v15 = dma_fence_context_alloc(1);
    v16 = *(_QWORD *)(a1 + 168);
    *(_QWORD *)(a1 + 272) = v15;
    if ( v16 && v16 < 0xFFFFFFFFFFFFF001LL )
    {
      v17 = *(_DWORD *)(a1 + 64);
      *(_QWORD *)(a1 + 296) = a2;
      *(_DWORD *)(a1 + 288) = v17;
      v18 = msm_hw_fence_register_error_cb(*(_QWORD *)(v16 + 8), msm_hw_fence_error_cb, a1 + 288);
      if ( v18 )
      {
        v21 = v18;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_hw_fence_init",
          241,
          -1,
          *(_DWORD *)(a1 + 64),
          60333,
          -1059143953,
          v19,
          v35);
        if ( (_drm_debug & 4) != 0 )
          *(double *)&v20 = _drm_dev_dbg(0, 0, 0, "hw fence cb register failed. ret = %d\n", v21);
      }
      v22 = v7 * *(_DWORD *)(a1 + 192) + 4095;
      v23 = *(_DWORD **)(*(_QWORD *)a5 + 88LL);
      v24 = *(_QWORD *)(a1 + 184);
      v25 = (v22 & 0xFFFFF000) + 0x200000;
      if ( *(v23 - 1) != 1814495457 )
        __break(0x8229u);
      v26 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, long double))v23)(
              a5,
              (v22 & 0xFFFFF000) + 0x200000,
              v24,
              v20);
      if ( v26 )
      {
        v34 = v26;
        printk(&unk_22BAC8, "sde_hw_fence_init");
        result = v34;
      }
      else
      {
        v27 = *(_QWORD *)(a1 + 176);
        v28 = _drm_debug;
        v29 = *(unsigned int *)(v27 + 8);
        v30 = (_DWORD *)(v27 + v29 + 28);
        v31 = (_DWORD *)(v29 + v25 + 128);
        *(_QWORD *)(a1 + 224) = v30;
        *(_QWORD *)(a1 + 232) = v31;
        if ( (v28 & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "hwfence registered ctl:%d client:%d handle:0x%pK tx_wm:0x%x wr_idx:0x%x\n",
            v7,
            *(_DWORD *)(a1 + 164),
            *(const void **)(a1 + 168),
            *v30,
            *v31);
        result = 0;
      }
      goto LABEL_30;
    }
    v33 = _drm_debug;
    *(_QWORD *)(a1 + 168) = 0;
    if ( (v33 & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "error cannot register ctl_id:%d hw-fence client:%d\n", v7, *(_DWORD *)(a1 + 164));
      result = 4294967274LL;
      goto LABEL_30;
    }
LABEL_29:
    result = 4294967274LL;
LABEL_30:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return sde_hw_fence_deinit(a1);
}
