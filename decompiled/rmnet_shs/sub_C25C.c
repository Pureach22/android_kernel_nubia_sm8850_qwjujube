__int64 __fastcall sub_C25C(__int64 a1, __int64 a2, __int64 _X2)
{
  __asm { STGP            X26, X17, [X2,#-0xBC] }
  return rmnet_shs_is_skb_stamping_reqd();
}
