__int64 __fastcall ipa3_replenish_rx_work_func(__int64 a1)
{
  __int64 v2; // x20
  void (__fastcall *v3)(_QWORD); // x8
  __int64 result; // x0

  v2 = a1 - 224;
  _ReadStatusReg(SP_EL0);
  ipa3_inc_client_enable_clks();
  v3 = *(void (__fastcall **)(_QWORD))(a1 + 136);
  if ( *((_DWORD *)v3 - 1) != 1136933575 )
    __break(0x8228u);
  v3(v2);
  result = ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return result;
}
