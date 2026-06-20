__int64 __fastcall sub_4E0C4(__int64 a1, char a2)
{
  if ( (a2 & 1) == 0 )
    JUMPOUT(0x48494);
  return _bpf_trace_msm_vidc_buffer_dma_ops();
}
