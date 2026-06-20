__int64 __fastcall qcom_scm_derive_sw_secret(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x19
  int convention; // w0
  __int64 v11; // x2
  __int64 result; // x0
  _QWORD v19[12]; // [xsp+0h] [xbp-70h] BYREF
  int v20; // [xsp+60h] [xbp-10h]
  int v21; // [xsp+64h] [xbp-Ch]
  __int64 v22; // [xsp+68h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v19[0] = 0x700000010LL;
  v19[1] = 548;
  v20 = 2;
  v19[5] = a4;
  memset(&v19[6], 0, 48);
  v19[2] = a1;
  v19[3] = a2;
  v19[4] = a3;
  v9 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) < 2 )
  {
    result = _scm_smc_call(v9, v19, qcom_scm_convention, nullptr, 2);
LABEL_3:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( convention != 1 )
  {
    printk(&unk_124E9, "qcom_scm_call_noretry", v11);
    result = 4294967274LL;
    goto LABEL_3;
  }
  __break(0x800u);
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qcom_scm_hdcp_available();
}
