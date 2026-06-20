__int64 __fastcall msm_venc_streamoff_output(__int64 a1)
{
  *(_QWORD *)(a1 + 15256) = *(_QWORD *)(*(_QWORD *)(a1 + 320) + 4256LL);
  return msm_vidc_session_streamoff(a1, 1);
}
