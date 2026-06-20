__int64 __fastcall sub_5CA4C8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, long double a7)
{
  if ( !a5 )
    JUMPOUT(0x63C910);
  return lim_send_sme_tdls_add_sta_rsp(a1, a2, a3, a4, a5, a6, a7);
}
