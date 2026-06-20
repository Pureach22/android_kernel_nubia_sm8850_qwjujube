__int64 __fastcall qmp_combo_usb_set_mode(__int64 a1, int a2, int a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 152);
  *(_DWORD *)(v3 + 272) = a2;
  if ( a3 )
    *(_DWORD *)(v3 + 276) = a3;
  return 0;
}
