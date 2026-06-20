__int64 __fastcall m31eusb2_phy_set_mode(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x0

  v2 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v2 + 88);
  *(_DWORD *)(v2 + 40) = a2;
  return phy_set_mode_ext(v3);
}
