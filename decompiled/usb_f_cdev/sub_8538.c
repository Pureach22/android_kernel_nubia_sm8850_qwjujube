__int64 __fastcall sub_8538(__int64 a1, __int64 a2, int a3, __int64 a4, int a5)
{
  _DWORD *v5; // x28

  *v5 = a3;
  v5[1] = a5;
  return usb_cser_get_status();
}
