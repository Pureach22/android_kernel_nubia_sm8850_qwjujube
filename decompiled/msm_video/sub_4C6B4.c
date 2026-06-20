__int64 __fastcall sub_4C6B4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v10; // x5

  _T1 = *(_QWORD *)(a6 + 20);
  v10 = a6 + 20;
  __asm { STGP            X24, X29, [X5,#0x14]! }
  return _traceiter_msm_vidc_dma_buffer(a1, a2, a3, a4, a5, v10);
}
