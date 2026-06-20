__int64 __fastcall dp_ipa_enable_autonomy(_QWORD *a1)
{
  __int64 v2; // x0
  char is_ipa_enabled; // w8
  __int64 result; // x0
  char is_target_ready; // w8
  char is_vlan_enabled; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  char v16; // w9
  __int64 v17; // x8
  _DWORD *v18; // x8
  int v19; // w0
  __int64 v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 v30; // x8
  _DWORD *v31; // x8
  int v32; // w0
  int v33; // w8
  __int64 v34; // x8
  int v35; // w9
  unsigned int v42; // w9
  unsigned int v43; // w9
  int v44; // w10
  int v45; // w9
  int v46; // w10
  unsigned int v47; // w10
  char *v48; // x10
  unsigned __int64 StatusReg; // x11
  unsigned int v52; // w10
  unsigned int v53; // w10
  int v54; // w11
  unsigned int v55; // w10
  int v56; // w11
  unsigned int v59; // w11
  unsigned int v62; // w12
  int v63; // [xsp+8h] [xbp-18h] BYREF
  int v64; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v65[2]; // [xsp+10h] [xbp-10h] BYREF

  v65[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[5];
  v63 = 0;
  v65[0] = 0;
  is_ipa_enabled = wlan_cfg_is_ipa_enabled(v2);
  result = 0;
  if ( (is_ipa_enabled & 1) != 0 )
  {
    is_target_ready = hif_is_target_ready(a1[8]);
    result = 3;
    if ( (is_target_ready & 1) != 0 )
    {
      LOWORD(v65[0]) = 1025;
      BYTE2(v65[0]) = 1;
      is_vlan_enabled = wlan_ipa_is_vlan_enabled(3);
      v15 = a1[141];
      if ( (is_vlan_enabled & 1) != 0 )
        v16 = 3;
      else
        v16 = 4;
      BYTE3(v65[0]) = v16;
      HIDWORD(v65[0]) = 101057796;
      if ( v15 && (v17 = *(_QWORD *)(v15 + 74392)) != 0 )
      {
        v18 = *(_DWORD **)(v17 + 80);
        if ( v18 )
        {
          if ( *(v18 - 1) != -236786424 )
            __break(0x8228u);
          v19 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))v18)(0, v65);
LABEL_14:
          v20 = a1[5];
          v64 = v19;
          if ( (wlan_cfg_is_rx_hash_enabled(v20) & 1) == 0 )
          {
            hal_reo_read_write_ctrl_ix(a1[141], 0, &v64, nullptr, nullptr, nullptr);
            v33 = v64;
            _X10 = &dp_ipa_reo_remap_history_index;
            __asm { PRFM            #0x11, [X10] }
            do
            {
              v42 = __ldxr((unsigned int *)&dp_ipa_reo_remap_history_index);
              v43 = v42 + 1;
            }
            while ( __stlxr(v43, (unsigned int *)&dp_ipa_reo_remap_history_index) );
            __dmb(0xBu);
            if ( v43 == 32 )
              goto LABEL_43;
            v44 = -v43;
            _NF = (-v43 & 0x80000000) != 0;
            v45 = v43 & 0x1F;
            v46 = v44 & 0x1F;
            if ( _NF )
              v47 = v45;
            else
              v47 = -v46;
            if ( v47 < 0x21 )
              goto LABEL_33;
LABEL_42:
            __break(0x5512u);
LABEL_43:
            _X10 = &dp_ipa_reo_remap_history_index;
            __asm { PRFM            #0x11, [X10] }
            do
              v59 = __ldxr((unsigned int *)&dp_ipa_reo_remap_history_index);
            while ( __stxr(v59 - 32, (unsigned int *)&dp_ipa_reo_remap_history_index) );
            v47 = 0;
LABEL_33:
            v48 = (char *)&dp_ipa_reo_remap_history + 24 * v47;
            v35 = 0;
            __isb(0xFu);
            StatusReg = _ReadStatusReg(CNTVCT_EL0);
LABEL_40:
            result = 0;
            *(_QWORD *)v48 = StatusReg;
            *((_DWORD *)v48 + 2) = v33;
            *((_DWORD *)v48 + 3) = v35;
            *((_DWORD *)v48 + 4) = v35;
            goto LABEL_41;
          }
          v29 = a1[141];
          v65[0] = 0x404040404040404LL;
          if ( v29 && (v30 = *(_QWORD *)(v29 + 74392)) != 0 )
          {
            v31 = *(_DWORD **)(v30 + 80);
            if ( v31 )
            {
              if ( *(v31 - 1) != -236786424 )
                __break(0x8228u);
              v32 = ((__int64 (__fastcall *)(__int64, _QWORD *))v31)(2, v65);
              goto LABEL_25;
            }
          }
          else
          {
            qdf_trace_msg(
              0x46u,
              2u,
              "%s: hal handle is NULL",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "hal_gen_reo_remap_val");
          }
          v32 = 0;
LABEL_25:
          v34 = a1[141];
          v63 = v32;
          hal_reo_read_write_ctrl_ix(v34, 0, &v64, nullptr, &v63, &v63);
          v35 = v63;
          v33 = v64;
          _X11 = &dp_ipa_reo_remap_history_index;
          __asm { PRFM            #0x11, [X11] }
          do
          {
            v52 = __ldxr((unsigned int *)&dp_ipa_reo_remap_history_index);
            v53 = v52 + 1;
          }
          while ( __stlxr(v53, (unsigned int *)&dp_ipa_reo_remap_history_index) );
          __dmb(0xBu);
          if ( v53 == 32 )
          {
            _X11 = &dp_ipa_reo_remap_history_index;
            __asm { PRFM            #0x11, [X11] }
            do
              v62 = __ldxr((unsigned int *)&dp_ipa_reo_remap_history_index);
            while ( __stxr(v62 - 32, (unsigned int *)&dp_ipa_reo_remap_history_index) );
            v55 = 0;
LABEL_39:
            v48 = (char *)&dp_ipa_reo_remap_history + 24 * v55;
            __isb(0xFu);
            StatusReg = _ReadStatusReg(CNTVCT_EL0);
            goto LABEL_40;
          }
          v54 = -v53;
          _NF = (-v53 & 0x80000000) != 0;
          v55 = v53 & 0x1F;
          v56 = v54 & 0x1F;
          if ( !_NF )
            v55 = -v56;
          if ( v55 < 0x21 )
            goto LABEL_39;
          goto LABEL_42;
        }
      }
      else
      {
        qdf_trace_msg(0x46u, 2u, "%s: hal handle is NULL", v7, v8, v9, v10, v11, v12, v13, v14, "hal_gen_reo_remap_val");
      }
      v19 = 0;
      goto LABEL_14;
    }
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
