__int64 __fastcall aw_cali_svc_dev_get_f0_q(__int64 a1)
{
  unsigned int f0_q; // w0
  int v3; // w21
  int v4; // w22
  int v5; // w23
  int v6; // w24
  int v7; // w25
  int v8; // w26
  int v9; // w27
  int v10; // w28
  int v11; // w21
  int v12; // w22
  __int64 result; // x0
  __int64 *v14; // x8
  unsigned int v15; // w20
  __int64 v16; // x1
  __int64 v17; // [xsp+8h] [xbp-38h] BYREF
  __int64 v18; // [xsp+10h] [xbp-30h] BYREF
  int v19; // [xsp+18h] [xbp-28h] BYREF
  __int64 v20; // [xsp+20h] [xbp-20h] BYREF
  __int64 v21; // [xsp+28h] [xbp-18h] BYREF
  int v22; // [xsp+30h] [xbp-10h] BYREF
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v20 = 0;
  v21 = 0;
  v19 = 0;
  v17 = 0;
  v18 = 0;
  f0_q = aw882xx_dsp_read_f0_q(a1, &v20, &v17);
  if ( f0_q )
    goto LABEL_7;
  v3 = v20;
  v4 = v17;
  usleep_range_state(70000, 70010, 2);
  f0_q = aw882xx_dsp_read_f0_q(a1, (char *)&v20 + 4, (char *)&v17 + 4);
  if ( f0_q )
    goto LABEL_7;
  v5 = HIDWORD(v20);
  v6 = HIDWORD(v17);
  usleep_range_state(70000, 70010, 2);
  f0_q = aw882xx_dsp_read_f0_q(a1, &v21, &v18);
  if ( f0_q )
    goto LABEL_7;
  v7 = v21;
  v8 = v18;
  usleep_range_state(70000, 70010, 2);
  f0_q = aw882xx_dsp_read_f0_q(a1, (char *)&v21 + 4, (char *)&v18 + 4);
  if ( f0_q
    || (v9 = HIDWORD(v21),
        v10 = HIDWORD(v18),
        usleep_range_state(70000, 70010, 2),
        (f0_q = aw882xx_dsp_read_f0_q(a1, &v22, &v19)) != 0) )
  {
LABEL_7:
    v14 = *(__int64 **)(a1 + 112);
    v15 = f0_q;
    v16 = v14[14];
    if ( !v16 )
      v16 = *v14;
    printk(&unk_273E7, v16, "aw_cali_svc_dev_get_f0_q");
    result = v15;
  }
  else
  {
    v11 = v22 + v9 + v7 + v5 + v3;
    v12 = v19 + v10 + v8 + v6 + v4;
    usleep_range_state(70000, 70010, 2);
    result = 0;
    *(_DWORD *)(a1 + 656) = v11 / 5;
    *(_DWORD *)(a1 + 660) = v12 / 5;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
