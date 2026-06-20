__int64 __fastcall sta_info_insert(__int64 a1, __int64 a2)
{
  __int64 inserted; // x0
  unsigned int v3; // w19

  inserted = sta_info_insert_rcu(a1, a2);
  v3 = inserted;
  _rcu_read_unlock(inserted);
  return v3;
}
