__int64 __fastcall sub_C240(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int8 a5)
{
  __int64 v5; // x14

  atomic_store(a5, (unsigned __int8 *)(v5 + 70));
  return schedule_client_voting();
}
