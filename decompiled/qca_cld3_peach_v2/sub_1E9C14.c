__int64 __fastcall sub_1E9C14(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, int a7)
{
  if ( (a7 & 0x100000) == 0 )
    JUMPOUT(0x1F0A10);
  return mlme_cm_ext_hdl_create(a1, a2);
}
