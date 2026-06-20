__int64 __fastcall hif_get_napi(__int64 a1, __int64 a2, __int64 a3)
{
  if ( (unsigned int)(a1 - 1) < 0xC )
    return *(_QWORD *)(a2 + 8LL * (unsigned int)(a1 - 1) + 40);
  __break(0x5512u);
  return hif_napi_event(a1, a2, a3);
}
