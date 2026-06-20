__int64 __fastcall kick_off_v1(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  _QWORD *v6; // x8
  __int64 v7; // x0
  int v8; // w11
  int v9; // w9
  int v10; // w8
  __int64 v11; // x8
  int v12; // w1
  int v13; // w10
  int v15; // w11
  int v16; // w12
  __int64 v17; // x14
  __int64 v18; // x13
  _DWORD *v19; // x14
  __int64 v20; // x14
  int v21; // w13
  int v22; // w21
  int v23; // w22
  unsigned int v24; // w1
  void (__fastcall *v25)(__int64, __int64 *); // x8
  void (__fastcall *v26)(__int64, __int64 *, _QWORD); // x8
  void (__fastcall *v27)(__int64, __int64 *); // x8
  __int64 v32; // [xsp+48h] [xbp-28h] BYREF
  __int64 v33; // [xsp+50h] [xbp-20h]
  __int64 v34; // [xsp+58h] [xbp-18h]
  __int64 v35; // [xsp+60h] [xbp-10h]
  __int64 v36; // [xsp+68h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = ((__int64 (*)(void))validate_kick_off_v1)();
  if ( (_DWORD)result )
    goto LABEL_33;
  if ( a2 >= 2 )
  {
    _drm_err("invalid dpu idx %d\n", a2);
    result = 4294967274LL;
LABEL_33:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = *(_QWORD **)(a1 + 16);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v7 = msm_gem_sync(*v6);
  v8 = *(_DWORD *)(a1 + 8);
  if ( v8 )
  {
    v9 = 0;
    v10 = 0;
    goto LABEL_8;
  }
  v11 = *(unsigned int *)(a1 + 24);
  if ( (unsigned int)v11 < 4 )
  {
    v9 = 0x800000;
    v10 = dspp_read_sel[v11] << 30;
LABEL_8:
    v12 = *(_DWORD *)(a1 + 36);
    v13 = *(_DWORD *)(a1 + 44) != 0;
    _ZF = v8 == 1;
    v15 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 20LL);
    v16 = _ZF;
    if ( v12 == 1 )
    {
      v20 = reg_dma_0[a2];
      v18 = *(_QWORD *)(v20 + 16);
      if ( *(_BYTE *)(v18 + 12) )
      {
        v32 = *(_QWORD *)(v20 + 160);
        v19 = (_DWORD *)(v18 + 16);
LABEL_17:
        v21 = *(_DWORD *)(v18 + 24);
        LODWORD(v33) = *v19;
        HIDWORD(v34) = v21;
        LODWORD(v35) = 0x4000;
        if ( v21 )
        {
          v22 = (unsigned __int16)v15 >> 2;
          v23 = v9 | (v16 << 22) | v10 | (v13 << 24);
          if ( reg_dma_opmode_offset )
            v24 = 4;
          else
            v24 = 0;
          sde_reg_write((__int64)&v32, v24, 1u, "reg_dma_opmode_offset");
          v25 = (void (__fastcall *)(__int64, __int64 *))read_clear_reg_dma_status;
          if ( *((_DWORD *)read_clear_reg_dma_status - 1) != 659216397 )
            __break(0x8228u);
          v25(a1, &v32);
          if ( *(_DWORD *)(a1 + 44) )
            __dsb(0xEu);
          v26 = (void (__fastcall *)(__int64, __int64 *, _QWORD))reg_dma_submit_payload;
          if ( *((_DWORD *)reg_dma_submit_payload - 1) != -987148149 )
            __break(0x8228u);
          v26(a1, &v32, v23 | (unsigned int)v22);
          if ( *(_DWORD *)(a1 + 44) )
          {
            __dsb(0xEu);
            v27 = (void (__fastcall *)(__int64, __int64 *))trigger_reg_dma;
            if ( *((_DWORD *)trigger_reg_dma - 1) != 659216397 )
              __break(0x8228u);
            v27(a1, &v32);
          }
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "write_kick_off_v1",
            871,
            -1,
            *(_DWORD *)(a1 + 40),
            *(_DWORD *)(a1 + 36),
            HIDWORD(*(_QWORD *)(a1 + 16)),
            *(_QWORD *)(a1 + 16),
            BYTE4(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 24LL)));
          result = 0;
          goto LABEL_33;
        }
      }
    }
    else if ( !v12 )
    {
      v17 = reg_dma_0[a2];
      v18 = *(_QWORD *)(v17 + 16);
      if ( *(_BYTE *)v18 )
      {
        v32 = *(_QWORD *)(v17 + 160);
        v19 = (_DWORD *)(v18 + 4);
        goto LABEL_17;
      }
    }
    _drm_err("DMA type %d is unsupported\n", v12);
    result = 4294967201LL;
    goto LABEL_33;
  }
  __break(0x5512u);
  __asm { STGP            X17, X3, [X27,#-0xF0]! }
  return hfi_kick_off_v1(v7);
}
