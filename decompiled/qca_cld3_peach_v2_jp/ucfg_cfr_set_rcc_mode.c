__int64 __fastcall ucfg_cfr_set_rcc_mode(
        __int64 a1,
        int a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  char v23; // w10
  char v24; // w9
  char v25; // w9
  char v26; // w9
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // [xsp+8h] [xbp-18h] BYREF
  __int64 v37[2]; // [xsp+10h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37[0] = 0;
  result = dev_sanity_check(a1, &v36, v37, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !(_DWORD)result )
  {
    if ( a2 <= 2 )
    {
      switch ( a2 )
      {
        case 0:
          v22 = v37[0];
          v25 = *(_BYTE *)(v37[0] + 176);
          goto LABEL_14;
        case 1:
          v22 = v37[0];
          v23 = 2 * (a3 & 1);
          v24 = *(_BYTE *)(v37[0] + 176) & 0xFD;
          break;
        case 2:
          v22 = v37[0];
          v23 = 4 * (a3 & 1);
          v24 = *(_BYTE *)(v37[0] + 176) & 0xFB;
          break;
        default:
          goto LABEL_20;
      }
    }
    else
    {
      if ( a2 <= 4 )
      {
        v22 = v37[0];
        if ( a2 == 3 )
        {
          v23 = 8 * (a3 & 1);
          v24 = *(_BYTE *)(v37[0] + 176) & 0xF7;
        }
        else
        {
          v23 = 16 * (a3 & 1);
          v24 = *(_BYTE *)(v37[0] + 176) & 0xEF;
        }
        goto LABEL_18;
      }
      if ( a2 != 5 )
      {
        if ( a2 == 6 )
        {
          v22 = v37[0];
          v25 = *(_BYTE *)(v37[0] + 176) & 0xC0
              | (2 * (a3 & 1)) & 0xC3
              | (4 * (a3 & 1)) & 0xC7
              | (8 * (a3 & 1)) & 0xCF
              | (16 * (a3 & 1)) & 0xDF
              | (32 * (a3 & 1));
LABEL_14:
          v26 = v25 & 0xFE | a3 & 1;
LABEL_19:
          *(_BYTE *)(v22 + 176) = v26;
        }
LABEL_20:
        qdf_trace_msg(
          0x6Au,
          8u,
          "%s: <CFR_UMAC> Capture mode set by user: 0x%x\n",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "ucfg_cfr_set_rcc_mode",
          a3);
        wlan_objmgr_pdev_release_ref(v36, 0x30u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
        result = 0;
        goto LABEL_21;
      }
      v22 = v37[0];
      v23 = 32 * (a3 & 1);
      v24 = *(_BYTE *)(v37[0] + 176) & 0xDF;
    }
LABEL_18:
    v26 = v24 | v23;
    goto LABEL_19;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
