__int64 __fastcall cam_ife_csid_1190_override_cb(__int64 a1)
{
  __int64 v3; // x9

  v3 = *(_QWORD *)(*(_QWORD *)a1 + 256LL);
  *(_QWORD *)a1 = v3;
  *(_DWORD *)(*(_QWORD *)(v3 + 120) + 476LL) = 0;
  *(_DWORD *)(*(_QWORD *)(v3 + 120) + 828LL) |= 0x800u;
  return 0;
}
