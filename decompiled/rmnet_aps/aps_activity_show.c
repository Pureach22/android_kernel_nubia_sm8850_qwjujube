__int64 __fastcall aps_activity_show(__int64 a1)
{
  atomic_uint *v2; // x9
  unsigned int v3; // w22
  __int64 v4; // x0
  char *v5; // x1
  char *v6; // x8
  int v7; // w6

  raw_spin_lock_bh(&dl_activity_lock);
  if ( (unsigned int)next_activity_index >= 0xA )
  {
LABEL_21:
    __break(0x5512u);
LABEL_22:
    __break(1u);
    atomic_fetch_add_explicit(v2, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
    atomic_fetch_add_explicit(v2, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
    atomic_fetch_add_explicit(v2, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
    atomic_fetch_add_explicit(v2, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
    JUMPOUT(0x86B8);
  }
  v2 = (atomic_uint *)dl_activity_records[7 * (unsigned int)next_activity_index];
  if ( v2 )
    v3 = next_activity_index;
  else
    v3 = 0;
  do
  {
    if ( v3 > 0xA )
      goto LABEL_21;
    if ( v3 == 10 )
      goto LABEL_22;
    v6 = (char *)&dl_activity_records[7 * v3];
    if ( !*(_QWORD *)v6 )
      break;
    v7 = (unsigned __int8)v6[11];
    if ( v7 == 17 || v7 == 6 )
    {
      v4 = a1;
      v5 = v6[8] == 4 ? "[%6lld %02d:%02d:%02d] %2u %pI4/%u %pI4/%u\n" : "[%6lld %02d:%02d:%02d] %2u %pI6/%u %pI6/%u\n";
    }
    else
    {
      v4 = a1;
      v5 = v6[8] == 4 ? "[%6lld %02d:%02d:%02d] %2u %pI4 %pI4\n" : "[%6lld %02d:%02d:%02d] %2u %pI6 %pI6\n";
    }
    seq_printf(v4, v5);
    if ( v3 <= 8 )
      ++v3;
    else
      v3 = 0;
  }
  while ( v3 != next_activity_index );
  raw_spin_unlock_bh(&dl_activity_lock);
  return 0;
}
