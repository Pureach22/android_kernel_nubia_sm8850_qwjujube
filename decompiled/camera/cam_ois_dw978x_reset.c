__int64 __fastcall cam_ois_dw978x_reset(__int64 a1, __int64 a2)
{
  return cam_ois_write_regs(a1, a2, *(_QWORD *)(a2 + 48), *(_DWORD *)(a2 + 56));
}
