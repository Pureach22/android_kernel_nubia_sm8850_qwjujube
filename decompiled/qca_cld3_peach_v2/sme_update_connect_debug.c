__int64 __fastcall sme_update_connect_debug(__int64 a1, char a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 8);
  *(_BYTE *)(v2 + 1060) = a2;
  return 0;
}
