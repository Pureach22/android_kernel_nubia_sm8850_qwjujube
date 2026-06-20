__int64 __fastcall sub_4F9E60(__int64 a1)
{
  __int16 v1; // w12

  if ( (v1 & 0x200) == 0 )
    JUMPOUT(0x4FD464);
  return os_if_dp_register_txrx_callbacks(a1);
}
