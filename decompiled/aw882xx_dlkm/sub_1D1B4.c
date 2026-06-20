__int64 __fastcall sub_1D1B4(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { STGP            X12, X23, [X16,#0xBC] }
  return aw882xx_dsp_read_run_state_avg(a1, a2, a3);
}
