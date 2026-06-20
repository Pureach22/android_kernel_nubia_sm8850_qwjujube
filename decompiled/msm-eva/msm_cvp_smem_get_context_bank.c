__int64 *__fastcall msm_cvp_smem_get_context_bank(__int64 a1, char a2)
{
  const char *v2; // x20
  __int64 *v3; // x21
  __int64 *v4; // x23
  unsigned int v5; // w22
  unsigned __int64 StatusReg; // x8

  if ( (a2 & 0x20) != 0 )
  {
    v2 = "cvp_sec_pixel";
  }
  else if ( (a2 & 0x10) != 0 )
  {
    v2 = "cvp_sec_nonpixel";
  }
  else if ( (a2 & 0x40) != 0 )
  {
    v2 = "cvp_camera";
  }
  else if ( (a2 & 8) != 0 )
  {
    v2 = "cvp_dsp";
  }
  else
  {
    v2 = "cvp_hlos";
  }
  v3 = *(__int64 **)(a1 + 336);
  v4 = (__int64 *)(a1 + 336);
  v5 = a2 & 4;
  if ( v3 == (__int64 *)(a1 + 336) )
    goto LABEL_16;
  while ( v5 >> 2 != *((unsigned __int8 *)v3 + 28) || strcmp(v2, (const char *)v3[2]) )
  {
    v3 = (__int64 *)*v3;
    if ( v3 == v4 )
      goto LABEL_16;
  }
  if ( !v3 )
  {
LABEL_16:
    v3 = nullptr;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_94F70, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return nullptr;
    }
  }
  return v3;
}
