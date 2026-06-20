__int64 __fastcall msm_cvp_mmrm_set_value_in_range(__int64 a1, unsigned int a2, unsigned int a3)
{
  int v3; // w8
  int v4; // w9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w19
  __int64 v8; // x21
  unsigned int v9; // w22
  unsigned int v10; // w23
  __int64 v11; // x21
  unsigned __int64 v12; // x8
  _QWORD v13[2]; // [xsp+Ch] [xbp-34h] BYREF
  int v14; // [xsp+1Ch] [xbp-24h]
  _QWORD v15[4]; // [xsp+20h] [xbp-20h] BYREF

  v15[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = msm_cvp_debug_out;
  v15[2] = 0;
  v14 = 0;
  v13[1] = 0;
  if ( a1 )
  {
    v4 = msm_cvp_debug & 0x400;
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    {
      v8 = a1;
      v9 = a2;
      v10 = a3;
      printk(&unk_8ED6C, &unk_8DA84, "msm_cvp_mmrm_set_value_in_range", *(_QWORD *)(a1 + 2400));
      v3 = msm_cvp_debug_out;
      a2 = v9;
      a3 = v10;
      a1 = v8;
      v4 = msm_cvp_debug & 0x400;
    }
    v15[0] = a2;
    v15[1] = a3;
    v13[0] = 1;
    if ( v4 && !v3 )
    {
      v11 = a1;
      printk(&unk_828B0, &unk_8DA84, "msm_cvp_mmrm_set_value_in_range", a2);
      a1 = v11;
    }
    result = mmrm_client_set_value_in_range(*(_QWORD *)(a1 + 2400), v13, v15);
    if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v7 = result;
      printk(&unk_8F810, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = v7;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      printk(&unk_861CC, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
