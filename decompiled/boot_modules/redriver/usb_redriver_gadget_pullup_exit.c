__int64 __fastcall usb_redriver_gadget_pullup_exit(__int64 result)
{
  __int64 (*v1)(void); // x8

  if ( result )
  {
    v1 = *(__int64 (**)(void))(result + 56);
    if ( v1 )
    {
      if ( *((_DWORD *)v1 - 1) != 45389739 )
        __break(0x8228u);
      return v1();
    }
  }
  return result;
}
