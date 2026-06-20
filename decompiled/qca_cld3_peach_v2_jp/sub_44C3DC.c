__int64 __fastcall sub_44C3DC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( a5 )
    JUMPOUT(0x4A0710);
  return csr_send_set_ie(a1, a2, a3);
}
