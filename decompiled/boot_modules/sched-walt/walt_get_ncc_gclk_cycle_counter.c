__int64 __fastcall walt_get_ncc_gclk_cycle_counter(unsigned int a1)
{
  __int64 v1; // x20
  _QWORD *v2; // x21
  __int64 v3; // x0
  __int64 v4; // x19
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x20

  if ( a1 >= 0x20 || (v1 = (unsigned int)cpu_topology[12 * a1 + 2], (unsigned int)v1 > 4) )
  {
    __break(0x5512u);
    goto LABEL_9;
  }
  v2 = (_QWORD *)((char *)&walt_gclk_counter + 24 * (unsigned int)v1);
  v3 = raw_spin_lock_irqsave(v2 + 2);
  if ( (_DWORD)v1 == 4 )
  {
LABEL_9:
    __break(1u);
    return ((__int64 (*)(void))readq_relaxed)();
  }
  v4 = v3;
  v5 = readq_relaxed(ncc_data[v1]);
  v6 = v2[1];
  v7 = v5 + *v2;
  if ( v5 < v6 )
    v8 = ~v6;
  else
    v8 = -(__int64)v6;
  v9 = v7 + v8;
  *v2 = v7 + v8;
  v2[1] = v5;
  raw_spin_unlock_irqrestore(v2 + 2, v4);
  return v9;
}
