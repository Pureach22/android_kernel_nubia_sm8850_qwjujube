__int64 __fastcall rpmh_rsc_invalidate(__int64 a1, unsigned int a2)
{
  ((void (__fastcall *)(__int64, _QWORD, _QWORD))tcs_invalidate)(a1, 0, a2);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))tcs_invalidate)(a1, 1, a2);
}
