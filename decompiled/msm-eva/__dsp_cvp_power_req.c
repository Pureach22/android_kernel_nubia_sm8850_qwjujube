_DWORD *__fastcall _dsp_cvp_power_req(__int64 a1)
{
  char v2; // w8
  _DWORD *result; // x0
  int v4; // w8
  int v5; // w9
  int v6; // w9
  int v7; // w8
  int v8; // w13
  int v9; // w10
  int v10; // w11
  int v11; // w12
  int v12; // w8
  int v13; // w8
  int v14; // w9
  int v15; // w8
  __int64 v16; // x3
  _DWORD *v17; // x23
  _DWORD *v18; // x23
  _DWORD *v19; // x23
  _DWORD *v20; // x23
  _DWORD *v21; // x23
  _DWORD *v22; // x23
  unsigned __int64 StatusReg; // x8

  v2 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(a1 + 4) = 0;
  if ( (v2 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_8CB46, "dsp", "__dsp_cvp_power_req", (unsigned int)dword_6C7D4);
  result = (_DWORD *)get_inst_from_dsp((unsigned int)dword_6C7DC, dword_6C7D8);
  if ( !result )
    goto LABEL_24;
  v4 = msm_cvp_debug_out;
  v5 = msm_cvp_debug & 0x800;
  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
  {
    v17 = result;
    printk(&unk_9749D, "dsp", (unsigned int)dword_6C7E4, (unsigned int)dword_6C7E8);
    v4 = msm_cvp_debug_out;
    result = v17;
    v5 = msm_cvp_debug & 0x800;
    if ( (msm_cvp_debug & 0x800) == 0 )
      goto LABEL_10;
  }
  else if ( (msm_cvp_debug & 0x800) == 0 )
  {
    goto LABEL_10;
  }
  if ( !v4 )
  {
    v18 = result;
    printk(&unk_93580, "dsp", (unsigned int)dword_6C7F8, (unsigned int)dword_6C7FC);
    v4 = msm_cvp_debug_out;
    result = v18;
    v5 = msm_cvp_debug & 0x800;
  }
LABEL_10:
  if ( v5 && !v4 )
  {
    v19 = result;
    printk(&unk_90F8B, "dsp", (unsigned int)dword_6C814, (unsigned int)dword_6C818);
    v4 = msm_cvp_debug_out;
    result = v19;
    v5 = msm_cvp_debug & 0x800;
    if ( (msm_cvp_debug & 0x800) == 0 )
      goto LABEL_15;
  }
  else if ( !v5 )
  {
    goto LABEL_15;
  }
  if ( !v4 )
  {
    v20 = result;
    printk(&unk_93580, "dsp", (unsigned int)dword_6C828, (unsigned int)dword_6C82C);
    v4 = msm_cvp_debug_out;
    result = v20;
    v5 = msm_cvp_debug & 0x800;
  }
LABEL_15:
  if ( v5 && !v4 )
  {
    v21 = result;
    printk(&unk_8665F, "dsp", (unsigned int)dword_6C80C, (unsigned int)dword_6C810);
    v4 = msm_cvp_debug_out;
    result = v21;
    if ( (msm_cvp_debug & 0x800) == 0 )
      goto LABEL_20;
  }
  else if ( !v5 )
  {
    goto LABEL_20;
  }
  if ( !v4 )
  {
    v22 = result;
    printk(&unk_8E4C4, "dsp", (unsigned int)dword_6C83C, (unsigned int)dword_6C840);
    result = v22;
  }
LABEL_20:
  v6 = dword_6C7E4;
  result[3715] = dword_6C7E8;
  v7 = dword_6C7EC;
  result[3714] = v6;
  result[3716] = v7;
  result[3717] = dword_6C7F0;
  result[3718] = dword_6C7F4;
  result[3719] = dword_6C7F8;
  result[3720] = dword_6C7FC;
  result[3721] = dword_6C800;
  result[3722] = dword_6C804;
  v8 = dword_6C814;
  v9 = dword_6C808;
  v10 = dword_6C80C;
  v11 = dword_6C810;
  result[3725] = dword_6C818;
  v12 = dword_6C81C;
  result[3723] = v9;
  result[3734] = v10;
  result[3726] = v12;
  v13 = dword_6C820;
  result[3736] = v11;
  result[3724] = v8;
  result[3727] = v13;
  result[3728] = dword_6C824;
  result[3729] = dword_6C828;
  result[3730] = dword_6C82C;
  result[3731] = dword_6C830;
  result[3732] = dword_6C834;
  v14 = dword_6C83C;
  result[3733] = dword_6C838;
  v15 = dword_6C840;
  result[3735] = v14;
  result[3737] = v15;
  result = (_DWORD *)msm_cvp_update_power((__int64)result);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      result = (_DWORD *)printk(
                           &unk_87B59,
                           *(unsigned int *)(StatusReg + 1800),
                           *(unsigned int *)(StatusReg + 1804),
                           &unk_8E7CE);
    }
LABEL_24:
    *(_DWORD *)(a1 + 4) = -1;
    return result;
  }
  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    return (_DWORD *)printk(&unk_9536A, "dsp", "__dsp_cvp_power_req", v16);
  return result;
}
