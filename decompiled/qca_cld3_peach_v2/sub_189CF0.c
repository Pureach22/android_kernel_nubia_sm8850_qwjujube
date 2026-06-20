__int64 __fastcall sub_189CF0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x15
  __int64 v6; // x16

  return qdf_get_keyed_hash(a1, v6 ^ (v5 >> 21), a3, a4, a5);
}
