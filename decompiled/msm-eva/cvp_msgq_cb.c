unsigned __int64 __fastcall cvp_msgq_cb(unsigned __int64 a1, __int64 a2, unsigned __int16 *a3)
{
  unsigned __int64 result; // x0
  __int64 v5; // x0
  unsigned __int64 v7; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // [xsp+8h] [xbp-18h]
  __int16 v11[2]; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int16 v12; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  result = 4294967274LL;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( a2 != 1443889160 )
      goto LABEL_15;
    if ( *((_BYTE *)a3 + 4) != 2 )
    {
      result = 4294967284LL;
      goto LABEL_16;
    }
    v5 = *(unsigned int *)(a1 - 16);
    v12 = 0;
    v7 = a1;
    v11[0] = 0;
    if ( (unsigned int)ghd_rm_get_vmid(v5, &v12) )
    {
      result = 4294967283LL;
      goto LABEL_16;
    }
    if ( (unsigned int)ghd_rm_get_vmid(1, v11) )
    {
      result = 4294967282LL;
      goto LABEL_16;
    }
    if ( v12 != *a3 )
    {
LABEL_15:
      result = 0;
      goto LABEL_16;
    }
    if ( (msm_cvp_debug & 0x8000) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_92CA5, &unk_85102, "cvp_msgq_cb", v12);
      if ( *(_QWORD *)(v7 - 8) )
        goto LABEL_14;
    }
    else if ( *(_QWORD *)(v7 - 8) )
    {
LABEL_14:
      result = 4294967281LL;
      goto LABEL_16;
    }
    result = gh_msgq_register(263);
    *(_QWORD *)(v7 - 8) = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v9 = v7 - 64;
      if ( (msm_cvp_debug & 0x8000) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_93817, &unk_85102, "cvp_msgq_cb", result);
        v9 = v7 - 64;
      }
      result = cvp_complete_msgq_init(v9);
    }
    else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v10 = result;
      printk(&unk_907E2, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = v10;
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
