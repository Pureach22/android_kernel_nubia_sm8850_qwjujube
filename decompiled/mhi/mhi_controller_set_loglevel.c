__int64 __fastcall mhi_controller_set_loglevel(__int64 result, int a2)
{
  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 16) + 192LL) + 24LL) = a2;
  return result;
}
