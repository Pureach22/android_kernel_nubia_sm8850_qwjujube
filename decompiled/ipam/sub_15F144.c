__int64 __fastcall sub_15F144(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned __int64 a8)
{
  _ReadStatusReg(TPIDR_EL2);
  return ipa_bridge_init(a1, a2, a3, (a8 >> 59) & 1);
}
