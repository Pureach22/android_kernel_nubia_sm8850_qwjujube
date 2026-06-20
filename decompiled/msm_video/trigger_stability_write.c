__int64 __fastcall trigger_stability_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  int v4; // w22
  size_t v5; // x20
  __int64 result; // x0
  __int64 v8; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v9[8]; // [xsp+10h] [xbp-50h] BYREF
  char v10; // [xsp+50h] [xbp-10h]
  __int64 v11; // [xsp+58h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v8 = 0;
  memset(v9, 0, sizeof(v9));
  v10 = 0;
  if ( !v3 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "trigger_stability_write");
    goto LABEL_13;
  }
  if ( !a2 )
  {
LABEL_17:
    result = -22;
    goto LABEL_18;
  }
  if ( !a3 )
  {
LABEL_13:
    result = 0;
    goto LABEL_18;
  }
  v4 = a3;
  if ( a3 >= 0x40 )
    v5 = 64;
  else
    v5 = a3;
  _check_object_size(v9, v5, 0);
  if ( !inline_copy_from_user((__int64)v9, a2, v5) )
  {
    if ( !(unsigned int)kstrtoull(v9, 0, &v8) )
    {
      msm_vidc_trigger_stability(v3, v8);
      result = v4;
      goto LABEL_18;
    }
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_88398, "err ", 0xFFFFFFFFLL, "codec", "trigger_stability_write");
    goto LABEL_17;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_8FDC9, "err ", 0xFFFFFFFFLL, "codec", "trigger_stability_write");
  result = -14;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
