__int64 __fastcall trigger_ssr_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  int v4; // w22
  size_t v5; // x20
  int v6; // w21
  __int64 result; // x0
  unsigned int v8; // w0
  __int64 v9; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v10[8]; // [xsp+10h] [xbp-50h] BYREF
  char v11; // [xsp+50h] [xbp-10h]
  __int64 v12; // [xsp+58h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v9 = 0;
  memset(v10, 0, sizeof(v10));
  v11 = 0;
  if ( !v3 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "trigger_ssr_write");
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
  v6 = a2;
  _check_object_size(v10, v5, 0);
  if ( !inline_copy_from_user((int)v10, v6, v5) )
  {
    v8 = kstrtoull(v10, 0, &v9);
    if ( !v8 )
    {
      msm_vidc_trigger_ssr(v3, v9);
      result = v4;
      goto LABEL_18;
    }
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_89BAE, "err ", 0xFFFFFFFFLL, "codec", v8);
    goto LABEL_17;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_8FDC9, "err ", 0xFFFFFFFFLL, "codec", "trigger_ssr_write");
  result = -14;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
