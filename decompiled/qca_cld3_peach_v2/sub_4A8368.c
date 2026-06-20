__int64 __fastcall sub_4A8368(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { STGP            X5, X19, [X17,#-0x84] }
  return csr_get_snr(a1, a2, a3, a4);
}
