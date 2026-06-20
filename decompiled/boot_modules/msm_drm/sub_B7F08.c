__int64 __fastcall sub_B7F08(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x14
  __int64 v5; // x19

  *(_QWORD *)(a4 + 32) = v4;
  *(_QWORD *)(a4 + 40) = v5;
  return hfi_crtc_destroy(a1, a2, a3, a4 + 32);
}
