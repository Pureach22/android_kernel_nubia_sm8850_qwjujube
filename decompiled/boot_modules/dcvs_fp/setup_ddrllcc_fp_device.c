__int64 __fastcall setup_ddrllcc_fp_device(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  unsigned int v6; // w19
  __int64 v7; // x9

  if ( *(_DWORD *)(a2 + 104) > 1u )
  {
    return (unsigned int)-22;
  }
  else
  {
    mutex_lock(&ddrllcc_lock);
    v5 = ddrllcc_data;
    if ( ddrllcc_data )
    {
      *(_QWORD *)(a3 + 120) = ddrllcc_data;
      *(_QWORD *)(a3 + 128) = ddrllcc_fp_commit;
      v6 = 0;
      v7 = 16;
      if ( !*(_DWORD *)(a2 + 104) )
        v7 = 8;
      *(_QWORD *)(v5 + v7) = a3;
    }
    else
    {
      v6 = -517;
    }
    mutex_unlock(&ddrllcc_lock);
  }
  return v6;
}
