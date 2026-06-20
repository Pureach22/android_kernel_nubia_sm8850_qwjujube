__int64 __fastcall mhi_controller_set_bw_scale_cb(__int64 result, __int64 a2)
{
  *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 16) + 192LL) + 72LL) = a2;
  return result;
}
