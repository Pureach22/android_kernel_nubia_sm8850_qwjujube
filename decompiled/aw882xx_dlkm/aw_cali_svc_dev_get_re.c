__int64 __fastcall aw_cali_svc_dev_get_re(__int64 a1)
{
  unsigned int r0; // w0
  int v3; // w20
  int v4; // w21
  int v5; // w22
  int v6; // w23
  int v7; // w24
  int v8; // w25
  int v9; // w26
  int v10; // w20
  __int64 result; // x0
  __int64 *v12; // x8
  unsigned int v13; // w20
  __int64 v14; // x1
  __int64 *v15; // x8
  __int64 v16; // x1
  __int64 v17; // [xsp+8h] [xbp-28h] BYREF
  __int64 v18; // [xsp+10h] [xbp-20h] BYREF
  __int64 v19; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v20[2]; // [xsp+20h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20[0] = 0;
  v17 = 0;
  v18 = 0;
  r0 = aw882xx_dsp_read_r0(a1, &v17);
  if ( r0 )
    goto LABEL_10;
  v3 = v17;
  usleep_range_state(32000, 32010, 2);
  r0 = aw882xx_dsp_read_r0(a1, (char *)&v17 + 4);
  if ( r0 )
    goto LABEL_10;
  v4 = HIDWORD(v17);
  usleep_range_state(32000, 32010, 2);
  r0 = aw882xx_dsp_read_r0(a1, &v18);
  if ( r0 )
    goto LABEL_10;
  v5 = v18;
  usleep_range_state(32000, 32010, 2);
  r0 = aw882xx_dsp_read_r0(a1, (char *)&v18 + 4);
  if ( r0 )
    goto LABEL_10;
  v6 = HIDWORD(v18);
  usleep_range_state(32000, 32010, 2);
  r0 = aw882xx_dsp_read_r0(a1, &v19);
  if ( r0 )
    goto LABEL_10;
  v7 = v19;
  usleep_range_state(32000, 32010, 2);
  r0 = aw882xx_dsp_read_r0(a1, (char *)&v19 + 4);
  if ( r0
    || (v8 = HIDWORD(v19), usleep_range_state(32000, 32010, 2), (r0 = aw882xx_dsp_read_r0(a1, v20)) != 0)
    || (v9 = v20[0], usleep_range_state(32000, 32010, 2), (r0 = aw882xx_dsp_read_r0(a1, (char *)v20 + 4)) != 0) )
  {
LABEL_10:
    v12 = *(__int64 **)(a1 + 112);
    v13 = r0;
    v14 = v12[14];
    if ( !v14 )
      v14 = *v12;
    printk(&unk_27FCD, v14, "aw_cali_svc_dev_get_re");
    if ( *(_BYTE *)(a1 + 665) )
    {
      *(_BYTE *)(a1 + 664) = -1;
      aw882xx_dev_mute(a1, 1);
      v15 = *(__int64 **)(a1 + 112);
      v16 = v15[14];
      if ( !v16 )
        v16 = *v15;
      printk(&unk_22D82, v16, "aw_cali_svc_run_mute");
    }
    result = v13;
  }
  else
  {
    v10 = HIDWORD(v20[0]) + v9 + v8 + v7 + v6 + v5 + v4 + v3;
    usleep_range_state(32000, 32010, 2);
    LODWORD(v17) = v10 / 8;
    *(_DWORD *)(a1 + 652) = v10 / 8;
    aw_cali_store_cali_re(a1, v10 / 8);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
