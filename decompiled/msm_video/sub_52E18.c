__int64 __fastcall sub_52E18(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 _X7)
{
  __asm { SUBG            X8, X7, #0x290, #0xC }
  return msm_vidc_allow_drain_last_flag();
}
