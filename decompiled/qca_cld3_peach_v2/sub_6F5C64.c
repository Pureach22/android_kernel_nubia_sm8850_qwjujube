__int64 __fastcall sub_6F5C64(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _QWORD *v5; // x29
  __int128 v6; // q26
  __int128 v7; // q27
  __int128 v8; // q28

  *v5 = *((_QWORD *)&v6 + 1);
  v5[1] = *((_QWORD *)&v7 + 1);
  v5[2] = *((_QWORD *)&v8 + 1);
  return aead_decrypt_assoc_rsp(a1, a2, a3, a4, a5);
}
