__int64 __fastcall msm_cvp_set_fw_version(__int64 a1)
{
  unsigned __int8 *v1; // x0
  unsigned int v2; // w21
  unsigned int v3; // w22
  unsigned int v4; // w23
  unsigned int v5; // w8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v7; // x8
  __int64 result; // x0
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  char v11[16]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  strcpy(v11, "EVA.FIRMWARE.");
  v1 = (unsigned __int8 *)strnstr(a1, v11, 128);
  if ( !v1 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8DA43, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
    goto LABEL_19;
  }
  v2 = v1[13] - 48;
  if ( v2 >= 0xA )
  {
    if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      goto LABEL_19;
LABEL_18:
    v7 = _ReadStatusReg(SP_EL0);
    printk(&unk_84402, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), "warn");
    goto LABEL_19;
  }
  v3 = v1[15] - 48;
  if ( v3 >= 0xA )
  {
    if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      goto LABEL_19;
    goto LABEL_18;
  }
  v4 = v1[17] - 48;
  if ( v4 < 0xA )
  {
    v5 = v1[18] - 48;
    if ( v5 >= 0xA )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        v10 = _ReadStatusReg(SP_EL0);
        printk(&unk_84402, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), "warn");
      }
    }
    else
    {
      LOBYTE(v4) = v5 + 10 * v4;
    }
    result = (v2 << 24) | ((unsigned __int8)v3 << 16) | (unsigned __int8)v4;
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_8A5FC, "core", "msm_cvp_set_fw_version", (unsigned int)result);
      result = (v2 << 24) | ((unsigned __int8)v3 << 16) | (unsigned __int8)v4;
    }
    goto LABEL_22;
  }
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    goto LABEL_18;
LABEL_19:
  result = 0;
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v9 = _ReadStatusReg(SP_EL0);
    printk(&unk_823E1, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), "warn");
    result = 0;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
