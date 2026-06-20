__int64 __fastcall aw_cali_svc_dev_get_f0(__int64 a1)
{
  unsigned int f0; // w0
  int v3; // w21
  int v4; // w22
  int v5; // w23
  int v6; // w24
  int v7; // w21
  __int64 result; // x0
  __int64 *v9; // x8
  unsigned int v10; // w20
  __int64 v11; // x1
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  int v14; // [xsp+10h] [xbp-10h] BYREF
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v12 = 0;
  v13 = 0;
  f0 = aw882xx_dsp_read_f0(a1, &v12);
  if ( f0 )
    goto LABEL_7;
  v3 = v12;
  usleep_range_state(70000, 70010, 2);
  f0 = aw882xx_dsp_read_f0(a1, (char *)&v12 + 4);
  if ( f0 )
    goto LABEL_7;
  v4 = HIDWORD(v12);
  usleep_range_state(70000, 70010, 2);
  f0 = aw882xx_dsp_read_f0(a1, &v13);
  if ( f0
    || (v5 = v13, usleep_range_state(70000, 70010, 2), (f0 = aw882xx_dsp_read_f0(a1, (char *)&v13 + 4)) != 0)
    || (v6 = HIDWORD(v13), usleep_range_state(70000, 70010, 2), (f0 = aw882xx_dsp_read_f0(a1, &v14)) != 0) )
  {
LABEL_7:
    v9 = *(__int64 **)(a1 + 112);
    v10 = f0;
    v11 = v9[14];
    if ( !v11 )
      v11 = *v9;
    printk(&unk_273E7, v11, "aw_cali_svc_dev_get_f0");
    result = v10;
  }
  else
  {
    v7 = v14 + v6 + v5 + v4 + v3;
    usleep_range_state(70000, 70010, 2);
    result = 0;
    *(_DWORD *)(a1 + 656) = v7 / 5;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
