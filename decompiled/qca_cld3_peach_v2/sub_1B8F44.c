__int64 __fastcall sub_1B8F44(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  int v4; // w29

  *(_DWORD *)(v3 + 8) = a3;
  *(_DWORD *)(v3 + 12) = v4;
  return ucfg_crypto_set_key_req(a1, a2, a3);
}
