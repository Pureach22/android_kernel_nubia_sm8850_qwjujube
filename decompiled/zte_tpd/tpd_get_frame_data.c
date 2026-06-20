__int64 __fastcall tpd_get_frame_data(__int64 a1)
{
  __int64 v1; // x9

  v1 = *(_QWORD *)(a1 + 3072);
  *(_DWORD *)(a1 + 1120) = *(_DWORD *)(v1 + 1504);
  return 0;
}
