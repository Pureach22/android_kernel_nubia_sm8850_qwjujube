__int64 __fastcall dp_ipa_disable_autonomy(_QWORD *a1)
{
  __int64 v2; // x0
  char is_ipa_enabled; // w8
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x8
  _DWORD *v15; // x8
  int v16; // w0
  __int64 v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w9
  int v27; // w10
  int v28; // w8
  unsigned int v35; // w11
  unsigned int v36; // w11
  int v37; // w12
  unsigned int v38; // w11
  int v39; // w12
  char *v40; // x11
  unsigned __int64 StatusReg; // x12
  unsigned int v44; // w9
  unsigned int v45; // w9
  int v46; // w10
  unsigned int v47; // w11
  unsigned int v50; // w13
  unsigned int v53; // w11
  __int64 v54; // [xsp+0h] [xbp-20h] BYREF
  __int64 v55; // [xsp+8h] [xbp-18h] BYREF
  __int64 v56; // [xsp+10h] [xbp-10h] BYREF
  __int64 v57; // [xsp+18h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[5];
  v56 = 0x606050203020101LL;
  LODWORD(v55) = 0;
  v54 = 0;
  is_ipa_enabled = wlan_cfg_is_ipa_enabled(v2);
  result = 0;
  if ( (is_ipa_enabled & 1) != 0 )
  {
    if ( (hif_is_target_ready(a1[8]) & 1) != 0 )
    {
      v13 = a1[141];
      if ( v13 && (v14 = *(_QWORD *)(v13 + 74392)) != 0 )
      {
        v15 = *(_DWORD **)(v14 + 80);
        if ( v15 )
        {
          if ( *(v15 - 1) != -236786424 )
            __break(0x8228u);
          v16 = ((__int64 (__fastcall *)(_QWORD, __int64 *))v15)(0, &v56);
LABEL_12:
          v17 = a1[5];
          HIDWORD(v55) = v16;
          if ( (wlan_cfg_is_rx_hash_enabled(v17) & 1) != 0 )
          {
            dp_reo_remap_config(
              (__int64)a1,
              (__int64)&v55,
              (unsigned int *)&v54 + 1,
              (unsigned int *)&v54,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25);
            hal_reo_read_write_ctrl_ix(a1[141], 0, (_DWORD *)&v55 + 1, nullptr, (_DWORD *)&v54 + 1, &v54);
            v27 = v54;
            v26 = HIDWORD(v54);
            v28 = HIDWORD(v55);
            _X12 = &dp_ipa_reo_remap_history_index;
            __asm { PRFM            #0x11, [X12] }
            do
            {
              v35 = __ldxr((unsigned int *)&dp_ipa_reo_remap_history_index);
              v36 = v35 + 1;
            }
            while ( __stlxr(v36, (unsigned int *)&dp_ipa_reo_remap_history_index) );
            __dmb(0xBu);
            if ( v36 == 32 )
              goto LABEL_33;
            v37 = -v36;
            _NF = (-v36 & 0x80000000) != 0;
            v38 = v36 & 0x1F;
            v39 = v37 & 0x1F;
            if ( !_NF )
              v38 = -v39;
            if ( v38 < 0x21 )
              goto LABEL_22;
LABEL_32:
            __break(0x5512u);
LABEL_33:
            _X12 = &dp_ipa_reo_remap_history_index;
            __asm { PRFM            #0x11, [X12] }
            do
              v50 = __ldxr((unsigned int *)&dp_ipa_reo_remap_history_index);
            while ( __stxr(v50 - 32, (unsigned int *)&dp_ipa_reo_remap_history_index) );
            v38 = 0;
LABEL_22:
            v40 = (char *)&dp_ipa_reo_remap_history + 24 * v38;
            __isb(0xFu);
            StatusReg = _ReadStatusReg(CNTVCT_EL0);
LABEL_30:
            result = 0;
            *(_QWORD *)v40 = StatusReg;
            *((_DWORD *)v40 + 2) = v28;
            *((_DWORD *)v40 + 3) = v26;
            *((_DWORD *)v40 + 4) = v27;
            goto LABEL_31;
          }
          hal_reo_read_write_ctrl_ix(a1[141], 0, (_DWORD *)&v55 + 1, nullptr, nullptr, nullptr);
          v28 = HIDWORD(v55);
          _X10 = &dp_ipa_reo_remap_history_index;
          __asm { PRFM            #0x11, [X10] }
          do
          {
            v44 = __ldxr((unsigned int *)&dp_ipa_reo_remap_history_index);
            v45 = v44 + 1;
          }
          while ( __stlxr(v45, (unsigned int *)&dp_ipa_reo_remap_history_index) );
          __dmb(0xBu);
          if ( v45 == 32 )
          {
            _X10 = &dp_ipa_reo_remap_history_index;
            __asm { PRFM            #0x11, [X10] }
            do
              v53 = __ldxr((unsigned int *)&dp_ipa_reo_remap_history_index);
            while ( __stxr(v53 - 32, (unsigned int *)&dp_ipa_reo_remap_history_index) );
            v47 = 0;
          }
          else
          {
            v46 = -v45;
            _NF = (-v45 & 0x80000000) != 0;
            v26 = v45 & 0x1F;
            v27 = v46 & 0x1F;
            if ( _NF )
              v47 = v26;
            else
              v47 = -v27;
            if ( v47 >= 0x21 )
              goto LABEL_32;
          }
          v40 = (char *)&dp_ipa_reo_remap_history + 24 * v47;
          v26 = 0;
          v27 = 0;
          __isb(0xFu);
          StatusReg = _ReadStatusReg(CNTVCT_EL0);
          goto LABEL_30;
        }
      }
      else
      {
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: hal handle is NULL",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "hal_gen_reo_remap_val",
          v54,
          v55,
          v56,
          v57);
      }
      v16 = 0;
      goto LABEL_12;
    }
    result = 3;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
