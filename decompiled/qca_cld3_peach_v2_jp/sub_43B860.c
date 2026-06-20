__int64 __fastcall sub_43B860(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  unsigned __int64 *v4; // x15

  atomic_store(a4, v4);
  return sme_get_opclass(a1, a2, a3, a4);
}
