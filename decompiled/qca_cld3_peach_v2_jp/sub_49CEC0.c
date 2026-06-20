__int64 __fastcall sub_49CEC0(__int64 a1)
{
  __int16 v1; // w12

  if ( (v1 & 0x200) == 0 )
    JUMPOUT(0x4A04C4);
  return os_if_dp_register_txrx_callbacks(a1);
}
