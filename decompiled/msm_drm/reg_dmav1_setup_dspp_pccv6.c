unsigned __int64 __fastcall reg_dmav1_setup_dspp_pccv6(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6)
{
  *(_DWORD *)(a2 + 160) = *(_DWORD *)(a2 + 160) & 0xFF0F0FFF | 0x6000;
  return reg_dmav1_setup_dspp_pcc_common(a1, (_QWORD *)a2, a3, a4, a5, a6);
}
