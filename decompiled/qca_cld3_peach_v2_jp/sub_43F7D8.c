__int64 __fastcall sub_43F7D8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __asm { STLLR           X26, [X14] }
  return sme_handle_sae_msg(a1, a2, a3, a4, a5);
}
