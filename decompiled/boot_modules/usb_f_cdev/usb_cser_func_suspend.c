__int64 __fastcall usb_cser_func_suspend(__int64 a1, char a2)
{
  *(_BYTE *)(a1 - 7) = (a2 & 2) != 0;
  *(_BYTE *)(a1 - 8) = a2 & 1;
  return 0;
}
