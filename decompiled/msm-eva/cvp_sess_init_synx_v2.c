__int64 __fastcall cvp_sess_init_synx_v2(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  _QWORD v4[2]; // [xsp+0h] [xbp-20h] BYREF
  int v5; // [xsp+10h] [xbp-10h]
  int v6; // [xsp+14h] [xbp-Ch]
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[1] = 0;
  v6 = 0;
  v4[0] = "cvp-kernel-client";
  v5 = 8;
  *(_QWORD *)(a1 + 15264) = synx_initialize(v4);
  if ( (unsigned __int64)(a1 + 15264) < 0xFFFFFFFFFFFFF001LL )
  {
    result = 0;
  }
  else
  {
    result = 4294967282LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8B898, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = 4294967282LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
