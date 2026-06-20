__int64 __fastcall sub_44F2C8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 _X5)
{
  __asm { STGP            X11, X11, [X5,#0x80]! }
  return dot11f_pack_assoc_response(a1, a2, a3, a4, a5);
}
