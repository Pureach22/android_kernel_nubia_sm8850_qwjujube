__int64 __fastcall msm_cvp_setup_context_bank(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4)
{
  unsigned __int64 v4; // x19
  _DWORD *v5; // x0
  __int64 v6; // x19
  _QWORD *v7; // x20
  __int64 v8; // x8
  int v9; // w8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x21

  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8CCDD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
    return result;
  }
  *(_QWORD *)(a2 + 40) = a3;
  v4 = a3[16];
  if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      printk(&unk_85D9B, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
    }
    if ( v4 )
      return (unsigned int)v4;
    else
      return 4294967277LL;
  }
  v5 = (_DWORD *)a3[84];
  if ( v5 || (v6 = a2, v7 = a3, v5 = (_DWORD *)devm_kmalloc(a3, 16, 3520), a3 = v7, a2 = v6, (v7[84] = v5) != 0) )
  {
    *v5 = -1;
    v8 = a3[84];
    if ( v8 )
    {
LABEL_7:
      *(_QWORD *)(v8 + 8) = -1;
      goto LABEL_8;
    }
  }
  else
  {
    __break(0x800u);
    v8 = v7[84];
    if ( v8 )
      goto LABEL_7;
  }
  __break(0x800u);
LABEL_8:
  v9 = msm_cvp_debug_out;
  if ( (msm_cvp_debug & 0x100) == 0 || msm_cvp_debug_out )
  {
    result = 0;
    if ( (msm_cvp_debug & 0x100) == 0 )
      return result;
    goto LABEL_11;
  }
  v13 = a3[14];
  v14 = a2;
  if ( !v13 )
    v13 = *a3;
  printk(&unk_95F7B, "core", v13, a4);
  v9 = msm_cvp_debug_out;
  a2 = v14;
  result = 0;
  if ( (msm_cvp_debug & 0x100) != 0 )
  {
LABEL_11:
    if ( !v9 )
    {
      printk(&unk_8721D, "core", *(_QWORD *)(a2 + 16), *(unsigned int *)(a2 + 24));
      return 0;
    }
  }
  return result;
}
